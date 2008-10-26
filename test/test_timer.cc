#include "test_timer.h"

#include <iostream>
#include <cmath>


#include <boost/numeric/ublas/lu.hpp>

#if 0
template<class matrix_T>
double determinant(ublas::matrix_expression<matrix_T> const& mat_r)
{
	double det = 1.0;

	matrix_T mLu(mat_r() );
	ublas::permutation_matrix<std::size_t> pivots(mat_r().size1() );

	int is_singular = lu_factorize(mLu, pivots);

	if (!is_singular)
	{
		for (std::size_t i=0; i < pivots.size(); ++i)
		{
			if (pivots(i) != i)
				det *= -1.0;

			det *= mLu(i,i);
		}
	}
	else
		det = 0.0;

	return det;
} 
#endif

TestTimer::TestTimer(KDLCV::QKDLChainView *view) :
	m_View(view),
	m_IkSolver(*view->chain()),
	m_FkSolver(*view->chain())
{

}

void TestTimer::do_tha_thang() {
	// std::cout << "." << std::endl;
#if 0
	for (unsigned int i = 0; i < viz->pose().size(); ++i) {
		viz->pose()[i] += 0.01;
	}
#endif
	KDL::JntArray array_in(m_View->pose().size());
	KDL::JntArray array_out(m_View->pose().size());

	for (unsigned int i = 0; i < m_View->pose().size(); ++i)
		array_in(i) = m_View->pose()[i];

	KDL::Twist twist;
	twist(0) = 0.05;
	twist(1) = 0.05;
	twist(2) = 0.05;
	twist(3) = 0;
	twist(4) = 0;
	twist(5) = 0;

	m_IkSolver.CartToJnt(array_in, twist, array_out);

	KDL::Frame fk_current_frame;
	m_FkSolver.JntToCart(array_in, fk_current_frame);

	KDL::Frame fk_next_frame;
	KDL::JntArray array_in_and_out = array_in;
	for (unsigned int i = 0; i < m_View->pose().size(); ++i)
		array_in_and_out(i) = array_in(i) + array_out(i);
	
	m_FkSolver.JntToCart(array_in_and_out, fk_next_frame);

	std::cout << (fk_next_frame.p.x() - fk_current_frame.p.x()) << " " << (fk_next_frame.p.y() - fk_current_frame.p.y()) << " " << (fk_next_frame.p.z() - fk_current_frame.p.z()) <<  std::endl; 
		
	if ((fk_next_frame.p - (fk_current_frame.p+KDL::Vector(0.05,0.05,0.05))).Norm() > KDL::Vector(0.05,0.05,0.05).Norm() ) 
	{
		//std::cout << (fk_next_frame.p.x() - fk_current_frame.p.x()) << " " << fk_next_frame.p.y() << " " << fk_next_frame.p.z() << std::endl; 
		for (unsigned int i = 0; i < m_View->pose().size(); ++i)
			array_out(i) *= 0.01/(1.0+(fk_next_frame.p - (fk_current_frame.p + KDL::Vector(0.05,0.05,0.05))).Norm());
		//array_out(i) *= KDL::Vector(0.05,0.05,0.05).Norm() / (fk_next_frame.p - fk_current_frame.p).Norm();
	}

	//std::cout << KDL::Vector(0.05,0.05,0.05).Norm() / (fk_next_frame.p - fk_current_frame.p).Norm() << std::endl;

	for (unsigned int i = 0; i < m_View->pose().size(); ++i)
		m_View->pose()[i] += array_out(i);

	m_View->update();
}

#include "test_timer.h"

#include <iostream>

#include <kdl/jntarray.hpp>

TestTimer::TestTimer(KDLCV::QKDLChainView *view) :
	m_View(view),
	m_Solver(*view->chain())
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
	for (unsigned int i = 0; i < m_View->pose().size(); ++i) 
		array_in(i) = m_View->pose()[i];

	KDL::JntArray array_out(m_View->pose().size());

	KDL::Twist twist;
	twist(0) = 0.1;
	twist(1) = 0.1;
	twist(2) = 0.1;

	m_Solver.CartToJnt(array_in, twist, array_out);

	for (unsigned int i = 0; i < m_View->pose().size(); ++i) 
		m_View->pose()[i] += array_out(i);

	m_View->update();
}


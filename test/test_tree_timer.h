#ifndef TEST_TIMER_HH
#define TEST_TIMER_HH

#include <QObject>

#include "qkdltreeview.h"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include <kdl/treefksolverpos_recursive.hpp>
//#include <kdl/treeiksolvervel_pinv.hpp>
#include <kdl/treejnttojacsolver.hpp>
#include <kdl/jntarray.hpp>
#include <kdl/jacobian.hpp>

using namespace boost::numeric;

class TestTimer : public QObject
{
	Q_OBJECT

	KDLCV::QKDLTreeView *m_View;

	//KDL::TreeIkSolverVel_pinv m_IkSolver;
	//KDL::TreeFkSolverPos_recursive m_FkSolver;

public:
	TestTimer(KDLCV::QKDLTreeView *view);

public slots:
	void do_tha_thang();
};

#endif

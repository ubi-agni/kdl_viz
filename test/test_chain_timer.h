#ifndef TEST_TIMER_HH
#define TEST_TIMER_HH

#include <QObject>

#include "qkdlchainview.h"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include <kdl/jntarray.hpp>
#include <kdl/jacobian.hpp>

using namespace boost::numeric;

class TestTimer : public QObject
{
	Q_OBJECT

	KDLCV::QKDLChainView *m_View;

	KDL::ChainIkSolverVel_pinv m_IkSolver;
	KDL::ChainFkSolverPos_recursive m_FkSolver;

public:
	TestTimer(KDLCV::QKDLChainView *view);

public slots:
	void do_tha_thang();
};

#endif

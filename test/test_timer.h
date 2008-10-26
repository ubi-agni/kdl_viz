#ifndef TEST_TIMER_HH
#define TEST_TIMER_HH

#include <QTimer>
#include "qkdlchainview.h"

#include <kdl/chainiksolvervel_pinv.hpp>

class TestTimer : public QTimer
{
	Q_OBJECT

	KDLCV::QKDLChainView *m_View;

	KDL::ChainIkSolverVel_pinv m_Solver;

public:
	TestTimer(KDLCV::QKDLChainView *view);

public slots:
	void do_tha_thang();
};

#endif

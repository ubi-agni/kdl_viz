#ifndef TEST_TIMER_HH
#define TEST_TIMER_HH

#include <QTimer>
#include "kdl_chain_viz.h"

class TestTimer : public QTimer
{
	Q_OBJECT

	KDLChainVisualizerWidget *viz;

public:
	TestTimer(KDLChainVisualizerWidget *viz);

public slots:
	void do_tha_thang();
};

#endif

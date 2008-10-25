#ifndef TEST_TIMER_HH
#define TEST_TIMER_HH

#include <QTimer>
#include "qkdlchainview.h"

class TestTimer : public QTimer
{
	Q_OBJECT

	KDLCV::QKDLChainView *viz;

public:
	TestTimer(KDLCV::QKDLChainView *viz);

public slots:
	void do_tha_thang();
};

#endif

#ifndef TEST_TIMER_HH
#define TEST_TIMER_HH

#include <QTimer>
#include "qkdlchainwidget.h"

class TestTimer : public QTimer
{
	Q_OBJECT

	KDLView::QKDLChainWidget *viz;

public:
	TestTimer(KDLView::QKDLChainWidget *viz);

public slots:
	void do_tha_thang();
};

#endif

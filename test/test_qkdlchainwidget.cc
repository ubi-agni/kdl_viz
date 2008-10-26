#include "qkdlchainview.h"

#include <QApplication>
#include <QTimer>

#include <kdl/chain.hpp>
#include <kdl/segment.hpp>
#include <kdl/frames.hpp>

#include "test_timer.h"


int main(int argc, char **argv) {
	QApplication app(argc, argv);

	KDL::Chain *chain = new KDL::Chain;

	for (int i = 0; i < 100; ++i) {
		chain->addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotX), KDL::Frame(KDL::Vector(0.0, 0.0, 0.3))));
		chain->addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotY), KDL::Frame(KDL::Vector(0.0, 0.0, 0.3))));
	}
	KDLCV::QKDLChainView w(chain);

	for (unsigned int i = 0; i < w.pose().size(); ++i) {
		w.pose()[i] = 0.1;
	}
	w.show();

	QTimer timer;
	timer.setInterval(100);

	TestTimer test_timer(&w);

	timer.connect(&timer, SIGNAL(timeout()), &test_timer, SLOT(do_tha_thang()));

	timer.start();

	app.exec();
	delete chain;
}


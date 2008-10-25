#include "qkdlchainwidget.h"

#include <QApplication>
#include <QTimer>

#include <kdl/chain.hpp>
#include <kdl/segment.hpp>
#include <kdl/frames.hpp>

#include "test_timer.h"


int main(int argc, char **argv) {
	QApplication app(argc, argv);

	ChainPtr chain(new KDL::Chain);

	chain->addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ), KDL::Frame(KDL::Vector(0.1, 0.1, 0.1))));
	chain->addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotY), KDL::Frame(KDL::Vector(0.1, 0.1, 0))));
	chain->addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotX), KDL::Frame(KDL::Vector(0.1, 0, 0.1))));
	chain->addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ), KDL::Frame(KDL::Vector(0.1, 0.1, 0))));
	chain->addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotY), KDL::Frame(KDL::Vector(0.1, 0, 0.1))));
	chain->addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotX), KDL::Frame(KDL::Vector(0.1, 0.1, 0))));

	QKDLChainWidget w(chain);

	w.pose()[0] = 2.0;
	w.pose()[1] = 0.1;
	w.pose()[2] = 0.1;
	w.pose()[3] = 0.1;
	w.pose()[4] = 0.1;
	w.pose()[5] = 0.1;

	w.show();

	QTimer timer;
	timer.setInterval(100);

	TestTimer test_timer(&w);

	timer.connect(&timer, SIGNAL(timeout()), &test_timer, SLOT(do_tha_thang()));

	timer.start();

	app.exec();
}


#include "qkdltreeview.h"

#include <cstdlib>
#include <cmath>
#include <sstream>

#include <QApplication>
#include <QTimer>

#include <kdl/tree.hpp>
#include <kdl/segment.hpp>
#include <kdl/frames.hpp>

#include "test_tree_timer.h"

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	KDL::Tree *tree = new KDL::Tree;

	if (
		!tree->addSegment(
			KDL::Segment(
				"1", 
				KDL::Joint(KDL::Joint::RotX), 
				KDL::Frame(KDL::Vector(0.0, 0.0, 0.3))
			),
			"root"
		)
	) { 
		std::cout << "Argh" << std::endl; exit(1); 
	}

	for (int i = 2; i < 30; ++i) {
		// name for current segment
		std::stringstream str;		
		str << i;

		// name for previous segment (the hook)
		std::stringstream str2;
		str2 << i - 1;

		std::cout << str.str() << " " << str2.str() << std::endl;
		if (
			!tree->addSegment(
				KDL::Segment(
					str.str(), 
					KDL::Joint(KDL::Joint::RotX), 
					KDL::Frame(KDL::Vector(0.0, 0.0, 0.3))
				), 
				str2.str())
		) 	{ 
			std::cout << "we ghwgjhawghw" << std::endl; 
			exit(1); 
		}
	}

	
	// std::cout << dump_kdl_tree_to_string(*tree) << std::endl;

	std::cout << ",,,: " << tree->getNrOfSegments() <<  std::endl;

	KDLCV::QKDLTreeView w(tree);

	// shuffle the joints, but do it deterministically
	std::cout << "pose.size(): " << w.pose().size() << std::endl;
	srand(0);
	for (unsigned int i = 0; i < w.pose().size(); ++i) {
		w.pose()[i] = M_PI * (((float)rand()/(float)(RAND_MAX))-0.5);
	}
	w.show();
	std::cout << "pose.size(): " << w.pose().size() << std::endl;
	QTimer timer;
	timer.setInterval(50);

	TestTimer test_timer(&w);

	timer.connect(&timer, SIGNAL(timeout()), &test_timer, SLOT(do_tha_thang()));

	timer.start();

	app.exec();
	delete tree;
}


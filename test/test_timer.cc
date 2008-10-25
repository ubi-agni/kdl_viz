#include "test_timer.h"

#include <iostream>

TestTimer::TestTimer(KDLChainVisualizerWidget *viz) :
	viz(viz)
{

}

void TestTimer::do_tha_thang() {
	// std::cout << "." << std::endl;
	viz->pose()[0] += 0.01;
	viz->pose()[1] += 0.01;
	viz->pose()[2] += 0.01;
	viz->pose()[3] += 0.01;
	viz->pose()[4] += 0.01;
	viz->pose()[5] += 0.01;

	viz->update();
}


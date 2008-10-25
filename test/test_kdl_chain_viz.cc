#include "kdl_chain_viz.h"

#include <QApplication>
#include <kdl/chain.hpp>

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	ChainPtr chain(new KDL::Chain);

	KDLChainVisualizerWidget w(chain);
	w.show();

	app.exec();
}


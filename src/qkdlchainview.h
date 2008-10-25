#ifndef KDLVC_QCHAIN_VIEW_HH
#define KDLVC_QCHAIN_VIEW_HH

#include <QObject>
#include "qkdlchainwidget.h"

namespace KDLCV {
	struct QKDLChainView : public QKDLChainWidget
	{
		Q_OBJECT

	public:
		QKDLChainView(KDL::Chain *chain, QWidget *parent = 0) :
			QKDLChainWidget(chain, parent)
		{

		}

		virtual void initializeGL() {
			QKDLChainWidget::initializeGL();

			gluPerspective(90.0, 1.0, 0.1, 10000.0);
		}
	};
} // namespace
#endif
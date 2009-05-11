#ifndef KDLVC_QCHAIN_VIEW_HH
#define KDLVC_QCHAIN_VIEW_HH

#include <QObject>
#include <QMouseEvent>
#include <QWheelEvent>

#include <GL/glu.h>

#include <iostream>
#include <cmath>

#include "qkdlchainwidget.h"


namespace KDLCV {
	/**
		A widget that provides some navigation functionality.. Press left mouse button
		and drag to rotate the scene around the up and right axes. Use the mouse wheel 
		to zoom in and out..
	*/
	struct QKDLChainView : public QKDLChainWidget
	{
		Q_OBJECT

		double m_AngleX;
		double m_AngleY;
		double m_Distance;

		QPoint m_LastPosition;

	public:
		QKDLChainView(KDL::Chain *chain, QWidget *parent = 0);

		virtual void initializeGL();

		virtual void paintGL();

		void mousePressEvent(QMouseEvent *event);

		void mouseReleaseEvent(QMouseEvent *event);

		void mouseMoveEvent (QMouseEvent * event);

		void wheelEvent (QWheelEvent *event);
	};
} // namespace
#endif

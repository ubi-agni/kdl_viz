#ifndef KDLVC_QTREE_VIEW_HH
#define KDLVC_QTREE_VIEW_HH

#include <QObject>
#include <QMouseEvent>
#include <QWheelEvent>

#include <GL/glu.h>

#include <iostream>
#include <cmath>

#include "qkdltreewidget.h"


namespace KDLCV {
	/**
		A widget that provides some navigation functionality.. Press left mouse button
		and drag to rotate the scene around the up and right axes. Use the mouse wheel 
		to zoom in and out..
	*/
	struct QKDLTreeView : public QKDLTreeWidget
	{
		Q_OBJECT

		double m_AngleX;
		double m_AngleY;
		double m_Distance;

		QPoint m_LastPosition;

	public:
		QKDLTreeView(KDL::Tree *tree, QWidget *parent = 0);

		virtual void initializeGL();

		virtual void paintGL();

		void mousePressEvent(QMouseEvent *event);

		void mouseReleaseEvent(QMouseEvent *event);

		void mouseMoveEvent (QMouseEvent * event);

		void wheelEvent (QWheelEvent *event);
	};
} // namespace
#endif

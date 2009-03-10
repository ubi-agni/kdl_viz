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
		QKDLChainView(KDL::Chain *chain, QWidget *parent = 0) :
			QKDLChainWidget(chain, parent),
			m_AngleX(0),
			m_AngleY(0),
			m_Distance(2)
		{

		}

		virtual void initializeGL() {
			QKDLChainWidget::initializeGL();

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(90.0, width()/height(), 0.1, 10000.0);
			gluLookAt(0,m_Distance,0,0,0,0,0,0,1);
		}

		virtual void paintGL() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(90.0, width()/height(), 0.1, 10000.0);
			gluLookAt(0,m_Distance,0,0,0,0,0,0,1);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glRotatef(m_AngleY, 1,0,0);
			glRotatef(m_AngleX, 0,0,1);

			draw_chain(m_Chain, m_Pose);
		}

		void mousePressEvent(QMouseEvent *event) {
			if (event->button() == Qt::LeftButton) {
				m_LastPosition = event->pos();
			}
		}

		void mouseReleaseEvent(QMouseEvent *event) {
			if (event->button() == Qt::LeftButton) {
			}
		}

		void mouseMoveEvent (QMouseEvent * event) {
			//if (event->button() != Qt::LeftButton) return;

			std::cout << "mouse move: " << m_AngleX << " " << m_AngleY << std::endl;
			QPoint delta = event->pos() - m_LastPosition;

			m_AngleX += 0.1 * delta.x();
			m_AngleY += 0.1 * delta.y();

			m_AngleX = fmod(m_AngleX, 360);
			m_AngleY = m_AngleY > 90 ? 90 : m_AngleY;
			m_AngleY = m_AngleY < -90 ? -90 : m_AngleY;

			m_LastPosition = event->pos();
			update();
		}

		void wheelEvent (QWheelEvent *event)
		{
			std::cout << "mouse wheel: " << event->delta() << std::endl;
			m_Distance += (-0.001 * event->delta());
			update();
		}
	};
} // namespace
#endif

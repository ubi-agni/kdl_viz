#include "qkdltreeview.h"

#include <iostream>

namespace KDLCV {

QKDLTreeView::QKDLTreeView(KDL::Tree *tree, QWidget *parent) :
	QKDLTreeWidget(tree, parent),
	m_AngleX(M_PI/4.0),
	m_AngleY(M_PI/4.0),
	m_Distance(2)
{
	std::cout << "qtreeview" << std::endl;
}

void QKDLTreeView::initializeGL() {
	QKDLTreeWidget::initializeGL();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, ((float)width())/((float)height()), 0.1, 10000.0);
	gluLookAt(0,m_Distance,0,0,0,0,0,0,1);
}

void QKDLTreeView::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, ((float)width())/((float)height()), 0.1, 10000.0);
	gluLookAt(0,m_Distance,0,0,0,0,0,0,1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(m_AngleY, 1,0,0);
	glRotatef(m_AngleX, 0,0,1);

	draw_tree(m_Pose);
}

void QKDLTreeView::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		m_LastPosition = event->pos();
	}
}

void QKDLTreeView::mouseReleaseEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
	}
}

void QKDLTreeView::mouseMoveEvent (QMouseEvent * event) {
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

void QKDLTreeView::wheelEvent (QWheelEvent *event)
{
	std::cout << "mouse wheel: " << event->delta() << std::endl;
	m_Distance += (-0.001 * event->delta());
	update();
}

} // namespace

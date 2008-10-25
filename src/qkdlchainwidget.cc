#include "qkdlchainwidget.h"

#include "kdlchainview.h"

QKDLChainWidget::QKDLChainWidget(ChainPtr chain, QWidget *parent) :
	QGLWidget(parent),
	m_Chain(chain),
	m_Pose(m_Chain->getNrOfSegments()),
	KDLChainView(chain)
{

}

QKDLChainWidget::~QKDLChainWidget() 
{

}

void QKDLChainWidget::resizeGL() 
{
	glViewport(0, 0, (GLint)width(), (GLint)height());
}

void QKDLChainWidget::paintGL() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	KDLView::draw_chain(*m_Chain.get(), m_Pose);
}

void QKDLChainWidget::initializeGL() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);

	initialize_gl();
}

ublas::vector<double> &QKDLChainWidget::pose()
{
	return m_Pose;
}

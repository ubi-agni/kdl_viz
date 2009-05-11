#include "qkdlchainwidget.h"

#include "kdlchainview.h"

namespace KDLCV {
/**
	The instance of chain is not owned by QKDLChainWidget. It will not be destroyed in the
	destructor.
*/
QKDLChainWidget::QKDLChainWidget(KDL::Chain* chain, QWidget *parent)  :
	QGLWidget(parent),
	m_Chain(chain),
	m_Pose(m_Chain->getNrOfSegments())
{

}

QKDLChainWidget::~QKDLChainWidget() { }

/**
	Reimplemented from QGLWidget. The user normally doesn't need
	to worry about this method
*/
void QKDLChainWidget::resizeGL(int width, int height) 
{
	std::cout << "resize" << std::endl;
	
	glViewport(0, 0, (GLint)width, (GLint)height);
}

/**
	Reimplemented from QGLWidget. The user normally doesn't need
	to worry about this method
*/
void QKDLChainWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	draw_chain(m_Chain, m_Pose);
}

/**
	Reimplemented from QGLWidget. The user normally doesn't need
	to worry about this method
*/
void QKDLChainWidget::initializeGL() 
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
}

/**
	Reimplemented from KDLCV::KDLChainView. Use this to access the pose 
	used to render the chain.
*/
std::vector<double> &QKDLChainWidget::pose()
{
	return m_Pose;
}

KDL::Chain* QKDLChainWidget::chain()
{
	return m_Chain;
}

} // namespace 


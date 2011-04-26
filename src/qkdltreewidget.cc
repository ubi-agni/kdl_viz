#include "qkdltreewidget.h"

#include "kdltreeview.h"

namespace KDLCV {
/**
	The instance of tree is not owned by QKDLTreeWidget. It will not be destroyed in the
	destructor.
*/
QKDLTreeWidget::QKDLTreeWidget(KDL::Tree* tree, QWidget *parent)  :
	QGLWidget(parent),
	KDLCV::KDLTreeView<KDL::Tree*, std::vector<double> >(tree),
	m_Pose(tree->getNrOfJoints())
{
	//std::cout << "widget" << std::endl;
}

QKDLTreeWidget::~QKDLTreeWidget() { }

/**
	Reimplemented from QGLWidget. The user normally doesn't need
	to worry about this method
*/
void QKDLTreeWidget::resizeGL(int width, int height) 
{
	//std::cout << "resize" << std::endl;
	
	glViewport(0, 0, (GLint)width, (GLint)height);
}

/**
	Reimplemented from QGLWidget. The user normally doesn't need
	to worry about this method
*/
void QKDLTreeWidget::paintGL()
{
	//std::cout << "paintGL" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	draw_tree(m_Pose);
}

/**
	Reimplemented from QGLWidget. The user normally doesn't need
	to worry about this method
*/
void QKDLTreeWidget::initializeGL() 
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
}

/**
	Reimplemented from KDLCV::KDLTreeView. Use this to access the pose 
	used to render the tree.
*/
std::vector<double> &QKDLTreeWidget::pose()
{
	return m_Pose;
}

KDL::Tree* QKDLTreeWidget::tree()
{
	return m_Tree;
}

} // namespace 


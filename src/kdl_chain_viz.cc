#include "kdl_chain_viz.h"

#include <iostream>

KDLChainVisualizerWidget::KDLChainVisualizerWidget(ChainPtr chain, QWidget *parent) :
	QGLWidget(parent),
	m_Chain(chain),
	m_Pose(m_Chain->getNrOfSegments())
{

}

KDLChainVisualizerWidget::~KDLChainVisualizerWidget() 
{

}

void KDLChainVisualizerWidget::resizeGL() 
{
	glViewport(0, 0, (GLint)width(), (GLint)height());
}

void KDLChainVisualizerWidget::paintGL() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	for (unsigned int segment = 0; segment < m_Chain->getNrOfSegments(); ++segment) {
		// std::cout << "segment " << segment << std::endl;

		KDL::Frame pose_frame = m_Chain->getSegment(segment).pose(m_Pose[segment]);

		double pose_matrix[16];
		for (unsigned int i = 0; i < 16; ++i) pose_matrix[i] = pose_frame(i % 4, i / 4);


		glColor3f(1,1,1);

		// draw a line from current origin to pose which is specified by
		// the translational part of the matrix	
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(pose_matrix[12], pose_matrix[13], pose_matrix[14]);
		glEnd();

#if 0
		KDL::Frame pose_frame = m_Chain->getSegment(segment).pose(0.3);

		double pose_matrix[16];
		for (unsigned int i = 0; i < 16; ++i) pose_matrix[i] = pose_frame(i % 4, i / 4);
#endif
		glMultMatrixd(pose_matrix);
	}
}

void KDLChainVisualizerWidget::initializeGL() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
}

ublas::vector<double> &KDLChainVisualizerWidget::pose()
{
	return m_Pose;
}

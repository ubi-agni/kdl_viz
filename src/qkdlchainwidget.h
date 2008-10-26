#ifndef QKDL_CHAIN_VIZ_HH
#define QKDL_CHAIN_VIZ_HH

#include <QGLWidget>
#include <QObject>

#include <iostream>

#include <kdl/chain.hpp>

#include "kdlchainview.h"

namespace KDLCV {
	/**
		A class which provides a Qt wrapper around KDLChainViewer. It is subclassed from 
		QGLWidget so it can be used as a drop in replacement..
	*/
	class QKDLChainWidget : 
		public QGLWidget,
		public KDLCV::KDLChainView<KDL::Chain*, std::vector<double> >
	{
		Q_OBJECT

	protected:
		KDL::Chain *m_Chain;
		std::vector<double> m_Pose;

	public:
		/**
			The instance of chain is not owned by QKDLChainWidget. It will not be destroyed in the
			destructor.
		*/
		QKDLChainWidget(KDL::Chain* chain, QWidget *parent = 0)  :
			QGLWidget(parent),
			m_Chain(chain),
			m_Pose(m_Chain->getNrOfSegments())
		{

		}

		virtual ~QKDLChainWidget() { }

		/**
			Reimplemented from QGLWidget. The user normally doesn't need
			to worry about this method
		*/
		virtual void resizeGL(int width, int height) 
		{
			std::cout << "resize" << std::endl;
			
			glViewport(0, 0, (GLint)width, (GLint)height);
		}

		/**
			Reimplemented from QGLWidget. The user normally doesn't need
			to worry about this method
		*/
		virtual void paintGL()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			draw_chain(m_Chain, m_Pose);
		}

		/**
			Reimplemented from QGLWidget. The user normally doesn't need
			to worry about this method
		*/
		virtual void initializeGL() 
		{
			glClearColor(0.0, 0.0, 0.0, 0.0);
			glEnable(GL_DEPTH_TEST);
		}

		/**
			Reimplemented from KDLCV::KDLChainView. Use this to access the pose 
			used to render the chain.
		*/
		virtual std::vector<double> &pose()
		{
			return m_Pose;
		}

		virtual KDL::Chain* chain()
		{
			return m_Chain;
		}
	};
} // namespace 

#endif


#ifndef QKDL_CHAIN_VIZ_HH
#define QKDL_CHAIN_VIZ_HH

#include <QGLWidget>

#include <kdl/chain.hpp>

#include <boost/shared_ptr.hpp>

#include "kdlchainview.h"

typedef boost::shared_ptr<KDL::Chain> ChainPtr;

namespace KDLView {
	/**
		A class which provides a Qt wrapper around KDLChainViewer. It is subclassed from 
		QGLWidget so it can be used as a drop in replacement..
	*/
	class QKDLChainWidget : 
		public QGLWidget,
		public KDLCV::KDLChainView<KDL::Chain*, std::vector<double> >
	{
		Q_OBJECT

		KDL::Chain *m_Chain;
		std::vector<double> m_Pose;

	public:	
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
		virtual void resizeGL() 
		{
			glViewport(0, 0, (GLint)width(), (GLint)height());
		}

		/**
			Reimplemented from QGLWidget. The user normally doesn't need
			to worry about this method
		*/
		virtual void paintGL()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();

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
	};
} // namespace 

#endif


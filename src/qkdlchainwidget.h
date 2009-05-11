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
		QKDLChainWidget(KDL::Chain* chain, QWidget *parent = 0);

		virtual ~QKDLChainWidget();

		/**
			Reimplemented from QGLWidget. The user normally doesn't need
			to worry about this method
		*/
		virtual void resizeGL(int width, int height);

		/**
			Reimplemented from QGLWidget. The user normally doesn't need
			to worry about this method
		*/
		virtual void paintGL();

		/**
			Reimplemented from QGLWidget. The user normally doesn't need
			to worry about this method
		*/
		virtual void initializeGL();

		/**
			Reimplemented from KDLCV::KDLChainView. Use this to access the pose 
			used to render the chain.
		*/
		virtual std::vector<double> &pose();

		virtual KDL::Chain* chain();
	};
} // namespace 

#endif


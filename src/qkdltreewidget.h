#ifndef QKDL_TREE_VIZ_HH
#define QKDL_TREE_VIZ_HH

#include <QGLWidget>
#include <QObject>

#include <iostream>

#include <kdl/tree.hpp>
#include "kdltreeview.h"

namespace KDLCV {
	/**
		A class which provides a Qt wrapper around KDLTreeViewer. It is subclassed from 
		QGLWidget so it can be used as a drop in replacement..
	*/
	class QKDLTreeWidget : 
		public QGLWidget,
		public KDLCV::KDLTreeView<KDL::Tree*, std::vector<double> >
	{
		Q_OBJECT

	protected:
		std::vector<double> m_Pose;

	public:
		/**
			The instance of tree is not owned by QKDLTreeWidget. It will not be destroyed in the
			destructor.
		*/
		QKDLTreeWidget(KDL::Tree* tree, QWidget *parent = 0);

		virtual ~QKDLTreeWidget();

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
			Reimplemented from KDLCV::KDLTreeView. Use this to access the pose 
			used to render the tree.
		*/
		virtual std::vector<double> &pose();

		virtual KDL::Tree* tree();
	};
} // namespace 

#endif


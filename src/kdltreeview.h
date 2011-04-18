#ifndef KDL_TREE_VIZ_HH
#define KDL_TREE_VIZ_HH

#include <kdl/tree.hpp>
#include <kdl/joint.hpp>
#include <kdl/treefksolverpos_recursive.hpp>

#include <GL/gl.h>

//#include <iostream>

namespace KDLCV {
	/**
		This class can be used to draw a KDL::Tree into an existing OpenGL context.
		The template parameter TreePtrType can be used to parametrize this class 
		e.g. with your favourite shared_ptr class or simply by (KDL::Tree*).. It has
		to have an operator->() to access the pointee..

		The PoseArrayType simply has to have an operator[] to access the elements and could
		be e.g. std::vector or boost::numeric::ublas::vector or simply (double*).
	*/
	template<
		class TreePtrType, 
		class PoseArrayType
	>
	struct KDLTreeView	
	{
		KDLTreeView(TreePtrType tree) :
			m_Tree(tree),
			m_Solver(*tree)
		{
			// std::cout << "kdltreeview" << std::endl;
		};

		TreePtrType m_Tree;
		KDL::TreeFkSolverPos_recursive m_Solver;

		/**
			This method draws a KDL::Tree into a OpengGL context which has
			to be setup by the user (it also has to be made current
			by the user).

			The matrix stack is used but returned to its previous state after
			the use of this method..
		*/
		void draw_tree(const PoseArrayType &pose) {
			// std::cout << "fergfherlghrklt hgrskhrslkh jerkhjhwr wrhjg" << std::endl;
			// std::cout << pose.size() << std::endl;
			glPushMatrix();

			glLineWidth(3);

			// draw a coordinate system,
			glColor3f(1,0,0);
			glBegin(GL_LINES);
				glVertex3f(0,0,0);
				glVertex3f(1,0,0);
			glEnd();

			glColor3f(0,1,0);
			glBegin(GL_LINES);
				glVertex3f(0,0,0);
				glVertex3f(0,1,0);
			glEnd();

			glColor3f(0,0,1);
			glBegin(GL_LINES);
				glVertex3f(0,0,0);
				glVertex3f(0,0,1);
			glEnd();

			//draw_element(tree->getRootSegment(), pose);
			// std::cout << "-" << std::endl;
			KDL::JntArray jnt_array(pose.size());
			// std::cout << "+" << std::endl;
			for (unsigned int i = 0; i < pose.size(); ++i) jnt_array(i) = pose[i];

			//std::cout << "=" << std::endl;
			KDL::SegmentMap segment_map = m_Tree->getSegments();
			//std::cout << "fjw afja" << std::endl;
			for (KDL::SegmentMap::const_iterator it = segment_map.begin(); it != segment_map.end(); ++it) {
				// std::cout << ".... " << (*it).first << std::endl;
				// If we are the root, we don't draw anything
				if ((*it).first == "root") continue; 
				if ((*it).second.parent == m_Tree->getSegments().end()) { std::cout << "root!!!!" << std::endl; continue; }

				// solve for position of element and its parents position, so we
				// can draw a line..
				KDL::Frame cur_pos;
				m_Solver.JntToCart(jnt_array, cur_pos, (*it).first);

				// std::cout << "parent: " << (*(*it).second.parent).first << std::endl;
				KDL::Frame parent_pos;

				m_Solver.JntToCart(jnt_array, parent_pos, (*(*it).second.parent).first);
				// std::cout << "." << std::endl;

				glColor3f(1,1,1);
				glBegin(GL_LINES);
					glVertex3f(parent_pos(0,3), parent_pos(1,3), parent_pos(2,3));
					glVertex3f(cur_pos(0,3), cur_pos(1,3), cur_pos(2,3));
				glEnd();
			}

			glPopMatrix();
		}

		/**
			A virtual destructor to make delete work on subclass objects behind 
			KDLTreeView pointers..
		*/
		virtual ~KDLTreeView() { }
	};

} // namespace

#endif



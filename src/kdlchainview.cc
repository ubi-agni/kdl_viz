#include "kdlchainvew.h"

#include <gl/GL.h>

namespace KDLView {
	void draw_chain(const KDL::Chain &chain, const std::vector<double> &pose) {
		glPushMatrix();

		for (unsigned int segment = 0; segment < chain->getNrOfSegments(); ++segment) {
			// std::cout << "segment " << segment << std::endl;

			KDL::Frame pose_frame = chain->getSegment(segment).pose(pose[segment]);

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
			KDL::Frame pose_frame = chain->getSegment(segment).pose(0.3);

			double pose_matrix[16];
			for (unsigned int i = 0; i < 16; ++i) pose_matrix[i] = pose_frame(i % 4, i / 4);
	#endif
			glMultMatrixd(pose_matrix);
		}
		glPopMatrix();
	}
} // namespace

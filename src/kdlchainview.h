#ifndef KDL_CHAIN_VIZ_HH
#define KDL_CHAIN_VIZ_HH

#include <kdl/chain.hpp>

namespace KDLView {
	/**
		This method draws a KDL::Chain into a OpengGL context which has
		to be setup by the user of this function

		The matrix stack is used but returned to its previous state after
		the use of this method..
	*/
	void draw_chain(const KDL::Chain &chain, const std::vector<double> &pose);
} // namespace

#endif



#ifndef KDL_CHAIN_VIZ_HH
#define KDL_CHAIN_VIZ_HH

#include <QGLWidget>
#include <kdl/chain.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/numeric/ublas/vector.hpp>

typedef boost::shared_ptr<KDL::Chain> ChainPtr;

using namespace boost::numeric;

class KDLChainVisualizerWidget : public QGLWidget 
{
	Q_OBJECT

	ChainPtr m_Chain;
	ublas::vector<double> m_Pose;

public:	
	KDLChainVisualizerWidget(ChainPtr chain = ChainPtr(new KDL::Chain), QWidget *parent = 0);
	virtual ~KDLChainVisualizerWidget();

	ublas::vector<double> &pose();

	virtual void resizeGL();
	virtual void paintGL();
	virtual void initializeGL();
};

#endif


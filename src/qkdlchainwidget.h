#ifndef QKDL_CHAIN_VIZ_HH
#define QKDL_CHAIN_VIZ_HH

#include <QGLWidget>

#include <kdl/chain.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/numeric/ublas/vector.hpp>

typedef boost::shared_ptr<KDL::Chain> ChainPtr;

using namespace boost::numeric;

class QKDLChainWidget : public QGLWidget
{
	Q_OBJECT

	ChainPtr m_Chain;
	ublas::vector<double> m_Pose;

public:	
	QKDLChainWidget(ChainPtr chain = ChainPtr(new KDL::Chain), QWidget *parent = 0);
	virtual ~QKDLChainWidget();

	virtual void resizeGL();
	virtual void paintGL();
	virtual void initializeGL();
};

#endif


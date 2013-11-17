#ifndef OBJDET_IO_HPP
#define OBJDET_IO_HPP

#include "core.hpp"
#include <pcl/io/openni_grabber.h>

using namespace boost;
using namespace pcl;

namespace libobjdetect {

    class KinectPointCloudProducer : public PointCloudProducer {
    public:
        KinectPointCloudProducer();
        void grabberCallback(const pcl::PointCloud<Point>::ConstPtr &cloud);
        void registerConsumer(boost::shared_ptr<PointCloudConsumer> consumer);
        void stop();

    private:
        shared_ptr<pcl::Grabber> grabber;
        std::vector<boost::shared_ptr<PointCloudConsumer> > consumers;
    };

}

#endif // OBJDET_IO_HPP

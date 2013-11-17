#include <libobjdetect/core.hpp>
#include <libobjdetect/io.hpp>
#include <libobjdetect/viewer.hpp>

#include <boost/make_shared.hpp>
#include <pcl/console/parse.h>

using namespace libobjdetect;


class ObjectDetectionViewer : public PointCloudViewer {
private:
    typedef PointCloudViewer super;

protected:

    virtual void onPointCloudReceived(PointCloud<Point>::ConstPtr cloud) {
        showPointCloud(cloud);
    }

    virtual void onInit(PCLVisualizer& visualizer) {
        super::onInit(visualizer);
    }

    virtual void onUpdate(PCLVisualizer& visualizer) {

    }
};


int main (int argc, char** argv) {
    shared_ptr<PointCloudViewer> viewer(new ObjectDetectionViewer);
    shared_ptr<PointCloudProducer> producer(new KinectPointCloudProducer);

    producer->registerConsumer(viewer);
    while (!viewer->wasStopped()) {}
    producer->stop();

    return 0;
}

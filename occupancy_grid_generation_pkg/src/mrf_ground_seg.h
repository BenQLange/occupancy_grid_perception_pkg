#include "ros/ros.h"
#include <pcl_ros/point_cloud.h>
#include <pcl_ros/transforms.h>
#include <occupancy_grid_msgs/point_types.h>
#include <tf/transform_listener.h>
#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>

using namespace std;

typedef occupancy_grid_msgs::PointXYZIDBS DDLPointType;
typedef pcl::PointCloud<DDLPointType> DDLPointCloud;
typedef set<pair<int, int> > Indices;

using namespace std;

namespace occupancy_grid_generation_pkg {

  class MrfGroundSeg : public nodelet::Nodelet
  {
  public:
    MrfGroundSeg(){};
  private:

    ros::Publisher pub;
    ros::Subscriber sub;

    virtual void onInit();
    void GroundSegMRFCallback(const DDLPointCloud::ConstPtr& originalPC);
  };
}

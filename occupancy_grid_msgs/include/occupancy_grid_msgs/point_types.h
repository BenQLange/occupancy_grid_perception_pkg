#include <pcl/point_types.h>
#include <pcl_ros/point_cloud.h>

namespace occupancy_grid_msgs
{
  struct PointXYZIDBS
  {
    PCL_ADD_POINT4D;
    // float intensity;
    // uint16_t device_id;
    // uint16_t beam_id;
    // float score;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  } EIGEN_ALIGN16;
};

POINT_CLOUD_REGISTER_POINT_STRUCT(occupancy_grid_msgs::PointXYZIDBS,
                                  (float, x, x)
                                  (float, y, y)
                                  (float, z, z))

                                  //                                   (float, intensity, intensity)
                                  //                                  (uint16_t, device_id, device_id)
                                  //                                  (uint16_t, beam_id, beam_id)
                                  //                                  (float, score, score)

typedef occupancy_grid_msgs::PointXYZIDBS DDLPointType;
typedef pcl::PointCloud<DDLPointType> DDLPointCloud;

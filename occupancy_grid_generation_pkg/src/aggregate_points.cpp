#include <pluginlib/class_list_macros.h>
#include "aggregate_points.h"

PLUGINLIB_EXPORT_CLASS(occupancy_grid_generation_pkg::AggregatePoints, nodelet::Nodelet)

namespace occupancy_grid_generation_pkg
{
  void AggregatePoints::onInit()
  {
    ROS_INFO("Initialized AggregatePoints Nodelet");
    ros::NodeHandle& private_nh = getPrivateNodeHandle();
    pub = private_nh.advertise<pcl::PointCloud<pcl::PointXYZ>>("agg_points",1); //pcl::PointCloud<pcl::PointXYZ> sensor_msgs::PointCloud2
    //filter.setVehicle(vehicle_msg); //???????????????????

    green_sub = private_nh.subscribe("/M_HDL32/velodyne_points", 1, &AggregatePoints::green_cb, this);
    timer = private_nh.createTimer(ros::Duration(0.001),&AggregatePoints::timerCallback, this);
  }

  void AggregatePoints::timerCallback(const ros::TimerEvent&)
  {
    pub.publish(agg_cloud);
  }

  void AggregatePoints::aggregate_cloud()
  {
    agg_cloud = green_cloud;
    agg_cloud.header.frame_id = green_cloud.header.frame_id;

  }

  void AggregatePoints::green_cb(const sensor_msgs::PointCloud2::ConstPtr &pcMsg)
  {
    // ROS_INFO("Received PCL packets.");
    pcl::PCLPointCloud2 pcl_pc2;
    pcl_conversions::toPCL(*pcMsg,pcl_pc2);
    pcl::PointCloud<pcl::PointXYZ>::Ptr temp_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(pcl_pc2,*temp_cloud);
    pcl_ros::transformPointCloud("velodyne", ros::Time::now(), *temp_cloud, "velodyne",green_cloud,tfListener);
    green_cloud.header.frame_id = (*pcMsg).header.frame_id;
    aggregate_cloud();
  }
}

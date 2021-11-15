cmake_minimum_required(VERSION 2.8.3)
#set(CMAKE_CXX_STANDARD 14)
project(occupancy_grid_generation_pkg)

find_package(catkin REQUIRED COMPONENTS
  occupancy_grid_msgs
  nodelet
  roscpp
  rospy
  std_msgs
  geometry_msgs
  sensor_msgs
  nav_msgs
  roslib
  pcl_conversions
  pcl_ros
  message_filters
  tf2
  tf2_ros
  tf
  class_loader
)

## Setup include directories
include_directories(${catkin_INCLUDE_DIRS})

catkin_package(
#  INCLUDE_DIRS include
#   LIBRARIES nodelet_plugins
#   CATKIN_DEPENDS
#    occupancy_grid_msgs
#    roscpp
#    rospy
#    std_msgs
#  DEPENDS system_lib
)

## Create the nodelet tutorial library
add_library(nodelet_plugins
          src/aggregate_points.cpp
          src/aggregate_points.h
          src/mrf_ground_seg.cpp
          src/occupancy_grid_generation.cpp
          src/occupancy_grid_generation.h
          )

target_link_libraries(nodelet_plugins ${catkin_LIBRARIES} ${PROJECT_LIBRARIES} ${CMAKE_LIBRARY_PATH})


if(catkin_EXPORTED_LIBRARIES)
  add_dependencies(nodelet_plugins ${catkin_EXPORTED_LIBRARIES})
endif()

## Mark the nodelet library for installations
install(TARGETS nodelet_plugins
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(FILES nodelet_plugins.xml mynodelet.launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

include_directories(${PROJECT_INCLUDE_DIRS})
target_link_libraries(nodelet_plugins ${PROJECT_LIBRARIES} ${catkin_LIBRARIES})

// #pragma once

#include <vector>
#include <occupancy_grid_msgs/vehicle_state.h>

namespace occupancy_grid_msgs
{

class VehicleData{

  private:
    occupancy_grid_msgs::vehicle_state ros_vehicleState;
    double psi_rad;
    double N_m;
    double E_m;
  public:

    /* Constructors */
    VehicleData();
    VehicleData(const occupancy_grid_msgs::vehicle_state& vehicleState);

    /* Setters & Getters */
    void setState(const occupancy_grid_msgs::vehicle_state& vehicleState);

    void getPose(double& E_m, double& N_m, double& psi_rad) const;
    void getPoseWrtE(double& E_m, double& N_m, double& psi_rad) const;

    /* Miscellaneous */
};

}

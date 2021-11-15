#include <occupancy_grid_msgs/vehicle_data.h>


namespace occupancy_grid_msgs
{


VehicleData::VehicleData(){}

VehicleData::VehicleData(const occupancy_grid_msgs::vehicle_state& vehicleState){
  setState(vehicleState);
}

void VehicleData::setState(const occupancy_grid_msgs::vehicle_state& vehicleState){
  this->psi_rad = vehicleState.psi_rad;
  this->N_m = vehicleState.N_m;
  this->E_m = vehicleState.E_m;
}

void VehicleData::getPose(double& E_m, double& N_m, double& psi_rad) const {
  E_m = this->E_m;
  N_m = this->N_m;
  psi_rad = this->psi_rad;
}

void VehicleData::getPoseWrtE(double& E_m, double& N_m, double& psi_rad) const {
  E_m = this->E_m;
  N_m = this->N_m;
  psi_rad = this->psi_rad + M_PI_2;
}

}

#pragma once

#include <vector>

struct Vehicle;

struct Highway
{
    void changeSpeed (const int newSpeed);
    void addVehicle (Vehicle* const v);
    void removeVehicle (Vehicle* const v);

private:
    void addVehicleInternal (Vehicle* const v);
    void removeVehicleInternal (Vehicle* const v);
    int speedLimit = 65;
    std::vector<Vehicle*> vehicles;

    friend struct HighwayPatrol;
    friend struct SemiTruck;
};

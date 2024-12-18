#include <iostream>

#include "Vehicle.h"

Vehicle::Vehicle (const std::string& n, const std::string& vt) : name (n), vehicleType (vt) { }

void Vehicle::setSpeed (const int s)
{
    std::cout << "\nHighway is adjusting " << name << "'s speed to " << s << " mph" << std::endl;
    speed = s;
}
    
void Vehicle::tryToEvade()
{
    std::cout << name << ": you'll never take me alive, ya dirty coppers!" << std::endl;
    setSpeed (100);
}

std::string Vehicle::getVehicleType()
{
    return vehicleType;
}

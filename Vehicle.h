#pragma once

#include <string>

struct HighwayPatrol;
struct Vehicle
{
    Vehicle (const std::string& n, const std::string& vt = "Unknown");
    
    //Special member Functions.  See instruction 9) and note in main()
    virtual ~Vehicle() = default;
    Vehicle (const Vehicle&) = default;
    Vehicle& operator= (const Vehicle&) = default;
    
    virtual void setSpeed (const int s);
    virtual void tryToEvade();
    std::string getVehicleType();

protected:
    int speed = 0;
    std::string name;
    std::string vehicleType;

    friend HighwayPatrol;
};

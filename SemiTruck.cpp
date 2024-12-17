#include "SemiTruck.h"

SemiTruck::SemiTruck (const std::string& name) : Vehicle (name) 
{
    
}

void SemiTruck::mergeOnto (Highway* highway)
{
    setSpeed (highway->speedLimit);
    std::cout << name << ": merging onto highway at " << highway->speedLimit << " km/h!" << std::endl;
}

void SemiTruck::pullOver()
{
    setSpeed (0);
    std::cout << name << ": hello officer, let's move this along, I have stuff to deliver." << std
}
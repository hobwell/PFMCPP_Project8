#include <iostream>

#include "SemiTruck.h"
#include "Highway.h"

SemiTruck::SemiTruck (const std::string& n, const std::string& vt) : Vehicle (n,vt) {}

SemiTruck::~SemiTruck () {}

void SemiTruck::mergeOnto (const Highway* highway)
{
    setSpeed (highway->speedLimit);
    std::cout << name << ": merging onto highway at " << highway->speedLimit << " km/h!" << std::endl;
}

void SemiTruck::pullOver()
{
    setSpeed (0);
    std::cout << name << ": hello officer, let's move this along, I have stuff to deliver." << std::endl;
}

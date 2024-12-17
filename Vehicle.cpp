#include "Vehicle.h"

Vehicle::Vehicle (const std::string& n) : name (n) { }

virtual void Vehicle::setSpeed (int s)
{
    std::cout << "\nHighway is adjusting " << name << "'s speed to " << s << " mph" << std::endl;
    speed = s;
}
    
virtual void Vehicle::tryToEvade()
{
    std::cout << name << ": you'll never take me alive, ya dirty coppers!" << std::endl;
    setSpeed (100);
}
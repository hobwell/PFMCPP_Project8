#include <algorithm>

#include "Highway.h"
#include "Car.h"
#include "HighwayPatrol.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

void Highway::changeSpeed (const int newSpeed)
{
    speedLimit = newSpeed;
    for (auto* vehicle : vehicles)
    {
        vehicle->setSpeed (speedLimit);
    }
}

void Highway::addVehicleInternal (Vehicle* const v)
{
    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    do not call `setSpeed`.  Pick a different function.
    */
    if (auto* c = dynamic_cast<Car*> (v))
    {
        c->closeWindows();
    }
    else if (auto* m = dynamic_cast<Motorcycle*> (v))
    {
        m->lanesplitAndRace (100);
    }
    else if (auto* s = dynamic_cast<SemiTruck*> (v))
    {
        s->mergeOnto (this);
    }
}

void Highway::removeVehicleInternal (Vehicle* const v)
{
    /*
    depending on the derived type, call the member function that tries to evade the cops. 
    do not call `setSpeed`.  Pick a different function.
    trucks pull over, but cars and bikes try to evade!!
    */
    if (auto* c = dynamic_cast<Car*> (v))
    {
        c->tryToEvade();
    }
    else if (auto* m = dynamic_cast<Motorcycle*> (v))
    {
        m->tryToEvade();
    }
    else if (auto* s = dynamic_cast<SemiTruck*> (v))
    {
        s->pullOver();
    }
}

void Highway::addVehicle (Vehicle* const v)
{
    vehicles.push_back (v);
    addVehicleInternal (v);
}

void Highway::removeVehicle (Vehicle* const v)
{
    vehicles.erase (std::remove (vehicles.begin(), 
                                 vehicles.end(), 
                                 v), 
                   vehicles.end());
    removeVehicleInternal (v);
}

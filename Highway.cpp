#include "Highway.h"
#include "Car.h"
#include "HighwayPatrol.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

#include <cassert>

void Highway::changeSpeed (int newSpeed)
{
    speedLimit = newSpeed;
    for (auto* vehicle : vehicles)
    {
        vehicle->setSpeed (speedLimit);
    }
}

void Highway::addVehicleInternal (Vehicle* v)
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
    else if (auto* h = dynamic_cast<HighwayPatrol*> (v))
    {
        h->scanHighway (this);
    }
}

void Highway::removeVehicleInternal (Vehicle* v)
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
        m->tryToEvade(100);
    }
    else if (auto* s = dynamic_cast<SemiTruck*> (v))
    {
        s->pullOver();
    }
    else if (auto* h = dynamic_cast<HighwayPatrol*> (v))
    {
        h->scanHighway(this);
    }
}

void Highway::addVehicle (Vehicle* v)
{
    vehicles.push_back (v);
    addVehicleInternal (v);
}
void Highway::removeVehicle (Vehicle* v)
{
    vehicles.erase (std::remove (vehicles.begin(), 
                                 vehicles.end(), 
                                 v), 
                   vehicles.end());
    removeVehicleInternal (v);
}

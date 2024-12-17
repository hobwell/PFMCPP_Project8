#pragma once 

#include "Vehicle.h"

struct Highway;
struct HighwayPatrol : private Vehicle 
{
    HighwayPatrol();
    ~HighwayPatrol() override;

    HighwayPatrol (const HighwayPatrol&) = default;
    HighwayPatrol& operator= (const HighwayPatrol&) = default;

    void scanHighway (Highway* h);
    void pullOver (Vehicle* const v, const bool willArrest, Highway* const h);
};

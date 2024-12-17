#pragma once

#include "Vehicle.h"

struct Highway;

struct SemiTruck : public Vehicle
{
    SemiTruck(const std::string& n);

    void mergeOnto (const Highway* highway);

    void pullOver();
}

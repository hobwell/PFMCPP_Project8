#pragma once

#include "Vehicle.h"

struct Highway;

struct SemiTruck : Vehicle
{
    SemiTruck (const std::string& n, const std::string& vt = "SemiTruck");
    ~SemiTruck() override;

    SemiTruck (const SemiTruck&) = default;
    SemiTruck& operator= (const SemiTruck&) = default;

    void mergeOnto (const Highway* highway);

    void pullOver();
};

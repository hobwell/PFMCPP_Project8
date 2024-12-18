#pragma once

#include <limits>

#include "Vehicle.h"

struct Motorcycle : Vehicle
{
    Motorcycle (const std::string& n, const std::string& vt = "Motorcycle");
    ~Motorcycle() override;

    Motorcycle (const Motorcycle&) = default;
    Motorcycle& operator= (const Motorcycle&) = default;

    void lanesplitAndRace (const int topSpeed = std::numeric_limits<int>::max());    
    void tryToEvade() override;
    void setSpeed (int s) override;
};

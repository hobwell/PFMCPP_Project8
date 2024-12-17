#pragma once

#include "Vehicle.h"

struct Car : public Vehicle
{
    Car (const std::string& s, const std::string& vt = "Car");
    ~Car() override;

    Car (const Car&) = default;
    Car& operator= (const Car&) = default;

    void closeWindows();
    void tryToEvade() override;
};

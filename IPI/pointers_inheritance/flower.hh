#pragma once

#include "plant.hh"

class Flower : public Plant {
    public:
    virtual void grow();
    virtual void die();
    void water(int amountWater);
    virtual void water(double liter);
    void turnToSun();
    virtual void bloom();
};

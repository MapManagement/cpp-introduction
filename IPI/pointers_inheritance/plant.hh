#pragma once

class Plant {
    public:
    virtual void grow() = 0;
    virtual void die();
    virtual void water(float amountWater);
};


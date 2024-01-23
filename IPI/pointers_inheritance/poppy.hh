#pragma once

#include "flower.hh"

class Poppy : public Flower {
public:
    virtual void grow();
    virtual void die();
    void water (int milliliter);
    virtual void bloom();
};

#include "flower.hh"
#include "printer.hh"
#include <iostream>

void Flower::grow() { print("Flower grow"); }

void Flower::die() { print("Flower die"); }

void Flower::water(int amountWater) { print("Flower int water"); }

void Flower::water(double amountWater) { print("Flower double water"); }

void Flower::turnToSun() { print("Flower turn to sun"); }

void Flower::bloom() { print("Flower bloom"); }

#include "poppy.hh"
#include "printer.hh"
#include <iostream>

void Poppy::grow() { print("Poppy grow"); }

void Poppy::die() { print("Poppy die"); }

void Poppy::water(int milliliter) { print("Poppy int water"); }

void Poppy::bloom() { print("Poppy bloom"); }

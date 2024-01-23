#include "flower.hh"
#include "plant.hh"
#include "poppy.hh"
#include <iostream>

void pointerMan();
void noPointerMan();

int main() {
    pointerMan();
    noPointerMan();

    return 0;
}

void pointerMan() {
    // Plant p; abstract class
    Flower f;
    Poppy p;

    Plant *plantF = &f;
    Plant *plantP = &p;
    Flower *flowerP = &p;
    Poppy *poppyP = &p;

    std::cout << "--- \n";

    plantF->grow();     // Flower
    plantF->water(5.0); // Plant
    plantF->die();      // Flower

    plantP->die();    // Poppy
    plantP->water(5); // Plant
    plantP->grow();   // Poppy

    std::cout << "--- \n";

    flowerP->grow();
    flowerP->die();
    flowerP->bloom();
    flowerP->turnToSun();
    flowerP->water(5);

    std::cout << "--- \n";

    poppyP->turnToSun();
    poppyP->bloom();
    poppyP->die();
    poppyP->grow();
    poppyP->water(5);
}

void noPointerMan() {
    std::cout << "====== \n";

    // Plant p; abstract class
    Flower f;
    Poppy p;

    //Plant plantF = (Plant)f;
    // Plant plantP(p);
    Flower flowerP = p;
    Poppy poppyP = p;

    /*plantF->grow();     // Flower
    plantF->water(5.0); // Plant
    plantF->die();      // Flower

    plantP->die();    // Poppy
    plantP->water(5); // Plant
    plantP->grow();   // Poppy*/

    flowerP.grow();
    flowerP.die();
    flowerP.bloom();
    flowerP.turnToSun();
    flowerP.water(5);

    std::cout << "--- \n";

    poppyP.turnToSun();
    poppyP.bloom();
    poppyP.die();
    poppyP.grow();
    poppyP.water(5);
}

#include "triplet.hh"
#include <iostream>
#include <ostream>
#include <string>

int main() {

  // Erster Test
  int initFirst = 1;
  std::string initSecond = "Mein Triplet";
  float initThird = 3.14f;

  auto myTriplet =
      Triplet<int, std::string, float>(initFirst, initSecond, initThird);

  std::cout << "Erwartet: " << initFirst << " Rückgabe: " << myTriplet.first()
            << std::endl;
  std::cout << "Erwartet: " << initSecond << " Rückgabe: " << myTriplet.second()
            << std::endl;
  std::cout << "Erwartet: " << initThird << " Rückgabe: " << myTriplet.third()
            << std::endl;

  int newFirst = 5;
  myTriplet.setFirst(newFirst);
  std::cout << "Erwartet: " << newFirst << " Rückgabe: " << myTriplet.first()
            << std::endl;

  std::string newSecond = "Neuer Wert";
  myTriplet.setSecond(newSecond);
  std::cout << "Erwartet: " << newSecond << " Rückgabe: " << myTriplet.second()
            << std::endl;

  float newThird = 2.7f;
  myTriplet.setThird(newThird);
  std::cout << "Erwartet: " << newThird << " Rückgabe: " << myTriplet.third()
            << std::endl;

  return 0;
}

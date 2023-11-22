#include <cmath>
#include <iostream>
#include <ostream>
#include <string>

struct Input {
    float p;
    float q;
};

Input readInput() {
    Input userInput;

    std::cout << "p: " << std::endl;
    std::cin >> userInput.p;

    std::cout << "q: " << std::endl;
    std::cin >> userInput.q;

    return userInput;
}

float calcDiscriminant(float p, float q) {
    float result = std::pow(p / 2, 2) - q;

    return result;
}

std::string calcX(float p, float q) {
    float discriminant = calcDiscriminant(p, q);

    if (discriminant < 0) {
        return "Es gibt keine reelle Lösung!";
    } else if (discriminant == 0) {
        return "Die einzige Lösung ist " + std::to_string(discriminant);
    }

    float discriminantSqrt = std::sqrt(discriminant);

    float x1 = -p / 2 + discriminantSqrt;
    float x2 = -p / 2 - discriminantSqrt;

    return "Die Lösungen sind " + std::to_string(x1) + " und " +
           std::to_string(x2);
}

int main() {
    Input input = readInput();

    std::string output = calcX(input.p, input.q);

    std::cout << output << std::endl;

    return 0;
}

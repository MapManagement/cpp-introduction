#include <iostream>

bool isEven(unsigned int number) { return number % 2 == 0; }

void collatz(unsigned int number) {
    std::cout << number << std::endl;

    while (number != 0 && number != 1) {
        if (isEven(number)) {
            number /= 2;
        } else {
            number = number * 3 + 1;
        }
        std::cout << number << std::endl;
    }
}

int main() {
    std::cout << "Geben Sie eine Zahl für die Collatz-Funktion an: "
              << std::endl;

    int number = 0;
    std::cin >> number;

    collatz(number);

    return 0;
}

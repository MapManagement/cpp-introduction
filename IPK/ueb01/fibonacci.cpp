#include <iostream>
#include <ostream>
#include <string>

unsigned int fib(unsigned int n) {
    if (n == 1) {
        return 1;
    } else if (n == 0) {
        return 0;
    }

    return fib(n - 1) + fib(n - 2);
}

unsigned int fibIter(unsigned int n) {
    int secondLast = 0;
    int last = 1;

    for (int i = 0; i < n - 1; ++i) {
        int temp = last;
        last += secondLast;
        secondLast = temp;
    }

    return last;
}

int main() {
    std::cout << "Welche Fibonacci-Zahl soll berechnet werden? " << std::endl;

    unsigned int inputInt = 0;
    std::cin >> inputInt;

    unsigned int resultRec = fib(inputInt);
    unsigned int resultIter = fibIter(inputInt);

    std::cout << "Die " + std::to_string(inputInt) +
                     "te Fibonacci-Zahl wird berechnet:"
              << std::endl;
    std::cout << "Rekursiv: " + std::to_string(resultRec) << std::endl;
    std::cout << "Iterativ: " + std::to_string(resultIter) << std::endl;

    return 0;
}

#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

// a)
void print(std::vector<double> vektor) {
    std::string ausgabeText = "[";

    for (int i = 0; i < vektor.size(); ++i) {
        if (i != 0) {
            ausgabeText += ", ";
        }

        ausgabeText += std::to_string(vektor[i]);
    }

    ausgabeText += "]";

    std::cout << ausgabeText << std::endl;
}
// b)
double median(std::vector<double> vektor) {
    if (vektor.size() == 0) {
        return 0;
    }

    std::sort(vektor.begin(), vektor.end());
    int medianIndex = 0;

    if (vektor.size() % 2 == 0) {
        medianIndex = vektor.size() / 2;
    } else {
        medianIndex = vektor.size() / 2;
    }

    return vektor[medianIndex];
}

// c)
void sin(std::vector<double> &vektor) {
    for (int i = 0; i < vektor.size(); ++i) {
        double sinusWert = std::sin(vektor[i]);

        vektor[i] = sinusWert;
    }
}

// d)
std::vector<double> sums(std::vector<std::vector<double>> vektor) {
    std::vector<double> summierterVektor;

    for (int i = 0; i < vektor.size(); ++i) {
        int vektorSumme = 0;
        for (int j = 0; j < vektor[i].size(); ++j) {
            vektorSumme += vektor[i][j];
        }

        summierterVektor.push_back(vektorSumme);
    }

    return summierterVektor;
}

// e)
int main() {
    std::vector<double> leererVektor = {};

    // a)
    std::cout << "a)" << std::endl;

    std::vector<double> vektorUngerade = {5.6, 4.6, 3.7, 2.2, 1.1};
    std::vector<double> vektorGerade = {5.6, 4.6, 3.7, 2.2};
    print(vektorUngerade);

    print(leererVektor);

    // b)
    std::cout << "b)" << std::endl;

    double medianWertUngerade = median(vektorUngerade);
    std::cout << medianWertUngerade << std::endl;

    double medianWertGerade = median(vektorGerade);
    std::cout << medianWertGerade << std::endl;

    double medianLeer = median(leererVektor);
    std::cout << medianLeer << std::endl;

    // c)
    std::cout << "c)" << std::endl;

    sin(vektorUngerade);
    print(vektorUngerade);

    sin(leererVektor);
    print(leererVektor);

    // d)
    std::cout << "d)" << std::endl;

    std::vector<std::vector<double>> vektor2 = {{2, 2}, {1}, {-6, -4, 10}};
    std::vector<double> sumsVektor = sums(vektor2);
    print(sumsVektor);

    std::vector<std::vector<double>> leererVektor2 = {};
    std::vector<double> sumsLeererVektor = sums(leererVektor2);
    print(sumsLeererVektor);
}

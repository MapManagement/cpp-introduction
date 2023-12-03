#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

unsigned int leben = 10;

// a)
std::string verstecken(std::string wort) {
    std::string verstecktesWort = "";

    for (int i = 0; i < wort.size(); ++i) {
        verstecktesWort += "_";
    }

    return verstecktesWort;
}

// b)
bool aufdecken(std::string &stand, std::string loesung, char buchstabe) {
    bool treffer = false;

    for (int i = 0; i < loesung.size(); ++i) {
        if (std::tolower(loesung[i]) != std::tolower(buchstabe)) {
            continue;
        }

        stand[i] = loesung[i];
        treffer = true;
    }

    return treffer;
}

// c)
bool istFertig(std::string zustand, std::string loesung) {
    char vergleichszeichen = '_';

    int zustandUnterstriche =
        std::count(zustand.begin(), zustand.end(), vergleichszeichen);
    int loesungUnterstriche =
        std::count(loesung.begin(), loesung.end(), vergleichszeichen);

    return zustandUnterstriche == loesungUnterstriche;
}

// d)
void gameLoop(std::string loesung) {
    std::string zustand = verstecken(loesung);

    while (true) {
        std::cout << zustand << std::endl;

        char zeicheneingabe;
        std::cin >> zeicheneingabe;

        bool treffer = aufdecken(zustand, loesung, zeicheneingabe);

        if (!treffer) {
            std::cout << "Das Zeichen " << zeicheneingabe
                      << " ist nicht im Wort vorhanden. Deine Leben werden von "
                      << leben << " auf " << leben - 1 << " reduziert."
                      << std::endl;
            leben--;

            if (leben == 0) {
                leben--;
                std::cout << "Du hast keine Leben mehr. Das Spiel wird beendet."
                          << std::endl;
                break;
            }
        }

        bool spielGewonnen = istFertig(zustand, loesung);

        if (spielGewonnen) {
            std::cout << "Du hast das Wort '" << loesung
                      << "' erraten und damit das Spiel gewonnen." << std::endl;
            break;
        }
    }
}

// f)
void readFiles(std::vector<std::string> &woerter) {
    woerter.clear();

    std::ifstream file;
    file.open("wortliste.txt");

    std::string letztesWort;

    while (true) {
        std::string aktuellesWort;
        file >> aktuellesWort;

        if (aktuellesWort == letztesWort) {
            break;
        }

        woerter.push_back(aktuellesWort);

        letztesWort = aktuellesWort;
    }

    file.close();
}

// e)
int main() {
    std::vector<std::string> words = {"Programmierkurs", "Informatik",
                                      "Heidelberg", "Softwareentwicklung"};
    // f)
    readFiles(words);

    std::srand(std::time(nullptr));

    int zufallInt = std::rand();
    int wortIndex = zufallInt % words.size();

    gameLoop(words[wortIndex]);

    return 0;
}

#include <fstream>
#include <iostream>
#include <ostream>
#include <unistd.h>

#include "twodboolarray.hh"

// Basisklassen
class Regel {
    public:
        typedef TwoDBoolArray Daten;

        virtual void anwenden(Daten &daten) = 0;
};

class BoundaryCondition {
    public:
        typedef TwoDBoolArray Daten;
        virtual bool boundary(Daten &daten, int i, int j) = 0;
};

class TorusCondition : public BoundaryCondition {
        // Implementieren Sie hier eine Randbedingung, welche das
        // Gebiet als doppelt periodisch annimmt.
    public:
        virtual bool boundary(Daten &daten, int i, int j) {
            int periodicRow = i;
            int periodicCol = j;

            if (i < 0)
                periodicRow = daten.rows() - 1;
            else if (i == daten.rows())
                periodicRow = 0;

            if (j < 0)
                periodicCol = daten.cols() - 1;
            else if (j == daten.cols())
                periodicCol = 0;

            return daten[periodicRow][periodicCol];
        }
};

class AliveCondition : public BoundaryCondition {
        // Implementieren Sie hier eine Randbedingung welche annimmt,
        // dass rund um das Rechengebiet lebende Zellen sitzen.
    public:
        virtual bool boundary(Daten &daten, int i, int j) { return true; }
};

class DeadCondition : public BoundaryCondition {
        // Implementieren Sie hier eine Randbedingung welche annimmt,
        // dass rund um das Rechengebiet tote Zellen sitzen.
    public:
        virtual bool boundary(Daten &daten, int i, int j) { return false; }
};

class GameOfLifeRules : public Regel {
    public:
        typedef TwoDBoolArray Daten;

        GameOfLifeRules(BoundaryCondition &_bc) : bc(_bc) {}

        // Implementieren Sie hier die Regeln des Game of Life
        virtual void anwenden(Daten &daten) {
            Daten neueDaten = TwoDBoolArray(daten.rows(), daten.cols());
            int rows = daten.rows();
            int cols = daten.cols();
            bool newCellStatus = false;

            for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < cols; ++col) {
                    newCellStatus = updateSingleCell(row, col, daten);
                    neueDaten[row][col] = newCellStatus;
                }
            }

            daten = neueDaten;
        }

        bool updateSingleCell(int cellRow, int cellCol, Daten &daten) {
            int counterLivingCells = 0;
            int cellState = daten[cellRow][cellCol];

            for (int row = cellRow - 1; row <= cellRow + 1; ++row) {
                for (int col = cellCol - 1; col <= cellCol + 1; ++col) {
                    bool isTargetCell = cellRow == row && cellCol == col;
                    bool isBoundaryCell =
                        row < 0 || col < 0 || row >= daten.rows() || col >= daten.cols();

                    if (isTargetCell) {
                        continue;
                    }

                    if (isBoundaryCell) {
                        bool isBoundaryCellAlive = bc.boundary(daten, row, col);
                        if (isBoundaryCellAlive) {
                            counterLivingCells++;
                        }
                    } else if (daten[row][col]) {
                        counterLivingCells++;
                    }
                }
            }

            bool cellStaysAlive = counterLivingCells == 3 || counterLivingCells == 2;
            bool cellDeadToAlive = counterLivingCells == 3;

            if (cellState) {
                return cellStaysAlive;
            }

            return cellDeadToAlive;
        }

    private:
        BoundaryCondition &bc;
};

// Ein zellulärer Automat, der Regeln und Datenstrukturen von außen bekommt
class Automat {
    public:
        typedef TwoDBoolArray Daten;
        Automat(Daten &daten, Regel &regel) : _daten(daten), _regel(regel) {}

        // mache n Schritte
        void step(int n = 1) {
            for (int i = 0; i < n; ++i) {
                // Linux-spezifische Art und Weise den Inhalt der Konsole zu löschen
                // und den Cursor nach oben links zu setzen.
                std::cout << "\x1B[2J\x1B[H"
                          << "Step " << i << std::endl
                          << _daten;
                // Das Wiedergeben der Lösung soll immer 10 Sekunden (=1e7
                // Mikrosekunden) dauern. Sie können diesen Wert auch ändern.
                usleep(1.e7 / n);
                _regel.anwenden(_daten);
            }
        }

    private:
        Daten &_daten;
        Regel &_regel;
};

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./<progname> <txt-file>" << std::endl;
        return 1;
    }

    // Initialisiere die Datenstruktur
    TwoDBoolArray a(1, 1);
    std::ifstream file;
    file.open(argv[1]);
    if (file.good())
        file >> a;
    else {
        std::cout << "Cannot read file" << std::endl;
        return 1;
    }

    // Wähle Randbedingung
    TorusCondition bc;

    // Wähle ein Regelsystem
    GameOfLifeRules rules(bc);

    // Initialisiere den zellulären Automaten
    Automat automat(a, rules);

    // Experimentieren Sie hier mit Ihrem Automaten.
    automat.step(75);

    return 0;
}

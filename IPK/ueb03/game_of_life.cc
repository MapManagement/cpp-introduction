#include <chrono>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <thread>
#include <vector>

// forward declaration for (e)
void addLivingCellsEdge(std::vector<std::vector<bool>>& playingField);

// (a)
std::vector<std::vector<bool>> readGamefile(std::string filePath) {
    std::string line;
    std::ifstream gameFile(filePath);
    int lastLineLength = -1;

    std::vector<std::vector<bool>> playingField = {};

    while (std::getline(gameFile, line)) {
        std::vector<bool> currentFieldLine = {};
        if (lastLineLength > 0 && line.size() != lastLineLength) {
            playingField.clear();
            return playingField;
        }

        for (char point : line) {
            if (point == ' ') {
                currentFieldLine.push_back(false);
            } else if (point == 'O') {
                currentFieldLine.push_back(true);
            } else {
                playingField.clear();
                return playingField;
            }
        }

        playingField.push_back(currentFieldLine);
    }

    return playingField;
}

// (b)
bool updateSingleCell(int cellRow, int cellColumn,
                      std::vector<std::vector<bool>>& playingField) {
    int counterLivingCells = 0;
    int cellState = playingField[cellRow][cellColumn];

    for (int row = cellRow - 1; row <= cellRow + 1; ++row) {
        for (int column = cellColumn - 1; column <= cellColumn + 1; ++column) {
            bool isTargetCell = cellRow == row && cellColumn == column;
            bool isRowEdge = row < 0 || column < 0;
            bool isColumnEdge = playingField.size() <= row ||
                                playingField[cellRow].size() <= column;

            if (isTargetCell || isRowEdge || isColumnEdge) {
                continue;
            }

            if (playingField[row][column]) {
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

// (b)
std::vector<std::vector<bool>> updatePlayingField(
    std::vector<std::vector<bool>>& playingField, bool livingCellsEdge) {
    std::vector<std::vector<bool>> newPlayingField = {};

    for (int row = 0; row < playingField.size(); ++row) {
        std::vector<bool> currentFieldLine = {};

        for (int column = 0; column < playingField[row].size(); ++column) {
            bool updatedCell = updateSingleCell(row, column, playingField);

            currentFieldLine.push_back(updatedCell);
        }

        newPlayingField.push_back(currentFieldLine);
    }

    // (e)
    if (livingCellsEdge) {
        addLivingCellsEdge(newPlayingField);
    }

    return newPlayingField;
}

// (c)
void printPlayingField(std::vector<std::vector<bool>>& playingField) {
    for (int row = 0; row < playingField.size(); ++row) {
        for (int column = 0; column < playingField[row].size(); ++column) {
            bool currentCell = playingField[row][column];

            if (currentCell) {
                std::cout << "O";
                continue;
            }

            std::cout << " ";
        }

        std::cout << std::endl;
    }
}

// (e)
void addLivingCellsEdge(std::vector<std::vector<bool>>& playingField) {
    int columns = playingField[0].size();
    std::vector<bool> newRow = {};

    for (int i = 0; i < columns; ++i) {
        newRow.push_back(true);
    }

    playingField.insert(playingField.begin(), newRow);
    playingField.push_back(newRow);

    int rows = playingField.size();

    for (int row = 0; row < rows; ++row) {
        playingField[row].insert(playingField[row].begin(), true);
        playingField[row].push_back(true);
    }
}

// (d)
int main() {
    std::vector<std::vector<bool>> playingField = readGamefile("gamefile");

    if (playingField.empty()) {
        return 1;
    }

    // (e)
    std::string userInput;
    std::cout << "Soll der Rand immer aus lebenden Zellen bestehen? [J/N]"
              << std::endl;
    std::cin >> userInput;
    bool withLivingCellsEdge = userInput == "J";

    // (e)
    if (withLivingCellsEdge) {
        addLivingCellsEdge(playingField);
    }

    std::cout << "\x1B[2J\x1B[H";
    printPlayingField(playingField);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    while (true) {
        std::cout << "\x1B[2J\x1B[H";

        playingField = updatePlayingField(playingField, withLivingCellsEdge);
        printPlayingField(playingField);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}

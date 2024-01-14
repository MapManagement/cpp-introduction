#include <string>
#include <vector>
template <typename T> class Collector {
    private:
    T sum;
    T adder;

    public:
    // Konstruktor
    Collector(T initialSum, T initialAdder)
        : sum(initialSum), adder(initialAdder) {}

    // Methode zum Hinzufügen eines Werts zu sum und adder
    void add(T value) {
        sum += adder;
        sum += value;
    }

    // Methode zum Abrufen des aktuellen Werts von sum
    T digest() const { return sum; }
};

template <> class Collector<std::string> {
    private:
    std::string separator;
    std::vector<std::string> stringVector;

    public:
    // Konstruktor
    Collector(std::string firstElement, std::string separator)
        : stringVector(), separator(separator) {
        stringVector.push_back(firstElement);
    }

    // Methode zum Hinzufügen eines Wertes zu Vector
    void add(std::string value) { stringVector.push_back(value); }

    // Methode zum Abrufen der separierten Ausgabeliste
    std::string digest() const {
        if (stringVector.size() == 0) {
            return "";
        }

        std::string output = "";

        for (int i = 0; i < stringVector.size(); ++i) {
            output += stringVector[i];

            if (i != stringVector.size() - 1) {
                output += separator;
            }
        }

        return output;
    }
};

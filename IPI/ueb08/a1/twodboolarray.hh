#include <iostream>
#include <ostream>

class TwoDBoolArray {
    public:
        // Baue leeres Array
        TwoDBoolArray() : n(0), m(0) { data = NULL; }

        // Baue ein Array mit n Zeilen und m Spalten
        TwoDBoolArray(int _n, int _m) : n(_n), m(_m) { data = new bool[n * m]; }

        // Kopiere ein Array: mach tiefe Kopie
        TwoDBoolArray(const TwoDBoolArray &other) : n(other.n), m(other.m) {
            data = new bool[n * m];
            for (int i = 0; i < n * m; ++i)
                data[i] = other.data[i];
        }

        // gebe Speicher beim Zerstören frei
        ~TwoDBoolArray() {
            if (data)
                delete[] data;
        }

        // Zuweisungsoperator
        TwoDBoolArray &operator=(const TwoDBoolArray &other) {
            // Vermeide Selbstzuweisung
            if (this != &other) {
                // Vermeide Allokationen, wenn die Größe bereits stimmt
                if (other.n * other.m != n * m) {
                    if (data)
                        delete[] data;
                    data = new bool[other.n * other.m];
                }
                n = other.n;
                m = other.m;

                // Kopiere die Daten
                for (int i = 0; i < n * m; ++i)
                    data[i] = other.data[i];
            }
            return *this;
        }

    private:
        // Ein temporäres Objekt, auf dem man nur den operator[] aufrufen kann
        class RowProxy {
            public:
                // Merke alle Daten der äußeren Klasse, die wir für den Aufruf benötigen
                RowProxy(bool *_data, int _m, int _i) : data(_data), m(_m), i(_i) {}

                // Rechne korrekten Index im Datenarray aus und gebe Referenz zurück
                bool &operator[](int j) { return data[i * m + j]; }

            private:
                bool *data;
                int m;
                int i;
        };

    public:
        // Der äußere operator[] gibt ein Proxyobjekt zurück
        RowProxy operator[](int i) { return RowProxy(data, m, i); }

        // Gebe Zeilenzahl zurück
        int rows() { return n; }

        // Gebe Spaltenzahl zurück
        int cols() { return m; }

    private:
        int n, m;
        bool *data;
}; // end class TwoDBoolArray

// Der Output Filestream
std::ostream &operator<<(std::ostream &stream, TwoDBoolArray &array) {
    stream << array.rows() << "x" << array.cols() << " array:" << std::endl;
    for (int i = 0; i < array.rows(); ++i) {
        for (int j = 0; j < array.cols(); ++j)
            stream << (array[i][j] ? "O" : " ");
        stream << std::endl;
    }
    return stream;
}

// Der Input Filestream
std::istream &operator>>(std::istream &stream, TwoDBoolArray &array) {
    int n, m;
    stream >> n;
    stream >> m;

    TwoDBoolArray tmp(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            stream >> tmp[i][j];

    array = tmp;
    return stream;
}

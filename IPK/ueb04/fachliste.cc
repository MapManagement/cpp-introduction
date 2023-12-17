#include "fachliste.hh"
#include "fach.hh"
#include <string>
#include <vector>

FachListe::FachListe() {}
FachListe::FachListe(std::vector<Fach> faecher) : _faecher(faecher) {}

void FachListe::addFach(Fach fach) { _faecher.push_back(fach); }

unsigned int FachListe::summeECTS() {
    unsigned int gesammelteECTS = 0;

    for (int i = 0; i < this->_faecher.size(); ++i) {
        if (this->_faecher[i].bestanden()) {
            gesammelteECTS += this->_faecher[i].getECTS();
        }
    }

    return gesammelteECTS;
}

double FachListe::durchschnitt() {
    unsigned int gesammelteECTS = 0;
    unsigned int anzahlFaecherBestanden = 0;

    for (int i = 0; i < this->_faecher.size(); ++i) {
        if (this->_faecher[i].bestanden()) {
            gesammelteECTS += this->_faecher[i].getECTS();
            anzahlFaecherBestanden++;
        }
    }
    
    if (anzahlFaecherBestanden < 1)
        return 0;

    float durchschnittECTS = (double)gesammelteECTS / anzahlFaecherBestanden;

    return durchschnittECTS;
}

std::vector<std::string> FachListe::list() {
    std::vector<std::string> beschreibungen;

    for (int i = 0; i < this->_faecher.size(); ++i) {
        std::string beschreibung = this->_faecher[i].toString();
        beschreibungen.push_back(beschreibung);
    }

    return beschreibungen;
}

bool FachListe::noteEintragen(std::string kuerzel, double note) {
    for (int i = 0; i < this->_faecher.size(); ++i) {
        if (this->_faecher[i].getKuerzel() == kuerzel) {
            this->_faecher[i].noteEintragen(note);

            return true;
        }
    }

    return false;
}

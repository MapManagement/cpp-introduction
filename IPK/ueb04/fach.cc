#include "fach.hh"
#include <string>

Fach::Fach(std::string name, std::string kuerzel, unsigned int ects)
    : name(name), kuerzel(kuerzel), ects(ects), note(0.0) {}

bool Fach::noteEintragen(double note) {
    if (!bestanden()) {
        return false;
    } else if (note > 5.0 && note < 1.0) {
        return false;
    }

    this->note = note;

    return true;
}

bool Fach::bestanden() const {
    if (this->note <= 4.0 && this->note >= 1.0)
        return true;

    return false;
}

double Fach::gewerteteNote() const {
    if (!bestanden()) {
        return 0.0;
    }

    return note * ects;
}

unsigned int Fach::getECTS() const {
    if (!bestanden()) {
        return 0;
    }

    return ects;
}

std::string Fach::getName() const { return this->name; }

std::string Fach::getKuerzel() const { return this->kuerzel; }

std::string Fach::toString() const {
    std::string ausgabe = this->kuerzel + " (" + this->name + ") [" +
                          std::to_string(this->ects) +
                          "]: " + std::to_string(this->note);
    return ausgabe;
}

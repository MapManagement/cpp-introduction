#include "vertraege.hh"
#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>

// b)
FlatrateVertrag::FlatrateVertrag(double fixbetrag) : _fixbetrag(fixbetrag) {}

double FlatrateVertrag::berechneKosten() { return _fixbetrag; }

void FlatrateVertrag::verbraucheTelefonEinheiten(double minuten) {
    _verbrauchteMinuten += minuten;
}

void FlatrateVertrag::verbraucheSMSEinheit() { _verbrauchteSMS += 1; }

// c)
GrundgebuehrVertrag::GrundgebuehrVertrag(double grundgebuehr,
                                         double preisProMinute, double smsPreis)
    : _grundgebuehr(grundgebuehr), _preisProMinute(preisProMinute),
      _smsPreis(smsPreis) {}

double GrundgebuehrVertrag::berechneKosten() {
    double gesamtkosten = 0;

    gesamtkosten += _grundgebuehr;
    gesamtkosten += _preisProMinute * _verbrauchteMinuten;
    gesamtkosten += _smsPreis * _verbrauchteSMS;

    return gesamtkosten;
}

void GrundgebuehrVertrag::verbraucheTelefonEinheiten(double minuten) {
    _verbrauchteMinuten += minuten;
}

void GrundgebuehrVertrag::verbraucheSMSEinheit() { _verbrauchteSMS += 1; }

OhneGrundgebuehrVertrag::OhneGrundgebuehrVertrag(double preisProMinute,
                                                 double smsPreis)
    : GrundgebuehrVertrag(0, preisProMinute, smsPreis) {}

double OhneGrundgebuehrVertrag::berechneKosten() {
    double gesamtkosten = 0;

    gesamtkosten += _preisProMinute * _verbrauchteMinuten;
    gesamtkosten += _smsPreis * _verbrauchteSMS;

    return gesamtkosten;
}

// d)
SekuendlicherVertrag::SekuendlicherVertrag(double grundgebuehr,
                                           double preisProMinute,
                                           double smsPreis)
    : GrundgebuehrVertrag(grundgebuehr, preisProMinute, smsPreis) {}

void SekuendlicherVertrag::verbraucheTelefonEinheiten(double sekunden) {}

// e)
GuthabenVertrag::GuthabenVertrag(double preisProMinute, double smsPreis,
                                 double fixbetrag)
    : OhneGrundgebuehrVertrag(preisProMinute, smsPreis), _fixbetrag(fixbetrag),
      _guthaben(0) {}

double GuthabenVertrag::berechneKosten() { return _kosten; }

void GuthabenVertrag::verbraucheTelefonEinheiten(double minuten) {
    _guthaben -= minuten * _preisProMinute;

    if (_guthaben < 0) {
        _guthaben += _fixbetrag;
        _kosten += _fixbetrag;
    }
}

void GuthabenVertrag::verbraucheSMSEinheit() {
    _guthaben -= _smsPreis;

    if (_guthaben < 0) {
        _guthaben += _fixbetrag;
        _kosten += _fixbetrag;
    }
}

// f)
VertragsBundle::VertragsBundle(std::shared_ptr<AbstrakterVertrag> hauptvertrag)
    : _hauptvertrag(hauptvertrag) {}

double VertragsBundle::berechneKosten() {
    double gesamtkosten = _hauptvertrag->berechneKosten();

    for (auto &vertrag : _untervertraege) {
        gesamtkosten += vertrag->berechneKosten();
    }

    return gesamtkosten;
}

void VertragsBundle::verbraucheTelefonEinheiten(double minuten) {
    _hauptvertrag->verbraucheTelefonEinheiten(minuten);
}

void VertragsBundle::verbraucheSMSEinheit() {
    _hauptvertrag->verbraucheSMSEinheit();
}

std::shared_ptr<AbstrakterVertrag> VertragsBundle::get(unsigned int index) {
    if (index < _untervertraege.size()) {
        return _untervertraege[index];
    }

    throw std::out_of_range("Nicht genügend Verträge.");
}

void VertragsBundle::vertragRegistrieren(
    std::shared_ptr<AbstrakterVertrag> vertrag) {
    _untervertraege.push_back(vertrag);
}

// g)
Rechnung::Rechnung(std::string name, std::string adresse,
                   std::shared_ptr<AbstrakterVertrag> vertrag)
    : _name(name), _adresse(adresse), _vertrag(vertrag) {}
std::shared_ptr<AbstrakterVertrag> Rechnung::getVertrag() { return _vertrag; }

std::ostream &operator<<(std::ostream &out, Rechnung &rechnung) {
    double rechnungsbetrag = rechnung.getVertrag()->berechneKosten();

    std::cout << rechnung._name << std::endl;
    std::cout << rechnung._adresse << std::endl;
    std::cout << "Rechnungsbetrag: " << rechnungsbetrag << std::endl;

    return out;
}

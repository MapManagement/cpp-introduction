#include <memory>
#include <ostream>
#include <string>
#include <valarray>
#include <vector>

// a)
class AbstrakterVertrag {
    protected:
    double _verbrauchteMinuten;
    double _verbrauchteSMS;

    public:
    virtual double berechneKosten() = 0;
    virtual void verbraucheTelefonEinheiten(double minuten) = 0;
    virtual void verbraucheSMSEinheit() = 0;
};

// b)
class FlatrateVertrag : public AbstrakterVertrag {
    double _fixbetrag;

    public:
    FlatrateVertrag(double fixbetrag);
    double berechneKosten() override;
    virtual void verbraucheTelefonEinheiten(double minuten) override;
    virtual void verbraucheSMSEinheit() override;
};

// c)
class GrundgebuehrVertrag : public AbstrakterVertrag {
    double _grundgebuehr;

    protected:
    double _preisProMinute;
    double _smsPreis;

    public:
    GrundgebuehrVertrag(double grundgebuehr, double preisProMinute,
                        double smsPreis);
    virtual double berechneKosten() override;
    virtual void verbraucheTelefonEinheiten(double minuten) override;
    virtual void verbraucheSMSEinheit() override;
};

class OhneGrundgebuehrVertrag : public GrundgebuehrVertrag {
    public:
    OhneGrundgebuehrVertrag(double preisProMinute, double smsPreis);
    virtual double berechneKosten() override;
};

// d)
class SekuendlicherVertrag : public GrundgebuehrVertrag {
    public:
    SekuendlicherVertrag(double grundgebuehr, double preisProMinute,
                         double smsPreis);
    virtual void verbraucheTelefonEinheiten(double sekunden) override;
};

// e)
class GuthabenVertrag : public OhneGrundgebuehrVertrag {
    protected:
    double _guthaben;
    double _fixbetrag;
    double _kosten;

    public:
    GuthabenVertrag(double preisProMinute, double smsPreis, double fixbetrag);
    virtual double berechneKosten() override;
    virtual void verbraucheTelefonEinheiten(double minuten) override;
    virtual void verbraucheSMSEinheit() override;
};

// f)
class VertragsBundle : public AbstrakterVertrag {
    protected:
    std::shared_ptr<AbstrakterVertrag> _hauptvertrag;
    std::vector<std::shared_ptr<AbstrakterVertrag>> _untervertraege;

    public:
    VertragsBundle(std::shared_ptr<AbstrakterVertrag> hauptvertrag);
    virtual double berechneKosten() override;
    virtual void verbraucheTelefonEinheiten(double minuten) override;
    virtual void verbraucheSMSEinheit() override;
    std::shared_ptr<AbstrakterVertrag> get(unsigned int index);
    void vertragRegistrieren(std::shared_ptr<AbstrakterVertrag> vertrag);
};

// g)
class Rechnung {
    protected:
    std::shared_ptr<AbstrakterVertrag> _vertrag;

    public:
    std::string _name;
    std::string _adresse;

    Rechnung(std::string name, std::string adresse,
             std::shared_ptr<AbstrakterVertrag> vertrag);
    std::shared_ptr<AbstrakterVertrag> getVertrag();
};

std::ostream &operator<<(std::ostream &out, Rechnung &rechnung);

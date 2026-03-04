#ifndef TARIF_H
#define TARIF_H

#include <string>

class livraison;

class tarif {
public:
    tarif();
    tarif(const std::string& dest,double p,double pe,
          double pf,double pef);
    std::string destination() const;
    double prixNormal() const;
    double prixExpress() const;
    double prixFragile() const;
    double prixExpressFragile() const;
    double prix(const livraison& l) const;

private:
    std::string d_destination;
    double d_prixNormal;
    double d_prixExpress;
    double d_prixFragile;
    double d_prixExpressFragile;
};

#endif // TARIF_H

#include "tarif.h"
#include "livraison.h"

tarif::tarif() : d_destination{""}, d_prixNormal{0}, d_prixExpress{0}, d_prixFragile{0},
    d_prixExpressFragile{0} {}

tarif::tarif(const std::string& dest,double p,double pe,
             double pf,double pef) : d_destination{dest}, d_prixNormal{p}, d_prixExpress{pe},
             d_prixFragile{pf}, d_prixExpressFragile{pef} {}

std::string tarif::destination() const{
    return d_destination;
}

double tarif::prixNormal() const{
    return d_prixNormal;
}

double tarif::prixExpress() const{
    return d_prixExpress;
}

double tarif::prixFragile() const{
    return d_prixFragile;
}

double tarif::prixExpressFragile() const{
    return d_prixExpressFragile;
}
double tarif::prix(const livraison& l) const{
    if(l.estExpress() && l.estFragile())
        return d_prixExpressFragile;
    if(l.estExpress())
        return d_prixExpress;
    if(l.estFragile())
        return d_prixFragile;
    return d_prixNormal;
}

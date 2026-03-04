#include "fiche.h"
#include "livraison.h"
#include "tarif.h"
#include <iostream>
#include <iomanip>

fiche::fiche() {}

void fiche::imprime(const livraison& livr,const tarif& t,std::ostream& ost)
{
    std::string livraison = livr.estExpress() ? "Express" : "Normale";
    std::string colis = livr.estFragile() ? "Fragile" : "Normal";

    ost << "Livraison\n";
    ost << "Pays de destination : " << t.destination() << "\n";
    ost << "Livraison : " << livraison << "\n";
    ost << "Colis : " << colis << "\n";
    ost << "Prix : " << std::fixed << std::setprecision(2) << t.prix(livr) << " Euros\n";
}

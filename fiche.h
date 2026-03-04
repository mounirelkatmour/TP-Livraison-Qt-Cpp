#ifndef FICHE_H
#define FICHE_H

#include <iostream>

class livraison;
class tarif;

class fiche
{
public:
    fiche();
    void imprime(const livraison& livr,const tarif& t,std::ostream& ost);
};

#endif // FICHE_H

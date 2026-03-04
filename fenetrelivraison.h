#ifndef FENETRELIVRAISON_H
#define FENETRELIVRAISON_H

#include <QWidget>
#include <vector>
#include <QButtonGroup>
#include <QLabel>
#include <QCheckBox>
#include "tarif.h"
#include "livraison.h"

class FenetreLivraison : public QWidget
{
    Q_OBJECT
public:
    FenetreLivraison(const std::vector<tarif>& tarifs, QWidget *parent = nullptr);

private:
    std::vector<tarif> d_tarifs;
    livraison d_livraison;
    int d_numeroTarif;
    QButtonGroup *d_radioDestinations;
    QLabel *d_labelPrix;
    void creeInterface();
    void afficheDestination();
    double prixLivraisonCourante() const;
    void affichePrix();
    QCheckBox *d_express, *d_fragile;
    void afficheTypeLivraison();
    bool d_achetee = false;
    void afficheEtatAchat();

public slots:
    void onDestination(int id);
    void onExpress(bool checked);
    void onFragile(bool checked);
    void onQuitter();
    void onReinitialiser();
    void onAcheter();
    void imprimeBonLivraison();
};

#endif // FENETRELIVRAISON_H

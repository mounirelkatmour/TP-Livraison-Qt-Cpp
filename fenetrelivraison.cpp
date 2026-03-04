#include "fenetrelivraison.h"
#include "fiche.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>
#include <QPushButton>
#include <QFrame>
#include <QMessageBox>
#include <fstream>

FenetreLivraison::FenetreLivraison(const std::vector<tarif>& tarifs, QWidget *parent) :
                    QWidget{parent},
                    d_tarifs{tarifs},
                    d_livraison{},
                    d_numeroTarif{0}
{
    creeInterface();
    afficheEtatAchat();
    afficheDestination();
    afficheTypeLivraison();
    affichePrix();
}

void FenetreLivraison::creeInterface(){
    auto *layout = new QHBoxLayout{this};

    auto *layoutDestination = new QVBoxLayout;

    auto *layoutPrix = new QVBoxLayout;

    auto *layoutType = new QVBoxLayout;

    auto *layoutBoutons = new QVBoxLayout;

    auto *boutonReinitialiser = new QPushButton{"Ré-initialiser"};
    auto *boutonAcheter = new QPushButton{"Acheter"};
    auto *boutonQuitter = new QPushButton{"Quitter"};

    auto *ligne = new QFrame;
    ligne->setFrameShape(QFrame::VLine);

    layoutBoutons->addWidget(boutonReinitialiser);
    layoutBoutons->addWidget(boutonAcheter);
    layoutBoutons->addWidget(boutonQuitter);

    layoutDestination->addWidget(new QLabel{"Destination"});
    d_radioDestinations = new QButtonGroup{this};
    for(int i = 0; i < d_tarifs.size(); ++i){
        auto *bouton = new QRadioButton{QString::fromStdString(d_tarifs[i].destination())};
        d_radioDestinations->addButton(bouton,i);
        layoutDestination->addWidget(bouton);
    }

    layoutType->addWidget(new QLabel("Type"));
    d_express = new QCheckBox("Express");
    d_fragile = new QCheckBox("Fragile");
    layoutType->addWidget(d_express);
    layoutType->addWidget(d_fragile);
    layoutType->addStretch();

    layoutPrix->addWidget(new QLabel("Prix"));
    d_labelPrix = new QLabel;
    layoutPrix->addWidget(d_labelPrix);
    layoutPrix->addStretch();

    layout->addLayout(layoutBoutons);
    layout->addSpacing(20);
    layout->addWidget(ligne);
    layout->addSpacing(20);
    layout->addLayout(layoutDestination);
    layout->addSpacing(20);
    layout->addLayout(layoutType);
    layout->addSpacing(20);
    layout->addLayout(layoutPrix);

    connect(d_radioDestinations, &QButtonGroup::idClicked,
            this, &FenetreLivraison::onDestination);
    connect(d_express, &QCheckBox::toggled,
            this, &FenetreLivraison::onExpress);
    connect(d_fragile, &QCheckBox::toggled,
            this, &FenetreLivraison::onFragile);
    connect(boutonQuitter, &QPushButton::clicked,
            this, &FenetreLivraison::onQuitter);
    connect(boutonReinitialiser, &QPushButton::clicked,
            this, &FenetreLivraison::onReinitialiser);
    connect(boutonAcheter, &QPushButton::clicked,
            this, &FenetreLivraison::onAcheter);
}

void FenetreLivraison::afficheDestination(){
    d_radioDestinations->button(d_numeroTarif)->setChecked(true);
}

double FenetreLivraison::prixLivraisonCourante() const{
    return d_tarifs[d_numeroTarif].prix(d_livraison);
}

void FenetreLivraison::affichePrix(){
    d_labelPrix->setText(QString::number(prixLivraisonCourante(),'f',2));
}

void FenetreLivraison::onDestination(int id){
    d_numeroTarif=id;
    affichePrix();
}

void FenetreLivraison::afficheTypeLivraison(){
    d_express->setChecked(d_livraison.estExpress());
    d_fragile->setChecked(d_livraison.estFragile());
}

void FenetreLivraison::onExpress(bool checked){
    d_livraison.rendExpress(checked);
    afficheTypeLivraison();
    affichePrix();
}

void FenetreLivraison::onFragile(bool checked){
    d_livraison.rendFragile(checked);
    afficheTypeLivraison();
    affichePrix();
}

void FenetreLivraison::onQuitter(){
    QMessageBox dialog{QMessageBox::Question, "Confirmation",
            "Livraison non achetée\nVoulez-vous vraiment quitter ?",
                       QMessageBox::Yes|QMessageBox::No};
    if(dialog.exec() == QMessageBox::Yes){
        close();
    }else{
        return;
    }
}

void FenetreLivraison::onReinitialiser(){
    d_numeroTarif=0;
    d_livraison.reInitialise();

    afficheDestination();
    afficheTypeLivraison();
    affichePrix();
}

void FenetreLivraison::onAcheter(){
    d_achetee=true;
    afficheEtatAchat();
    imprimeBonLivraison();
    QMessageBox{QMessageBox::Information,tr("Information"),
                tr("Livraison achetée")}.exec();
}

void FenetreLivraison::imprimeBonLivraison(){
    std::ofstream fichier("../../output/livraison.txt");
    if(!fichier) return;
    fiche f;
    f.imprime(d_livraison,d_tarifs[d_numeroTarif], fichier);
}

void FenetreLivraison::afficheEtatAchat(){
    if(d_achetee){
        setWindowTitle("Livraison");
    }else{
        setWindowTitle("Livraison*");
    }
}


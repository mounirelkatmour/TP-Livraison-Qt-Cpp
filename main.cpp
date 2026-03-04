#include "fenetrelivraison.h"

#include <QApplication>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::vector<tarif> tarifs = {tarif{"France", 10, 15, 20, 35},
                                 tarif{"Belgique", 20, 50, 70, 90},
                                 tarif{"Suisse", 30, 40, 50, 80},
                                 tarif{"USA", 50, 80, 90, 180}
    };
    FenetreLivraison f(tarifs);
    f.show();
    return a.exec();
}

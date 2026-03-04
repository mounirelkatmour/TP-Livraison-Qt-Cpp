# Qt Livraison Application

Application graphique développée en **C++** avec **Qt 6.10.1 (Qt Widgets)** permettant de gérer une **commande de livraison** et de calculer automatiquement son **prix** en fonction de plusieurs options.

<img width="490" height="226" alt="image" src="https://github.com/user-attachments/assets/1190ba1c-1834-4280-8380-3ba18be44500" />

----------------------------------------------------------------

## Fonctionnalités

- Sélection d'une **destination** via des **boutons radio**
- Choix du **type de livraison** :
  - **Livraison Express**
  - **Colis Fragile**
- **Calcul automatique du prix** selon :
  - la **destination**
  - les **options sélectionnées**
- **Boutons d'actions** :
  - **Ré-initialiser** la commande
  - **Acheter** la livraison
  - **Quitter** l'application
- Génération d'un **bon de livraison** dans un fichier **livraison.txt**

----------------------------------------------------------------

## Architecture du projet

Le projet est structuré autour de plusieurs classes :

- **tarif**  
  Représente les **tarifs associés à une destination** selon les différentes options.

- **livraison**  
  Représente l'**état d'une livraison** (express ou fragile).

- **fiche**  
  Permet d'**imprimer le bon de livraison** dans un flux de sortie (**std::ostream**).

- **FenetreLivraison**  
  Implémente l'**interface graphique principale** et la **logique de l'application**.

----------------------------------------------------------------

## Technologies utilisées

- **C++**
- **Qt 6.10.1 (Qt Widgets)**
- **Programmation Orientée Objet (POO)**
- **Layouts Qt**
  - `QHBoxLayout`
  - `QVBoxLayout`
- **Signals & Slots**
- **Gestion de fichiers avec `std::ofstream`**

----------------------------------------------------------------

## Exemple de bon de livraison généré

Livraison
Pays de destination : France
Livraison : Express
Colis : Fragile
Prix : 35.00 Euros

----------------------------------------------------------------

## Objectif pédagogique

Ce projet a été réalisé dans le cadre d'un **TP d'Interfaces Graphiques** afin de pratiquer :

- la création d'**interfaces graphiques avec Qt Widgets**
- la gestion des **événements avec le mécanisme Signals / Slots**
- la **séparation logique métier / interface graphique**
- la manipulation de **flux de sortie (`std::ostream`)**
- l'**organisation d'un projet C++ orienté objet**

----------------------------------------------------------------

## Auteur

**Mounir ELKATMOUR**

----------------------------------------------------------------

## Encadrement académique

Projet réalisé sous la supervision de  
**Professeur Stéphane RIVIÈRE**  
dans le cadre du module **Interfaces Graphiques**.

----------------------------------------------------------------

## Établissement

**Faculté des Sciences et Techniques de Mulhouse**  
**Université de Haute-Alsace (UHA)**

----------------------------------------------------------------

## Filière

**Licence 2 - Informatique**

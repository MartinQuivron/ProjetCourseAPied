#include "Coureur.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;


int i = 0;
Coureur::Coureur() {
    dossard = i + 1;
    nom = tab[i];
    masse = rand() % 75 + 45;
    taille = rand() % 70 + 130;
    pChaussure = rand() % 200 + 101;
    vMoyenne = rand() % 14 + 7;
    semainesPreparation = rand() % 9 + 8;
    hydratation = 0.5*vMoyenne/5;
    i++;
}

void Coureur::print() {
    cout << "nom : " << nom << endl;
    cout << "numéro de dossad : " << dossard << endl;
    cout << "masse : " << masse << " Kg" << endl;
    cout << "taille : " << taille << " cm" << endl;
    cout << "Poids chaussure : " << pChaussure << " gr" << endl;
    cout << "Vitesse moyenne épreuve précédente : " << vMoyenne << " Km/h" << endl;
    cout << "Nombre semaines de préparation : " << semainesPreparation << endl;
    cout << "Hydratation : " << hydratation << " l" << endl;
}
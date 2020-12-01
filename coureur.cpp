#include "Coureur.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

float distanceParcourue;
int i = 0;
Coureur::Coureur() {
    dossard = i + 1;
    nom = tab[i];
    masse = rand() % 75 + 45;
    taille = rand() % 70 + 130;
    pChaussure = rand() % 200 + 101;
    vMoyenne = rand() % 14 + 7;
    vMoyenneEnMetre = vMoyenne / 3.6;
    semainesPreparation = rand() % 9 + 8;
    hydratation_initiale = 0.5*vMoyenne/(42/9);
    float poidChaussure = pChaussure * 0.011;
    float vitesseMoy = vMoyenneEnMetre - (poidChaussure/100 * vMoyenneEnMetre);
    vitesse = vitesseMoy;
    i++;
}

float Coureur::getDistanceCoureur()
{
    return distanceParcourue;
}

void Coureur::setVitesseMoy(float VMOY) {
    vitesse = VMOY;
}

float Coureur::getVitesseMoy()
{
    return vitesse;
}

float Coureur::getTemps(){
    float temps = 42000 / getVitesseMoy();
    return temps;
}

void Coureur::print() {
    cout << "nom : " << nom << endl;
    cout << "numéro de dossad : " << dossard << endl;
    cout << "masse : " << masse << " Kg" << endl;
    cout << "taille : " << taille << " cm" << endl;
    cout << "Poids chaussure : " << pChaussure << " gr" << endl;
    cout << "Vitesse moyenne épreuve précédente : " << getVitesseMoy() << " m/s" << " -> " << getVitesseMoy()*3.6 << " km/h" << endl;
    cout << "Nombre semaines de préparation : " << semainesPreparation << endl;
    cout << "Hydratation : " << hydratation_initiale << " l" << endl;
    cout << "Vitesse Moyenne : " << getVitesseMoy() << " m/s" << " -> " << getVitesseMoy()*3.6 << " km/h" << endl;
    cout << "Temps : " << getTemps() << " secondes" << endl;
}




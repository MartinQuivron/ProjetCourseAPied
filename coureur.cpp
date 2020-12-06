#include "Coureur.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int i = 0;
Coureur::Coureur() {
    distance = 0;
    dossard = i + 1;
    nom = tab[i];
    masse = rand() % 76 + 45;
    taille = rand() % 71 + 130;
    pChaussure = rand() % 201 + 100;
    vMoyenne = rand() % 13 + 8;
    vMoyenneEnMetre = vMoyenne / 3.6;
    semainesPreparation = rand() % 9 + 8;
    hydratation_initiale = (0.5*vMoyenne/(42/9))*1000;
    hydratation = hydratation_initiale;
    float poidChaussure = pChaussure * 0.011;
    float vitesseMoy = vMoyenneEnMetre - (poidChaussure/100 * vMoyenneEnMetre);
    vitesse = vitesseMoy;
    vitesseInstant = vitesse;
    i++;
}

float Coureur::getDistance()
{
    return distance;
}

void Coureur::setDistance(float distanceAdd) {
    distance = distanceAdd;
}

float Coureur::getVitesseInstant() {
    return vitesseInstant;
}

void Coureur::setVitesseInstant(float vitesseIns) {
    vitesseInstant = vitesseIns;
}

float Coureur::getHydratation() {
    return hydratation;
}

void Coureur::setHydratation(float hydra) {
    hydratation = hydra;
}

float Coureur::getDistanceTotale()
{
    return distance;
}

float Coureur::getVitesseMoy()
{
    return vitesse;
}

float Coureur::getTaille()
{
    return taille;
}

float Coureur::getMasse()
{
    return masse;
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
    cout << "Hydratation initiale : " << hydratation_initiale/1000 << " l" << endl;
    cout << "Vitesse Moyenne : " << getVitesseMoy() << " m/s" << " -> " << getVitesseMoy()*3.6 << " km/h" << endl;
    cout << "Temps : " << getTemps() << " secondes" << endl;
    cout << "Distance : " << getDistance() << endl;
}




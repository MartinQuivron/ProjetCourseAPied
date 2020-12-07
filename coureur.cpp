#include "Coureur.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int i = 0;
//-----------------Création Coureur--------------------------------------------------------------------------------------------
Coureur::Coureur() {
    temps = 0;
    distance = 0;
    dossard = i + 1;
    nom = tab[i];
    masse = rand() % 76 + 45;
    taille = rand() % 71 + 130;
    pChaussure = rand() % 201 + 100;
    vMoyenne = rand() % 13 + 8;
    vMoyenneEnMetre = vMoyenne / 3.6;
    semainesPreparation = rand() % 9 + 8;
    (float)hydratation_initiale = (0.5*vMoyenne/(42/9))*1000;
    (float)hydratation = hydratation_initiale;
    float poidChaussure = pChaussure * 0.011;
    vitesseMoy = vMoyenneEnMetre - (poidChaussure/100 * vMoyenneEnMetre);
    vitesse = vitesseMoy;
    vitesseInstant = vitesse;
    apportHydrique = 0;
    i++;
}

//----------------------------GETTERS--------------------------------------------------------------------------------------

float Coureur::getPlace() {
    return place;
}

float Coureur::getTemps() {
    return temps;
}

float Coureur::getDistance()
{
    return distance;
}

float Coureur::getVitesseInstant() {
    return vitesseInstant;
}

float Coureur::getHydratationInit() {
    return hydratation_initiale;
}

float Coureur::getHydratation() {
    return hydratation;
}

float Coureur::getApportHydrique() {
    return apportHydrique;
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

float Coureur::getSemaine() {
    return semainesPreparation;
}

string Coureur::getName() {
    return nom;
}

//----------------------------SETTERS--------------------------------------------------------------------------------------

void Coureur::setPlace() {
    place++;
}

void Coureur::setTemps(float tmps) {
    temps = tmps;
    //cout << "temppppppppppppp " << temps << endl;
}

void Coureur::setDistance(float distanceAdd) {
    distance = distanceAdd;
}

void Coureur::setVitesseInstant(float vitesseIns) {
    vitesseInstant = vitesseIns;
}

void Coureur::setHydratation(float hydra) {
    hydratation = hydra;
}

void Coureur::setApportHydrique(float apport) {
    apportHydrique = apport;
}


void Coureur::setVitesseMoy(float vitesse) {
    vitesseMoy = vitesse;
}

//-----------------affichage Coureur--------------------------------------------------------------------------------------------
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
    cout << "Temps : " << temps << " secondes" << endl;
    cout << "Distance : " << distance << " km" << endl;
}

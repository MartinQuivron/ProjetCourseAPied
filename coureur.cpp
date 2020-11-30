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
    hydratation = 0.5*vMoyenne/5;
    i++;
}

float Coureur::getDistanceCoureur()
{
    return distanceParcourue;
}

float Coureur::setVitesseMoy(float vMoyenneEnMetre) {
    float vitMoyenne = vMoyenneEnMetre;
    return vitMoyenne;
}
float Coureur::getVitesseMoy()
{
    float poidChaussure = pChaussure * 0.011;
    float vitesseMoy = setVitesseMoy(vMoyenneEnMetre) - (poidChaussure/100 * setVitesseMoy(vMoyenneEnMetre));
    return vitesseMoy;
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
    cout << "Hydratation : " << hydratation << " l" << endl;
    cout << "Vitesse Moyenne : " << getVitesseMoy() << " m/s" << " -> " << getVitesseMoy()*3.6 << " km/h" << endl;
    cout << "Temps : " << getTemps() << " secondes" << endl;
}




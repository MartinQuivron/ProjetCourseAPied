#pragma once
#include <string>
using namespace std;

class Coureur
{
public:
    Coureur();
    void print();
    float getVitesseMoy();
    float getDistance();
    void setDistance(float distanceAdd);
    float getDistanceTotale();
    float getTaille();
    float getMasse();
    float getTemps();
    float getHydratation();
    void setHydratation(float hydra);
    float getVitesseInstant();
    void setVitesseInstant(float vitesseIns);
private:
    string tab[20] = { "Michel", "Jean", "Richard", "Dominique", "Sonic", "Nathalie", "Thomas", "Mikael", "Germain", "Tongue", "Grigny", "Marine", "WiiSport", "Mazence", "Jacques", "Mii", "Cortex", "Pigeon", "Solange", "EmmaTaVoisine" };
    string nom;
    int dossard;
    float masse;
    float taille;
    float pChaussure;
    float vMoyenne;
    float vMoyenneEnMetre;
    float semainesPreparation;
    float hydratation_initiale;
    float hydratation;
    float vitesse;
    float vitesseInstant;
    float distance;
};

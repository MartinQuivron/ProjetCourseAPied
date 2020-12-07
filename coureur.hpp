#pragma once
#include <string>
using namespace std;

class Coureur
{
public:
    Coureur();
    void print();
    float getVitesseMoy();
    void setVitesseMoy(float vitesse);
    float getDistance();
    void setDistance(float distanceAdd);
    float getDistanceTotale();
    float getTaille();
    float getMasse();
    float getTemps();
    void setTemps(float tmps);
    float getHydratation();
    void setHydratation(float hydra);
    float getVitesseInstant();
    void setVitesseInstant(float vitesseIns);
    float getApportHydrique();
    void setApportHydrique(float apport);
    float getHydratationInit();
    float getSemaine();
    void setPlace(int pla);
    float getPlace();
    float temps;
    int dossard;
    float distance;
    int place;
   
private:
    string tab[20] = { "Michel", "Jean", "Richard", "Dominique", "Sonic", "Nathalie", "Thomas", "Mikael", "Germain", "Tongue", "Grigny", "Marine", "WiiSport", "Mazence", "Jacques", "Mii", "Cortex", "Pigeon", "Solange", "EmmaTaVoisine" };
    string nom;
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
    float apportHydrique;
    float vitesseMoy;
};

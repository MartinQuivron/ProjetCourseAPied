#pragma once
#include <string>
using namespace std;

class Coureur
{
public:
    Coureur();
    void print();
    //-------------------------------GETTERS---------------------------------------------
    float getVitesseMoy();
    float getDistance();
    float getDistanceTotale();
    float getTaille();
    float getMasse();
    float getTemps();
    float getHydratation();
    float getVitesseInstant();
    float getApportHydrique();
    float getHydratationInit();
    float getPlace();
    string getName();
    //-----------------------------SETTERS---------------------------------------------------
    void setVitesseMoy(float vitesse);
    void setDistance(float distanceAdd);
    void setTemps(float tmps);
    void setHydratation(float hydra);
    void setVitesseInstant(float vitesseIns);
    void setApportHydrique(float apport);
    float getSemaine();
    void setPlace();

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

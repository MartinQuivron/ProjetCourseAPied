#pragma once
#include <string>
using namespace std;

class Coureur
{
public:
    Coureur();
    void print();
    float setVitesseMoy(float);
    float getVitesseMoy();
    float getDistanceCoureur();
    float getTemps();
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
    float hydratation;
};

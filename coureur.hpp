#pragma once
#include <string>


class Coureur
{
public:
    Coureur();
    void print();
    float dParcouru = 0;
private:
    std :: string tab[20] = { "Michel", "Jean", "Richard", "Dominique", "Sonic", "Nathalie", "Thomas", "Mikael", "Germain", "Tongue", "Grigny", "Marine", "WiiSport", "Mazence", "Jacques", "Mii", "Cortex", "Pigeon", "Solange", "EmmaTaVoisine" };
    std :: string nom;
    int dossard;
    float masse;
    float taille;
    float pChaussure;
    float vMoyenne;
    float semainesPreparation;
    float hydratation;
};

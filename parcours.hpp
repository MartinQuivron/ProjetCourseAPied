#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include "coureur.hpp"
using namespace std;

class Parcours {
public:
	Parcours();
	void course(Coureur &joueur);
	void course1(Coureur& joueur);
	float vent(Coureur &joueur, float vitesse);
	//-----------------------------GETTERS------------------------------------------------------
	vector<int> getEtapes();
	float getNbEtapes();
	vector<float> getDeniv();
private:
	int ravitaillement[8];
	int placeplace;
	float Pair;
	float vVent;
	float distance;
	int nombreEtapes;
	vector<int> etapes;
	vector<float> denivele;
};
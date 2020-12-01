#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include "coureur.hpp"
using namespace std;

class Parcours {
public:
	Parcours();
	void print();
	void course(Coureur joueur);
private:
	int ravitaillement[8];
	float distance;
	int nombreEtapes;
	vector<int> etapes;
	//vector<int> ravitaillement;
	vector<float> denivele;
	int condition;
};
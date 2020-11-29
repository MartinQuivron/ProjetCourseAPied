#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include "coureur.hpp"
using namespace std;

class Parcours {
public:
	Parcours();
	void genParcours();
private:
	int distance;
	int hauteur;
	vector<int> ravitaillement;
	vector<float> denivPos;
	vector<float> denivNeg;
	int condition;
};
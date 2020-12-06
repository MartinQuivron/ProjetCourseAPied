#include "parcours.hpp"
#include "coureur.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

Parcours::Parcours() {
	distance = 42000;
	nombreEtapes = rand() % 51 + 50;
	etapes.push_back(0);
	for (int i = 0; i < nombreEtapes - 2; i++) {
		etapes.push_back((rand() % 21000 + 1)*2);
	}
	etapes.push_back(42000);

	sort(etapes.begin(), etapes.end());

	for (int i = 0; i < nombreEtapes; i++) {
		denivele.push_back(rand() % 101 - 50);
	}

	for (int i = 0; i < 8; i++) {
		ravitaillement[i] = (distance / 9) * i;
	}

}

float Parcours::vent(Coureur joueur,float vitesse) {
	float vMoy = vitesse;
	float Pr = vMoy * joueur.getMasse() * 0.98;
	float Pa = 0.5 * Pair * 0.137 * (joueur.getTaille() / 100) * vMoy;
	float PtMAX = Pr + Pa;
	Pa = 0.5 * Pair * 0.137 * (joueur.getTaille() / 100) * (vMoy + (vVent * vVent) * vMoy);
	Pr = PtMAX - Pa;
	vMoy = Pr / (joueur.getMasse() * 0.98);
	cout << "puissance vent : " << -Pa << endl;
	return vMoy;
}

float Parcours::hydratation(Coureur joueur) {
	for (int i = 0; i < 8; i++) {
		if (joueur.getDistance() >= ravitaillement[i] - joueur.getVitesseInstant() && joueur.getDistance() < ravitaillement[i]) {
			//int ravi = 
		}
	}
	return 0;
}

void Parcours::course(Coureur joueur){
	int temps = 0;
	float distance = joueur.getDistance();
	
	//float vitesseMoy = joueur.getVitesseMoy();
	float tempo;
	for (int i = 0; i < nombreEtapes; i++) {
		Pair = rand() % 3 - 1;
		vVent = (rand() % 26 + 75) / 10;
		//int condition = rand() % 3;
		//float Pa = 0.5*pair*0.137*joueur.getTaille()*(joueur.getVitesseMoy() + vVent^2 * joueur.getVitesseMoy());
		float vitesseDenivPOS = joueur.getVitesseMoy() - (joueur.getVitesseMoy() * ((denivele[i] / 1.5) / 100));
		float vitesseDenivNEG = joueur.getVitesseMoy() - (joueur.getVitesseMoy() * ((denivele[i] / 1.5)* 0.35) / 100);
		if (denivele[i] < 0) {
			cout << "Descente ------------" << endl;
		}
		if (denivele[i] > 0) {
			cout << "montée ------------" << endl;
		}
		while (distance < etapes[i]) {
			
			if (denivele[i] < 0) {
				tempo = vent(joueur, vitesseDenivNEG);
				distance += tempo;
				joueur.setDistance(distance);
				joueur.setVitesseInstant(tempo);
				cout << tempo << endl;
			}
			if (denivele[i] > 0) {
				tempo = vent(joueur, vitesseDenivPOS);
				distance += tempo;
				joueur.setDistance(distance);
				joueur.setVitesseInstant(tempo);
				cout << tempo << endl;
			}
			if (denivele[i] == 0) {
				tempo = vent(joueur, joueur.getVitesseMoy());
				distance += tempo;
				joueur.setDistance(distance);
				joueur.setVitesseInstant(tempo);
				cout << tempo << endl;
			}
			temps++;
			cout << joueur.getDistance() << endl;
		}
	}
	cout << "Fin en : " << temps << " secondes" << endl;
}

void Parcours::print() {
	cout << "etapes" << nombreEtapes << endl;
}

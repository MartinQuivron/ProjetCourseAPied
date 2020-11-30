#include "parcours.hpp"
#include "coureur.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

Parcours::Parcours() {
	condition = rand() % 3;
	distance = 42000;
	nombreEtapes = rand() % 50 + 50;
	
	for (int i = 0; i < nombreEtapes; i++) {
		etapes.push_back((rand() % 20999 + 1)*2);
	}

	sort(etapes.begin(), etapes.end());

	for (int i = 0; i < nombreEtapes; i++) {
		denivele.push_back(rand() % 100 - 50);
	}

	for (int i = 0; i < nombreEtapes; i++) {
		if (i == 0) {

		}
	}

}
void Parcours::course(Coureur joueur){
	int temps = 0;
	float distance = 0;
	float vitesseMoy = joueur.getVitesseMoy();
	float vitesseMoyMetre = vitesseMoy / 3.6;
	for (int i = 0; i < nombreEtapes; i++) {
		float vitesseDenivNEG = vitesseMoyMetre - (vitesseMoyMetre * ((denivele[i] / 1.5) / 100));
		float vitesseDenivPOS = vitesseMoyMetre - (vitesseMoyMetre * ((denivele[i] / 1.5)* 0.35) / 100);
		while (distance < etapes[i]) {
			if (denivele[i] < 0) {
				joueur.setVitesseMoy(vitesseDenivNEG);
			}
			if (denivele[i] > 0) {
				joueur.setVitesseMoy(vitesseDenivPOS);
			}
			distance += joueur.getVitesseMoy();
			temps++;
			cout << distance << endl;
		}
	}
	cout << "Fin en : " << temps << " secondes" << endl;
}

void Parcours::print() {
	cout << "etapes" << nombreEtapes << endl;
}

/*void Parcours::genParcours() {
	
}*/
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

float Parcours::vent(Coureur &joueur,float vitesse) {
	float vMoy = vitesse;
	float Pr = vMoy * joueur.getMasse() * 0.98;
	float Pa = 0.5 * Pair * 0.137 * (joueur.getTaille() / 100) * vMoy;
	float PtMAX = Pr + Pa;
	Pa = 0.5 * Pair * 0.137 * (joueur.getTaille() / 100) * (vMoy + (vVent * vVent) * vMoy);
	Pr = PtMAX - Pa;
	vMoy = Pr / (joueur.getMasse() * 0.98);
	//cout << "puissance vent : " << -Pa << endl;
	return vMoy;
}

void Parcours::course(Coureur &joueur){
	float temps = joueur.getTemps();
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
			//cout << "Descente ---------------------------------------------------------------" << endl;
		}
		if (denivele[i] > 0) {
			//cout << "montée -----------------------------------------------------------------" << endl;
		}
		while (distance < etapes[i]) {
			
			if (denivele[i] < 0) {
				tempo = vent(joueur, vitesseDenivNEG);
				distance += tempo;
				joueur.setDistance(distance);
				joueur.setVitesseInstant(tempo);
				//cout << tempo << endl;
			}
			if (denivele[i] > 0) {
				tempo = vent(joueur, vitesseDenivPOS);
				distance += tempo;
				joueur.setDistance(distance);
				joueur.setVitesseInstant(tempo);
				//cout << tempo << endl;
			}
			if (denivele[i] == 0) {
				tempo = vent(joueur, joueur.getVitesseMoy());
				distance += tempo;
				joueur.setDistance(distance);
				joueur.setVitesseInstant(tempo);
				//cout << tempo << endl;
			}
			temps++;
			//----------------------------------------------------------------------------------------
			float nice = joueur.getHydratation() - 0.139;//(500/3600)
			joueur.setHydratation(nice);
			float hydratInit = joueur.getHydratationInit() / 1000;
			float apport = joueur.getApportHydrique() / 1000;
			for (int i = 0; i < 8; i++) {
				if (joueur.getDistance() >= ravitaillement[i] - joueur.getVitesseInstant() && joueur.getDistance() < ravitaillement[i]) {
					//cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-------------ravitaillement--------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
					float ravi = (rand() % 50) * 10;
					double test = (apport + hydratInit) / (0.5 * (joueur.getTemps() / 3600));
					float apportInit = joueur.getApportHydrique() + ravi;
					joueur.setApportHydrique(apportInit);
					
					float ravitaillement = joueur.getHydratation() + ravi;
					joueur.setHydratation(ravitaillement);
					if (test < 0.9 && test >= 0.4) {
						float pourcent = ((9 - test * 10) * 0.038) + 1;
						float vitejoueur = joueur.getVitesseMoy();
						vitejoueur -= vitejoueur * pourcent;
						joueur.setVitesseMoy(vitejoueur);
					}
					if (test < 0.4) {
						joueur.setDistance(99999);
					}
				}
			}
			//---------------------------------------------------------------------------------------
			if (joueur.getSemaine() == 8) {
				if (joueur.getDistance() >= 21000 - joueur.getVitesseInstant() && joueur.getDistance() < 21000) {
					float baisse = (-0.2 / 21000) * joueur.getDistance() + 1.2;
					float vitevite = joueur.getVitesseMoy() * baisse;
					joueur.setVitesseMoy(vitevite);
				}
			}
			if (joueur.getSemaine() > 8 && joueur.getSemaine() < 16){
				float dist = (42000 / 2 * (1 + (joueur.getSemaine() - 8) / 8));
				//cout << "-----------------------------------------------------------------------------------------" << dist << endl;
				if (joueur.getDistance() >= dist - joueur.getVitesseInstant() && joueur.getDistance() < dist) {
					float baisse = (-0.2 / dist) * joueur.getDistance() + 1.2;
					float vitevite = joueur.getVitesseMoy() * baisse;
					joueur.setVitesseMoy(vitevite);
				}
			}
			//----------------------------------------------------------------------------------------
			//cout << joueur.getDistance() << endl;
			//cout << "son hydratation : " << joueur.getHydratation() << endl;
			joueur.setTemps(temps);
			if (joueur.getDistance() >= 42000) {
				joueur.setPlace();
			}
		}
	}
	joueur.temps = temps;
	joueur.distance = distance;
	//cout << "Fin en : " << joueur.temps << " secondes" << endl;
	//cout << "distance " << joueur.distance << " m" << endl;
}


//Montrer une seule personne
void Parcours::course1(Coureur& joueur) {
	float temps = joueur.getTemps();
	float distance = joueur.getDistance();

	//float vitesseMoy = joueur.getVitesseMoy();
	float tempo;
	for (int i = 0; i < nombreEtapes; i++) {
		Pair = rand() % 3 - 1;
		vVent = (rand() % 26 + 75) / 10;
		//int condition = rand() % 3;
		//float Pa = 0.5*pair*0.137*joueur.getTaille()*(joueur.getVitesseMoy() + vVent^2 * joueur.getVitesseMoy());
		float vitesseDenivPOS = joueur.getVitesseMoy() - (joueur.getVitesseMoy() * ((denivele[i] / 1.5) / 100));
		float vitesseDenivNEG = joueur.getVitesseMoy() - (joueur.getVitesseMoy() * ((denivele[i] / 1.5) * 0.35) / 100);
		if (denivele[i] < 0) {
			cout << "Descente ---------------------------------------------------------------" << endl;
		}
		if (denivele[i] > 0) {
			cout << "montée -----------------------------------------------------------------" << endl;
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
			//----------------------------------------------------------------------------------------
			float nice = joueur.getHydratation() - 0.139;//(500/3600)
			joueur.setHydratation(nice);
			float hydratInit = joueur.getHydratationInit() / 1000;
			float apport = joueur.getApportHydrique() / 1000;
			for (int i = 0; i < 8; i++) {
				if (joueur.getDistance() >= ravitaillement[i] - joueur.getVitesseInstant() && joueur.getDistance() < ravitaillement[i]) {
					cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-------------ravitaillement--------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
					float ravi = (rand() % 50) * 10;
					double test = (apport + hydratInit) / (0.5 * (joueur.getTemps() / 3600));
					float apportInit = joueur.getApportHydrique() + ravi;
					joueur.setApportHydrique(apportInit);

					float ravitaillement = joueur.getHydratation() + ravi;
					joueur.setHydratation(ravitaillement);
					if (test < 0.9 && test >= 0.4) {
						float pourcent = ((9 - test * 10) * 0.038) + 1;
						float vitejoueur = joueur.getVitesseMoy();
						vitejoueur -= vitejoueur * pourcent;
						joueur.setVitesseMoy(vitejoueur);
					}
					if (test < 0.4) {
						joueur.setDistance(99999);
					}
				}
			}
			//---------------------------------------------------------------------------------------
			if (joueur.getSemaine() == 8) {
				if (joueur.getDistance() >= 21000 - joueur.getVitesseInstant() && joueur.getDistance() < 21000) {
					float baisse = (-0.2 / 21000) * joueur.getDistance() + 1.2;
					float vitevite = joueur.getVitesseMoy() * baisse;
					joueur.setVitesseMoy(vitevite);
				}
			}
			if (joueur.getSemaine() > 8 && joueur.getSemaine() < 16) {
				float dist = (42000 / 2 * (1 + (joueur.getSemaine() - 8) / 8));
				//cout << "-----------------------------------------------------------------------------------------" << dist << endl;
				if (joueur.getDistance() >= dist - joueur.getVitesseInstant() && joueur.getDistance() < dist) {
					float baisse = (-0.2 / dist) * joueur.getDistance() + 1.2;
					float vitevite = joueur.getVitesseMoy() * baisse;
					joueur.setVitesseMoy(vitevite);
				}
			}
			//----------------------------------------------------------------------------------------
			cout << joueur.getDistance() << endl;
			cout << "son hydratation : " << joueur.getHydratation() << endl;
			joueur.setTemps(temps);
			if (joueur.getDistance() >= 42000) {
				joueur.setPlace();
			}
		}
	}
	joueur.temps = temps;
	joueur.distance = distance;
	//cout << "Fin en : " << joueur.temps << " secondes" << endl;
	//cout << "distance " << joueur.distance << " m" << endl;
}


float Parcours::getNbEtapes() {
	return nombreEtapes;
}

vector<int> Parcours::getEtapes() {
	return etapes;
}

vector<float> Parcours::getDeniv() {
	return denivele;
}
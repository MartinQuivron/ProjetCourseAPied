#include <SFML/Graphics.hpp>
#include "coureur.hpp"
#include "parcours.hpp"
#include <iostream>
#include <time.h>
#include <locale.h>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
using namespace sf;

int main() {
	setlocale(LC_ALL, "fr-FR");
	srand(time(nullptr));

	Coureur tableau[20];
	Parcours personne;
	tableau[0].print();
	personne.course1(tableau[0]);
	tableau[0].print();
	for (int i = 1; i < 20; i++) {
		personne.course(tableau[i]);
		tableau[i].print();
	}
	//Leaderboard------------------------------------------------------------------------------
	vector<Coureur> rangement;
	int best = 99999;
	int tmp = 99999;
	int leJ = 0;
	for (int j = 0; j < 20; j++) {
		if (tableau[j].getTemps() < tmp) {
			tmp = tableau[j].getTemps();
			leJ = j;
		}
		
	}
	rangement.push_back(tableau[leJ]);
	for (int i = 1; i < 20; i++) {
		best = 99999;
		for (int j = 0; j < 20; j++) {
			if (tableau[j].getTemps() < best && tableau[j].getTemps() > tmp) {
				best = tableau[j].getTemps();
				leJ = j;
			}
		}
		tmp = best;
		rangement.push_back(tableau[leJ]);
	}

	string fichier;
	cin >> fichier;
	ofstream fichierDeResultat;
	fichierDeResultat.open("C:/Users/marti/Desktop/LeaderBoard/" + fichier + ".txt", ios::out);
	if (fichierDeResultat) {
		fichierDeResultat << "Resultats de l'�preuve du marathon :" << endl;
		for (int i = 0; i < 20; i++) {
			fichierDeResultat << i+1 << ") - Nom : " << rangement[i].getName() << " - Temps : " << rangement[i].getTemps() / 3600 << " h - Vitesse Moyenne : " << 42000/(rangement[i].getTemps()) << " m/s" << endl;
		}
	}
	else { cout << "Impossible d'ouvrir ce fichier ! " << endl; }
	fichierDeResultat.close();
	return 0;
}
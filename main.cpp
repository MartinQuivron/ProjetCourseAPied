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
	for (int i = 0; i < 20; i++) {
		personne.course(tableau[i]);
		tableau[i].print();
	}

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

	/*personne.course(tableau);
	tableau[0].print();
	cout << tableau[0].temps << endl;*/


	/*tableau[18].print();
	Parcours joueur;
	joueur.print();
	return 0;*/
	string fichier;
	cin >> fichier;
	ofstream fichierDeResultat;
	fichierDeResultat.open("C:/Users/marti/Desktop/" + fichier + ".txt", ios::out);
	if (fichierDeResultat) {
		fichierDeResultat << "Resultats de l'épreuve du marathon :" << endl;
		for (int i = 0; i < 20; i++) {
			fichierDeResultat << i+1 << ") - Nom : " << rangement[i].getName() << " - Temps : " << rangement[i].getTemps() / 3600 << " h - Vitesse Moyenne : " << 42000/(rangement[i].getTemps()) << " m/s" << endl;
		}
		/*filetop << "Temps : " << hours << " H " << mins << " M " << secs << " S " << "\n";
			filetop << "Semaine de préparation : " << smp << "\n";
			filetop << "Vitesse Moyenne Précédente : " << UnTab.AllCoureur[i].VMprec << "\n";
			filetop << "\n";*/
	}
	else { cout << "Impossible d'ouvrir ce fichier ! " << endl; }
	fichierDeResultat.close();
	return 0;
}
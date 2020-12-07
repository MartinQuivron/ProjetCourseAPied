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
	//for (int i = 0; i < 20; i++) {
	//	personne.course(tableau[i]);
		
	//}
		personne.course(tableau[0]);
		tableau[0].print();
		cout << tableau[0].temps << endl;


	/*tableau[18].print();
	Parcours joueur;
	joueur.print();
	return 0;*/

	string fichier;
	cin >> fichier;
	ofstream fichierDeResultat;
	fichierDeResultat.open("C:/Users/marti/Desktop/" + fichier + ".txt", ios::out); //on ouvre le fichier en ecriture
	if (fichierDeResultat) {

		fichierDeResultat << "Resultats de l'épreuve du marathon :" << endl;
		fichierDeResultat;





	}
	else { cout << "Impossible d'ouvrir ce fichier ! " << endl; }



	fichierDeResultat << "contenu du fichier" << endl;//*
	fichierDeResultat.close(); //on ferme le fichier pour liberer la mémoire
	return 0;

}
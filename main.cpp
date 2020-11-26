#include <SFML/Graphics.hpp>
#include "coureur.hpp"
#include <iostream>
#include <time.h>
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "fr-FR");
	srand(time(nullptr));
	Coureur tableau[20];
	for (int i = 0; i < 20; i++) {
		tableau[i].print();
		cout << endl << endl;
	}
	tableau[19].print();

	return 0;
}
#include "parcours.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Parcours::Parcours() {
	condition = rand() % 3;
}

void Parcours::genParcours() {
	distance = 42000;
	hauteur= 1000;

}
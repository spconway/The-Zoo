/*
 * Crocodile.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#include <iostream>
#include <iomanip>
#include "header/Crocodile.h"

string Crocodile::GetSubType() {
	return subType;
}

void Crocodile::Print() {
	Animal::Print();
	Oviparous::PrintAnimalType();
	cout << setw(15) << left << subType;
	Oviparous::PrintNumberOfEggs();
	cout << setw(15) << left << '0';
}

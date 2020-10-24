/*
 * Pelican.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: stephen.conwa_snhu
 */

#include <iostream>
#include <iomanip>
#include "header/Pelican.h"

string Pelican::GetSubType() {
	return subType;
}

void Pelican::Print() {
	Animal::Print();
	Oviparous::PrintAnimalType();
	cout << setw(15) << left << subType;
	Oviparous::PrintNumberOfEggs();
	cout << setw(15) << left << '0';
}

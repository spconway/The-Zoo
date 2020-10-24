/*
 * Bat.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: stephen.conwa_snhu
 */

#include <iostream>
#include <iomanip>
#include "header/Bat.h"

string Bat::GetSubType() {
	return subType;
}

void Bat::Print() {
	Animal::Print();
	Mammal::PrintAnimalType();
	cout << setw(15) << left << subType;
	cout << setw(15) << left << '0';
	Mammal::PrintNurse();
}

/*
 * SeaLion.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: stephen.conwa_snhu
 */

#include <iostream>
#include <iomanip>
#include "header/SeaLion.h"

string SeaLion::GetSubType() {
	return subType;
}

void SeaLion::Print() {
	Animal::Print();
	Mammal::PrintAnimalType();
	cout << setw(15) << left << subType;
	cout << setw(15) << left << '0';
	Mammal::PrintNurse();
}

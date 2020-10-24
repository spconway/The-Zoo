/*
 * Mammal.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: stephen.conwa_snhu
 */

#include <iomanip>
#include <iostream>
#include "header/Mammal.h"
using namespace std;

string Mammal::GetAnimalType() const {
	return animalType;
}

void Mammal::SetNurse(int nurse) {
	this->nurse = nurse;
}

int Mammal::GetNurse() const {
	return nurse;
}

void Mammal::PrintAnimalType() {
	cout << setw(15) << left << animalType;
}

void Mammal::PrintNurse() {
	cout << setw(15) << left << nurse;
}

void Mammal::Print() {
	cout << setw(15) << left << "Mammal";
	cout << setw(15) << left << "0";
	cout << setw(15) << left << nurse;
}

/*
 * Oviparous.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "header/Oviparous.h"

string Oviparous::GetAnimalType() const {
	return animalType;
}

void Oviparous::SetNumberOfEggs(int eggs) {
	this->eggs = eggs;
}

int Oviparous::GetNumberOfEggs() const {
	return eggs;
}

void Oviparous::PrintAnimalType() {
	cout << setw(15) << left << animalType;
}

void Oviparous::PrintNumberOfEggs() {
	cout << setw(15) << left << eggs;
}

void Oviparous::Print() {
	Animal::Print();
	cout << setw(15) << left << "Oviparous";
	cout << setw(15) << left << eggs;
	cout << setw(15) << left << "0";
}

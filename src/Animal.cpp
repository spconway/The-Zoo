/*
 * Animal.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#include <string>
#include <iostream>
#include <iomanip>
#include "header/Animal.h"

string Animal::GetName() const {
	return name;
}

string Animal::GetTrackNum() const {
	return trackNum;
}

void Animal::SetName(string name) {
	this->name = name;
}

void Animal::SetTrackNum(string trackNum) {
	this->trackNum = trackNum;
}

void Animal::PrintName() {
	cout << setw(15) << left << name;
}

void Animal::PrintTrackNum() {
	cout << setw(15) << left << trackNum;
}

void Animal::Print() {
	cout << setw(15) << left << trackNum;
	cout << setw(15) << left << name;
}

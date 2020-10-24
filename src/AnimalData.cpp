/*
 * AnimalData.cpp
 *
 *  Created on: Oct 18, 2020
 *  Author: Stephen Conway
 *
 *  The AnimalData class stores animal data and manages the life cycle -
 *  of each animal object. It manages memory consumption by deleting -
 *  objects when they are no longer being used and also handled writing -
 *  data to an output file.
 */

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "header/Bat.h"
#include "header/Crocodile.h"
#include "header/Goose.h"
#include "header/Pelican.h"
#include "header/SeaLion.h"
#include "header/Whale.h"
#include "header/AnimalData.h"
#include "header/Oviparous.h"
#include "header/Mammal.h"
#include "header/Animal.h"
using namespace std;

void AnimalData::AddAnimalData(Animal* animal) {
	animalVector.push_back(animal);
	++count;
}

void AnimalData::DeleteAnimalData(string trackNum) {
	unsigned int i;
	Animal* tmp = nullptr;
	for(i = 0; i < count; ++i) {
		if(animalVector.at(i)->GetTrackNum() == trackNum) {
			tmp = animalVector.at(i);
			delete tmp;
			animalVector.erase(animalVector.begin() + i);
			--count;
		}
	}
}

void AnimalData::DeleteAnimalData(Animal animal) {
	DeleteAnimalData(animal.GetName());
}

void AnimalData::TruncateData() {
	Animal* tmp = nullptr;
	while(animalVector.size() > 0) {
		tmp = animalVector.at(count-1);
		delete tmp;
		animalVector.erase(animalVector.begin() + count-1);
		--count;
	}
}

Animal* AnimalData::GetAnimalData(string trackNum) {
	Animal* animal = nullptr;
	unsigned int i;
	for(i = 0; i < count; ++i) {
		if(animalVector.at(i)->GetTrackNum() == trackNum) {
			animal = animalVector.at(i);
		}
	}
	return animal;
}

void AnimalData::WriteAnimalDataToFile(string filename) {
	ofstream outFS;			// output stream to write to file

	// open file for writing
	outFS.open(filename);

	if(!outFS.is_open()) {
		cout << "Could not open file.";
	} else {
		// accumulate to stream with a stringstream
		// found the following resource to help redirect all print
		// statements to a stringstream which can be used to
		// write the contents to a file
		// https://stackoverflow.com/questions/5419356/redirect-stdout-stderr-to-a-string
		stringstream buffer;
		// store old buffer for reset
		streambuf * old = cout.rdbuf(buffer.rdbuf());
		for(unsigned int i = 0; i < count; ++i) {
			// reset stringstream
			buffer.str("");
			animalVector.at(i)->Print();
			outFS << buffer.str();
		}
		// reset cout buffer
		cout.rdbuf(old);
		cout << "Save successfully completed." << endl;
		outFS.close();
	}
}

void AnimalData::Print() {
	unsigned int i;

	// print out data
	cout << setw(15) << left << "Track #";
	cout << setw(15) << left << "Name";
	cout << setw(15) << left << "Type";
	cout << setw(15) << left << "Eggs";
	cout << setw(15) << left << "Nurse";
	cout << setw(15) << left << "Sub-type";
	cout << endl;

	for(i = 0; i < count; ++i) {
		animalVector.at(i)->Print();
		cout << endl;
	}
}


/*
 * AnimalResolver.cpp
 *
 *  Created on: Oct 18, 2020
 *  Author: stephen conway
 *
 *  The AnimalResolver class' sole purpose is to take raw data and -
 *  resolve it to a sub type instance (Mammal or Oviparous). It does -
 *  this by taking a reference to an object manager and passing -
 *  back the correct instance of a new animal object.
 */

#include <string>
#include <sstream>
#include <vector>
#include "header/AnimalData.h"
#include "header/Bat.h"
#include "header/Crocodile.h"
#include "header/Goose.h"
#include "header/Pelican.h"
#include "header/SeaLion.h"
#include "header/Whale.h"
#include "header/Mammal.h"
#include "header/Oviparous.h"
#include "header/Animal.h"
using namespace std;

class AnimalResolver {
	public:
		void resolve(AnimalData* animalData, string track, string name, string animalType, string subType, int eggs, int nurse) {
			if (subType == "Bat" || subType == "bat") {
				Bat* bat = new Bat;
				bat->SetName(name);
				bat->SetTrackNum(track);
				bat->SetNurse(nurse);
				animalData->AddAnimalData(bat);
			}

			if (subType == "Whale" || subType == "whale") {
				Whale* whale = new Whale;
				whale->SetName(name);
				whale->SetTrackNum(track);
				whale->SetNurse(nurse);
				animalData->AddAnimalData(whale);
			}

			if (subType == "SeaLion" || subType == "sealion") {
				SeaLion* sealion = new SeaLion;
				sealion->SetName(name);
				sealion->SetTrackNum(track);
				sealion->SetNurse(nurse);
				animalData->AddAnimalData(sealion);
			}

			if (subType == "Crocodile" || subType == "crocodile") {
				Crocodile* crocodile = new Crocodile;
				crocodile->SetName(name);
				crocodile->SetTrackNum(track);
				crocodile->SetNumberOfEggs(eggs);
				animalData->AddAnimalData(crocodile);
			}

			if (subType == "Goose" || subType == "goose") {
				Goose* goose = new Goose;
				goose->SetName(name);
				goose->SetTrackNum(track);
				goose->SetNumberOfEggs(eggs);
				animalData->AddAnimalData(goose);
			}

			if (subType == "Pelican" || subType == "pelican") {
				Pelican* pelican = new Pelican;
				pelican->SetName(name);
				pelican->SetTrackNum(track);
				pelican->SetNumberOfEggs(eggs);
				animalData->AddAnimalData(pelican);
			}
		}
};

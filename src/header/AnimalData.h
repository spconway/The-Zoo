/*
 * AnimalData.h
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#ifndef ANIMALDATA_H_
#define ANIMALDATA_H_

#include <string>
#include "Animal.h"
using namespace std;

class AnimalData {
	public:
		void AddAnimalData(Animal* animal);
		void DeleteAnimalData(string trackNum);
		void DeleteAnimalData(Animal animal);
		void TruncateData();
		Animal* GetAnimalData(string trackNum);
		void WriteAnimalDataToFile(string filename);
		void Print();
	private:
		vector<Animal*> animalVector;
		string name = "Animal Data Warehouse";
		unsigned int count = 0;
};


#endif /* ANIMALDATA_H_ */

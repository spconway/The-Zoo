/*
 * Oviparous.h
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#ifndef HEADER_OVIPAROUS_H_
#define HEADER_OVIPAROUS_H_

#include "Animal.h"
#include "Common.h"

class Oviparous : public Animal {
	public:
		string GetAnimalType() const;
		void SetNumberOfEggs(int eggs);
		int GetNumberOfEggs() const;
		void PrintAnimalType();
		void PrintNumberOfEggs();
		virtual void Print();
	private:
		int eggs;
		string animalType = "Oviparous";
};

#endif /* HEADER_OVIPAROUS_H_ */

/*
 * Mammal.h
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#ifndef HEADER_MAMMAL_H_
#define HEADER_MAMMAL_H_

#include "Animal.h"

class Mammal : public Animal {
	public:
		string GetAnimalType() const;
		void SetNurse(int nurse);
		int GetNurse() const;
		void PrintAnimalType();
		void PrintNurse();
		virtual void Print();
	private:
		int nurse;
		string animalType = "Mammal";
};

#endif /* HEADER_MAMMAL_H_ */

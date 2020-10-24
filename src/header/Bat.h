/*
 * Bat.h
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#ifndef HEADER_BAT_H_
#define HEADER_BAT_H_

#include <string>
#include "Mammal.h"

class Bat : public Mammal {
	public:
		string GetSubType();
		void Print();
	private:
		string subType = "Bat";
};

#endif /* HEADER_BAT_H_ */

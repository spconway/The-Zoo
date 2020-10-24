/*
 * Whale.h
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#ifndef HEADER_WHALE_H_
#define HEADER_WHALE_H_

#include <string>
#include "Common.h"
#include "Mammal.h"

class Whale : public Mammal {
	public:
		string GetSubType();
		void Print();
	private:
		string subType = "Whale";
};

#endif /* HEADER_WHALE_H_ */

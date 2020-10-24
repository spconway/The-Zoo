/*
 * SeaLion.h
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#ifndef HEADER_SEALION_H_
#define HEADER_SEALION_H_

#include <string>
#include "Common.h"
#include "Mammal.h"

class SeaLion : public Mammal {
	public:
		string GetSubType();
		void Print();
	private:
		string subType = "SeaLion";
};

#endif /* HEADER_SEALION_H_ */

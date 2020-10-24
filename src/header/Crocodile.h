/*
 * Crocodile.h
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#ifndef HEADER_CROCODILE_H_
#define HEADER_CROCODILE_H_

#include "Oviparous.h"

class Crocodile : public Oviparous {
	public:
		string GetSubType();
		void Print();
	private:
		string subType = "Crocodile";
};

#endif /* HEADER_CROCODILE_H_ */

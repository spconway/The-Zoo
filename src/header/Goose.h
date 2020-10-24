/*
 * Goose.h
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#ifndef HEADER_GOOSE_H_
#define HEADER_GOOSE_H_

#include <string>
#include <iostream>
#include "Common.h"
#include "Oviparous.h"
using namespace std;

class Goose : public Oviparous {
	public:
		string GetSubType();
		void Print();
	private:
		string subType = "Goose";
};

#endif /* HEADER_GOOSE_H_ */

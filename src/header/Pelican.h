/*
 * Pelican.h
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#ifndef HEADER_PELICAN_H_
#define HEADER_PELICAN_H_

#include <string>
#include <iostream>
#include "Common.h"
#include "Oviparous.h"
using namespace std;

class Pelican : public Oviparous {
	public:
		string GetSubType();
		void Print();
	private:
		string subType = "Pelican";
};

#endif /* HEADER_PELICAN_H_ */

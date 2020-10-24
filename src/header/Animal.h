/*
 * Animal.h
 *
 *  Created on: Oct 18, 2020
 *      Author: stephen.conwa_snhu
 */

#ifndef HEADER_ANIMAL_H_
#define HEADER_ANIMAL_H_

using namespace std;

class Animal {
	public:
		string GetName() const;
		string GetTrackNum() const;
		void SetName(string name);
		void SetTrackNum(string trackNum);
		void PrintName();
		void PrintTrackNum();
		virtual void Print();
	private:
		string name;
		string trackNum;
};

#endif /* HEADER_ANIMAL_H_ */

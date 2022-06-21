/*
 * Guard.h
 *
 *  Created on: Aug 22, 2010
 *      Author: Luke
 */

#ifndef GUARD_H_
#define GUARD_H_

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include "Shift.h"

using namespace std;

class Shift; // forward declaration

class Guard{

private:
	string name;
	int shiftsWanted;
	int shiftsLeft;
	bool available[7][4];

public:
	Shift* s;
	Guard();
	Guard(string, int);
	string getName();
	void setName(string);
	int getShiftsWanted();
	void setShiftsWanted(int) throw (out_of_range);
	int getShiftsLeft();
	void setShiftsLeft(int);
	bool getAvailable(int, int);
	void setAvailable(int, int, bool);
	void setAvailable(Shift, bool);
	void read(istream &) throw (out_of_range);
	void print(ostream &) ;

}; // Guard class

#endif /* GUARD_H_ */

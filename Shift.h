/*
 * Shift.h
 *
 *  Created on: Aug 22, 2010
 *      Author: Luke
 */

#ifndef SHIFT_H_
#define SHIFT_H_

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Guard.h"
#include "Guards.h"

using namespace std;

class Guard; // forward declaration
class Guards;

class Shift{

private:
	string shiftName;
	int day;
	int time;
	int desks;
	int desksLeft;
	bool scheduled;
	vector<string> guardNames;

public:
	Guard* g;
	Shift();
	Shift(string, int, int, int);
	string getShiftName();
	void setShiftName(string);
	int getDay();
	void setDay(int) throw ( out_of_range );
	int getTime();
	void setTime(int) throw ( out_of_range );
	int getDesks();
	void setDesks(int);
	int getDesksLeft();
	void setDesksLeft(int) throw ( out_of_range );
	bool getScheduled();
	void setScheduled(bool);
	void claimGuards(Guards &);
	int getGuardCount(Guards &);
	void addGuardName(string);
	void print(ostream &, Guards &);


}; // Shift class

#endif /* SHIFT_H_ */

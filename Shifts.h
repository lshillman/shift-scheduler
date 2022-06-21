/*
 * Shifts.h
 *
 *  Created on: Aug 22, 2010
 *      Author: Luke
 */

#ifndef SHIFTS_H_
#define SHIFTS_H_

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cmath>
#include "Shift.h"
#include "Guards.h"

using namespace std;

class Shifts
{

  public:
    Shifts();
    void add(Shift);
    void print( ostream &out, Guards &guards);
    int getMin(Guards &);
    unsigned size();
	void scheduleNextShift(Guards &);
    //~Shifts();

  private:
    vector<Shift> shifts;

}; // Shifts class

#endif /* SHIFTS_H_ */

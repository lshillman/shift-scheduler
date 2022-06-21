/*
 * Shifts.cpp
 *
 *  Created on: Aug 22, 2010
 *      Author: Luke
 */

#include "Shifts.h"

Shifts::Shifts(){
	// default constructor stub; nothing to see here...
}

void Shifts::add(Shift s){
	//Shift* sp = &s;
	shifts.push_back(s);
	//delete sp;
}

void Shifts::print( ostream &out, Guards &guards ){
	out << "Generated by Scheduler 0.1, (c) 2010 Luke Hillman, all rights reserved.\n";
	out << "This program may not be used without express written permission from Luke Hillman.\n" << endl;
	for (unsigned i = 0; i < shifts.size(); i++) {
		shifts[i].print(out, guards);
	} // for
}

int Shifts::getMin(Guards &guards){
	int min = 200;/*guards.size();*/
	for (unsigned s = 0; s < shifts.size(); s++) { // iterate through shifts
		int tally = 0;
		for (unsigned g = 0; g < guards.size(); g++){ // iterate through guards
			if ((shifts[s].getScheduled() == false) && (guards.getGuard(g)->getAvailable(shifts[s].getDay(), shifts[s].getTime()))){
				tally++;
				//cout << "incremented tally to " << tally << endl;
				//cout << "min is " << min << endl;
			}
		} // guard loop
		if (tally < min && tally != 0)
			min = tally;
	} // shift loop
	return min;
}

unsigned Shifts::size(){
	return shifts.size();
}

void Shifts::scheduleNextShift(Guards &guards){

	for (unsigned s = 0; s < shifts.size(); s++) { // iterate through shifts
		if (shifts[s].getGuardCount(guards) == getMin(guards)){
			shifts[s].claimGuards(guards);
			shifts[s].setScheduled(true);
		}
	} // shift loop

}

/*
Shifts::~Shifts(){
	cout << "Made it to the Shifts destructor..." << endl;
	for (unsigned i = 0; i < shifts.size(); i++) {
		delete shifts[i];
	}
}
*/ // Shifts used to be a vector of shift pointers.

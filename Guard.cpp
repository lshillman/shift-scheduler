/*
 * Guard.cpp
 *
 *  Created on: Aug 22, 2010
 *      Author: Luke
 */

#include "Guard.h"

Guard::Guard(){
	setName("Unnamed Guard");
	setShiftsWanted(2);
	setShiftsLeft(2);
	//setAvailable( {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0} );

	for (unsigned time = 0; time < 4; time++){
		for (unsigned day = 0; day < 7; day++){
			available[day][time] = 0;
		}
	}

}

Guard::Guard(string name, int shiftsWanted){
	setName(name);
	setShiftsWanted(shiftsWanted);
	setShiftsLeft(shiftsWanted);
	for (unsigned time = 0; time < 4; time++){
		for (unsigned day = 0; day < 7; day++){
			available[day][time] = false;
		}
	}
}

string Guard::getName(){
	return name;
}

void Guard::setName(string name){
	this->name = name;
}

int Guard::getShiftsWanted(){
	return shiftsWanted;
}

void Guard::setShiftsWanted(int shiftsWanted) throw (out_of_range){
	if (this->shiftsWanted < 2 && this->shiftsWanted > 10)
		throw out_of_range("Guard::setShiftsWanted: out of range");
	else
		this->shiftsWanted = shiftsWanted;
}

int Guard::getShiftsLeft(){
	return shiftsLeft;
}

void Guard::setShiftsLeft(int shiftsLeft){
	this->shiftsLeft = shiftsLeft;
}

bool Guard::getAvailable(int day, int time){
	return available[day][time];
}

void Guard::setAvailable(int day, int time, bool b){
	// available[s.getDay()][s.getTime()] = b; // if we're taking a shift
	available[day][time] = b;
}

void Guard::setAvailable(Shift s, bool b){
	setAvailable(s.getDay(), s.getTime(), b);
}

void Guard::read(istream &in) throw (out_of_range){

	string name;
	string shiftsWantedString;
	int shiftsWantedInt;
	getline(in, name, ',');											// read name
	getline(in, shiftsWantedString, ',');								// read shiftsWanted
	//cout << "Name: " << name << endl;
	//cout << "Shifts wanted: " << shiftsWantedString << endl;

	shiftsWantedInt = atoi(shiftsWantedString.c_str());					// convert shiftsWantedString to int
	setName(name);
	setShiftsWanted(shiftsWantedInt);
	setShiftsLeft(shiftsWantedInt);
	//cout << "Name has been set to " << getName() << endl;
	//cout << "shiftsWanted has been set to " << getShiftsWanted() << endl;
	//cout << "Shifts wanted (post-conversion): " << shiftsWantedInt << endl;
	int day = 0;

	while (day < 7){													// begin day processing loop
		// cout << "Entering while at day " << day << "..." << endl;
		string token;
		getline(in, token, ',');
		// cout << "Token has been set to " << token << endl;
		if (token != ""){
																		// move to next column
		for ( unsigned i = 0; i < ((token.length()+1)/5); i++){			// Time processing loop. start counting at i = 0, continue until i is (token.length+1)/5.

			int position = i*5;
			string stuff = token.substr(position, 4);

			if (stuff == "2000")
				setAvailable(day, 3, true);

			else if (stuff == "1600")
				setAvailable(day, 2, true);

			else if (stuff == "1200")
				setAvailable(day, 1, true);

			else if (stuff == "0800")
				setAvailable(day, 0, true);
			// cout << "leaving time processor..." << endl;
		} // End time processing loop.
		day++;
	 } // if
		else
			day++;
	} // End day processing loop.
} // Guard::read


void Guard::print(ostream &out) {
	out << "Name: " << getName() << endl;
	out << "Shifts wanted: " << getShiftsWanted() << endl;
	out << "ShiftsLeft: " << shiftsLeft << endl;
	out << "Shifts Scheduled: " << getShiftsWanted() - getShiftsLeft() << endl;
	out << "      M T W R F S S" << endl;
	for (unsigned time = 0; time < 4; time++){
		if (time == 0)
			out << "0800: ";
		else if (time == 1)
			out << "1200: ";
		else if (time == 2)
			out << "1600: ";
		else if (time == 3)
			out << "2000: ";
		for (unsigned day = 0; day < 7; day++){
			if (getAvailable(day, time) == true)
				out << "A ";
			else
				out << "  ";
		}
		out << endl;
	}
} // Guard::print()

/*
 * Shift.cpp
 *
 *  Created on: Aug 22, 2010
 *      Author: Luke
 */

#include "Shift.h"

Shift::Shift(){
	//day = 0;
	//time = 0;
	//desks = 0;
}

Shift::Shift(string shiftName, int day, int time, int desks){
	setShiftName(shiftName);
	setDay(day);
	setTime(time);
	setDesks(desks);
	setDesksLeft(desks);
	setScheduled(0);
}

string Shift::getShiftName(){
	return shiftName;
}

void Shift::setShiftName(string shiftName){
	this->shiftName = shiftName;
}

int Shift::getDay(){
	return day;
}

void Shift::setDay(int day) throw (out_of_range){
	if (day < 0 || day > 6)
		throw out_of_range ("setDay: out of range");
	else
		this->day = day;
}

int Shift::getTime(){
	return time;
}

void Shift::setTime(int time) throw (out_of_range){
	if (time < 0 || time > 3)
		throw out_of_range ("setTime: out of range");
	else
		this->time = time;
}

int Shift::getDesks(){
	return desks;
}

void Shift::setDesks(int desks) {
	if (desks < 0)
		throw out_of_range ("setDesks: out of range");
	else
		this->desks = desks;
}

int Shift::getDesksLeft(){
	return desksLeft;
}

void Shift::setDesksLeft(int desksLeft) throw (out_of_range){
	if (desksLeft > desks)
		throw out_of_range ("setDesksLeft: desksLeft exceeds total desks");
	else
		this->desksLeft = desksLeft;
}

bool Shift::getScheduled(){
	return scheduled;
}

void Shift::setScheduled(bool b){
	scheduled = b;
}

void Shift::claimGuards(Guards &guards){
	for (unsigned g = 0; g < guards.size(); g++){ // iterate through guards
		if ((getDesksLeft() > 0) && (guards.getGuard(g)->getAvailable(getDay(), getTime())) && ( guards.getGuard(g)->getShiftsLeft() > 0 ) ){
			guardNames.push_back(guards.getGuard(g)->getName());
			guards.getGuard(g)->setAvailable(getDay(), getTime(), false);
			guards.getGuard(g)->setShiftsLeft(guards.getGuard(g)->getShiftsLeft() - 1);
			setDesksLeft(getDesksLeft()-1);
		} // if
	} // guard loop
}

int Shift::getGuardCount(Guards &guards) {
	int tally = 0;
	for (unsigned g = 0; g < guards.size(); g++){ // iterate through guards
		if (guards.getGuard(g)->getAvailable(getDay(), getTime()))
			tally++;
	}
	return tally;
}

void Shift::print(ostream &out, Guards &guards){
	out << getShiftName() << endl;
	out << "Total number of Desks: " << getDesks() << endl;
	out << "Guards available for this shift: " << getGuardCount(guards) << endl;
	out << "Desks currently unfilled: " << getDesksLeft() << endl;
	if (scheduled)
		out << "Scheduling complete." << endl;
	else
		out << "Scheduling incomplete." << endl;
	out << "Guards currently assigned to this shift:" << endl;
	for (unsigned i = 0; i < guardNames.size(); i++) {
		out << i+1 << ". " << guardNames[i] << endl;
	} // for
	out << endl;
}

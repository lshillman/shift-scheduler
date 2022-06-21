/*
 * Enums.h
 *
 *  Created on: Aug 23, 2010
 *      Author: Luke
 */

#ifndef SHIFTENUMS_H_
#define SHIFTENUMS_H_

using namespace std;

enum Time {T0800, T1200, T1600, T2000};
const char* const times_str[] = {"0800", "1200", "1600", "2000"};

enum Day {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
const char* const days_str[]= {"Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Sun"};

#endif

/*
 * Guards.h
 *
 *  Created on: Aug 22, 2010
 *      Author: Luke
 */

#ifndef GUARDS_H_
#define GUARDS_H_

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cmath>
#include "Guard.h"

using namespace std;

class Guard;

class Guards
{

  public:
    Guards();
    Guards( string filename ) throw ( out_of_range, runtime_error );
    unsigned size();
    Guard* getGuard(unsigned);
    void print( ostream &out = cout );
    void read( string filename ) throw ( out_of_range, runtime_error );
    //double getTotalAge();
    ~Guards();

  private:
    vector<Guard *> guards;

}; // Guards class



#endif /* GUARDS_H_ */

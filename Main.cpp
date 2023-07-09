//
// Shift Scheduler
// by Luke Hillman
// 
// This program reads a CSV of employee availabilities for a series
// of predefined shifts, and then allocates employees to each shift
// beginning with the most difficult shift to fill. Originally written
// for use at Georgetown University's Department of Public Safety.
//

#include "Main.h"



int main() {

	cout << "Scheduler 0.1\n(c) 2010 Luke Hillman, all rights reserved." << endl;
	cout << "This program may not be used without express\nwritten permission from Luke Hillman.\n" << endl;
	cout << "Press enter to continue..." << endl;
	cin.get();

try{
	//cout << "Scheduler 0.1\n(c) 2010 Luke Hillman, all rights reserved.\n" << endl;

	Shift mon0800("Monday 0800-1200", 0, 0, 14);
	Shift mon1200("Monday 1200-1600", 0, 1, 15);
	Shift mon1600("Monday 1600-2000", 0, 2, 12);
	Shift mon2000("Monday 2000-0000", 0, 3, 12);

	Shift tue0800("Tuesday 0800-1200", 1, 0, 14);
	Shift tue1200("Tuesday 1200-1600", 1, 1, 15);
	Shift tue1600("Tuesday 1600-2000", 1, 2, 12);
	Shift tue2000("Tuesday 2000-0000", 1, 3, 12);

	Shift wed0800("Wednesday 0800-1200", 2, 0, 14);
	Shift wed1200("Wednesday 1200-1600", 2, 1, 15);
	Shift wed1600("Wednesday 1600-2000", 2, 2, 12);
	Shift wed2000("Wednesday 2000-0000", 2, 3, 12);

	Shift thu0800("Thursday 0800-1200", 3, 0, 14);
	Shift thu1200("Thursday 1200-1600", 3, 1, 15);
	Shift thu1600("Thursday 1600-2000", 3, 2, 12);
	Shift thu2000("Thursday 2000-0000", 3, 3, 12);

	Shift fri0800("Friday 0800-1200", 4, 0, 14);
	Shift fri1200("Friday 1200-1600", 4, 1, 15);
	Shift fri1600("Friday 1600-2000", 4, 2, 12);
	Shift fri2000("Friday 2000-0000", 4, 3, 12);

	Shift sat0800("Saturday 0800-1200", 5, 0, 15);
	Shift sat1200("Saturday 1200-1600", 5, 1, 15);
	Shift sat1600("Saturday 1600-2000", 5, 2, 13);
	Shift sat2000("Saturday 2000-0000", 5, 3, 13);

	Shift sun0800("Sunday 0800-1200", 6, 0, 15);
	Shift sun1200("Sunday 1200-1600", 6, 1, 15);
	Shift sun1600("Sunday 1600-2000", 6, 2, 13);
	Shift sun2000("Sunday 2000-0000", 6, 3, 13);

	/* Tests...
	Shift wed1600("Wednesday 1600-2000", 2, 2, 10);
	Shift mon2000("Monday 2000-0000", 0, 3, 10);
	Shift thu0800("Thursday 0800-1200", 3, 0, 10);
	Shift mon1200("Monday 1200-1600", 0, 1, 10);
	Shift tue2000("Tuesday 2000-0000", 1, 3, 10);
	Shift sat1200("Saturday 1200-1600", 5, 1, 10);
	Shift sun0800("Sunday 0800-1200", 6, 0, 10);

	Shifts shifts;
	shifts.add(wed1600);
	shifts.add(mon2000);
	shifts.add(thu0800);
	shifts.add(mon1200);
	shifts.add(tue2000);
	shifts.add(sat1200);
	shifts.add(sun0800);
	*/

	Shifts shifts;
	shifts.add(mon0800);
	shifts.add(mon1200);
	shifts.add(mon1600);
	shifts.add(mon2000);

	shifts.add(tue0800);
	shifts.add(tue1200);
	shifts.add(tue1600);
	shifts.add(tue2000);

	shifts.add(wed0800);
	shifts.add(wed1200);
	shifts.add(wed1600);
	shifts.add(wed2000);

	shifts.add(thu0800);
	shifts.add(thu1200);
	shifts.add(thu1600);
	shifts.add(thu2000);

	shifts.add(fri0800);
	shifts.add(fri1200);
	shifts.add(fri1600);
	shifts.add(fri2000);

	shifts.add(sat0800);
	shifts.add(sat1200);
	shifts.add(sat1600);
	shifts.add(sat2000);

	shifts.add(sun0800);
	shifts.add(sun1200);
	shifts.add(sun1600);
	shifts.add(sun2000);

	Guards guards;
	guards.read("guards.csv");
//	guards.print(cout);

//	shifts.print(cout, guards);

	unsigned i = 0;
	while(i < shifts.size()){
	shifts.scheduleNextShift(guards);
	i++;
	}

	ofstream guardfile;
	guardfile.open("guards.txt");
	guards.print(guardfile);
	guardfile.close();

	ofstream shiftfile;
	shiftfile.open("shifts.txt");
	shifts.print(shiftfile, guards);
	shiftfile.close();

	cout << "Program complete. Schedule has been written to shifts.txt.\nGuard information has been written to guards.txt." << endl;

//	shifts.print(cout, guards);



}
catch (out_of_range &e){
	cerr << e.what() << endl;
}

catch (runtime_error &e){
	cerr << e.what() << endl;
}

catch (...){
	cerr << "Caught some kind of exception" << endl;
}

	return 0;
}

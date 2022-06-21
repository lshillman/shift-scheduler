# C++ shift scheduler

In a previous role, I managed about 170 student security guards. Each semester, I was responsible for collecting their availability and producing a schedule for them. By hand, the scheduling took over a week of full-time work, on top of all the other managerial stuff. After doing it once, I vowed: never again.

The program uses an object-oriented approach to calculate schedules. The two objects involved are ‘Shifts’ and ‘Guards’. Each shift has a time, a number of desks, and a desirability ranking. Each guard has a name, an array of availability, and a maximum number of shifts per week they would like to work.

At runtime, the user provides the guards’ names, availabilities, and max desired shifts via a CSV (I was particularly proud of my pipeline here; I had all employees submit their information through a google form, and then just used the resulting CSV). Each shift’s desirability is then set to the number of guards available for that shift. Then, the shift with the lowest desirability claims all the guards it needs (or all the guards it can, depending). All affected guards’ desired shifts per week are decremented. The process is repeated by the next-least-desirable shift, and so on, with guards being taken out of the available pool as their maximum desired shifts hits zero.

The final output is 1) a list of all shifts and the guards assigned to them, 2) a list of any shifts that were not able to be completely filled, and 3) a list of all guards and their remaining availability after scheduling.

# To run:
Download the files in this repository and compile.

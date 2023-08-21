//
// Created by Edgar Pena on July 7, 2023.
// CS-210
//

#ifndef PROJECTONE_CLOCK_H
#define PROJECTONE_CLOCK_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
//Clock class declaration
class Clock
{
private:
    //structure to store time
    struct tm * localTime;
    //private member variables to store hours, minutes, seconds added to the clock
    int d_hours;
    int d_mins;
    int d_secs;
    bool format_24;  //flag to store if the clock is set to 24-hour format or not
public:
    //flag to store if the clock is set to 24-hour format or not
    explicit Clock(bool format_24);
    //call all the methods
    void addHours(int hours);    //Method to add hours to the clock
    void addMinutes(int mins);   //Method to add minutes to the clock
    void addSeconds(int secs);   //Method to add seconds to the clock
    void resetClock();    //Method to reset the clock
    void displayTime(ostream &out);   //Method to display the time
};


#endif //PROJECTONE_CLOCK_H

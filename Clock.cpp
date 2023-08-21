//
// Created by Edgar Pena on July 7, 2023.
// CS-210
//

#include "Clock.h"

// Constructor initializes the object with the current time and the format (12 hour or 24 hour)
Clock::Clock(bool format_24)
{
    // Initialize the time and local time
    time_t seconds = time(0);
    localTime = localtime(&seconds);
    d_hours = 0;
    d_secs = 0;
    d_mins = 0;
    //access class, structure or union members using a pointer
    this->format_24 = format_24;
}
// Function to add hours to the clock
void Clock::addHours(int hours)
{
    d_hours +=hours;   // Add the given number of hours to the hour offset
}
// Function to add minutes to the clock
void Clock::addMinutes(int mins)
{
    d_mins += mins;  // Add the given number of minutes to the minute offset

}
// Function to add seconds to the clock
void Clock::addSeconds(int secs)
{
    d_secs += secs;  // Add the given number of seconds to the second offset
}

// Function to reset the clock
void Clock::resetClock()
{
    // Set the hour, minute, and second offsets to 0
    d_hours = 0;
    d_secs = 0;
    d_mins = 0;
}
// Function to display the time
void Clock::displayTime(ostream &out)
{
    int seconds=0,minutes=0,hours=0;
    seconds = localTime->tm_sec + d_secs;  // Calculate the total number of seconds
    minutes += (seconds/60);   // Calculate the total number of minutes
    seconds = seconds%60;   // Get the remaining seconds

    minutes += localTime->tm_min + d_mins;  // Add the minutes offset to the total number of minutes
    hours += minutes/60;   // Calculate the total number of hours
    minutes = minutes%60; // Get the remaining minutes

    // Add the hour offset to the total number of hours, and take the modulus with 24 to handle overflow
    hours = (hours+localTime->tm_hour + d_hours)%24;

    // Output the time in the specified format
    string timestr ="";
    out<<setw(2)<<setfill('0')<<(format_24?hours:(hours%12))<<":";
    out<<setw(2)<<setfill('0')<<minutes<<":";
    out<<setw(2)<<setfill('0')<<seconds<<" ";
    // If the time format is 12-hour, add AM or PM as appropriate
    if(!format_24)
    {
        if(hours>12)
        {
            out<<"PM";
        }
        else
        {
            out<<"AM";
        }
    }
}

//
// Created by Edgar Pena on July 7, 2023.
// CS-210
//

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class Clock
{
private:
    struct tm * localTime;  // Structure to store time
    int d_hours;  // Hours added to the clock
    int d_mins;  // Minutes added to the clock
    int d_secs;  // Seconds added to the clock
    bool format_24;  // Flag to store the clock format (24-hour or not)

public:
    Clock(bool format_24);  // Constructor to set the clock format
    void addHours(int hours);  // Method to add hours to the clock
    void addMinutes(int mins);  // Method to add minutes to the clock
    void addSeconds(int secs);  // Method to add seconds to the clock
    void resetClock();  // Method to reset the clock
    void displayTime(ostream &out);  // Method to display the time
};

int main()
{
    Clock clock12(false);  // Clock in 12-hour format
    Clock clock24(true);  // Clock in 24-hour format
    int choice;
    bool exit = false;  // Variable to keep track of whether the program should exit or not

    while (!exit)
    {
        cout << endl;
        cout << "**************** ****************" << endl;
        cout << "* " << setw(12);
        clock12.displayTime(cout);  // Displaying the time of the 12-hour clock
        cout << "  * ";
        cout << "* " << setw(12);
        clock24.displayTime(cout);  // Displaying the time of the 24-hour clock
        cout << "\t*" << endl;
        cout << "**************** ****************" << endl;
        cout << endl;

        cout << "Menu:" << endl;
        cout << "1 - Add One Hour" << endl;
        cout << "2 - Add One Minute" << endl;
        cout << "3 - Add One Second" << endl;
        cout << "4 - Exit" << endl;

        cin >> choice;  // User choice

        switch (choice)
        {
            case 1:
                clock12.addHours(1);
                clock24.addHours(1);
                break;
            case 2:
                clock12.addMinutes(1);
                clock24.addMinutes(1);
                break;
            case 3:
                clock12.addSeconds(1);
                clock24.addSeconds(1);
                break;
            case 4:
                exit = true;  // Setting the exit flag to true to exit the program
                break;
            default:
                break;
        }
    }

    return 0;
}

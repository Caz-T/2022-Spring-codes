
#include <iostream>
#include <string>
#include "calendar.h"
using namespace std;

int main()
{
    calendar a;
    string command;
    while (true)
    {
        cout << "Input command (help for manual): ";
        cin >> command;
        system("cls");
        if (command == "exit") break;
        else if (command == "help")
        {
            cout << R"(
All supported commands:

diff        Calculates the time difference from a certain date to the saved date
exit        Exits the programme
future      Calculates the date after a given interval
help        Shows this page
reset       Resets the date to system date
set         Sets the date to another date
show        Shows the saved date)";
        }
        else if (command == "show") a.showdate();
        else if (command == "diff")
        {
            int x = 0, y = 0, z = 0;
            while(true)
            {
                cout << "Input a date in YYYY MM DD format: ";
                cin >> x >> y >> z;
                if (a.is_valid(x, y, z)) break;
                cout << "INVALID DATE!\n";
            }
            a.show_date_diff(x, y, z);
        }
        else if (command == "reset") a.reset();
        else if (command == "set")
        {
            int x = 0, y = 0, z = 0;
            while(true)
            {
                cout << "Input a date in YYYY MM DD format: ";
                cin >> x >> y >> z;
                if (a.is_valid(x, y, z)) break;
                cout << "INVALID DATE!\n";
            }
            a.setdate(x, y, z);
            a.showdate();
        }
        else if (command == "future")
        {
            cout << "Input a time interval: ";
            int interval;
            cin >> interval;
            a.show_date_after(interval);
        }
        else
        {
            cout << "Wrong command!" << endl;
        }
        cout << endl << endl << "Press ENTER to continue" << endl;
        getchar();
        getchar();
        system("cls");
    }
    return 0;
}

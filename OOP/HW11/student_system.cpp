//
// Created by Chen Qingzhi on 2022/5/15.
//

#include "student_system.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

student_system::student_system()
{
    int command;
    while (true)
    {
        cout << R"(
STUDENT SCORE MANAGEMENT SYSTEM
-------------------------------
    INPUT A COMMAND(1~8) BELOW
        INPUT 0 FOR HELP
        INPUT -1 TO QUIT
)";
        cin >> command;
        string tempstr;
        long long templl;
        int tempint;
        switch(command)
        {
            case 1:
                cout << "Provide a path from which to read data: ";
                cin >> tempstr;
                while (!read_file(tempstr))
                {
                    cout << "Error in opening file!\nProvide another path from which to read data: ";
                    cin >> tempstr;
                }
                cout << "Data read from file!" << endl;
                break;
            case 2:
                cout << "Provide a student number and a score: ";
                cin >> templl >> tempint;
                if (students.find(templl) != students.end())
                {
                    cout << "Record already exists: Student " << templl << " has score "
                         << students.find(templl)->second << "\nDo you wish to alter their score instead? (Y/[N])\n";
                    cin.clear();
                    if (getchar() != 'Y') break;
                }
                students[templl] = tempint;
                cout << "Entry created!" << endl;
                break;
            case 3:
                cout << "Provide a student number: ";
                cin >> templl;
                if (students.find(templl) == students.end()) cout << "No record found with Student " << templl << endl;
                else
                {
                    students.erase(templl);
                    cout << "Entry deleted!" << endl;
                }
                break;
            case 4:
                cout << "About to erase all data. Are you sure to proceed? (Y/[N])" << endl;
                cin.clear();
                if (getchar() == 'Y')
                {
                    students.clear();
                    cout << "All data erased!" << endl;
                }
                break;
            case 5:
                cout << "Provide a student number and a score: ";
                cin >> templl >> tempint;
                if (students.find(templl) == students.end())
                {
                    cout << "No record found with Student " << templl
                         << "\n Do you wish to create a new entry? (Y/[N])\n";
                    cin.clear();
                    if (getchar() != 'Y') break;
                }
                students[templl] = tempint;
                break;
            case 6:
                cout << "Provide a student number: ";
                cin >> templl;
                if (students.find(templl) != students.end()) cout << "Student " << templl << " has score " << students.find(templl)->second << endl;
                else cout << "No record found with Student " << templl;
                break;
            case 7:
                cout << R"(
    SHOWING ALL RECORDS
Student No.         Score
)";
                for (auto & stu : students)
                {
                    cout.width(20);
                    cout.fill(' ');
                    cout << stu.first << stu.second << endl;
                }
                break;
            case 8:
                cout << "Provide a path to which records are to be saved: ";
                cin >> tempstr;
                while (!write_file(tempstr))
                {
                    cout << "Error in opening file!\nProvide another path to which records are to be saved: ";
                    cin >> tempstr;
                }
                cout << "Data written to file!" << endl;
                break;
            case -1:
                cout << "Quitting the system!\nDo you want to save current records to external files? ([Y]/N)" << endl;
                cin.clear();
                if (getchar() != 'N')
                {
                    cout << "Provide a path to which records are to be saved: ";
                    cin >> tempstr;
                    while (!write_file(tempstr))
                    {
                        cout << "Error in opening file!\nProvide another path to which records are to be saved: ";
                        cin >> tempstr;
                    }
                }
                cout << "Thanks for using Student Management System!\nPress ENTER to quit...";
                getchar();
                return;
        }
        cout << "\n\nPress ENTER to continue...";
        getchar();
        cin.clear();
        system("clear");
    }
}

bool student_system::read_file(string& path)
{
    ifstream infile(path);
    if (infile.fail()) return false;
    long long templl;
    int tempint;
    int mode = 0;
    infile >> templl >> tempint;
    while (!infile.eof())
    {
        if (students.find(templl) == students.end()) students[templl] = tempint;
        else
        {
            switch(mode)
            {
                case 0:
                    cout << "Conflict for student " << templl << ":\nCurrent record: score " << students[templl]
                         << "\nFrom file:      score " << tempint << endl;
                    cout << "How to solve this conflict? (Default = use current)\n";
                    cout << "(use [C]urrent / update from [F]ile / always [S]kip / always [U]pdate): ";
                    switch(getchar())
                    {

                        case 'S':
                            cout << "Skipping records without asking.\n";
                            mode = 1;
                        case 'C':
                        default:
                            cout << "Record skipped!" << endl;
                            break;
                        case 'U':
                            cout << "Updating records without asking.\n";
                            mode = 2;
                        case 'F':
                            students[templl] = tempint;
                            cout << "Record updated!" << endl;
                            break;
                    }
                    break;
                case 1:
                    break;
                case 2:
                    students[templl] = tempint;
                    break;
            }
        }
        infile >> templl >> tempint;
    }
    infile.close();
    return true;
}

bool student_system::write_file(string & path)
{
    ofstream outfile;
    outfile.open(path, ios_base::out | ios_base:: trunc);
    if (outfile.fail()) return false;
    for (auto& stu : students) outfile << stu.first << ' ' << stu.second << endl;
    outfile.close();
    return true;
}
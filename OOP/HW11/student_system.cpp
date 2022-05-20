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
        cout << R"(STUDENT SCORE MANAGEMENT SYSTEM
-------------------------------
  INPUT A COMMAND(1~8) BELOW
      INPUT 0 FOR HELP
      INPUT -1 TO QUIT
)";
        cin >> command;
        system("cls");
        cout << R"(STUDENT SCORE MANAGEMENT SYSTEM
-------------------------------
)";
        string tempstr;
        long long templl;
        int tempint;
        switch(command)
        {
            case 1:
                cout << "Provide a path from which to read data: ";
                cin >> tempstr;
                while (tempstr != "CANCEL" and !read_file(tempstr))
                {
                    cout << "Error in opening file!\nProvide another path from which to read data, or type in CANCEL: ";
                    cin >> tempstr;
                }
                if (tempstr != "CANCEL") cout << "Data read from file!" << endl;
                break;
            case 2:
                cout << "Provide a student number and a score: ";
                cin >> templl >> tempint;
                if (students.find(templl) != students.end())
                {
                    cout << "Record already exists: Student " << templl << " has score "
                         << students.find(templl)->second << "\nDo you wish to alter their score instead? (Y/[N])\n";
                    clrscr();
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
                clrscr();
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
                    clrscr();
                    if (getchar() != 'Y') break;
                }
                students[templl] = tempint;
                cout << "Entry updated!" << endl;
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
                    cout << left;
                    cout << stu.first << stu.second << endl;
                }
                break;
            case 8:
                cout << "Provide a path to which records are to be saved: ";
                cin >> tempstr;
                while (tempstr != "CANCEL" and !write_file(tempstr))
                {
                    cout << "Error in opening file!\nProvide another path to which records are to be saved, or type in CANCEL: ";
                    cin >> tempstr;
                }
                if (tempstr != "CANCEL") cout << "Data written to file!" << endl;
                break;
            case 0:
                cout << R"(1   Read in data from a file.
    Should conflicts occur, for each conflict, we will ask you whether to leave the data unmodified or to update it.
    You can also specify the default action at any time.
2   Create a new record.
    If a record exists with that number, we will ask you whether to leave the data unmodified or to update it.
3   Delete a record.
    If such record does not exist, this does nothing.
4   Delete all records. THIS COULD BE DANGEROUS.
    We recommend you save first. We will also do a double-check before actually clearing all data.
5   Modify a record by student's id number.
    If such record does not exist, we will ask you whether to create a new record.
6   Show the score of the student of a given id number.
    We will tell you if such doesn't exist.
7   Show all records.
8   Save all records to a given file.
    Note that this overwrites all data in that file.
    If such file doesn't exist, we will create one first.
-1  Quit the programme.
    We will ask whether you want to save the data.
    )";
                break;
            case -1:
                cout << "Quitting the system!" << endl << endl;
                cout << R"(
    SHOWING ALL RECORDS
Student No.         Score

)";
                for (auto& stu : students)
                {
                    cout.width(20);
                    cout.fill(' ');
                    cout << left;
                    cout << stu.first << stu.second << endl;
                }
                cout << "Do you want to save the records above to external files? ([Y]/N)";
                clrscr();
                if (getchar() != 'N')
                {
                    cout << "Provide a path to which records are to be saved: ";
                    cin >> tempstr;
                    while (tempstr != "CANCEL" and !write_file(tempstr))
                    {
                        cout << "Error in opening file!\nProvide another path to which records are to be saved, or type in CANCEL: ";
                        cin >> tempstr;
                    }
                }
                cout << "Thanks for using Student Management System!\nPress ENTER to quit...";
                clrscr();
                getchar();
                return;
        }
        clrscr("\nPress ENTER to continue");
        getchar();
        system("cls");
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
            if (students[templl] == tempint) students[templl] = tempint;
            else
            {
                switch (mode)
                {
                case 0:
                    cout << "Conflict for student " << templl << ":\nCurrent record: score " << students[templl]
                        << "\nFrom file:      score " << tempint << endl;
                    cout << "How to solve this conflict? (Default = use current)\n";
                    cout << "(use [C]urrent / update from [F]ile / always [S]kip / always [U]pdate): ";
                    clrscr();
                    switch (getchar())
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

void student_system::clrscr(string msg)
{
    if (getchar() != '\n') cout << "Error occurred!" << endl;
    cout << msg;
}
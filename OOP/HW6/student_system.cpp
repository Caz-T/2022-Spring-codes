//
// Created by Chen Qingzhi on 2022/3/29.
//

#include "student_system.h"
#include <iostream>
using namespace std;

student_system::student_system()
{
    int command = 0;
    while (command != -1)
    {
        cout << "Input code: ";
        cin >> command;
        long long tempid;
        unsigned int tempscore;
        bool flag;
        node* temp = data.head()->next;
        switch (command)
        {
            case 1:
                cout << "Input students' ID and score:" << endl;
                while (true)
                {
                    cin >> tempid;
                    if (tempid == 0) break;
                    cin >> tempscore;
                    data.add_node(student(tempid, tempscore));
                }
                break;
            case 2:
                cout << "Input an id: ";
                cin >> tempid;
                while (temp->id() != tempid and temp != data.head()) temp = temp->next;
                if (temp == data.head()) cout << "No student with ID " << tempid;
                else
                {
                    cout << "Student deleted with ID " << tempid << " and score " << temp->score() << endl;
                    double_list::delete_node(temp);
                }
                break;
            case 3:
                cout << "Input a score, data with which score are subject to removal: ";
                cin >> tempscore;
                while (temp != data.head())
                {
                    if (temp->score() == tempscore)
                    {
                        cout << "Student deleted with ID " << temp->id() << " and score " << tempscore << endl;
                        node* to_delete = temp;
                        temp = temp->next;
                        double_list::delete_node(to_delete);
                    }
                    else temp = temp->next;
                }
                break;
            case 4:
                cout << "Input an ID: ";
                cin >> tempid;
                while (temp != data.head() and temp->id() != tempid) temp = temp->next;
                if (temp == data.head()) cout << "No student with ID " << tempid << endl;
                else cout << "Student with ID " << tempid << " has score " << temp->score() << endl;
                break;
            case 5:
                flag = false;
                cout << "Input a score, data with which score are subject to demonstration: ";
                cin >> tempscore;
                cout << "Students with score " << tempscore << " have ID ";
                while (temp != data.head())
                {
                    if (temp->score() == tempscore)
                    {
                        if (flag) cout << ", ";
                        flag = true;
                        cout << temp->id();
                    }
                    temp = temp->next;
                }
                if (!flag) cout << "NONE!";
                cout << endl;
                break;
            case 6:
                while (temp != data.head())
                {
                    cout << "ID: " << temp->id() << ", score: " << temp->score() << endl;
                    temp = temp->next;
                }
                break;
            case -1:
                break;
            default:
                cout << "Wrong code! " << endl;
        }
    }
}
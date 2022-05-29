//
// Created by Chen Qingzhi on 2022/5/29.
//

#include "student_system.h"
#include "factory.h"
#include <iostream>
using namespace std;

void student_system::run()
{
    factory<student> fact;
    int command = 0;
    while (command != -1)
    {
        cout << "Input code: ";
        cin >> command;
        long long tempid;
        unsigned int tempscore;
        bool flag;
        student* temp = data.head()->next;
        switch (command)
        {
            case 1:
                cout << "Input students' ID and score, ending with 0:" << endl;
                while (true)
                {
                    cin >> tempid;
                    if (tempid == 0) break;
                    cin >> tempscore;
                    student* tempstu = fact.get_node();
                    tempstu->set_id(tempid);
                    tempstu->set_score(tempscore);
                    data.add_node(tempstu);
                }
                break;
            case 2:
                cout << "Input an id: ";
                cin >> tempid;
                while (temp->id() != tempid and temp != data.head()) temp = temp->next;
                if (temp == data.head()) cout << "No student with ID " << tempid << endl;
                else
                {
                    cout << "Student deleted with ID " << tempid << " and score " << temp->score() << endl;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    fact.recycle_node(temp);
                }
                break;
            case 3:
                cout << "Input a score, data with which score are subject to removal: ";
                cin >> tempscore;
                flag = true;
                while (temp != data.head())
                {
                    if (temp->score() == tempscore)
                    {
                        cout << "Student deleted with ID " << temp->id() << " and score " << tempscore << endl;
                        student* to_delete = temp;
                        temp = temp->next;
                        to_delete->prev->next = to_delete->next;
                        to_delete->next->prev = to_delete->prev;
                        fact.recycle_node(to_delete);
                        flag = false;
                    }
                    else temp = temp->next;
                }
                if (flag) cout << "No student with score " << tempscore << endl;
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
                if (data.empty()) cout << "No data!" << endl;
                else
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

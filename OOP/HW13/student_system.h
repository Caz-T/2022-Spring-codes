//
// Created by Chen Qingzhi on 2022/5/29.
//

#ifndef HW13_STUDENT_SYSTEM_H
#define HW13_STUDENT_SYSTEM_H

#include "double_list.h"
#include "student.h"
class student_system
{
public:
    student_system() = default;
    ~student_system() = default;

    void run();

private:
    double_list<student> data;
};


#endif //HW13_STUDENT_SYSTEM_H

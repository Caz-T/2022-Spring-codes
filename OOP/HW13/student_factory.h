//
// Created by Chen Qingzhi on 2022/5/29.
//

#ifndef HW13_STUDENT_FACTORY_H
#define HW13_STUDENT_FACTORY_H

#include "double_list.h"
#include "student.h"

class student_factory
{
public:
    student_factory() = default;
    ~student_factory() = default;
    student* get_student();
    void recycle_student(student*);

private:
    double_list<student> stock;

};



#endif //HW13_STUDENT_FACTORY_H

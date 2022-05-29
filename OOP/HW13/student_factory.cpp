//
// Created by Chen Qingzhi on 2022/5/29.
//

#include "student_factory.h"

student *student_factory::get_student()
{
    if (stock.empty())
    {
        auto product = new student;
        return product;
    }
    else
    {
        auto product = stock.head()->next;
        return product;
    }
}

void student_factory::recycle_student(student * another)
{
    stock.add_node(another);
}

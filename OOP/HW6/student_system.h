//
// Created by Chen Qingzhi on 2022/3/29.
//

#ifndef HW6_STUDENT_SYSTEM_H
#define HW6_STUDENT_SYSTEM_H

#include "double_list.h"


class student_system {
public:
    student_system();
    ~student_system() = default;

    /*
    void add_student();
    void remove_student_by_id(long long id);
    void remove_student_by_score(unsigned int score);
    void query_by_id(long long id);
    void query_by_score(unsigned int score, node* starting_point);
    void showall();
     */

private:
    double_list data;
};


#endif //HW6_STUDENT_SYSTEM_H

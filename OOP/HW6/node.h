//
// Created by Chen Qingzhi on 2022/3/29.
//

#ifndef HW6_NODE_H
#define HW6_NODE_H

#include "student.h"

class node {
public:
    node(const student& stu, node * p, node * n): data(stu), prev(p), next(n){};
    ~node() = default;

    long long id() const;
    unsigned int score() const;
    node* prev;
    node* next;

private:
    student data;

};


#endif //HW6_NODE_H

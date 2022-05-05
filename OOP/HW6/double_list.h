//
// Created by Chen Qingzhi on 2022/4/2.
//

#ifndef HW6_DOUBLE_LIST_H
#define HW6_DOUBLE_LIST_H

#include "node.h"

class double_list
{
public:
    double_list();
    ~double_list();

    node* add_node(const student&);
    static void delete_node(node*);
    node* head();

private:
    node sentinel;
};


#endif //HW6_DOUBLE_LIST_H

//
// Created by Chen Qingzhi on 2022/5/29.
//

#ifndef HW13_FACTORY_H
#define HW13_FACTORY_H

#include "double_list.h"

template <typename node>
class factory
{
public:
    factory<node>() = default;
    ~factory<node>() = default;
    node* get_node();
    void recycle_node(node*);

private:
    double_list<node> stock;
};

template <typename node>
node* factory<node>::get_node()
{
    node* product = nullptr;
    product = stock.empty() ? new node : stock.head()->next;
    return product;
}

template <typename node>
void factory<node>::recycle_node(node * another)
{
    stock.add_node(another);
}

#endif //HW13_FACTORY_H

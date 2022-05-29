//
// Created by Chen Qingzhi on 2022/4/2.
//
/*
#include <new>
#include "double_list.h"

template <typename node>
double_list<node>::double_list() : sentinel(node(), &sentinel, &sentinel) {}

template <typename node>
double_list<node>::~double_list()
{
    node* curr = &sentinel;
    node* temp;
    while (curr->next != &sentinel)
    {
        temp = curr;
        curr = curr->next;
        if (temp != &sentinel) delete temp;
    }
}

template <typename node>
node* double_list<node>::add_node(const node * another)
{
    node* lugar = sentinel.next;
    while (*lugar < another and lugar != &sentinel) lugar = lugar->next;
    lugar = lugar->prev;
    lugar->next = another;
    another->next->prev = another;
    return another;
}

template <typename node>
void double_list<node>::delete_node(node * lugar)
{
    lugar->prev->next = lugar->next;
    lugar->next->prev = lugar->prev;
    delete lugar;
}

template <typename node>
node* double_list<node>::head() {return &sentinel;}

template<typename node>
long long double_list<node>::length()
{
    node* probe = sentinel.next;
    if (probe == sentinel) return 0;
    long long count = 1;
    while (probe != sentinel)
    {
        probe = probe->next;
        count ++;
    }
    return count;
}

template<typename node>
bool double_list<node>::empty()
{
    return sentinel.next == sentinel;
}
*/
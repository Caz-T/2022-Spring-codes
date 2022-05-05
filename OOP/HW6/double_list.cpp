//
// Created by Chen Qingzhi on 2022/4/2.
//

#include <new>
#include "double_list.h"

double_list::double_list() : sentinel(student(0, 0), &sentinel, &sentinel) {}
double_list::~double_list()
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

node* double_list::add_node(const student & another)
{
    node* lugar = sentinel.next;
    while (lugar->id() < another.id and lugar != &sentinel) lugar = lugar->next;
    lugar = lugar->prev;
    node* temp = new (std::nothrow) node(another, lugar, lugar->next);
    if (temp == nullptr) return nullptr;
    lugar->next = temp;
    temp->next->prev = temp;
    return temp;
}

void double_list::delete_node(node * lugar)
{
    lugar->prev->next = lugar->next;
    lugar->next->prev = lugar->prev;
    delete lugar;
}

node* double_list::head() {return &sentinel;}
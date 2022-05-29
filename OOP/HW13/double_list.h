//
// Created by Chen Qingzhi on 2022/4/2.
//

#ifndef HW6_DOUBLE_LIST_H
#define HW6_DOUBLE_LIST_H

template <typename node>
class double_list
{
public:
    double_list();
    ~double_list();

    node* add_node(node*);
    static void delete_node(node*);
    node* head();
    long long length();
    bool empty();

private:
    node sentinel;
};

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
node* double_list<node>::add_node(node * another)
{
    node* lugar = sentinel.next;
    while (*lugar < *another and lugar != &sentinel) lugar = lugar->next;
    another->next = lugar;
    lugar = lugar->prev;
    another->prev = lugar;
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
    if (probe == &sentinel) return 0;
    long long count = 1;
    while (probe != &sentinel)
    {
        probe = probe->next;
        count ++;
    }
    return count;
}

template<typename node>
bool double_list<node>::empty()
{
    return sentinel.next == &sentinel;
}


#endif //HW6_DOUBLE_LIST_H

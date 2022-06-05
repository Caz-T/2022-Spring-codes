//
// Created by Chen Qingzhi on 2022/6/5.
//

#include "union_doubleint.h"
#include <iostream>
#include <bitset>
using namespace std;

void gb_show_bin_memory(const union_doubleint& t)
{
    cout << t.double_value;
    cout << "在内存当中存储的数据是" << bitset<sizeof(union_doubleint) * 8>(t.ll_value) << endl;
}

void gb_test()
{
    union_doubleint u(0.0f);
    u.double_value = 0.0f / u.double_value;
    gb_show_bin_memory(u);
}
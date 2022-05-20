//
// Created by Chen Qingzhi on 2022/5/20.
//
#include "exceptions.h"
using namespace std;

EXC_bad_char::EXC_bad_char(int pos, char ch) : first_position(pos), bad_character(ch) {}
EXC_unexpected_zero::EXC_unexpected_zero(int cnt) : zero_count(cnt) {}
EXC_minus::EXC_minus(int pos) : position(pos) {}

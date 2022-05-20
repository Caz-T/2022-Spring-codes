//
// Created by Chen Qingzhi on 2022/5/20.
//

#ifndef HW12_EXCEPTIONS_H
#define HW12_EXCEPTIONS_H

#include <exception>
#include <vector>
using namespace std;

class EXC_bad_char : public exception
{
public:
    EXC_bad_char(int, char); // throw position and the character itself
    int first_position;
    char bad_character;
};

class EXC_decimal : public exception
{
public:
    EXC_decimal() = default;
};

class EXC_overflow : public exception
{
public:
    EXC_overflow() = default;
};

class EXC_unexpected_zero : public exception
{
public:
    explicit EXC_unexpected_zero(int); // throw count of consecutive zeros
    int zero_count;
};

class EXC_minus_zero : public exception
{
public:
    EXC_minus_zero() = default;
};

class EXC_minus : public exception
{
public:
    explicit EXC_minus(int); // throw position
    int position;
};
#endif //HW12_EXCEPTIONS_H

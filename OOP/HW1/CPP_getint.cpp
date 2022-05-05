#include "CPP_getint.h"
#include <iostream>
namespace customconst
{
    const long long INF = 2147483647;
    const long long big_prime = 1000000007;
}
short customdata::cpp_int::set_num(long long to_change)
{
    if (to_change >= customconst::INF or to_change <= -customconst::INF - 1) return 1;
    value = to_change;
    return 0;
}
int customdata::cpp_int::get_value() const
{
    return value;
}
bool customdata::cpp_int::read_num()
{
    char* input_str = new char[100];
    long long val = -customconst::INF - 1;
    while (set_num(val))
    {
        val = 0;
        std::cout << "Input a number: ";
        std::cin >> input_str;
        int i = input_str[0] == '-' ? 1 : 0;
        char ch = input_str[i];
        if (ch == 0)
        {
            delete[] input_str;
            return false;
        }
        while (ch)
        {
            if (ch < 48 or ch > 57)
            {
                delete[] input_str;
                return false;
            }
            val *= 10;
            val += (ch - 48);
            i++;
            ch = input_str[i];
        }
        if (input_str[0] == '-') val = -val;
    }
    delete[] input_str;
    return true;
}
long long customdata::cpp_int::calculate_positive_smaller_even_num(int method_type) const
{
    if (value <= 0) return 0;
    long long ans = 0;
    long long temp = value >> 1;
    switch (method_type) {
        case 0:
            return (temp * (temp + 1));
        case 1:
            temp++;
            while (temp--) ans += temp;
            return ans << 1;
        default:
            return -1;
    }
}
void test(long long upper_limit)
{
    std::cout << "<-----This part is for verification only----->" << std::endl;
    long long i = 0;
    long long step = 1073741824;
    customdata::cpp_int test;
    while (true)
    {
        test.set_num(i);
        long long method_0 = test.calculate_positive_smaller_even_num(), method_1 = test.calculate_positive_smaller_even_num(1);
        if (i > upper_limit or method_0 != method_1)
        {
            if (step > 1)
            {
                i -= step;
                step = step >> 1;
            }
            else
            {
                std::cout << "All answers are correct up to " << i - 1 << std::endl;
                std::cout << "<-------------Verification ended------------->" << std::endl;
                return;
            }
        }
        i += step;
    }
}
//
// Created by Chen Qingzhi on 2022/5/20.
//

#ifndef HW12_STRING_VALIDATOR_H
#define HW12_STRING_VALIDATOR_H

#include <string>
using namespace std;

class string_validator
{
private:
    string_validator() = default;

public:
    static long long check_legality(string);
    /* This function throws exceptions, derived from std::exception.
     * Read exceptions.h for more info
     */
    static bool is_num(char ch);
    static void run();
};


#endif //HW12_STRING_VALIDATOR_H

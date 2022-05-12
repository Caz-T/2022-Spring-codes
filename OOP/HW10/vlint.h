#ifndef HW10_VLINT_H
#define HW10_VLINT_H

#include <vector>
#include <iostream>
using namespace std;

class vlint // vlint stands for very long int
{
public:
    vlint();
    vlint(vlint& another);
    ~vlint() = default;

    int operator[](int n);
    vlint operator+ (vlint another);
    vlint operator- (vlint another);

    vector<int> digit; //digit[0] is the right-most digit
    bool sign = true; // true for positive
};

istream& operator>> (istream& in, vlint& to_read);
ostream& operator<< (ostream& out, vlint& to_write);

/*
vlint operator+ (long long& a, vlint& b);
vlint operator- (long long& a, vlint& b);
 */
#endif //HW10_VLINT_H

#ifndef HW10_VLINT_H
#define HW10_VLINT_H

#include <vector>
using namespace std;

class vlint // vlint stands for very long int
{
public:
    vlint();
    vlint(long long& another);
    vlint(vlint& another);
    ~vlint() = default;

    int operator[](int n);
    vlint operator+ (vlint another);
    vlint operator- (vlint another);

    vector<int> digit; //digit[0] is the right-most digit
    bool sign = true; // true for positive
};

/*
vlint operator+ (long long& a, vlint& b);
vlint operator- (long long& a, vlint& b);
 */
#endif //HW10_VLINT_H

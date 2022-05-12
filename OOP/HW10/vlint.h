#ifndef HW10_VLINT_H
#define HW10_VLINT_H

#include <vector>
using namespace std;

class vlint // vlint stands for very long int
{
public:
    vlint();

    ~vlint() = default;

    int operator[](int n);
    vlint operator+ (vlint& another);
    vlint operator+ (long long& another);
    vlint operator- (vlint& another);
    vlint operator- (long long& another);

    vector<int> digit; //digit[0] is the right-most digit
};

vlint operator+ (long long& a, vlint& b);
vlint operator- (long long& a, vlint& b);
#endif //HW10_VLINT_H

#ifndef HW2_CPP_INT_H
#define HW2_CPP_INT_H
class intpair
{
public:
    intpair();
    ~intpair();
private:
    int *value1, *value2;
    long long calc_gcd();
    long long *gcd;
    long long calc_lcm();
    long long *lcm;
    long long *timeused;
public:
    void output();
};
#endif //HW2_CPP_INT_H


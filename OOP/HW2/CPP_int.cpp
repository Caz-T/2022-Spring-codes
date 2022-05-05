#include <iostream>
#include <ctime>
#include "CPP_int.h"

using namespace std;
intpair::intpair()
{
    cout << "Input two numbers: ";
    int n1, n2;
    cin >> n1 >> n2;
    value1 = new int(n1);
    value2 = new int(n2);
    timeused = new long long (-clock());
    gcd = new long long(calc_gcd());
    lcm = new long long(calc_lcm());
    int temp = 1000000;
    int count = 0;
    while (temp--)
    {
        *gcd = calc_gcd();
        count++;
        *lcm = calc_lcm();
    }
    *timeused += clock();
}

intpair::~intpair()
{
    delete value1;
    delete value2;
    delete gcd;
    delete lcm;
}

long long intpair::calc_gcd()
{
    int m = *value1, n = *value2;
    if (m == n) return m;
    if (m > n)
    {
        m = m - n;
        n = m + n;
        m = n - m;
    }
    while (true)
    {
        m = m % n;
        if (m == 0) return n;
        n = n % m;
        if (n == 0) return m;
    }
}

long long intpair::calc_lcm()
{
    return *value1 * *value2 / *gcd;
}

void intpair::output()
{
    cout << "Greatest common divisor = " << *gcd << "\nLeast common multiple = " << *lcm << "\nTime consumed " << *timeused / 1000.0 << " ns\n";
}
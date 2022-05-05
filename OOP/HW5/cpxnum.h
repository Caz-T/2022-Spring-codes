//
// Created by Chen Qingzhi on 2022/3/26.
//

#ifndef HW5NEW_CPXNUM_H
#define HW5NEW_CPXNUM_H

#include <iostream>
using namespace std;

class cpxnum {
public:
    cpxnum();
    cpxnum(cpxnum& another);
    cpxnum(double r, double i);
    explicit cpxnum(double r);

    static double real(cpxnum&);
    static double imag(cpxnum&);
    static double abs(cpxnum&);
    static cpxnum conj(cpxnum&);

    cpxnum operator+ (cpxnum&) const;
    cpxnum operator+ (double) const;
    cpxnum operator- (cpxnum&) const;
    cpxnum operator- (double) const;
    cpxnum operator* (cpxnum&) const;
    cpxnum operator* (double) const;
    cpxnum operator/ (cpxnum&) const;
    cpxnum operator/ (double) const;

    cpxnum operator++ (int);
    cpxnum& operator++ ();
    cpxnum operator-- (int);
    cpxnum& operator-- ();

    bool operator== (cpxnum&) const;
    bool operator== (double) const;

    cpxnum& operator= (const cpxnum&);
    cpxnum& operator= (double);

private:
    double real_part, imaginary_part;
};

cpxnum operator+ (double, cpxnum&);
cpxnum operator- (double, cpxnum&);
cpxnum operator* (double, cpxnum&);
cpxnum operator/ (double, cpxnum&);

ostream& operator<< (ostream&, cpxnum&);

#endif //HW5NEW_CPXNUM_H

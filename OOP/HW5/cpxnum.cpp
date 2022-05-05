//
// Created by Chen Qingzhi on 2022/3/26.
//

#include "cpxnum.h"
#include <cmath>

cpxnum::cpxnum(): cpxnum(0, 0){}
cpxnum::cpxnum(double r): cpxnum(r, 0){}
cpxnum::cpxnum(double r, double i): real_part(r), imaginary_part(i) {}

cpxnum::cpxnum(cpxnum &another): cpxnum(real(another), imag(another)){}

double cpxnum::real(cpxnum& a) {return a.real_part;}
double cpxnum::imag(cpxnum& a) {return a.imaginary_part;}
double cpxnum::abs(cpxnum& a) {return std::sqrt(a.real_part * a.real_part + a.imaginary_part * a.imaginary_part);}
cpxnum cpxnum::conj(cpxnum& a) {return {a.real_part, -a.imaginary_part};}

cpxnum cpxnum::operator+ (cpxnum& another) const
{
    return {real_part + another.real_part, imaginary_part + another.imaginary_part};
}
cpxnum cpxnum::operator+ (double r) const
{
    return {real_part + r, imaginary_part};
}
cpxnum operator+ (double r, cpxnum& z)
{
    return {cpxnum::real(z) + r, cpxnum::imag(z)};
}
cpxnum cpxnum::operator- (cpxnum& another) const
{
    return {real_part - another.real_part, imaginary_part - another.imaginary_part};
}
cpxnum cpxnum::operator- (double r) const
{
    return {real_part - r, imaginary_part};
}
cpxnum operator- (double r, cpxnum& z)
{
    return {r - cpxnum::real(z), -cpxnum::imag(z)};
}
cpxnum cpxnum::operator* (cpxnum& another) const
{
    return {real_part * another.real_part - imaginary_part * another.imaginary_part,
            real_part * another.imaginary_part + imaginary_part * another.real_part};
}
cpxnum cpxnum::operator* (double r) const
{
    return {real_part * r, imaginary_part * r};
}
cpxnum operator* (double r, cpxnum& z)
{
    return {r * cpxnum::real(z),  r * cpxnum::imag(z)};
}
cpxnum cpxnum::operator/ (cpxnum& another) const
{
    cpxnum ans;
    ans = cpxnum::conj(another) / cpxnum::abs(another);
    ans = *this * ans;
    return ans;
}
cpxnum cpxnum::operator/ (double r) const
{
    return {real_part / r, imaginary_part / r};
}
cpxnum operator/ (double r, cpxnum& z)
{
    cpxnum ans;
    ans = cpxnum::conj(z) / cpxnum::abs(z);
    ans = r * ans;
    return ans;
}

cpxnum cpxnum::operator++ (int)
{
    cpxnum tempsave = *this;
    real_part += 1.0;
    return tempsave;
}
cpxnum& cpxnum::operator++ ()
{
    real_part += 1.0;
    return *this;
}
cpxnum cpxnum::operator-- (int)
{
    cpxnum tempsave = *this;
    real_part -= 1.0;
    return tempsave;
}
cpxnum& cpxnum::operator-- ()
{
    real_part -= 1.0;
    return *this;
}

cpxnum &cpxnum::operator= (double r)
{
    real_part = r;
    imaginary_part = 0;
    return *this;
}
cpxnum& cpxnum::operator= (const cpxnum& another) = default;

bool cpxnum::operator== (cpxnum& another) const
{
    return real_part == another.real_part and imaginary_part == another.imaginary_part;
}
bool cpxnum::operator== (double another) const
{
    return real_part == another and imaginary_part == 0;
}

ostream& operator<< (ostream& out, cpxnum& z)
{
    if (cpxnum::real(z) != 0 and cpxnum::imag(z) != 0)
    {
        char connection_mark = cpxnum::imag(z) > 0 ? '+' : '-';
        out << cpxnum::real(z) << connection_mark;
        if (abs(cpxnum::imag(z)) != 1) out << abs(cpxnum::imag(z));
        out << 'i';
    }
    else if (cpxnum::real(z) == 0 and cpxnum::imag(z) != 0)
    {
        if (cpxnum::imag(z) < 0) out << '-';
        if (abs(cpxnum::imag(z)) != 1) out << abs(cpxnum::imag(z));
        out << 'i';
    }
    else out << cpxnum::real(z);
    return out;
}

#include "shape.h"

shape::shape(double nn, double ll) : side_length(ll)
{
    if ((int)nn != nn or nn >= 6 or nn <= 0) throw 2;
    else n = (int)nn + 2;
}

double shape::getarea() const
{
    double area = side_length * side_length;
    switch (n)
    {
        case 3:
            area *= 0.4330127019;
            break;
        case 4:
            break;
        case 5:
            area *= 1.720477401;
            break;
        case 6:
            area *= 2.598076211;
            break;
        case 7:
            area *= pi;
            break;
        default:
            break;
    }
    return area;
}
double shape::getcir() const
{
    return n == 7 ? 2 * pi * side_length : n * side_length;
}
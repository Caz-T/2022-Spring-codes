#ifndef HW3_TEST_H
#define HW3_TEST_H

#include "shape_dealer.h"
#include <iostream>

void test()
{
    using namespace std;
    const int test_size = 5;
    const int totest_sides[test_size] = {1, 2, 3, 4, 5};
    const double totest_lengths[test_size] = {1, 2, 3, 4, 5};
    for (int i = 0; i < test_size; i++)
    {
        cout << shape(totest_sides[i], totest_lengths[i]).getcir() << ' '
             << shape(totest_sides[i], totest_lengths[i]).getarea() << endl;
    }
}
#endif //HW3_TEST_H

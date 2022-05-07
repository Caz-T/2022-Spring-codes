//
// Created by Chen Qingzhi on 2022/3/26.
//

#include "test.h"
#include <iostream>
using namespace std;

void test_unitary(cpxnum z)
{
    system("cls");
    cout << "TESTING FOR z = " << z << endl;
    cpxnum ans;
    ans = z + 1.5;
    cout << "z + 1.5 = " << ans << endl;
    ans = z - 1.5;
    cout << "z - 1.5 = " << ans << endl;
    ans = z * 4.5;
    cout << "z * 4.5 = " << ans << endl;
    ans = z / 4.5;
    cout << "z / 4.5 = " << ans << endl;
    ans = 1.5 + z;
    cout << "1.5 + z = " << ans << endl;
    ans = 1.5 - z;
    cout << "1.5 - z = " << ans << endl;
    ans = 4.5 * z;
    cout << "4.5 * z = " << ans << endl;
    ans = 4.5 / z;
    cout << "4.5 / z = " << ans << endl;
    ans = z++;
    cout << "After ans = z++, ans = " << ans << ", z = " << z << endl;
    ans = z--;
    cout << "After ans = z--, ans = " << ans << ", z = " << z << endl;
    ans = ++z;
    cout << "After ans = ++z, ans = " << ans << ", z = " << z << endl;
    ans = --z;
    cout << "After ans = --z, ans = " << ans << ", z = " << z << endl;
    cout << "PRESS ENTER TO CONTINUE" << endl;
    getchar();
}
void test_binary(cpxnum w, cpxnum z)
{
    system("cls");
    cout << "TESTING FOR w = " << w << " and z = " << z << endl;
    cpxnum ans;
    ans = w + z;
    cout << "w + z = " << ans << endl;
    ans = w - z;
    cout << "w - z = " << ans << endl;
    ans = w * z;
    cout << "w * z = " << ans << endl;
    ans = w / z;
    cout << "w / z = " << ans << endl;
    cout << "PRESS ENTER TO CONTINUE" << endl;
    getchar();
}

void test()
{
    cpxnum test_series[] = {{1.5, 2}, {1.5, 0}, {0, 0}, {0, 1.5}, {-1, -1}};
    for (cpxnum & i : test_series)
        test_unitary(i);
    for (cpxnum & i : test_series)
        for (cpxnum & j : test_series)
            if (not (i == j)) test_binary(i, j);
    system("pause");
}
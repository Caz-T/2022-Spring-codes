//
// Created by Chen Qingzhi on 2022/4/30.
//

#include "controller.h"
#include <iostream>
using namespace std;

controller::controller()
{
    cout << "Input the number of integers:" << endl;
    int n;
    cin >> n;
    long long temp;
    if (n == 0)
    {
        cout << "No data input!" << endl;
        return;
    }
    cout << "Input " << n << " integers:" << endl;
    while (n--)
    {
        cin >> temp;
        data_with_reps.emplace_back(temp);
    }
    sort(data_with_reps.begin(), data_with_reps.end());
    cout << "Data after sorting: ";
    for (auto& i : data_with_reps) cout << i << ' ';
    cout << endl << "Data after removing duplicates: ";
    for (auto& i : data_with_reps) data_wo_reps.emplace(i);
    for (auto& i : data_wo_reps) cout << i << ' ';
    system("pause");
}
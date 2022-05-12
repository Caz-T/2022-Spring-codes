#include "vlint.h"
#include "calculator.h"
#include <iostream>
using namespace std;


calculator::calculator()
{
    calculate();
    system("pause");
}
void calculator::calculate()
{
    cout << "Input two numbers connected by a sign:" << endl;
    vlint opera, operb;
    string sgn;
    cin >> opera >> sgn >> operb;
    cout << "= ";
    if (sgn == "+") opera = opera + operb;
    else opera = opera - operb;
    cout << opera << endl;
}


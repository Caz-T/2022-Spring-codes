#include "vlint.h"
#include "calculator.h"
#include <iostream>
using namespace std;

calculator::calculator()
{
    cout << "Input two numbers:" << endl;
    vlint opera, operb;
    string sgn;
    cin >> opera >> sgn >> operb;
    assert(sgn.length() == 1);
    cout << opera << " " << sgn << " " << operb << " = ";
    if (sgn == "+") opera = opera + operb;
    else opera = opera - operb;
    cout << opera;
}
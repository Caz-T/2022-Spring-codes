#include <iostream>
#include "shape_dealer.h"
using namespace std;
shape_dealer::shape_dealer()
{
    double commandnum;
    double a;
    cout << "Input command and corresponding data: ";
    cin >> commandnum;
    while (commandnum != 0)
    {
        cin >> a;
        while (not push_shape(commandnum, a))
        {
            cout << "Input command and corresponding data: ";
            cin >> commandnum;
            cin >> a;
        }
        cout << "Input command and corresponding data: ";
        cin >> commandnum;
    }
    report();
}

bool shape_dealer::push_shape(double command, double data)
{
    try
    {
        shapes.emplace_back(shape(command, data));
    }
    catch (...)
    {
        cout << "Error in input!!\n";
        return false;
    }
    return true;
}

void shape_dealer::report()
{
    double ar = 0, circ = 0;
    if (shapes.size())
        for (shape &i : shapes)
        {
            ar += i.getarea();
            circ += i.getcir();
        }
    cout << shapes.size() << " shapes read with a total circumference of " << circ << " and a total area of " << ar << endl;
    system("pause");
}
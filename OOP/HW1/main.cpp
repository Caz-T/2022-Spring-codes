#include <iostream>
#include <cstdlib>
#include "CPP_getint.h"

int main(int argc, char** argv)
{
    using namespace customdata;
    using namespace std;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-t") == 0)
        {
            if (++i < argc)
            {
                long long to_test = strtol(argv[i], nullptr, 0);
                if (to_test > 2147483647 or to_test <= 0)
                {
                    cout << "ERROR: test number too big (expected [1,2147483647])" << endl;
                    return 0;
                }
                else test(to_test);
            }
            else
            {
                cout << "ERROR: parameters mismatch (expected number after -t)" << endl;
                return 0;
            }
        }
    }
    cpp_int someint;
    while(!someint.read_num());
    cout << "Using mathematical algorithm, the answer is: " << someint.calculate_positive_smaller_even_num() << endl;
    cout << "Using loop algorithm, the answer is: " << someint.calculate_positive_smaller_even_num(1) << endl << endl << endl;
    system("pause");
    return 0;
}

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;


int main()
{
    srand(time(nullptr));
    ofstream outfile;
    outfile.open("test.txt");
    outfile << "20 199" << endl;
}

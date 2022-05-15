//
// Created by Chen Qingzhi on 2022/5/15.
//

#ifndef HW11_STUDENT_SYSTEM_H
#define HW11_STUDENT_SYSTEM_H

#include <string>
#include <map>
using namespace std;

class student_system
{
public:
    student_system();
    ~student_system();

private:
    map<long long, int> students;
    bool read_file(string&);
    bool write_file(string&);
};


#endif //HW11_STUDENT_SYSTEM_H

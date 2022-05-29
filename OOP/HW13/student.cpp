//
// Created by Chen Qingzhi on 2022/5/29.
//

#include "student.h"

student::student(long long i, int scr): _id(i), _score(scr) {}
student::student(student another, student* pr, student* nx): _id(another.id()), _score(another.score()), prev(pr), next(nx){}

bool student::operator<(student &another) const
{
    if (_id == another.id()) return _score < another.score();
    else return _id < another.id();
}
bool student::operator<(const student &another) const
{
    if (_id == another.id()) return _score < another.score();
    else return _id < another.id();
}

long long student::id() const {return _id;}
int student::score() const {return _score;}
void student::set_id(long long i) {_id = i;}
void student::set_score(int s) {_score = s;}


//
// Created by Chen Qingzhi on 2022/3/29.
//

#include "student.h"
student::student(long long new_id, unsigned int new_score) : id(new_id), score(new_score) {}
bool student::operator== (student& another) const {return id == another.id and score == another.score;}
bool student::operator< (student& another) const {return id < another.id;}
bool student::operator> (student& another) const {return id > another.id;}
bool student::operator!= (student& another) const {return id != another.id or score != another.score;}
//
// Created by Chen Qingzhi on 2022/3/29.
//

#ifndef HW6_STUDENT_H
#define HW6_STUDENT_H


class student {
public:
    student(long long, unsigned int);
    long long id;
    unsigned int score;

    bool operator== (student&) const;
    bool operator< (student&) const;
    bool operator> (student&) const;
    bool operator!= (student&) const;
};



#endif //HW6_STUDENT_H

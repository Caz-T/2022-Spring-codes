//
// Created by Chen Qingzhi on 2022/5/29.
//

#ifndef HW13_STUDENT_H
#define HW13_STUDENT_H


class student
{
public:
    student() = default;
    student(long long i, int scr);
    student(student, student*, student*);
    ~student() = default;

    long long id() const;
    int score() const;
    void set_id(long long);
    void set_score(int);
    student* next = nullptr;
    student* prev = nullptr;

    bool operator< (student& another) const;
    bool operator< (const student& another) const;

private:
    long long _id = 0;
    int _score = 0;

};


#endif //HW13_STUDENT_H

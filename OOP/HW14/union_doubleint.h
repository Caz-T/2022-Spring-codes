//
// Created by Chen Qingzhi on 2022/6/5.
//

#ifndef HW14_UNION_DOUBLEINT_H
#define HW14_UNION_DOUBLEINT_H


union union_doubleint
{
    double double_value;
    long long ll_value;
    explicit union_doubleint(double d) : double_value(d){}
    explicit union_doubleint(long long ll): ll_value(ll){}
    union_doubleint(const union_doubleint& another): ll_value(another.ll_value){}
    ~union_doubleint() = default;
};

extern void gb_show_bin_memory(const union_doubleint&);
extern void gb_test();
#endif //HW14_UNION_DOUBLEINT_H

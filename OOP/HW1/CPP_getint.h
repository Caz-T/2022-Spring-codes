#ifndef HW1_CPP_GETINT_H
#define HW1_CPP_GETINT_H

namespace customdata
{
    class cpp_int
    {
    private:
        int value = 0;
    public:
        short set_num(long long to_change);
        cpp_int() = default;
        ~cpp_int() = default;
        int get_value() const;
        bool read_num();
        long long calculate_positive_smaller_even_num(int method_type = 0) const;
    };
}
void test(long long upper_limit);
#endif //HW1_CPP_GETINT_H

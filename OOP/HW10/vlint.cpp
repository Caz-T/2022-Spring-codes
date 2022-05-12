#include "vlint.h"

vlint::vlint()
{
    digit.emplace_back(0);
}

vlint::vlint(long long& another)
{
    if (another < 0) sign = false;
    while (another)
    {
        digit.emplace_back(another % 10);
        another = another / 10;
    }
}

vlint::vlint(vlint &another) : sign(another.sign) {for (auto iter = another.digit.rend(); iter != another.digit.rbegin(); iter++) digit.emplace_back(*iter);}

int vlint::operator[](int n) {return digit[n];}
vlint vlint::operator+(vlint another)
{
    vlint ans(another);
    if (!another.sign) for (auto& i : ans.digit) i = -i;
    for (int i = ans.digit.size() + 1; i <= digit.size(); i++) ans.digit.emplace_back(0);
    ans.digit.emplace_back(0);
    for (int i = 0; i < ans.digit.size(); i++)
    {
        if (sign) ans.digit[i] += digit[i];
        else ans.digit[i] -= digit[i];
        if (ans.digit[i] > 10)
        {
            ans.digit[i] -= 10;
            ans.digit[i + 1]++;
        }
        if (ans.digit[i] < 0)
        {
            ans.digit[i] += 10;
            ans.digit[i + 1]--;
        }
    }
    if (*ans.digit.end() < 0)
    {
        ans.sign = false;
        for (auto& i : ans.digit) i = -i;
        for (int i = 0; i < ans.digit.size() - 1; i++)
        {
            if (ans.digit[i] > 10)
            {
                ans.digit[i] -= 10;
                ans.digit[i + 1]++;
            }
            if (ans.digit[i] < 0)
            {
                ans.digit[i] += 10;
                ans.digit[i + 1]--;
            }
        }
    }
    if (*ans.digit.end() == 0) ans.digit.pop_back();
    return ans;
}
vlint vlint::operator-(vlint another)
{
    vlint temp(another);
    temp.sign = not temp.sign;
    return *this + temp;
}


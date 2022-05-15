#include "vlint.h"
#include <string>

vlint::vlint()
{
    digit.emplace_back(0);
}
vlint::vlint(vlint &another) : sign(another.sign)
{
    digit.clear();
    for (int & iter : another.digit) digit.emplace_back(iter);
}

vlint vlint::operator+(vlint another)
{
    vlint ans(another);
    if (!another.sign) for (int & i : ans.digit) i = -i;
    ans.sign = true;
    for (int i = ans.digit.size() + 1; i <= digit.size(); i++) ans.digit.emplace_back(0);
    for (int i = digit.size() + 1; i <= ans.digit.size(); i++) digit.emplace_back(0);
    ans.digit.emplace_back(0);
    digit.emplace_back(0);
    for (int i = 0; i < ans.digit.size() - 1; i++)
    {
        if (sign) ans.digit[i] += digit[i];
        else ans.digit[i] -= digit[i];
        if (ans.digit[i] >= 10)
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
    if (ans.digit.back() < 0)
    {
        ans.sign = false;
        for (int & i : ans.digit) i = -i;
        for (int i = 0; i < ans.digit.size() - 1; i++)
        {
            if (ans.digit[i] >= 10)
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
    while (ans.digit.back() == 0 and ans.digit.size() > 1) ans.digit.pop_back();
    while (digit.back() == 0 and digit.size() > 1) digit.pop_back();
    return ans;
}
vlint vlint::operator-(vlint another)
{
    vlint temp(another);
    temp.sign = not temp.sign;
    vlint ans;
    ans = *this + temp;
    return ans;
}

ostream& operator<< (ostream& out, vlint& to_write)
{
    auto iter = to_write.digit.rbegin();
    while (*iter == 0)
    {
        iter++;
        if (iter == to_write.digit.rend())
        {
            out << 0;
            return out;
        }
    }
    if (not (to_write.sign)) out << "-";
    for (;iter != to_write.digit.rend(); iter++) out << *iter;
    return out;
}

istream& operator>> (istream& in, vlint& to_read)
{
    string str;
    in >> str;
    to_read.digit.clear();
    if (str[0] == '-')
    {
        to_read.sign = false;
        str = str.substr(1);
    }
    for (int i = str.length() - 1; i >= 0; i--) to_read.digit.emplace_back(str[i]-48);
    return in;
}

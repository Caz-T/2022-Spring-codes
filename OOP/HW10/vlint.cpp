#include "vlint.h"
#include <string>

vlint::vlint()
{
    digit.emplace_back(0);
}
vlint::vlint(long long& another)
{
    digit.clear();
    sign = true;
    if (another < 0) sign = false;
    while (another)
    {
        digit.emplace_back(another % 10);
        another = another / 10;
    }
}
vlint::vlint(vlint &another) : sign(another.sign)
{
    digit.clear();
    for (auto iter = another.digit.rend(); iter != another.digit.rbegin(); iter++) digit.emplace_back(*iter);
}

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
    vlint ans;
    ans = *this + temp;
    return ans;
}

ostream& operator<< (ostream& out, vlint& to_write)
{
    if (to_write.sign) out << "-";
    for (auto iter = to_write.digit.rend(); iter != to_write.digit.rbegin(); iter++) out << *iter;
    return out;
}

istream& operator>> (istream& in, vlint& to_read)
{
    string str;
    in >> str;
    // check legality
    if (str[0] == '-')
    {
        to_read.sign = false;
        str = str.substr(1);
    }
    for (int i = str.length() - 1; i >= 0; i--) to_read.digit.emplace_back(str[i]-48);
    return in;
}

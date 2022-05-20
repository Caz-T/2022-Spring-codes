//
// Created by Chen Qingzhi on 2022/5/20.
//

#include "string_validator.h"
#include "exceptions.h"
#include <string>
#include <iostream>
using namespace std;

void string_validator::run()
{
    string command;
    cout << "Type in a string withOUT spaces: \n";
    cin >> command;
    while (command != "end")
    {
        try {cout << check_legality(command) << " is a valid integer.\n";}
        catch (EXC_bad_char& e)
        {
            cout << "Bad characters: detected " << e.bad_character << " at position " << e.first_position << endl;
        }
        catch (EXC_minus_zero&)
        {
            cout << "Minus zero (\"-0\") is not a legal number\n";
        }
        catch (EXC_overflow&)
        {
            cout << "This is a integer indeed, but it's too big to fit into long long type\n";
        }
        catch (EXC_unexpected_zero& e)
        {
            cout << "Unexpected " << e.zero_count << " zero" << (e.zero_count == 1? "":"s") << " at the beginning of the given string\n";
        }
        catch (EXC_minus& e)
        {
            cout << "Unexpected minus sign at position " << e.position << ". Check whether this is a mistyped negative integer.\n";
        }
        catch (EXC_decimal&)
        {
            cout << "This is a decimal number, not an integer. Note that decimals like 123.00 is not considered an integer due to precision issues.\n";
        }
        catch (...)
        {
            cout << "FOR DEBUGGING PURPOSES ONLY.\nIf you see this, contact me at cqz21@mails.tsinghua.edu.cn.\n";
            return;
        }
        cout << "Type in a string withOUT spaces, or type END to end this program: \n";
        cin >> command;
    }
    system("pause");
}

bool string_validator::is_num(char ch) {return (ch >= 48) and (ch <= 57);}
long long string_validator::check_legality(string str)
{
    long long ans = 1;
    if (str[0] == '-')
    {
        if (str.length() == 2 and str[1] == '0') throw EXC_minus_zero();
        ans = -1;
        str = str.substr(1);
    }
    bool decimal_flag = false;
    int temp_pos;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '.')
        {
            if (decimal_flag) throw EXC_bad_char(temp_pos, '.');
            else
            {
                decimal_flag = true;
                temp_pos = i;
                continue;
            }
        }
        if (ch == '-') throw EXC_minus(i);
        if (not is_num(ch)) throw EXC_bad_char(i, ch);
    }
    if (str.length() >= 19) throw EXC_overflow();
    return ans * stoll(str);
}
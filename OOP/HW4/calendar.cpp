//
// Created by Chen Qingzhi on 2022/3/18.
//
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <string>
#include "calendar.h"
using namespace std;
calendar::calendar()
{
    reset();
}
calendar::calendar(int yy, int mm, int dd) : year(yy), month(mm), day(dd) {}
calendar::~calendar() = default;
bool calendar::is_valid(int yy, int mm, int dd)
{
    if (yy == 0) return false;
    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (isleap(yy)) days[2] ++;
    return mm <= 12 and mm >= 1 and dd >= 1 and dd <= days [mm];
}
void calendar::reset()
{
    time_t now = time(0);
    tm *currtime = localtime(&now);
    year = currtime->tm_year + 1900;
    month = currtime->tm_mon + 1;
    day = currtime->tm_mday;
    cout << "Current date acquired from system: " << year << '/' << month << '/' << day << endl;
}
bool calendar::isleap(long long yr)
{
    return (yr%4==0 and (yr%100!=0 or yr%400==0));
}
bool calendar::setdate(int yy, int mm, int dd)
{
    if (!is_valid(yy, mm, dd)) return false;
    year = yy;
    month = mm;
    day = dd;
    return true;
}
void calendar::showdate(int yy, int mm, int dd)
{
    if (yy < 0) cout << "B.C. ";
    cout << yy << '/';
    if (mm < 10) cout << '0';
    cout << mm << '/';
    if (dd < 10) cout << '0';
    cout << dd << endl;
}
void calendar::showdate() const
{
    showdate(year, month, day);
}
void calendar::show_date_after(long long time_interval)
{
    short flag = 0;
    int eracount = (time_interval - (time_interval % 146097 + 146097) % 146097) / 146097;
    if (year > 0 and year <= -400 * eracount) flag = -1;
    if (year < 0 and year >= -400 * eracount) flag = 1;
    calendar tempcal(year + 400 * eracount + flag, month, day);
    time_interval = (time_interval % 146097 + 146097) % 146097;
    while (time_interval--) tempcal.advance();
    tempcal.showdate();
}
long long calendar::date_diff(int yy, int mm, int dd)
{
    long long ans = 0;
    int eradiff = (yy / abs(yy)) * (yy / 400) - (year / abs(year)) * (year / 400);
    short flag = 0;
    if (year > 0 and year <= -400 * eradiff) flag = -1;
    if (year < 0 and year >= -400 * eradiff) flag = 1;
    ans += 146097 * eradiff;
    yy -= eradiff * 400 + flag;
    ans += 365 * (yy - year);
    if (year < yy) for (int i = year; i < yy; i++) ans += isleap(i);
    else for (int i = year - 1; i >= yy; i--) ans -= isleap(i);
    ans -= yearorder(year, month, day);
    ans += yearorder(yy, mm, dd);
    return ans;
}
void calendar::show_date_diff(int yy, int mm, int dd)
{
    cout << "The day difference is " << date_diff(yy, mm, dd) << " days" << endl;
}
int calendar::yearorder(int yy, int mm, int dd)
{
    int ans = (isleap(yy) and mm >= 3) ? 1 : 0;
    const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < mm; i++) ans += days[i];
    ans += dd;
    return ans;
}
void calendar::advance()
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isleap(year)) days[2]++;
    day++;
    if (day > days[month]) {
        day = 1;
        month++;
    }
    if (month > 12) {
        month = 1;
        year += year == -1? 2 : 1;
    }

}
date calendar::readdate()
{
    return date{year, month, day};
}
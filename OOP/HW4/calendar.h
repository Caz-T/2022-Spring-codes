//
// Created by Chen Qingzhi on 2022/3/18.
//

#ifndef HW4_CALENDAR_H
#define HW4_CALENDAR_H
struct date
{
    int yy, mm, dd;
};
class calendar
{
public:
    calendar();
    calendar(int yy, int mm, int dd);
    // starts with the current date read from system.
    ~calendar();
    // does the cleanup. So far just a trivial destructor.
    bool setdate(int yy, int mm, int dd);           // sets the date to yy/mm/dd, returns whether this is valid
    void showdate() const;                          // shows the recorded date, a convenient function
    static void showdate(int yy, int mm, int dd);   // shows any date
    date readdate();
    void show_date_after(long long time_interval);  // shows time_interval days after the recorded date
    void show_date_diff(int yy, int mm, int dd);    // inverse function of the last one
    bool is_valid(int yy, int mm, int dd);          // judges whether a certain date is valid
    void reset();                                   // resets the date to system date UTC+8


private:
    bool isleap(long long);                         // judges whether a year is a leap one
    long long date_diff(int yy, int mm, int dd);    //private function for date difference
    int yearorder(int yy, int mm, int dd);          // a convenient function: determines which day it is in a year
    //int eraorder(int yy, int mm, int dd);         // decides which day is it in an 'era' = 400 years
    void advance();
    int year, month, day;                           // these record as they seem
};

#endif //HW4_CALENDAR_H

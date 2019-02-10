//source for days between to dates general use calculator: by Martin York, Aug 29 '13 at 20:42 posted on https://codereview.stackexchange.com/questions/30448/day-counter-between-two-dates
//source for getting current date: by anon at Jun 15 '09 at 19:43, and edited by milleniumbug at Mar 21 '18 at 22:24 posted on https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c


#include <iostream>
#include <cmath>
#include <ctime>
int days;

struct Day
{
    int count;
    friend std::istream& operator>>(std::istream& s, Day& d)
    {
        int day_year;
        int day_month;
        int day_days;

        s >> day_month >> day_days >> day_year;

        // calculate number of leap years.
        int leapyears    = day_year / 4;
        if (day_year % 4 == 0 && day_month < 3)
        {
            // If this is a leap year
            // And we have not passed Feburary then it does
            // not count.....
            leapyears   --;
        }
        // convert year/month/day into a day count
        d.count    = day_year * 365 + month_days[day_month-1] + day_days + leapyears;

        // return stream for chaining
        return s;
    }
    Day* operator=(std::tm* now)
    {
        int day_year;
        int day_month;
        int day_days;

        //add code to set date
        day_year = (now->tm_year + 1900);
        day_month = (now->tm_mon + 1) ;
        day_days = now->tm_mday;

        // calculate number of leap years.
        int leapyears    = day_year / 4;
        if (day_year % 4 == 0 && day_month < 3)
        {
            // If this is a leap year
            // And we have not passed Feburary then it does
            // not count.....
            leapyears   --;
        }
        // convert year/month/day into a day count
        this->count    = day_year * 365 + month_days[day_month-1] + day_days + leapyears;
        return this;
    }
     friend int operator-(Day const& lhs, Day const& rhs)
    {
        // subtraction gives you the difference between two Days objects.
        return lhs.count - rhs.count;
    }
    static int month_days[];
};

int Day::month_days[] = {0,31,59,90,120,151,181,212,243,273,304,334};

int main()
{

    // Declare variables as close to the point of first use as you can.
    Day     first;

    std::cout << "Jan. 2nd 2018 = 1 2 2018\n";
    std::cout << "Enter first date(M D Y): ";
    std::cin >> first;
    std::cout<<"\n";

    std::time_t t = std::time(0);   // get time now
    tm* now = std::localtime(&t);
    Day     second;//current date
    second = now;

    std::cout << "Days between the date and today = " << std::abs(first - second) << "\n";
}

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
class Date
{
public:
    Date()
    {
        year = 1;
        month = 1;
        day = 1;
    }
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    virtual string toString()
    { // "mm, dd, yyyy"
        stringstream datee;
        datee << setw(2) << setfill('0') << month << ", " << setw(2) << setfill('0') << day << ", " << year;
        return datee.str();
    }
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setYear(int y)
    {
        year = y;
    }
    int getDay() const
    {
        return day;
    }
    int getMonth() const
    {
        return month;
    }
    int getYear() const
    {
        return year;
    }
    int maxday(int m)
    {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            return 31;
        }
        else if (m == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            return 29;
        }
        else if (m == 2)
        {
            return 28;
            ;
        }
        else
        {
            return 30;
        }
    }
    void addDays(int d)
    { // adds the specified number of days to this instance
        day = day + d;
        while (day > maxday(month))
        {
            day = day - maxday(month);
            addMonths(1);
        }
    }
    void addMonths(int m)
    {
        month = month + m;
        while (month > 12)
        {
            month = month - 12;
            addYears(1);
        }
    } // adds the specified number of months to this instance
    void addYears(int y)
    {
        year = year + y;
    } // adds the specified number of years to this instance
    static bool isLeapYear(const Date &d)
    {
        if ((d.getYear() % 4 == 0 && d.getYear() % 100 != 0) || (d.getYear() % 400 == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    int year, month, day;
};

class TimeSpan
{
public:
    TimeSpan()
    {
        day = 0, hour = 0, minute = 0, second = 0;
    }
    TimeSpan(int d, int hh, int mm, int ss)
    {
        day = d, hour = hh, minute = mm, second = ss;
    }
    void setsecond(int s){
        second=s;
    }
    void setminute(int m){
        minute=m;
    }
    void setdays(int d){
        day=d;
    }
    int toTotalDays();
    int toTotalHours();
    int toTotalMinutes();
    int toTotalSeconds()
    {
        return second;
    }
    string toString();

private:
    int day, hour, minute, second;
};
class DateTime : public Date
{
public:
    virtual string toString()
    {
        stringstream timee;
        timee << setw(2) << setfill('0') << getMonth() << ", " << setw(2) << setfill('0') << getDay() << ", " << getYear() << " " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second;
        return timee.str();
    } // "mm/dd/yyyy HH:MM:SS"
    DateTime() : Date()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    DateTime(int y, int m, int d, int hh = 0, int mm = 0, int ss = 0) : Date(y, m, d)
    {
        hour = hh;
        minute = mm;
        second = ss;
    }
    void setHour(int h)
    {
        hour = h;
    }
    void setMinute(int m)
    {
        minute = m;
    }
    void setSecond(int s)
    {
        second = s;
    }
    int getHour() const
    {
        return hour;
    }
    int getMinute() const
    {
        return minute;
    }
    int getSecond() const
    {
        return second;
    }
    void addHours(int h)
    {
        hour = hour + h;
        while (hour >= 24)
        {
            addDays(1);
            hour = hour - 24;
        }
    } // adds the specified number of hours to this instance
    void addMinutes(int m)
    {
        minute = minute + m;
        while (minute >= 60)
        {
            addHours(1);
            minute = minute - 60;
        }
    } // adds the specified number of minutes to this instance
    void addSeconds(int s)
    {
        second = second + s;
        while (second >= 60)
        {
            addMinutes(1);
            second = second - 60;
        }
    } // adds the specified number of seconds to this instance
    TimeSpan operator-(const DateTime &dt) const
    {
        DateTime d = (*this);
        TimeSpan result;
        int Sec = 0;
        while (d.getYear() != dt.getYear() || d.getMonth() != dt.getMonth() || d.getDay() != dt.getDay() ||
                d.getHour() != dt.getHour() || d.getMinute() != dt.getMinute() || d.getSecond() != dt.getSecond())
        {
            Sec++;
            d.addSeconds(1);
            //cout << d.getYear() << " " << d.getMonth() << " " << d.getDay() << " " << d.getHour() <<  " " << d.getMinute() << " " << d.getSecond() <<endl;
        }
        result.setsecond(Sec);
        return result;
    } // return a TimeSpan object represents a time interval
private:
    int hour, minute, second;
};
int main()
{
    int y, m, d, hh, mm, ss;
    cin >> y >> m >> d >> hh >> mm >> ss;
    DateTime d1(y, m, d, hh, mm, ss);
    cin >> y >> m >> d >> hh >> mm >> ss;
    DateTime d2(y, m, d, hh, mm, ss);
    cout << (d1 - d2).toTotalSeconds();
    return 0;
}
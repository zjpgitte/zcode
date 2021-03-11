#include <iostream>

using namespace std;

//    class Time 
//    {
//    public:
//        Time(int hour, int minute, int second)
//        :_hour(hour)
//        ,_minute(minute)
//        ,_second(second)
//        {
//
//        }
//    private:
//        int _hour;
//        int _minute;
//        int _second;
//    };
//
//    class Date
//    {
//
//    public:
//        Date(int year, int month, int day)
//        :_year(year) 
//        ,_month(month) 
//        ,_day(day)
//        ,_a(10)
//        ,_b(year)
//        ,_t(year, month, day)
//        {}
//
//    private:
//        int _year;
//        int _month;
//        int _day;
//        const int _a;
//        int& _b;
//        Time _t;
//    };

class Time 
{
public:
    Time(int hour, int minute, int second)
    :_hour(hour)
    ,_minute(minute)
    ,_second(second)
    {}

private:
        int _hour;
        int _minute;
        int _second;
};
class Date 
{
public:
    Date(int year, int month, int day, int hour, int minute, int second)
    :_year(year)
    ,_month(month)
    ,_day(day)
    ,_t(hour, minute, second)
    {}   
    static int GetA()
    {
        return _year;
    }
private:
    int _year;
    int _month;
    int _day;
    Time _t;
    static int _a;
};

int Date::_a = 0;

int main()
{

    Date d1(2000, 1, 1, 0, 0, 0);
    cout << d1.GetA() << endl;
    return 0;
}

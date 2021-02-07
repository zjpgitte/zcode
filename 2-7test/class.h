#include <iostream>

using namespace std;

bool DayCorrect(int, int );
class Date
{
public:
    Date(int year = 2000, int month = 1, int day = 1)
    {   
        if(month >= 1 && month <= 12)
        {
            if(DayCorrect(month, day))
            {    
                _year = year;
                _month = month;
                _day = day;
            }
        }
        else 
        {
           printf("Date Init Error!\n");
        }
    }
    ~Date()
    {

    }
    Date(Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    //d1 = d2 
    const Date& operator = (const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
        return d;
    }
    //d1 == d2
    bool operator == (const Date& d)
    {
        return _year == d._year 
            && _month == d._month 
            && _day == d._day;
    }
    // d1 += d2 
    Date& operator += (const Date& d)
    {
        

        return *this;
    }
    // d1 + d2 
    Date operator + (const Date& d)
    {
        Date temp = *this;
        temp += d;
        return temp;
    }
    // d1 - d2 
    Date operator - (const Date& d)
    {
        Date temp;
        temp._year = _year - d._year;
        temp._month = _month - d._month;
        temp._day = _day - d._day;
        return temp;
    }
    //d1 -= d2 
    Date& operator -= (const Date& d)
    {
        *this = *this - d;
        return *this;
    }
    // ++d 前置++
    Date& operator ++ ()
    {
        (*this)._day += 1;
    }
private:
    int _year;
    int _month;
    int _day;
};

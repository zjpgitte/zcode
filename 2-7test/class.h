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
    // d1 != d2 
    bool operator != (const Date& d)
    {
        return !(*this == d);
    }
    // d1 > d2 
    bool operator > (const Date& d)
    {
        if(_year > d._year)
        {
            return true;
        }
        else if(_year == d._year)
        {
            if(_month > d._month)
            {
                return true;
            }
            else if(_month == d._month)
            {
                if(_day > d._day)
                {
                    return true;
                }
            }
        }

        return false;
    }
    //d1 >= d2 
    bool operator >= (const Date& d)
    {
        return *this > d || *this == d;
    }
    // d1 < d2 
    bool operator < (const Date& d)
    {
        return !(*this >= d);
    }
    // d1 <= d2 
    bool operator <= (const Date& d)
    {
        return !(*this > d);
    }

    // d1 += d2 
//    Date& operator += (const Date& d)
//    {
//        
//
//        return *this;
//    }
//    // d1 + d2 
//    Date operator + (const Date& d)
//    {
//        Date temp = *this;
//        temp += d;
//        return temp;
//    }
//    // d1 - d2 
    
    // d + 2
    Date operator + (int day)
    {
        Date temp = *this;
        temp._day = _day + day;
        int MonthDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        //判断是否为闰年
        if((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
        {
            MonthDay[1] = 29;
        }
        //判断天数是否正确
        while(temp._day > MonthDay[temp._month-1])
        {
            temp._day -= MonthDay[temp._month-1];
            temp._month += 1;
            if(temp._month > 12)
            {
                temp._year += 1;
                temp._month = 1;
            }
        }

        return temp;

    }
    
    // d += 1
    Date& operator += (int day)
    {
        *this = *this + day;

        return *this;
    }

    // ++d 前置++
    Date& operator ++ ()
    {
        *this += 1;
        return *this;
    }
    // d++ 后置++
    Date operator ++ (int)
    {
        Date temp = *this;
        *this += 1;
        return temp;
    }
    // d1 - 3
    Date operator - (int day)
    {
        Date temp = *this;
        int MonthDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        while(day >= temp._day)
        {
            day -= temp._day;
            temp._month--;
            if(temp._month <= 0)
            {
                temp._month = 12;
                temp._year--;
            }
            temp._day = MonthDay[temp._month-1];
        }
        temp._day -= day;
        return temp;
    }
    //d -= 31
    Date& operator -= (int day)
    {
        *this = *this - day;
        return *this;
    }
    // --d1
    Date& operator -- ()
    {
        *this -= 1;
        return *this;
    }
    // d-- 
    Date operator --(int)
    {
        Date temp = *this;
        --(*this);
        return temp;
    }
    // d1 - d2
    int operator - ( Date& d)
    {
        int c = 1;
        Date MaxDate = *this;
        Date MinDate = d;
        if(*this < d)
        {
            MaxDate = d;
            MinDate = *this;
            c = -1;
        }
        int n = 0;
        while(MinDate != MaxDate)
        {
            MinDate++;
            n++;
        }
        return c*n;
    }

    
    void Print()
    {
        printf("%d-%d-%d\n",_year,_month,_day);
        printf("\n");
    }
private:
    int _year;
    int _month;
    int _day;
};

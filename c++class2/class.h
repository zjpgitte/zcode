#include <iostream>

using namespace std;

int Add(const int& x, const int& y);

class Date
{
public:
    //构造函数
    Date(int year = 2000, int month = 1, int day = 1)
    {
        this->_year = year;
        this->_month = month;
        this->_day = day;
    }
    //拷贝构造函数(用于初始化对象)
    Date(const Date& d)
    {
        this->_year = d._year;
        this->_month = d._month;
        this->_day = d._day;
    }
    //赋值运算符。用于赋值d1 = d2;
    const Date& operator = (const Date& d)
    {
        this->_year = d._year;
        this->_month = d._month;
        this->_day = d._day;
        return d;
    }
    // d1 == d2 
    bool operator == (const Date& d)
    {
        return this->_year == d._year 
            && this->_month == d._month 
            && this->_day == d._day;
    }
    // d1 += d2 
    Date& operator += (const Date& d)
    {
        this->_year += d._year;
        this->_day += d._day;
        this->_month += d._month;
        return *this;
    }
    //d1 + d2 
    Date operator + (const Date& d)
    {
       Date temp = *this; 
       return temp += d;
    }
    void Print()
    {
        printf("%d-%d-%d\n",_year, _month, _day);
    }

private:
    int _year;
    int _month;
    int _day;
};

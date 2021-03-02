#include <iostream>

using namespace std;

class Date
{
public:
    Date(int year = 2000, int month = 1, int day = 1)
    {
        this->_year = year;
        this->_month = month;
        this->_day = day;
    }
    // d1 = d2
    Date(const Date& d)//只能传引用
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
   // 赋值运算符重载
    // d1 = d2
    const Date& operator = (/*Date *this */const Date& d)  //参数的个数就是运算符操作数的个数，这里因为有个隐含的 this针
    {                               //可认为参数两个，函数内我把this 指针写出来了，它是可以不用写的。
        this->_year = d._year;
        this->_month = d._month;
        this->_day = d._day;
        return d;
    }

    void Print()
    {
        printf("%d-%d-%d\n",this->_year, this->_month, this->_day);
    }
private:
    int _year;
    int _month;
    int _day;
};

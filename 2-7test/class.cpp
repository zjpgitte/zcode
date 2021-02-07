#include "class.h"

bool DayCorrect(int month, int day)
{
    int MonthDay[12] = {31,30,31,30,31,30,31,31,30,31,30,31};
    return day <= MonthDay[month-1] && day >= 1;
}

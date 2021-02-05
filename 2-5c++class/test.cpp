
#include "class.h"


int main()
{

    Date d1(2020,1,1);
    d1.Print();

    Date d2 = d1;
    d2.Print();
    Date d3;
    d3 = d1;
    d3.Print();

    return 0;
}

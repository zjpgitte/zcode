#include "class.h"
#include <unistd.h>


int main()
{
   // while(1)
   // {
    //    int ret = Add(1, 2);
    //    cout << ret << endl;
   // }
   
    //cout <<  getpid() << endl;
    //cout << getppid() << endl;

    Date d1;
    d1.Print();
    Date d2(2020,1,1);
    d2.Print();
    Date d3(d2);
    d3.Print();
    Date d4,d5;
    d5 = d4 = d3;
    d4.Print();
    d5.Print();
    Date d6;
    d6 += d2;
    d6.Print();
    Date d7;
    d7 = d7+d2;
    d7.Print();
    printf("%d\n",d3 == d2);
    cout << (d2 == d3) << endl;
    return 0;

}

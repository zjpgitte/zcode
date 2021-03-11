#include <iostream>

using namespace std;

class Date
{
	friend ostream& operator << (ostream& out, Date& d);
	//ostream& operator << (ostream& out, Date& d);
public:
	Date(int year = 2000)
		: _year(year)
	{}
private:
	int _year;
};

//cout << d << endl;
ostream& operator << (ostream& out, Date& d)
{
	cout << d._year;
	return out;
}

int main()
{
	
	//cout << sizeof(nullptr) << endl;
	////cout << sizeof((void*)0) << end;
	//printf("%d\n", sizeof((void*)0));

	Date d1;
	Date d2(2);
	cout << d1 << d2 << endl;
	system("pause");
	return 0;
}
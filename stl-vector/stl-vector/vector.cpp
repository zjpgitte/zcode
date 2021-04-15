#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include "vector.h"
using namespace std;

void TestVector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.pop_back();
	v1.pop_back();
	v1.erase(v1.begin() + 2);

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	/*vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;*/
	
	/*for (const auto& e: v1)
	{
	cout << e << " ";
	}
	cout << endl;*/
}

void TestVector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
		}
		else
		{
			it++;
		}
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void TestMyVector()
{
	//zjp::vector<int> v(5, 1);
	vector<int> stdv(5, 1);
	auto stditbegin = stdv.begin();
	auto stditend = stdv.end();
	zjp::vector<int> myv(stditbegin, stditend);
	myv.push_back(2);
	myv.push_back(2);
	myv.push_back(2);
	myv.push_back(2);
	myv.push_back(2);
	myv.pop_back();
	myv.pop_back();
	myv.pop_back();
	myv.pop_back();
	
	auto myit = myv.begin();
	while (myit != myv.end())
	{
		cout << *myit << " ";
		myit++;
	}
	cout << endl;
}

void TestMyVector2()
{
	zjp::vector<int> myv;
	myv.resize(5, 2);

	auto it = myv.begin();
	it = myv.insert(it, 3);
	it = myv.insert(it, 3);
	it = myv.insert(it, 3);
	myv.erase(it + 2);
	myv.erase(it + 2);
	myv.erase(it + 2);

	auto myit = myv.begin();
	while (myit != myv.end())
	{
		cout << *myit << " ";
		myit++;

	}
	cout << endl;
}

void TestMyVector3()
{
	zjp::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	
	cout << endl;
}

int main()
{
	
	//TestVector1();
	//TestVector2();
	//TestMyVector2();
	TestMyVector3();
	system("pause");
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

bool Is(const string& A)
{
	size_t left = 0, right = A.size() - 1;
	while (left < right)
	{
		if (A[left] != A[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}

int main()
{
	string s("1234");

	int ret = stoi(s);

	cout << ret << endl;
	return 0;
}

//int main()
//{
//	string A;
//	string B;
//	cin >> A;
//	cin >> B;
//
//
//	int count = 0;
//	for (size_t i = 0; i < A.size(); i++)
//	{
//		string Acopy(A);
//		//ÔÚi²åÈëB´®
//		Acopy.insert(i, B);
//		if (Is(Acopy))
//		{
//			count++;
//		}
//	}
//
//	cout << count;
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//
//
//class A
//{
//	A()
//	{
//
//	}
//};
//
//int main()
//{
//
//	
//	system("pause");
//	return 0;
//}
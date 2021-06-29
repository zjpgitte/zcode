#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class func{
public:
	bool operator() (const int& a, const int & b) {
		return a > b;
	}
};

int main()
{
	
	vector<int> nums = { 1, 2, 7, 3, 8, 2, 1, 34, 0 };

	sort(nums.begin(), nums.end(), func());
	
	system("pause");
	return 0;
}
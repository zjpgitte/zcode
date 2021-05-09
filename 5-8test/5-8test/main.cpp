#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		// 记录两个结点所有祖先存放在两个数组中
		// 找出两个数组最后一个相同的元素
		if (a == b)
		{
			return a;
		}
		vector<int> pArr1;
		vector<int> pArr2;

		// 保存a的所有祖先
		int parent = a;
		pArr1.push_back(parent);
		while (parent != 1)
		{
			parent /= 2;
			pArr1.push_back(parent);
		}
		pArr1.push_back(1);

		//保存b的所有祖先
		parent = b;
		while (parent != 1)
		{
			pArr2.push_back(parent);
			parent /= 2;
		}
		pArr2.push_back(1);

		//找出两数组中最后一个相同元素
		int i = pArr1.size() - 1, j = pArr2.size() - 1;
		while (i >= 0 && j >= 0)
		{
			if (pArr1[i] != pArr2[j])
			{
				break;
			}
			i--;
			j--;
		}

		return pArr1[i + 1];
	}
};

int main()
{
	LCA a;
	cout << a.getLCA(8, 4) << endl;

	return 0;
}

//int main()
//{
//	int b;
//	char a;
//	cin >> b;
//	a = b;
//	int max = 0;
//	int count = 0;
//	int i = 0;
//	while (i < 8)
//	{
//		if (a & (1 << i))
//		{
//			count++;
//			i++;
//		}
//		else
//		{
//			if (count > max)
//			{
//				max = count;
//			}
//			count = 0;
//			i++;
//		}
//	}
//
//	if (count > max)
//	{
//		max = count;
//	}
//
//	cout << max << endl;
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	
//	char a;
//	cin >> a;
//
//	cout << a;
//	
//	system("pause");
//	return 0;
//}
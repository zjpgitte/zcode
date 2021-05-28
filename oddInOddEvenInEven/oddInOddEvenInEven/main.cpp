#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int oddI = 0; // ��¼ż��λ
		int evenI = 1; // ��¼����λ

		while (oddI < arr.size() && evenI < arr.size())
		{
			// ż��λ��������
			while (oddI < arr.size() && arr[oddI] % 2 == 0)
			{
				oddI += 2;
			}

			//����Ϊ����ż��
			while (evenI < arr.size() && arr[evenI] % 2 != 0)
			{
				evenI += 2;
			}

			// ��һ���ߵ�ͷ�ˣ�˵��Ҫô����Ϊȫ��������Ҫôż��λȫ��ż��
			if (oddI >= arr.size() || evenI >= arr.size())
			{
				break;
			}

			swap(arr[oddI], arr[evenI]);
		}
	}
};


int main()
{
	
	
	
	system("pause");
	return 0;
}
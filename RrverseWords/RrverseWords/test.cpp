#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		//�����ַ���
		int cur = 0;//��¼��ǰ���ʵ��±�
		while (cur < s.size())
		{
			//ȷ����������
			int left = cur; //���ʵ�������
			int pos = s.find_first_of(' ', left); //��¼�ո��λ��
			//�Ƿ��ҵ��ո�        
			if (pos == string::npos)
			{
				pos = s.size();
			}

			int right = pos - 1; //���ʵ�������
			//��ת����
			while (left < right)
			{
				swap(s[left], s[right]);
				left++;
				right--;
			}

			cur = pos + 1;

		}

		return s;
	}
};

int main()
{
	
	
	
	system("pause");
	return 0;
}
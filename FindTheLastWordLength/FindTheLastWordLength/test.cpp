#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	//cin >> s;
	getline(cin, s); //���Զ�ȡ�ո�

	//�����һ���ո�
	size_t pos = s.find_last_of(' ');

	if (pos == string::npos) //û�ҵ��ո�
	{
		cout << s.size() << endl;
	}
	else // �ҵ��ո�
	{
		cout << (s.size() - pos - 1) << endl;
	}

	return 0;
}
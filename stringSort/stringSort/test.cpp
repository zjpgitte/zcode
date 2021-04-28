#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int main()
{

	int n;
	cin >> n;
	vector<string> vs;
	vs.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vs[i];
	}
	//lexicographically   lengths
	vector<string> retS;
	//�ж��Ƿ����ֵ���
	int i;
	for (i = 0; i < vs.size() - 1; i++)
	{
		//�ж��Ƿ����ֵ���
		//�������ֵ���
		if (strcmp(vs[i].c_str(), vs[i + 1].c_str()) > 0)
		{
			break;
		}
	}
	if (i == vs.size() - 1)
	{
		retS.push_back("lexicographically");
	}

	//�ж��Ƿ��ǳ�����
	for (i = 0; i < vs.size() - 1; i++)
	{
		if (vs[i].size() > vs[i + 1].size())
		{
			break;
		}
	}
	if (i == vs.size() - 1)
	{
		retS.push_back("lengths");
	}

	if (retS.size() == 0)
	{
		cout << "none" << endl;
	}
	else if (retS.size() == 2)
	{
		cout << "both" << endl;
	}
	else
	{
		cout << retS[0] << endl;
	}

	return 0;
}
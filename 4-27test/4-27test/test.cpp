

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stack>

using namespace std;

class Parenthesis {
public:
	bool Is(char ch)
	{
		if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsLeft(char ch)
	{
		if (ch == '(' || ch == '[' || ch == '{')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Match(char ch1, char ch2)
	{
		if ((ch1 == '(' && ch2 == ')') || (ch1 == '{' && ch2 == '}') || (ch1 == '[' && ch2 == ']'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> st;
		for (int i = 0; i < A.size(); i++)
		{
			//ÅÐ¶ÏÊÇ·ñÊÇÀ¨ºÅ
			if (Is(A[i]))
			{
				if (IsLeft(A[i]))
				{
					//×óÀ¨ºÅÈëÕ»
					st.push(A[i]);

				}
				else
				{
					//ÓÒÀ¨ºÅÅÐ¶ÏÊÇ·ñÆ¥Åä
					if (!st.empty() && Match(st.top(), A[i]))
					{
						st.pop();
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				return false;
			}

		}
		if (st.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	/*Parenthesis p;
	string s("(()())");
	p.chkParenthesis(s, s.size());*/

	stack<int> st;

	int x = st.top();



}


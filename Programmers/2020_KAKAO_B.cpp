#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isBalanced(string str)
{
	stack <char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			s.push('(');
		else
		{
			if (!s.empty())
				s.pop();
			else
				return false;
		}
	}
	return true;
}

string recursion(string w)
{
	string u, v, empty;
	int cnt = 0, flag = 0;

	if (w.size() == 0)
		return "";

	for (int i = 0; i < w.size(); i++)
	{
		if (flag == 0)
		{
			if (w[i] == '(')
				cnt++;
			else
				cnt--;

			u += w[i];

			if (cnt == 0)
				flag = 1;
		}
		else
			v += w[i];
	}

	if (isBalanced(u))
	{
		u += recursion(v);
		empty += u;
	}
	else
	{
		empty += '(';
		empty += recursion(v);
		empty += ')';
		for (int j = 1; j < u.size() - 1; j++)
		{
			if (u[j] == '(')
				empty += ')';
			else
				empty += '(';
		}
	}
	return empty;
}

string solution(string p) {
	string answer = "";
	answer = recursion(p);
	return answer;
}
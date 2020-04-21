#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector <int> a, vector <int> b)
{
	return a.size() < b.size();
}

vector<int> solution(string s) {
	vector <int> answer;
	vector <int> tmp;
	vector <vector<int>> v;
	int num = 0, size = s.size();
	int chk[100001] = { 0, };

	for (int i = 1; i < size - 1; i++)
	{
		if (s[i] == '{')
		{
			tmp.clear();
		}
		else if (s[i] == '}')
		{
			tmp.push_back(num);
			v.push_back(tmp);
			num = 0;
		}
		else if (s[i] == ',')
		{
			if (num != 0)
			{
				tmp.push_back(num);
				num = 0;
			}
		}
		else
		{
			num = num * 10 + (s[i] - '0');
		}
	}
	sort(v.begin(), v.end(), cmp);
	int v_size = v.size();

	for (int i = 0; i < v_size; i++)
	{
		int vv_size = v[i].size();
		for (int j = 0; j < vv_size; j++)
		{
			if (chk[v[i][j]] == 0)
			{
				answer.push_back(v[i][j]);
				chk[v[i][j]] = 1;
			}
		}
	}
	return answer;
}
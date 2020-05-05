#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct st
{
	double num;
	int n;
};

bool cmp(st a, st b)
{
	if (a.num == b.num)
		return a.n < b.n;

	return a.num > b.num;
}

int getUnclear(vector <int> &v, int num)
{
	int sz = v.size();
	int cnt = 0;

	for (int i = 0; i < sz; i++)
	{
		if (v[i] == num)
			cnt++;
	}

	return cnt;
}

int getClear(vector <int> &v, int num)
{
	int sz = v.size();
	int cnt = 0;

	for (int i = 0; i < sz; i++)
	{
		if (v[i] >= num)
			cnt++;
	}

	return cnt;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<st> ans;
	int sz = stages.size(), ex = -1, cnt = 0;
	sort(stages.begin(), stages.end());

	for (int i = 1; i <= N; i++)
	{
		int n1 = getUnclear(stages, i);
		int n2 = getClear(stages, i);
		if (n2 == 0)
			ans.push_back({ 0,i });
		else
			ans.push_back({ n1 / (double)n2,i });
	}
	sort(ans.begin(), ans.end(), cmp);

	for (int i = 0; i < ans.size(); i++)
		answer.push_back(ans[i].n);

	return answer;
}
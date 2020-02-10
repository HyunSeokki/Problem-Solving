#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int answer, chk[9], dist_size;
bool flag;
vector <int> v;

void check(vector<int> weak, int n, int max)
{
	int size = weak.size();
	int v_size = v.size();

	for (int i = 0; i < size; i++)
	{
		int cnt = 0, num;
		vector <int> vv;
		for (int j = 0; j < size; j++)
			vv.push_back((i <= j) ? weak[j] : weak[j] + n);

		sort(vv.begin(), vv.end());

		num = vv[cnt++];
		for (int j = 0; j < v_size; j++)
		{
			while (cnt <= size)
			{
				if (num + v[j] >= vv[cnt])
					cnt++;
				else
				{
					num = vv[cnt++];
					break;
				}
			}
		}
		if (cnt > size)
		{
			answer = max;
			flag = true;
			break;
		}
	}
}

void dfs(int num, int max, vector<int> weak, vector<int> dist, int n)
{
	if (flag)
		return;

	if (num == max)
	{
		check(weak, n, max);
		return;
	}

	for (int i = 0; i < dist_size; i++)
	{
		if (chk[i] == 1)
			continue;

		v.push_back(dist[i]);
		chk[i] = 1;
		dfs(num + 1, max, weak, dist, n);
		chk[i] = 0;
		v.pop_back();
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	answer = 0;
	dist_size = dist.size();

	if (weak.size() == 1)
		return 1;

	for (int i = 1; i <= dist_size; i++)
	{
		dfs(0, i, weak, dist, n);
		if (flag)
			break;
	}
	if (flag == false)
		answer = -1;

	return answer;
}
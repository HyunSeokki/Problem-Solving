#include <stdio.h>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

int n, m;
int cnt[32001];
vector <int> v[32001];
queue <int> q;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		cnt[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 0)
			q.push(i);
	}

	for (int i = 0; i < n; i++)
	{
		int num = q.front();
		q.pop();
		printf("%d ", num);

		int size = v[num].size();
		for (int j = 0; j < size; j++)
		{
			cnt[v[num][j]]--;
			if (cnt[v[num][j]] == 0)
			{
				q.push(v[num][j]);
			}
		}
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int tc, n, m;
int cnt[501], flag = 0;
bool order[501][501];
queue <int> q;
vector <int> ans;

void init()
{
	while (!q.empty())
		q.pop();

	flag = 0;

	for (int i = 0; i < 501; i++)
		cnt[i] = 0;
	//memset(cnt, 0, sizeof(int) * sizeof(cnt));
	ans.clear();
}

int main()
{
	scanf("%d", &tc);

	while (tc--)
	{
		vector <int> v;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int team;
			scanf("%d", &team);
			v.push_back(team);
		}

		int size = v.size();
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				order[v[i]][v[j]] = true;
				order[v[j]][v[i]] = false;
				cnt[v[j]]++;
			}
		}

		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int team1, team2;
			scanf("%d %d", &team1, &team2);
			if (order[team1][team2] == true)
			{
				order[team1][team2] = false;
				order[team2][team1] = true;

				cnt[team1]++;
				cnt[team2]--;
			}
			else
			{
				order[team1][team2] = true;
				order[team2][team1] = false;

				cnt[team1]--;
				cnt[team2]++;
			}
		}

		for (int i = 0; i < size; i++)
		{
			if (cnt[v[i]] == 0)
				q.push(v[i]);
		}

		while (!q.empty())
		{
			if (q.size() >= 2)
			{
				flag = 1;
				break;
			}

			int num = q.front();
			q.pop();

			ans.push_back(num);

			for (int j = 1; j <= n; j++)
			{
				if (order[num][j] == true)
				{
					cnt[j]--;
					if (cnt[j] == 0)
						q.push(j);
				}
			}
		}

		if (flag == 0 && ans.size() == n)
		{
			int ans_size = ans.size();
			for (int i = 0; i < ans.size(); i++)
				printf("%d ", ans[i]);

			printf("\n");
		}
		else if (flag == 1)
			printf("?\n");
		else
			printf("IMPOSSIBLE\n");

		init();
	}

	return 0;
}
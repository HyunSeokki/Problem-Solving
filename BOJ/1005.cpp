#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct st
{
	int num;
	int cnt;
	vector <int> v;
};

int t, n, k, w;
int ans[1001];
st s[1001];
queue <int> q;

void init()
{
	while (!q.empty())
		q.pop();

	memset(ans, 0, sizeof(int) * 1001);
	memset(s, 0, sizeof(struct st) * 1001);

}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &s[i].num);
		}

		for (int i = 0; i < k; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);

			s[x].v.push_back(y);
			s[y].cnt++;
		}

		for (int i = 1; i <= n; i++)
			if (s[i].cnt == 0)
			{
				q.push(i);
				ans[i] = s[i].num;
			}

		for (int i = 1; i <= n; i++)
		{
			int num = q.front();
			q.pop();

			int size = s[num].v.size();
			for (int j = 0; j < size; j++)
			{
				int idx = s[num].v[j];

				ans[idx] = max(ans[idx], ans[num] + s[idx].num);
				s[idx].cnt--;
				if (s[idx].cnt == 0)
					q.push(idx);
			}
		}
		scanf("%d", &w);
		printf("%d\n", ans[w]);

		init();
	}
	return 0;
}
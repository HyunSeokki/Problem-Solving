#include <stdio.h>
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

int n, m, num, ans[10001], maxx = 0;
st s[10001];
queue <int> q;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s[i].num);
		scanf("%d", &m);

		for (int j = 0; j < m; j++)
		{
			scanf("%d", &num);
			s[num].cnt++;
			s[i].v.push_back(num);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (s[i].cnt == 0)
		{
			q.push(i);
			ans[i] = s[i].num;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int num = q.front();
		q.pop();

		int size = s[num].v.size();
		for (int j = 0; j < size; j++)
		{
			int idx = s[num].v[j];
			s[idx].cnt--;
			ans[idx] = max(ans[idx], ans[num] + s[idx].num);

			if (s[idx].cnt == 0)
				q.push(idx);
		}
	}

	for (int i = 1; i <= n; i++)
		maxx = max(maxx, ans[i]);

	printf("%d\n", maxx);
	return 0;
}
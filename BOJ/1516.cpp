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

int n, ans[501];
st building[501];
priority_queue <int> pq;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int num;
		scanf("%d", &num);
		building[i].num = num;

		while (true)
		{
			scanf("%d", &num);
			if (num == -1)
				break;

			building[i].cnt++;
			building[num].v.push_back(i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (building[i].cnt == 0)
		{
			pq.push(i);
			ans[i] = building[i].num;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int num = pq.top();
		pq.pop();

		int size = building[num].v.size();
		for (int j = 0; j < size; j++)
		{
			int idx = building[num].v[j];

			building[idx].cnt--;
			ans[idx] = max(ans[idx], building[idx].num + ans[num]);

			if (building[idx].cnt == 0)
			{
				pq.push(idx);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);

	return 0;
}
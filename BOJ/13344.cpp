#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, cnt = 0;
int ind[50001];
int k[250001], l[250001];
int p[50001];
vector <int> vec[50001];
queue <int> q;

int find(int x)
{
	if (p[x] == x)
		return x;

	return p[x] = find(p[x]);
}

void uni(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
		return;
	else if (u < v)
		p[v] = u;
	else
		p[u] = v;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		p[i] = i;

	for (int i = 0; i < m; i++)
	{
		char op;
		scanf("%d %c %d", &k[cnt], &op, &l[cnt]);

		if (op == '=')
			uni(k[cnt], l[cnt]);
		else
			cnt++;
	}

	for (int i = 0; i < cnt; i++)
	{
		int u = find(k[i]);
		int v = find(l[i]);

		vec[u].push_back(v);
		ind[v]++;
	}

	for (int i = 0; i < n; i++)
		if (ind[i] == 0)
			q.push(i);

	for (int i = 0; i < n; i++)
	{
		if (q.empty())
		{
			printf("inconsistent\n");
			return 0;
		}
		int num = q.front();
		q.pop();

		int size = vec[num].size();
		for (int j = 0; j < size; j++)
		{
			int idx = vec[num][j];
			ind[idx]--;

			if (ind[idx] == 0)
				q.push(idx);
		}
	}

	printf("consistent\n");
	return 0;
}
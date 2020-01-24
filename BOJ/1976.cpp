#include <stdio.h>
using namespace std;


int n, m, u, v;
int parent[201];
int rank[201];
bool flag;

int find(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = find(parent[x]);
}

void uni(int u, int v)
{
	u = find(u);
	v = find(v);

	if (rank[u] > rank[v])
		parent[v] = u;
	else
		parent[u] = v;

	if (rank[u] == rank[v])
		rank[v]++;
}


int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{

			int tmp;
			scanf("%d", &tmp);

			if (i > j)
				continue;

			if (tmp == 1)
			{
				uni(i, j);
			}
		}
	}

	scanf("%d", &u);
	for (int i = 1; i < m; i++)
	{
		scanf("%d", &v);
		if (find(u) == find(v))
		{
			u = v;
		}
		else
		{
			flag = true;
			break;
		}
	}

	if (flag)
		printf("NO");
	else
		printf("YES");

	return 0;
}
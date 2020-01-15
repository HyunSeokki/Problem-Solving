#include<stdio.h>

int n, m;
int parent[1000001];
int rank[1000001];

int find(int x)
{
	if (x == parent[x])
		return x;

	return parent[x] = find(parent[x]);
}

void uni(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;

	if (rank[x] > rank[y])
		parent[y] = x;
	else
		parent[x] = y;

	if (rank[x] == rank[y])
		rank[y]++;

	return;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
		{
			uni(b, c);
		}
		else
		{
			if (find(b) == find(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
#include <stdio.h>
using namespace std;

bool flag;
int g, p, ans = 0;
int plane[100001];

int find(int x)
{
	if (x == plane[x])
		return x;

	return plane[x] = find(plane[x]);
}

void uni(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u > v)
		plane[u] = v;
	else if (u == v)
		plane[u] = u - 1;
	else
		plane[v] = u;
}

int main()
{
	scanf("%d %d", &g, &p);
	for (int i = 1; i <= g; i++)
		plane[i] = i;

	for (int i = 0; i < p; i++)
	{
		int input;
		scanf("%d", &input);

		if (flag)
			continue;
		else
		{
			if (find(plane[input]) == 0 || find(plane[plane[input]]) == 0)
			{
				flag = true;
			}
			else
			{
				uni(plane[input], input);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
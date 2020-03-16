#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int ans[100001];
vector <int> v[100001];
bool visited[100001];

void dfs(int num)
{
	int size = v[num].size();
	for (int i = 0; i < size; i++)
	{
		if (!visited[v[num][i]])
		{
			visited[v[num][i]] = true;
			ans[v[num][i]] = num;
			dfs(v[num][i]);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
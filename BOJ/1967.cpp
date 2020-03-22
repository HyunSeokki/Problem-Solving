#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct st
{
	int num;
	int dist;
};

int v, maxx = 0, max_num;
bool visited[100001], flag = false;
vector <st> vv[100001];
queue <st> q;

void bfs()
{
	while (!q.empty())
	{
		int num = q.front().num;
		int dist = q.front().dist;
		if (dist > maxx)
		{
			maxx = dist;
			max_num = num;
		}
		q.pop();

		int size = vv[num].size();
		for (int i = 0; i < size; i++)
		{
			if (!visited[vv[num][i].num])
			{
				q.push({ vv[num][i].num, dist + vv[num][i].dist });
				visited[vv[num][i].num] = true;
			}
		}

	}
}

int main()
{
	scanf("%d", &v);
	for (int i = 1; i < v; i++)
	{
		int node, num, dist;
		scanf("%d %d %d", &node, &num, &dist);

		vv[node].push_back({ num,dist });
		vv[num].push_back({ node, dist });
	}

	visited[1] = true;
	q.push({ 1,0 });
	bfs();

	memset(visited, false, sizeof(visited));
	maxx = 0;

	visited[max_num] = true;
	q.push({ max_num, 0 });
	bfs();

	printf("%d\n", maxx);
	return 0;
}
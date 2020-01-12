#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>	
using namespace std;

#define INF 0x7fffffff

struct v_st
{
	int v;
	int w;
};
struct pq_st
{
	int v;
	int dist;
};

bool operator<(pq_st a, pq_st b)
{
	return a.dist > b.dist;
}

int v, e, k;
priority_queue <pq_st> pq;
vector<v_st> vv[20001];
int dist[20001];

int main()
{
	scanf("%d %d", &v, &e);
	scanf("%d", &k);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vv[a].push_back({ b,c });
	}
	for (int i = 1; i <= v; i++)
	{
		dist[i] = INF;
		pq.push({ i,(i == k) ? INF - 1 : INF });
	}

	dist[k] = 0;
	while (!pq.empty())
	{
		int pq_v = pq.top().v;
		int pq_dist = pq.top().dist;
		pq.pop();

		int size = vv[pq_v].size();
		for (int i = 0; i < size; i++)
		{
			if (dist[pq_v] + vv[pq_v][i].w < 0)
				continue;
			if (dist[vv[pq_v][i].v] > dist[pq_v] + vv[pq_v][i].w)
			{
				dist[vv[pq_v][i].v] = dist[pq_v] + vv[pq_v][i].w;
				pq.push({ vv[pq_v][i].v, dist[pq_v] + vv[pq_v][i].w });
			}
		}
	}
	for (int i = 1; i <= v; i++)
		(dist[i] == INF) ? printf("INF\n") : printf("%d\n", dist[i]);

	return 0;
}
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define INF 0x7fffffff

int init(vector <int> &a, vector <int> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];

	return tree[node] = min(init(a, tree, node * 2, start, (start + end) / 2), init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}

int search(vector <int> &tree, int node, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return INF;
	else if (left <= start && end <= right)
		return tree[node];

	return min(search(tree, node * 2, start, (start + end) / 2, left, right), search(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int h = (int)ceil(log2(n));
	int size = (1 << (h + 1));

	vector <int> v(n), tree(size);

	for (int i = 0; i < size; i++)
		tree[i] = INF;

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	init(v, tree, 1, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", search(tree, 1, 0, n - 1, a - 1, b - 1));
	}
	return 0;
}

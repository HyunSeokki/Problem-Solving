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

int min_init(vector <int> &a, vector <int> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];

	return tree[node] = min(min_init(a, tree, node * 2, start, (start + end) / 2), min_init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}

int min_search(vector <int> &tree, int node, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return INF;
	else if (left <= start && end <= right)
		return tree[node];

	return min(min_search(tree, node * 2, start, (start + end) / 2, left, right), min_search(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int max_init(vector <int> &a, vector <int> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];

	return tree[node] = max(max_init(a, tree, node * 2, start, (start + end) / 2), max_init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}

int max_search(vector <int> &tree, int node, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return 0;
	else if (left <= start && end <= right)
		return tree[node];

	return max(max_search(tree, node * 2, start, (start + end) / 2, left, right), max_search(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int h = (int)ceil(log2(n));
	int size = (1 << (h + 1));

	vector <int> v(n), min_tree(size), max_tree(size);

	for (int i = 0; i < size; i++)
		min_tree[i] = INF;

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	min_init(v, min_tree, 1, 0, n - 1);
	max_init(v, max_tree, 1, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", min_search(min_tree, 1, 0, n - 1, a - 1, b - 1), max_search(max_tree, 1, 0, n - 1, a - 1, b - 1));
	}
	return 0;
}
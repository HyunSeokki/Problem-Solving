#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m;

ll init(vector <ll> &a, vector <ll> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];

	return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

ll sum(vector <ll> &tree, int node, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main()
{
	scanf("%d %d", &n, &m);
	vector <ll> v(n);
	int h = ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector <ll> tree(tree_size);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	init(v, tree, 1, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", sum(tree, 1, 0, n - 1, a - 1, b - 1));
	}
	return 0;
}
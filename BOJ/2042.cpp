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

int n, m, k;

ll init(vector <ll> &a, vector <ll> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];
	else
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

ll sum(vector <ll> &tree, int node, int start, int end, int left, int right)
{
	if (end < left || start > right)
		return 0;
	else if (left <= start && end <= right)
		return tree[node];

	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector <ll> &tree, int node, int start, int end, int index, ll diff)
{
	if (index < start || end < index)
		return;

	tree[node] = tree[node] + diff;

	if (start != end)
	{
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main()
{
	vector <ll> v;

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		ll tmp;
		scanf("%lld", &tmp);
		v.push_back(tmp);
	}
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector <ll> tree(tree_size);

	init(v, tree, 1, 0, n - 1);

	for (int i = 0; i < m + k; i++)
	{
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1)
		{
			ll diff = c - v[b - 1];
			v[b - 1] = c;
			update(tree, 1, 0, n - 1, b - 1, diff);
		}
		else
		{
			printf("%lld\n", sum(tree, 1, 0, n - 1, b - 1, c - 1));
		}
	}
	return 0;
}
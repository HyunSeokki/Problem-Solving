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

void update_lazy(vector <ll> &tree, vector <ll> &lazy, int node, int start, int end)
{
	if (lazy[node] == 0)
		return;

	tree[node] += (end - start + 1) * lazy[node];
	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}

	lazy[node] = 0;
}

ll init(vector <ll> &a, vector <ll> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];
	else
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

ll sum(vector <ll> &tree, vector <ll> &lazy, int node, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, node, start, end);

	if (end < left || start > right)
		return 0;
	else if (left <= start && end <= right)
		return tree[node];

	return sum(tree, lazy, node * 2, start, (start + end) / 2, left, right) + sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update_range(vector <ll> &tree, vector <ll> &lazy, int node, int start, int end, int left, int right, ll num)
{
	update_lazy(tree, lazy, node, start, end);

	if (right < start || end < left)
		return;
	else if (left <= start && end <= right)
	{
		tree[node] += (end - start + 1) * num;
		if (start != end)
		{
			lazy[node * 2] += num;
			lazy[node * 2 + 1] += num;
		}

		return;
	}

	update_range(tree, lazy, node * 2, start, (start + end) / 2, left, right, num);
	update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, num);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
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
	vector <ll> lazy(tree_size);

	init(v, tree, 1, 0, n - 1);

	for (int i = 0; i < m + k; i++)
	{
		ll a;
		scanf("%lld", &a);
		if (a == 1)
		{
			ll b, c, d;
			scanf("%lld %lld %lld", &b, &c, &d);
			update_range(tree, lazy, 1, 0, n - 1, b - 1, c - 1, d);
		}
		else
		{
			ll b, c;
			scanf("%lld %lld", &b, &c);
			printf("%lld\n", sum(tree, lazy, 1, 0, n - 1, b - 1, c - 1));
		}
	}
	return 0;
}
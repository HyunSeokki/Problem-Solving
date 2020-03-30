#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MOD 1000000007
typedef long long ll;

int n, m, k;

ll init(vector <ll> &a, vector <ll> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];

	return tree[node] = (init(a, tree, node * 2, start, (start + end) / 2) * init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end)) % MOD;
}

ll product(vector <ll> &tree, int node, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return 1;
	else if (left <= start && end <= right)
		return tree[node];

	return (product(tree, node * 2, start, (start + end) / 2, left, right) * product(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;
}

ll update(vector <ll> &tree, int node, int start, int end, int index, int new_num)
{
	if (index < start || end < index)
		return tree[node];
	else if (start == end)
		return tree[node] = new_num;

	return tree[node] = (update(tree, node * 2, start, (start + end) / 2, index, new_num) * update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, new_num)) % MOD;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	vector <ll> v(n);

	for (int i = 0; i < n; i++)
		scanf("%lld", &v[i]);

	int h = ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector <ll> tree(tree_size);

	init(v, tree, 1, 0, n - 1);
	for (int i = 0; i < m + k; i++)
	{
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		if (a == 1)
			update(tree, 1, 0, n - 1, b - 1, c);
		else
			printf("%lld\n", product(tree, 1, 0, n - 1, b - 1, c - 1) % MOD);
	}
	return 0;
}
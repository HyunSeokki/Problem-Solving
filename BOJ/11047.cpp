#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, ans = 0;
vector <int> v;

int main()
{
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.rbegin(), v.rend());

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] <= k)
		{
			ans += k / v[i];
			k %= v[i];
		}
	}

	printf("%d\n", ans);
	return 0;
}
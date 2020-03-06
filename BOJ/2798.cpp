#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, minn = 0x7fffffff, ans;
int num[101];

void select(int sum, int len, int idx)
{
	if (sum > m)
		return;

	if (len == 3)
	{
		int temp = m - sum;

		if (minn > temp)
		{
			minn = temp;
			ans = sum;
		}

		return;
	}

	for (int i = idx; i < n; i++)
	{
		select(sum + num[i], len + 1, i + 1);
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	select(0, 0, 0);

	printf("%d\n", ans);

	return 0;
}
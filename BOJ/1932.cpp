#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int num, maxx = 0;
int dp[502][502];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &num);
			dp[i][j] = max(dp[i - 1][j - 1] + num, dp[i - 1][j] + num);
		}
	}
	for (int i = 1; i <= n; i++)
		maxx = max(maxx, dp[n][i]);

	printf("%d\n", maxx);
	return 0;
}
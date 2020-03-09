#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
long long dp[101][10];
long long ans = 0;

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= 100; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				dp[i][j] += dp[i - 1][1];
			else if (j == 9)
				dp[i][j] += dp[i - 1][8];
			else
			{
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= 1000000000;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		ans += dp[n][i];

	printf("%lld\n", ans % 1000000000);
	return 0;
}
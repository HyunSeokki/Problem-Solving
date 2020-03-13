#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[1001], maxx = 0;
int dp[1001][2];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)
	{
		if (dp[i][0] == 0)
			dp[i][0] = 1;

		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[i][0] < dp[j][0] + 1)
					dp[i][0] = dp[j][0] + 1;
			}
		}
	}

	for (int i = n; i >= 1; i--)
	{
		if (dp[i][1] == 0)
			dp[i][1] = 1;

		for (int j = i; j >= 1; j--)
		{
			if (arr[i] < arr[j])
			{
				if (dp[j][1] < dp[i][1] + 1)
					dp[j][1] = dp[i][1] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		maxx = max(maxx, dp[i][0] + dp[i][1] - 1);

	printf("%d\n", maxx);
	return 0;
}
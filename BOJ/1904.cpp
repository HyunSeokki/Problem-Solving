#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int dp[1000001];

int main()
{
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 1000000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;

	printf("%d\n", dp[n]);
	return 0;
}
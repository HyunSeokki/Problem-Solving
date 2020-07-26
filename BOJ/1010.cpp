#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define INF 0x7fffffff

int t, n, m;
long long top, down;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		top = down = 1;
		scanf("%d %d", &n, &m);
		if (n == m)
		{
			printf("1\n");
			continue;
		}
		else if (m - n < n)
		{
			n = m - n;
		}

		for (long long i = m; i > m - n; i--)
			top *= i;

		for (long long i = 1; i <= n; i++)
			down *= i;

		printf("%lld\n", top / down);
	}

	return 0;
}
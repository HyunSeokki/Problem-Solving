#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, ans[10001], cnt = 1;

bool check(int num)
{
	int count = 0;

	while (num != 0)
	{
		if (num % 10 == 6)
		{
			count++;

			if (count == 3)
				return true;
		}
		else
			count = 0;

		num /= 10;
	}

	return false;
}

int main()
{
	scanf("%d", &n);

	for (int i = 666;; i++)
	{
		if (cnt == 10001)
			break;

		if (check(i))
		{
			ans[cnt++] = i;
		}
	}

	printf("%d\n", ans[n]);

	return 0;
}
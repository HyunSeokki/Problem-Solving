#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
vector <int> v;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)
	{
		if (v.empty())
			v.push_back(arr[i]);
		else
		{
			if (v.back() < arr[i])
				v.push_back(arr[i]);
			else
			{
				auto it = lower_bound(v.begin(), v.end(), arr[i]);
				*it = arr[i];
			}
		}
	}

	printf("%d\n", v.size());
	return 0;
}
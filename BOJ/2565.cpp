#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct st
{
	int a, b;
};

bool cmp(st a, st b)
{
	if (a.a < b.a)
		return true;

	return false;
}

vector <int> v;
st s[501];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &s[i].a, &s[i].b);
	}
	sort(s, s + n, cmp);

	for (int i = 0; i < n; i++)
	{
		if (v.empty())
			v.push_back(s[i].b);
		else
		{
			if (v.back() < s[i].b)
				v.push_back(s[i].b);
			else
			{
				auto it = lower_bound(v.begin(), v.end(), s[i].b);
				*it = s[i].b;
			}
		}
	}

	printf("%d\n", n - v.size());
	return 0;
}
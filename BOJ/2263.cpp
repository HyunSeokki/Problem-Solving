#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int inorder[100001], postorder[100001], pos[100001];

void solve(int in_start, int in_end, int post_start, int post_end)
{
	if (in_start >= in_end || post_start >= post_end)
		return;

	int idx = postorder[post_end - 1];
	printf("%d ", idx);

	solve(in_start, pos[idx], post_start, post_start + (pos[idx] - in_start));
	solve(pos[idx] + 1, in_end, post_start + (pos[idx] - in_start), post_end - 1);

	/*
	for (int i = in_start; i < in_end; i++)
	{
		if (inorder[i] == postorder[post_end - 1])
		{
			idx = i - in_start;
			printf("%d ", inorder[i]);
			break;
		}
	}

	solve(in_start, in_start + idx, post_start, post_start + idx);
	solve(in_start + idx + 1, in_end, post_start + idx, post_end - 1);
	*/
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &inorder[i]);
		pos[inorder[i]] = i;
	}

	for (int i = 0; i < n; i++)
		scanf("%d", &postorder[i]);

	solve(0, n, 0, n);
	return 0;
}
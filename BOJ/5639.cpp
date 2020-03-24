#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Tree {
	Tree *left;
	Tree *right;
	int num = -1;

	void insert(int n)
	{
		if (num == -1)
			num = n;
		else if (n < num)
		{
			if (left == NULL)
				left = new Tree();
			left->insert(n);
		}
		else
		{
			if (right == NULL)
				right = new Tree();
			right->insert(n);
		}
	}
};

void postOrder(Tree *node)
{
	if (node->left != NULL)
		postOrder(node->left);
	if (node->right != NULL)
		postOrder(node->right);

	printf("%d\n", node->num);
}

Tree *head = new Tree();

int main()
{
	while (true)
	{
		int num;
		if (scanf("%d", &num) == EOF)
			break;

		head->insert(num);
	}

	postOrder(head);
	return 0;
}
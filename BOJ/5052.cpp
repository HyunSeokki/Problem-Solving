#include <stdio.h>
#include <string.h>
using namespace std;

struct Trie {

	Trie *next[10];
	bool term;

	Trie() : term(false) {
		for (int i = 0; i <= 9; i++)
			next[i] = 0;
	}
	~Trie() {
		for (int i = 0; i <= 9; i++)
			if (next[i])
				delete next[i];
	}

	void insert(const char* key)
	{
		if (*key == '\0')
			term = true;
		else
		{
			int curr = (*key) - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();

			next[curr]->insert(key + 1);
		}
	}
	int find(const char* key, int size)
	{
		int curr = (*key) - '0';

		if (next[curr] == NULL)
			return 0;

		if (next[curr]->term == true)
			return size;
		return next[curr]->find(key + 1, size + 1);
	}
};

int t, n;
Trie *root;
char input[10001][11];
bool flag;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		root = new Trie();
		flag = true;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			getchar();
			scanf("%s", input[i]);

			root->insert(input[i]);
		}
		for (int i = 0; i < n; i++)
		{
			int chk = root->find(input[i], 1);
			if (chk != strlen(input[i]))
			{
				flag = false;
				break;
			}
		}

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
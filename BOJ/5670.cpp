#include <stdio.h>
#include <string.h>
using namespace std;

struct Trie {

	Trie *next[26];
	int cnt;
	bool term;

	Trie() : term(false), cnt(0) {
		for (int i = 0; i < 26; i++)
			next[i] = 0;
	}

	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i] != NULL)
				delete next[i];
	}

	void insert(const char* key)
	{
		if (*key == '\0')
			term = true;
		else
		{
			int curr = *key - 'a';

			if (next[curr] == NULL)
			{
				next[curr] = new Trie();
				cnt++;
			}

			next[curr]->insert(key + 1);
		}
	}

	int find(const char* key, int push, int idx, int len)
	{
		int curr = *key - 'a';

		if (idx == len)
			return push;

		if (idx < len && term == true)
			push++;
		else if (idx == 0 || cnt != 1)
			push++;

		return next[curr]->find(key + 1, push, idx + 1, len);
	}
};

int n;
char str[100001][81];

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		int push = 0;
		Trie* root = new Trie();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
			root->insert(str[i]);
		}

		for (int i = 0; i < n; i++)
		{
			push += root->find(str[i], 0, 0, strlen(str[i]));
		}
		delete root;

		printf("%.2f\n", (float)push / n);
	}

	return 0;
}
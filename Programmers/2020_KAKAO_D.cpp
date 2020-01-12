#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Trie
{
	Trie *next[26];
	bool term;
	int cnt;

	Trie() : term(false), cnt(0) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0')
			term = true;
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->cnt++;
			next[curr]->insert(key + 1);
		}
	}
	int find(const char* key) {
		int curr = *key - 'a';
		if (next[curr] == NULL)
			return 0;
		if (*(key + 1) == '?')
			return next[curr]->cnt;
		return next[curr]->find(key + 1);
	}
};

Trie *root[10001], *reverse_root[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	int word_size = words.size();
	int queries_size = queries.size();

	for (int i = 0; i < word_size; i++)
	{
		int size = words[i].size();
		if (root[size] == NULL)
			root[size] = new Trie;
		root[size]->insert(words[i].c_str());

		if (reverse_root[size] == NULL)
			reverse_root[size] = new Trie;
		reverse(words[i].begin(), words[i].end());
		reverse_root[size]->insert(words[i].c_str());
	}

	for (int i = 0; i < queries_size; i++)
	{
		int tmp = 0;
		int size = queries[i].size();
		if (queries[i][0] != '?')
		{
			if (root[size] == NULL)
				tmp = 0;
			else
				tmp = root[size]->find(queries[i].c_str());
		}
		else
		{
			if (reverse_root[size] == NULL)
				tmp = 0;
			else if (queries[i][0] == '?' && queries[i][size - 1] == '?')
			{
				for (int i = 0; i < 26; i++)
				{
					if (root[size]->next[i] != NULL)
						tmp += root[size]->next[i]->cnt;
				}
			}
			else
			{
				reverse(queries[i].begin(), queries[i].end());
				tmp = reverse_root[size]->find(queries[i].c_str());
			}
		}
		answer.push_back(tmp);
	}

	return answer;
}
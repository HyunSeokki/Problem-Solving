#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int user_size, banned_size, answer;
int chk[9] = { 0 }, cnt = 0;
set <vector<string>> s;
vector <string> tmp;

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;

	return a.size() < b.size();
}

bool check(string user_id, string banned_id)
{
	if (user_id.size() != banned_id.size())
		return false;

	int user_id_size = user_id.size();
	for (int i = 0; i < user_id_size; i++)
	{
		if (banned_id[i] == '*')
			continue;
		else if (user_id[i] != banned_id[i])
			return false;
	}

	return true;
}

void select(vector<string> user_id, vector<string> banned_id, int user_idx, int banned_idx)
{
	if (banned_idx == banned_size)
	{
		vector <string> sort_tmp;
		sort_tmp.assign(tmp.begin(), tmp.end());
		sort(sort_tmp.begin(), sort_tmp.end(), cmp);
		s.insert(sort_tmp);

		return;
	}

	for (int i = user_idx; i < user_size; i++)
	{
		if (check(user_id[i], banned_id[banned_idx]))
		{
			if (chk[i] == 0)
			{
				chk[i] = 1;
				tmp.push_back(user_id[i]);

				select(user_id, banned_id, 0, banned_idx + 1);

				tmp.pop_back();
				chk[i] = 0;
			}
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	answer = 0;
	user_size = user_id.size();
	banned_size = banned_id.size();

	select(user_id, banned_id, 0, 0);

	return s.size();
}
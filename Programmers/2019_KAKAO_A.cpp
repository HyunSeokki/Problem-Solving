#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map <string, string> m;
	int sz = record.size();

	for (int i = 0; i < sz; i++)
	{
		string command, id, name;
		int n = record[i].find(' ');
		int n1 = record[i].find(' ', n + 1);
		command = record[i].substr(0, n);

		if (command == "Enter")
		{
			id = record[i].substr(n + 1, n1 - n - 1);
			name = record[i].substr(n1 + 1);
			m[id] = name;
		}
		else if (command == "Change")
		{
			id = record[i].substr(n + 1, n1 - n - 1);
			name = record[i].substr(n1 + 1);
			m[id] = name;
		}
	}

	for (int i = 0; i < sz; i++)
	{
		string command, id, name;
		int n = record[i].find(' ');
		int n1 = record[i].find(' ', n + 1);
		command = record[i].substr(0, n);

		if (command == "Enter")
		{
			id = record[i].substr(n + 1, n1 - n - 1);
			string ans = m[id] + "님이 들어왔습니다.";
			answer.push_back(ans);
		}
		else if (command == "Leave")
		{
			id = record[i].substr(n + 1, n1 - n);
			string ans = m[id] + "님이 나갔습니다.";
			answer.push_back(ans);
		}
	}

	return answer;
}
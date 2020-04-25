#include <string>
#include <vector>
#include <map>
using namespace std;

long long f(map <long long, long long> &m, long long x)
{
	if (m[x] == 0)
	{
		m[x] = x + 1;
		return x;
	}

	return m[x] = f(m, m[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	map <long long, long long> m;
	int sz = room_number.size();

	for (int i = 0; i < sz; i++)
	{
		answer.push_back(f(m, room_number[i]));
	}
	return answer;
}
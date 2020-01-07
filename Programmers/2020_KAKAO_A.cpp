#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
	int answer = 0x7fffffff;
	int size = s.size();
	int len = 1;
	string first = "", second = "", result = "";

	if (s.size() == 1)
		return 1;

	for (int i = 1; i < size; i++)
	{
		first = s.substr(0, i);
		for (int j = i; j < size;)
		{
			second = s.substr(j, i);
			if (j + i >= size)
			{
				if (first == second)
				{
					len++;
					result += to_string(len) + first;
				}
				else
				{
					result += (len == 1 ? "" : to_string(len)) + first + second;
				}
				break;
			}
			else
			{
				if (first == second)
				{
					len++;
				}
				else
				{
					result += (len == 1 ? "" : to_string(len)) + first;
					first = second;
					len = 1;
				}
				j += i;
			}
		}
		answer = min(answer, (int)result.size());
		result = "";
		len = 1;
	}

	return answer;
}
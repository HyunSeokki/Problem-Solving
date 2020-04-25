#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	int sz = stones.size();
	int left = 0, right = 200000000;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 0;
		int jumpAll = 1;

		for (int i = 0; i < sz; i++)
		{
			if (stones[i] - mid < 0)
			{
				cnt++;
				if (cnt >= k)
				{
					jumpAll = 0;
					break;
				}
			}
			else
				cnt = 0;
		}
		if (jumpAll)
		{
			left = mid + 1;
			answer = mid;
		}
		else
			right = mid - 1;
	}
	return answer;
}
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int n = board.size();
	int moves_size = moves.size();

	stack <int> s[31], result;

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (board[j][i] != 0)
				s[i].push(board[j][i]);
		}
	}

	for (int i = 0; i < moves_size; i++)
	{
		int idx = moves[i] - 1;
		if (!s[idx].empty())
		{
			int num = s[idx].top();
			s[idx].pop();

			if (!result.empty() && result.top() == num)
			{
				answer += 2;
				result.pop();
			}
			else
			{
				result.push(num);
			}
		}
	}

	return answer;
}
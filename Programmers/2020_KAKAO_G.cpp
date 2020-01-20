#include <string>
#include <vector>
#include <queue>
using namespace std;

struct st
{
	int y;
	int x;
	int dir;
	int cnt;
};

queue <st> q;
bool visited[101][101][2];
int answer, board_size;

void bfs(vector<vector<int>> board)
{
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		int cnt = q.front().cnt;
		q.pop();

		if (dir == 0)
		{
			if (y == board_size - 1 && x + 1 == board_size - 1)
			{
				answer = cnt;
				break;
			}
			//위
			if (y - 1 >= 0 && !visited[y - 1][x][dir])
			{
				if (board[y - 1][x] == 0 && board[y - 1][x + 1] == 0)
				{
					visited[y - 1][x][dir] = true;
					q.push({ y - 1,x,dir,cnt + 1 });
				}
			}
			//아래
			if (y + 1 < board_size && !visited[y + 1][x][dir])
			{
				if (board[y + 1][x] == 0 && board[y + 1][x + 1] == 0)
				{
					visited[y + 1][x][dir] = true;
					q.push({ y + 1,x,dir,cnt + 1 });
				}
			}
			//왼
			if (x - 1 >= 0 && !visited[y][x - 1][dir])
			{
				if (board[y][x - 1] == 0)
				{
					visited[y][x - 1][dir] = true;
					q.push({ y,x - 1,dir,cnt + 1 });
				}
			}
			//오
			if (x + 2 < board_size && !visited[y][x + 1][dir])
			{
				if (board[y][x + 1] == 0 && board[y][x + 2] == 0)
				{
					visited[y][x + 1][dir] = true;
					q.push({ y,x + 1,dir,cnt + 1 });
				}
			}
			if (y + 1 < board_size && x + 1 < board_size && board[y + 1][x] == 0 && board[y + 1][x + 1] == 0)
			{
				if (!visited[y][x + 1][1])
				{
					visited[y][x + 1][1] = true;
					q.push({ y,x + 1,1,cnt + 1 });
				}
				if (!visited[y][x][1])
				{
					visited[y][x][1] = true;
					q.push({ y,x,1,cnt + 1 });
				}
			}
			if (y - 1 >= 0 && x + 1 < board_size && board[y - 1][x] == 0 && board[y - 1][x + 1] == 0)
			{
				if (!visited[y - 1][x][1])
				{
					visited[y - 1][x][1] = true;
					q.push({ y - 1,x,1,cnt + 1 });
				}
				if (!visited[y - 1][x + 1][1])
				{
					visited[y - 1][x + 1][1] = true;
					q.push({ y - 1,x + 1,1,cnt + 1 });
				}
			}
		}
		else
		{
			if (y + 1 == board_size - 1 && x == board_size - 1)
			{
				answer = cnt;
				break;
			}
			//위
			if (y - 1 >= 0 && !visited[y - 1][x][dir])
			{
				if (board[y - 1][x] == 0)
				{
					visited[y - 1][x][dir] = true;
					q.push({ y - 1,x,dir,cnt + 1 });
				}
			}
			//아래
			if (y + 2 < board_size && !visited[y + 1][x][dir])
			{
				if (board[y + 1][x] == 0 && board[y + 2][x] == 0)
				{
					visited[y + 1][x][dir] = true;
					q.push({ y + 1,x,dir,cnt + 1 });
				}
			}
			//왼
			if (x - 1 >= 0 && !visited[y][x - 1][dir])
			{
				if (board[y][x - 1] == 0 && board[y + 1][x - 1] == 0)
				{
					visited[y][x - 1][dir] = true;
					q.push({ y,x - 1,dir,cnt + 1 });
				}
			}
			//오
			if (x + 1 < board_size && !visited[y][x + 1][dir])
			{
				if (board[y][x + 1] == 0 && board[y + 1][x + 1] == 0)
				{
					visited[y][x + 1][dir] = true;
					q.push({ y,x + 1,dir,cnt + 1 });
				}
			}
			if (x - 1 >= 0 && y + 1 < board_size && board[y][x - 1] == 0 && board[y + 1][x - 1] == 0)
			{
				if (!visited[y + 1][x - 1][0])
				{
					visited[y + 1][x - 1][0] = true;
					q.push({ y + 1,x - 1,0,cnt + 1 });
				}
				if (!visited[y][x - 1][0])
				{
					visited[y][x - 1][0] = true;
					q.push({ y,x - 1,0,cnt + 1 });
				}
			}
			if (x + 1 < board_size && y + 1 < board_size && board[y][x + 1] == 0 && board[y + 1][x + 1] == 0)
			{
				if (!visited[y + 1][x][0])
				{
					visited[y + 1][x][0] = true;
					q.push({ y + 1,x,0,cnt + 1 });
				}
				if (!visited[y][x][0])
				{
					visited[y][x][0] = true;
					q.push({ y,x,0,cnt + 1 });
				}
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	answer = 0;
	board_size = board.size();

	visited[0][0][0] = true;
	q.push({ 0,0,0,0 });
	bfs(board);
	return answer;
}
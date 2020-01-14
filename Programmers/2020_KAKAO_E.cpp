#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101][2];

bool make_col(int x, int y, int n)
{
	if (0 > x || x > n || 0 > y || y > n)
		return true;

	if (y == 0)
		return true;
	if (y - 1 >= 0 && map[y - 1][x][0] == 1)
		return true;
	if ((x - 1 >= 0 && map[y][x - 1][1] == 1) || map[y][x][1] == 1)
		return true;

	return false;
}

bool make_row(int x, int y, int n)
{
	if (0 > x || x > n || 0 > y || y > n)
		return true;

	if ((y - 1 >= 0 && map[y - 1][x][0] == 1) || (x + 1 <= n && map[y - 1][x + 1][0] == 1))
		return true;
	if (x - 1 >= 0 && x + 1 < n && map[y][x - 1][1] == 1 && map[y][x + 1][1] == 1)
		return true;

	return false;
}

bool cmp(vector<int> a, vector<int> b)
{
	if (a[0] == b[0] && a[1] == b[1])
		return a[2] < b[2];
	else if (a[0] == b[0])
		return a[1] < b[1];

	return a[0] < b[0];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	int size = build_frame.size();

	for (int i = 0; i < size; i++)
	{
		int x, y, a, b;
		x = build_frame[i][0];
		y = build_frame[i][1];
		a = build_frame[i][2];
		b = build_frame[i][3];

		if (a == 0)
		{
			if (b == 0)
			{
				map[y][x][0] = 0;
				if (y + 1 <= n && map[y + 1][x][0] == 1 && !make_col(x, y + 1, n))
				{
					map[y][x][0] = 1;
					continue;
				}
				if (y + 1 <= n && x - 1 >= 0 && map[y + 1][x - 1][1] == 1 && !make_row(x - 1, y + 1, n))
				{
					map[y][x][0] = 1;
					continue;
				}
				if (y + 1 <= n && map[y + 1][x][1] == 1 && !make_row(x, y + 1, n))
				{
					map[y][x][0] = 1;
					continue;
				}
			}
			else
			{
				if (make_col(x, y, n))
					map[y][x][0] = 1;
			}
		}
		else
		{
			if (b == 0)
			{
				map[y][x][1] = 0;
				if (map[y][x][0] == 1 && !make_col(x, y, n))
				{
					map[y][x][1] = 1;
					continue;
				}
				if (x + 1 <= n && map[y][x + 1][0] == 1 && !make_col(x + 1, y, n))
				{
					map[y][x][1] = 1;
					continue;
				}
				if (x - 1 >= 0 && map[y][x - 1][1] == 1 && !make_row(x - 1, y, n))
				{
					map[y][x][1] = 1;
					continue;
				}
				if (x + 1 <= n && map[y][x + 1][1] == 1 && !make_row(x + 1, y, n))
				{
					map[y][x][1] = 1;
					continue;
				}
			}
			else
			{
				if (make_row(x, y, n))
					map[y][x][1] = 1;
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (map[i][j][0] == 1)
				answer.push_back({ j,i,0 });
			if (map[i][j][1] == 1)
				answer.push_back({ j,i,1 });
		}
	}

	sort(answer.begin(), answer.end(), cmp);
	return answer;
}
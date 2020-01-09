#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> v)
{
	vector<vector<int>> ans;
	int size = v.size();

	for (int i = 0; i < size; i++)
	{
		vector<int> tmp;
		for (int j = size - 1; j >= 0; j--)
		{
			tmp.push_back(v[j][i]);
		}
		ans.push_back(tmp);
	}

	return ans;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	vector<vector<int>> three_lock;
	int size = lock.size();
	int k_size = key.size();
	int cnt = 0, lock_cnt = 0;

	for (int i = 1; i < size * 3 - 1; i++)
	{
		vector<int> tmp;
		if (size <= i && i < size * 2)
		{
			for (int j = 1; j < size * 3 - 1; j++)
			{
				if (size <= j && j < size * 2)
				{
					if (lock[i%size][j%size] == 0)
						lock_cnt++;
					tmp.push_back(lock[i%size][j%size]);
				}

				else
					tmp.push_back(0);
			}
		}
		else
		{
			for (int j = 1; j < size * 3 - 1; j++)
			{
				tmp.push_back(0);
			}
		}
		three_lock.push_back(tmp);
	}

	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < size * 3 - 2; i++)
		{
			for (int j = 0; j < size * 3 - 2; j++)
			{
				for (int ii = 0; ii < k_size; ii++)
				{
					for (int jj = 0; jj < k_size; jj++)
					{
						if (size - 1 <= i + ii && i + ii < size * 2 - 1 && size - 1 <= j + jj && j + jj < size * 2 - 1)
						{
							if (key[ii][jj] == 1 && three_lock[i + ii][j + jj] == 0)
							{
								cnt++;
							}
							else if (key[ii][jj] == 1 && three_lock[i + ii][j + jj] == 1)
							{
								cnt = 0;
								break;
							}
						}
					}
				}
				if (cnt == lock_cnt)
				{
					return true;
				}
				cnt = 0;
			}
		}
		key = rotate(key);
	}

	return false;
}
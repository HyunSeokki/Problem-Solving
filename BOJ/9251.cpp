#include <stdio.h>
#include <string.h>
#include<algorithm>

using namespace std;

int map[1002][1002];
char str[2][1002];
int str_size[2];
int maxx = 0;

int main()
{
	scanf("%s", str[0]);
	scanf("%s", str[1]);

	str_size[0] = strlen(str[0]);
	str_size[1] = strlen(str[1]);

	for (int i = 0; i < str_size[0]; i++)
	{
		for (int j = 0; j < str_size[1]; j++)
		{
			if (str[0][i] == str[1][j])
			{
				map[i + 1][j + 1] = map[i][j] + 1;
			}
			else
			{
				map[i + 1][j + 1] = max(map[i][j + 1], map[i + 1][j]);
			}
			maxx = max(maxx, map[i + 1][j + 1]);
		}
	}
	printf("%d\n", maxx);

	return 0;
}
#include <iostream>
#include <string>
#include <map>
using namespace std;

int t, F;
map <string, int> level;
map <string, string> parent;

string find(string x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = find(parent[x]);
}

void uni(string u, string v)
{
	u = find(u);
	v = find(v);

	if (level[u] > level[v])
	{
		parent[v] = u;
		level[u] += level[v];
	}
	else
	{
		parent[u] = v;
		level[v] += level[u];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> F;
		level.clear();
		parent.clear();

		for (int i = 0; i < F; i++)
		{
			string a, b;
			cin >> a >> b;

			if (parent.find(a) == parent.end())
			{
				parent[a] = a;
				level[a] = 1;
			}
			if (parent.find(b) == parent.end())
			{
				parent[b] = b;
				level[b] = 1;
			}

			string pa_a = find(a);
			string pa_b = find(b);

			if (pa_a == pa_b)
			{
				cout << level[pa_a] << '\n';
			}
			else
			{
				cout << level[pa_a] + level[pa_b] << '\n';
				uni(a, b);
			}
		}
	}
	return 0;
}
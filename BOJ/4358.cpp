#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string, int> m;
map <string, int>::iterator iter;
string str;
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (getline(cin, str)) {
		if (cin.eof())
			break;
		m[str]++;
		cnt++;
	}

	cout << fixed;
	cout.precision(4);

	for (iter = m.begin(); iter != m.end(); iter++)
		cout << iter->first << ' ' << (iter->second / (double)cnt) * 100 << '\n';

	return 0;
}
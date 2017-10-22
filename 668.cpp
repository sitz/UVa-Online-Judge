#include <bits/stdc++.h>

using namespace std;

void solve(int n)
{
	int x = (int)floor(sqrt(8 * n + 9) - 3) / 2;
	int discard = (x + 1) * (4 + x) / 2 - n;
	int i;
	int p[10000], num = 0;
	if (discard != 1)
	{
		for (i = 2; i <= x + 2; i++)
		{
			if (i != discard)
			{
				p[num++] = i;
			}
		}
		for (i = 0; i < num - 1; i++)
		{
			cout << p[i] << ' ';
		}
		cout << p[num - 1] << endl;
	}
	else
	{
		for (i = 3; i <= x + 2; i++)
		{
			p[num++] = i;
		}
		p[num - 1]++;
		for (i = 0; i < num - 1; i++)
		{
			cout << p[i] << ' ';
		}
		cout << p[num - 1] << endl;
	}
}
int main()
{
	int N;
	int i, t;
	cin >> t;
	int f = 0;
	for (i = 0; i < t; i++)
	{
		if (f)
		{
			cout << endl;
		}
		f = 1;
		cin >> N;
		solve(N);
	}
	return 0;
}

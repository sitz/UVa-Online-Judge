#include <bits/stdc++.h>

using namespace std;

#define for if (0); else for

int n, K, p;
int d[16][16];
int bit[16];
int a[16];

void done()
{
	int res = 0;
	for (int c = 0; c < (1 << n); ++c)
	{
		int ft = 0;
		for (int i = 0; i < n; ++i)
		{
			if (bit[i] & c)
			{
				a[i] = 1, ft++;
			}
			else
			{
				a[i] = 0;
			}
		}
		if (ft == K)
		{
			int f = 1;
			for (int i = 0; i < n; ++i)
			{
				if (a[i] == 0)
				{
					int x = 0;
					for (int j = 0; j < n; ++j)
					{
						if (d[i][j] && a[j] == 1)
						{
							x++;
						}
					}
					if (x > 1)
					{
						f = 0;
						break;
					}
				}
			}
			if (f)
			{
				res++;
			}
		}
	}
	cout << res << endl;
}
int main()
{
	for (int i = 0; i < 16; ++i)
	{
		bit[i] = 1 << i;
	}
	string s;
	while (cin >> s)
	{
		cout << s << endl;
		if (s == "TheEnd")
		{
			break;
		}
		cin >> n >> K >> p;
		memset(d, 0, sizeof(d));
		for (int i = 0; i < p; ++i)
		{
			cin >> s;
			d[s[0] - 'A'][s[1] - 'A'] = 1;
			d[s[1] - 'A'][s[0] - 'A'] = 1;
		}
		done();
	}
	return 0;
}

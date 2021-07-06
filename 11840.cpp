#include <bits/stdc++.h>

using namespace std;

#define MAX 2000000000
#define _match(a, b) ((a) == (b))

bool mark[11000];
char s[11000];
int main()
{
	int sg[11000];
	sg[0] = 0;
	sg[1] = 1;
	sg[2] = 1;
	int i, j;
	for (i = 3; i <= 10000; i++)
	{
		memset(mark, 0, sizeof(mark));
		for (j = 1; j <= i; j++)
		{
			int x, y;
			x = j - 3;
			y = j + 2;
			if (x < 0)
			{
				x = 0;
			}
			if (y > i)
			{
				y = i;
			}
			y = i - y;
			mark[sg[x] ^ sg[y]] = true;
		}
		for (j = 0; j >= 0; j++)
			if (!mark[j])
			{
				sg[i] = j;
				break;
			}
	}
	int d[4] = {-2, -1, 1, 2};
	int x, n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		scanf("%s", s);
		memset(mark, 0, sizeof(mark));
		bool ff = false;
		for (i = 0; i < n; i++)
		{
			if (s[i] != 'X')
			{
				continue;
			}
			mark[i] = true;
			for (j = 0; j < 4; j++)
			{
				x = i + d[j];
				if (x < 0)
				{
					x = 0;
				}
				if (x >= n)
				{
					x = n - 1;
				}
				mark[x] = true;
				if (x != i && s[x] == 'X')
				{
					ff = true;
				}
			}
		}
		if (ff)
		{
			cout << "S" << endl;
			continue;
		}
		int ans = 0;
		for (i = 0; i < n; i++)
		{
			if (!mark[i])
			{
				for (j = i; j < n; j++)
				{
					if (mark[j])
					{
						break;
					}
				}
				x = j - i;
				ans = ans ^ sg[x];
				i = j;
			}
		}
		if (ans)
		{
			cout << "S" << endl;
		}
		else
		{
			cout << "N" << endl;
		}
	}
	return 0;
}

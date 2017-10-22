#include <bits/stdc++.h>

using namespace std;

int a[40];
int main()
{
	int t;
	cin >> t;
	int c, d;
	while (t--)
	{
		cin >> c >> d;
		bool re = 1;
		;
		int len = 0;
		while (c || d)
		{
			if ((d & 1) == 1 && (c & 1) == 1)
			{
				a[len] = 1;
			}
			else if ((d & 1) == 1 && (c & 1) == 0)
			{
				a[len] = 2;
			}
			else if ((d & 1) == 0 && (c & 1) == 1)
			{
				re = 0;
				break;
			}
			else if ((d & 1) == 0 && (c & 1) == 0)
			{
				a[len] = 0;
			}
			len++;
			c = c >> 1;
			d = d >> 1;
		}
		if (re == 0)
		{
			cout << "-1\n";
		}
		else
		{
			bool first = 0;
			int aa = 0, bb = 0;
			for (int i = len - 1; i >= 0; i--)
				if (a[i] == 1)
				{
					aa = aa * 2 + 1;
					bb = bb * 2 + 1;
				}
				else if (a[i] == 0)
				{
					aa *= 2;
					bb *= 2;
				}
				else
				{
					if (first == 0)
					{
						aa = aa * 2 + 1;
						bb = bb * 2;
						first = 1;
					}
					else
					{
						aa = aa * 2;
						bb = bb * 2 + 1;
					}
				}
			cout << bb << " " << aa << "\n";
		}
	}
	return 0;
}

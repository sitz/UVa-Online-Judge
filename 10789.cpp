#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, x[62], p[303], c1 = 5, j;
	char c[2002];
	bool b;
	p[0] = 2;
	p[1] = 3;
	p[2] = 5;
	p[3] = 7;
	p[4] = 11;
	p[5] = 13;
	for (int i = 17; i <= 2002; i += 2)
	{
		for (j = 1; p[j] <= sqrt((double)i); j++)
			if (i % p[j] == 0)
			{
				break;
			}
		if (i % p[j] != 0)
		{
			c1++;
			p[c1] = i;
		}
	}
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> c;
		for (int j = 0; j < 62; j++)
		{
			x[j] = 0;
		}
		for (int j = 0; c[j] != '\0'; j++)
		{
			if (c[j] <= '9')
			{
				x[c[j] - '0']++;
			}
			else if (c[j] <= 'Z')
			{
				x[c[j] - 'A' + 10]++;
			}
			else
			{
				x[c[j] - 'a' + 36]++;
			}
		}
		cout << "Case " << i << ": ";
		b = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 303; j++)
			{
				if (x[i] == p[j])
				{
					cout << (char)('0' + i);
					b = 1;
					break;
				}
			}
		}
		for (int i = 10; i < 36; i++)
		{
			for (int j = 0; j < 303; j++)
			{
				if (x[i] == p[j])
				{
					cout << (char)('A' + i - 10);
					b = 1;
					break;
				}
			}
		}
		for (int i = 36; i < 62; i++)
		{
			for (int j = 0; j < 303; j++)
			{
				if (x[i] == p[j])
				{
					cout << (char)('a' + i - 36);
					b = 1;
					break;
				}
			}
		}
		if (b == 0)
		{
			cout << "empty";
		}
		cout << endl;
	}
	return 0;
}

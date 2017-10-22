#include <bits/stdc++.h>

using namespace std;

const int MAXL = 1001;

// roman numeral to int
int getNum(char ch)
{
	switch (ch)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return -1;
	}
}

char str[MAXL], chr[MAXL];
void getShortest(int val)
{
	int l = 0;
	if (val >= 1000)
	{
		int t = val / 1000;
		for (int i = 1; i <= t; i++)
		{
			chr[l++] = 'M';
		}
		val -= t * 1000;
	}
	if (val >= 100)
	{
		int t = val / 100;
		if (t != 4 && t != 9)
		{
			if (t < 5)
				for (int i = 1; i <= t; i++)
				{
					chr[l++] = 'C';
				}
			else
			{
				chr[l++] = 'D';
				for (int i = 6; i <= t; i++)
				{
					chr[l++] = 'C';
				}
			}
		}
		else
		{
			if (t == 4)
			{
				chr[l++] = 'C';
				chr[l++] = 'D';
			}
			else
			{
				chr[l++] = 'C';
				chr[l++] = 'M';
			}
		}
		val -= t * 100;
	}
	if (val >= 10)
	{
		int t = val / 10;
		if (t != 4 && t != 9)
		{
			if (t < 5)
				for (int i = 1; i <= t; i++)
				{
					chr[l++] = 'X';
				}
			else
			{
				chr[l++] = 'L';
				for (int i = 6; i <= t; i++)
				{
					chr[l++] = 'X';
				}
			}
		}
		else
		{
			if (t == 4)
			{
				chr[l++] = 'X';
				chr[l++] = 'L';
			}
			else
			{
				chr[l++] = 'X';
				chr[l++] = 'C';
			}
		}
		val -= t * 10;
	}
	if (val > 0)
	{
		int t = val;
		if (t != 4 && t != 9)
		{
			if (t < 5)
				for (int i = 1; i <= t; i++)
				{
					chr[l++] = 'I';
				}
			else
			{
				chr[l++] = 'V';
				for (int i = 6; i <= t; i++)
				{
					chr[l++] = 'I';
				}
			}
		}
		else
		{
			if (t == 4)
			{
				chr[l++] = 'I';
				chr[l++] = 'V';
			}
			else
			{
				chr[l++] = 'I';
				chr[l++] = 'X';
			}
		}
		val = 0;
	}
	chr[l] = '\0';
}
void solve()
{
	int l1 = strlen(str);
	int l2 = strlen(chr);
	int ae, ac, res;
	res = 100000000;
	ae = ac = 0;
	for (int i = 0; i < l1; i++)
	{
		int e = 0, c = 0;
		for (int j = 0; j < l2; j++)
			if (chr[j] == str[i + j])
			{
				e++;
			}
		c = l2 - e;
		e = l1 - e;
		if (e + c < res || (e + c == res && e < ae))
		{
			res = e + c;
			ae = e;
			ac = c;
		}
	}
	printf("%d %d\n", ae, ac);
}

int main()
{
	while (gets(str))
	{
		if (strcmp(str, "*") == 0)
		{
			break;
		}
		int val = 0;
		for (int i = 0; str[i]; i++)
		{
			val += getNum(str[i]);
		}
		getShortest(val);
		solve();
	}
	return 0;
}

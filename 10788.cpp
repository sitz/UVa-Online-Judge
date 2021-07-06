#include <bits/stdc++.h>

using namespace std;

/*
10788.
Parenthesizing Palindromes
*/

#define maxn 102
char F[maxn][maxn];
int Cost[maxn][maxn];
char ss[maxn];
int Impos()
{
	int ff[30] = {0};
	int i, j;
	for (i = 0; ss[i]; i++)
	{
		j = ss[i] - 'a';
		ff[j]++;
	}
	for (i = 0; i < 26; i++)
		if (ff[i] % 2)
		{
			return 1;
		}
	return 0;
}
int Recur(int l, int r)
{
	int i, c = 0, d, k;
	d = r - l + 1;
	if (F[l][r])
	{
		return Cost[l][r];
	}
	if (d % 2)
	{
		return 0;
	}
	if (d == 2)
	{
		if (ss[l] == ss[r])
		{
			Cost[l][r] = 1;
			return 1;
		}
		return 0;
	}
	F[l][r] = 1;
	if (ss[l] == ss[r])
	{
		c = Recur(l + 1, r - 1);
	}
	for (i = l + 1; i + 1 < r; i += 2)
	{
		if (ss[l] != ss[i])
		{
			continue;
		}
		d = Recur(l, i);
		k = Recur(i + 1, r);
		c += d * k;
	}
	Cost[l][r] = c;
	return c;
}
void Cal()
{
	int i, l, r, c = 0, d;
	l = strlen(ss);
	if (l % 2 || Impos())
	{
		cout << "Invalid\n";
		return;
	}
	if (l == 2)
	{
		if (ss[0] == ss[1])
		{
			cout << "Valid, Unique\n";
		}
		else
		{
			cout << "Invalid\n";
		}
		return;
	}
	if (ss[0] == ss[l - 1])
	{
		c = Recur(1, l - 2);
	}
	for (i = 1; i + 2 < l; i += 2)
	{
		if (ss[0] != ss[i])
		{
			continue;
		}
		r = Recur(0, i);
		d = 0;
		if (r)
		{
			d = Recur(i + 1, l - 1);
		}
		c += r * d;
		if (c > 1)
		{
			break;
		}
	}
	if (c > 1)
	{
		cout << "Valid, Multiple\n";
	}
	else if (c == 1)
	{
		cout << "Valid, Unique\n";
	}
	else
	{
		cout << "Invalid\n";
	}
}
int main()
{
	int k, c = 1;
	cin >> k;
	while (k--)
	{
		cin >> ss;
		cout << "Case " << c++ << ": ";
		Cal();
		memset(F, 0, maxn * maxn);
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

char ss[102];
int fre[30], cnt, len;

int f()
{
	int i, j;
	len = strlen(ss);
	for (i = 0; ss[i]; i++)
	{
		j = ss[i] - 'a';
		fre[j]++;
	}
	j = 0;
	for (i = 0; i < 26; i++)
	{
		if (fre[i] % 2)
		{
			j++;
		}
	}
	if (j > 1)
	{
		return 1;
	}
	if (j > 0 && len % 2 == 0)
	{
		return 1;
	}
	return 0;
}
int FindB(int n, int m, char ch)
{
	int i;
	for (i = m; i > n; i--)
		if (ss[i] == ch)
		{
			break;
		}
	return i;
}
int FindF(int n, int m, char ch)
{
	int i;
	for (i = n; i < m; i++)
		if (ss[i] == ch)
		{
			break;
		}
	return i;
}
void MoveB(int n, int m, char ch)
{
	int i;
	for (i = n; i < m; i++)
	{
		ss[i] = ss[i + 1];
	}
	ss[m] = ch;
}

void MoveF(int n, int m, char ch)
{
	int i;
	for (i = m; i > n; i--)
	{
		ss[i] = ss[i - 1];
	}
	ss[n] = ch;
}

void recur(int lo, int up)
{
	int k, l, ind1, d1, d2, ind2;
	if (lo >= up)
	{
		return;
	}
	k = ss[lo] - 'a';
	l = ss[up] - 'a';
	if (ss[lo] == ss[up])
	{
		recur(lo + 1, up - 1);
	}
	else
	{
		d1 = d2 = 1000;
		if (fre[k] > 1)
		{
			ind1 = FindB(lo, up, ss[lo]);
			d1 = up - ind1;
		}
		if (fre[l] > 1)
		{
			ind2 = FindF(lo, up, ss[up]);
			d2 = ind2 - lo;
		}
		if (d1 <= d2)
		{
			cnt += d1;
			MoveB(ind1, up, ss[lo]);
			fre[k] -= 2;
			recur(lo + 1, up - 1);
		}
		else
		{
			cnt += d2;
			MoveF(lo, ind2, ss[up]);
			fre[l] -= 2;
			recur(lo + 1, up - 1);
		}
	}
}

void cal()
{
	if (f())
	{
		printf("Impossible\n");
		return;
	}
	cnt = 0;
	recur(0, strlen(ss) - 1);
	cout << cnt << endl;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		cin >> ss;
		cal();
		for (int i = 0; i < 26; i++)
		{
			fre[i] = 0;
		}
	}
	return 0;
}

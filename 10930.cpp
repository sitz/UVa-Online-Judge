#include <bits/stdc++.h>

using namespace std;

/*
10930
*/

#define maxn 40
char Fg[31000];
int A[maxn];
int Recur(int n, int sum, int level, int lim, int k)
{
	int i, j = sum, d;
	if (level > 1 && Fg[sum] == 1)
	{
		return 1;
	}
	for (i = n + 1; i < k; i++)
	{
		if (A[i] + sum > lim)
		{
			return 0;
		}
		d = Recur(i, A[i] + sum, level + 1, lim, k);
		if (d)
		{
			return 1;
		}
	}
	return 0;
}
void Cal(int n)
{
	int d, k;
	for (k = 1; k < n; k++)
	{
		d = Recur(k, A[k], 1, A[n], n);
		if (d)
		{
			break;
		}
	}
	if (d == 0)
	{
		cout << "This is an A-sequence.\n";
	}
	else
	{
		cout << "This is not an A-sequence.\n";
	}
}
void Free(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		Fg[A[i]] = 0;
	}
}
int main()
{
	int n, i, fg = 0, pre = 0, k;
	int ks = 1;
	while (cin >> n)
	{
		fg = 0;
		pre = 0;
		cout << "Case #" << ks++ << ":";
		for (i = 1; i <= n; i++)
		{
			cin >> A[i];
			cout << " " << A[i];
			if (pre >= A[i])
			{
				fg = 1;
			}
			pre = A[i];
			Fg[A[i]] = 1;
		}
		cout << endl;
		if (fg)
		{
			cout << "This is not an A-sequence.\n";
			Free(n);
			continue;
		}
		Cal(n);
		Free(n);
	}
	return 0;
}

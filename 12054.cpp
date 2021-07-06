#include <bits/stdc++.h>

using namespace std;

#define for if (0); else for

int plist[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int pn = 15;
int d[15], res[100];
int pc[51][15];
int n, F;
int e[100][100];

void out(int t)
{
	memset(e, 0, sizeof(e));
	int x = 0;
	for (int c = 0; c < t - 1; ++c)
	{
		int df = x + res[c];
		for (int i = x; i < x + res[c]; ++i)
		{
			e[i][df] = 1;
			df++;
			if (df >= x + res[c] + res[c + 1])
			{
				df = x + res[c];
			}
		}
		x += res[c];
	}
	for (int i = 0; i < n; ++i)
	{
		int x = 0;
		for (int j = 0; j < n; ++j)
			if (e[i][j] == 1)
			{
				x++;
			}
		cout << x;
		for (int j = 0; j < n; ++j)
			if (e[i][j] == 1)
			{
				cout << " " << j + 1;
			}
		cout << endl;
	}
}
void done(int t, int left, int last, int a[15])
{
	if (F)
	{
		return;
	}
	for (int i = 0; i < 15; ++i)
		if (a[i] < 0)
		{
			return;
		}
	if (left < 0)
	{
		return;
	}
	int i;
	for (i = 0; i < 15; ++i)
		if (a[i])
		{
			break;
		}
	if (i >= 15 && left == 0)
	{
		out(t);
		F = 1;
	}
	int at[15];
	for (int i = last; i >= 1; --i)
	{
		memcpy(at, a, sizeof(int) * 15);
		for (int j = 0; j < 15; ++j)
		{
			at[j] -= pc[i][j];
		}
		res[t] = i;
		done(t + 1, left - i, i, at);
	}
}
int main()
{
	for (int i = 1; i < 51; ++i)
	{
		memcpy(pc[i], pc[i - 1], sizeof(pc[i - 1]));
		int x = i;
		for (int j = 0; j < 15; ++j)
		{
			while (x % plist[j] == 0)
			{
				x /= plist[j];
				pc[i][j]++;
			}
		}
	}
	int tc, R, x1, x2;
	cin >> tc;
	for (int t = 1; t <= tc; ++t)
	{
		cout << "Case#" << t << ":" << endl;
		cin >> n >> R;
		memset(d, 0, sizeof(d));
		for (int i = 0; i < R; ++i)
		{
			cin >> x1 >> x2;
			for (int j = 0; j < pn; ++j)
				if (x1 == plist[j])
				{
					d[j] += x2;
				}
		}
		F = 0;
		done(0, n, 50, d);
	}
	return 0;
}

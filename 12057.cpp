#include <bits/stdc++.h>

using namespace std;

#define for if (0); else for

double a[110];
int p[110][110];
double e[110][110];
int n;
string s[110];

void work(int ge, int b)
{
	if (ge <= 1)
	{
		return;
	}
	int k = p[ge][b];
	for (int i = b; i < b + ge; ++i)
	{
		if (i < b + k)
		{
			s[i] = s[i] + '0';
		}
		else
		{
			s[i] = s[i] + '1';
		}
	}
	work(k, b);
	work(ge - k, b + k);
}
void done()
{
	for (int j = 0; j < n; ++j)
	{
		e[1][j] = a[j];
	}
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= n - i; ++j)
		{
			double rt = 1e30;
			for (int k = 1; k < i; ++k)
			{
				double t = e[k][j] + e[i - k][j + k];
				for (int l = 0; l < i; ++l)
				{
					t += a[j + l];
				}
				if (t < rt)
				{
					rt = t;
					p[i][j] = k;
				}
			}
			e[i][j] = rt;
		}
	}
	cout << e[n][0] - 1 << endl;
	for (int i = 0; i < n; ++i)
	{
		s[i] = "";
	}
	work(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cout << s[i] << endl;
	}
}
int main()
{
	cout.setf(ios::fixed);
	cout.precision(4);
	int f = 0;
	while (cin >> n && n)
	{
		if (f)
		{
			cout << endl;
		}
		else
		{
			f = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		if (n == 1)
		{
			cout << "1.0000" << endl
					 << "0" << endl;
		}
		else
		{
			done();
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
typedef long data;
#define bmax 30
#else
typedef long long data;
#define bmax 62
#endif
#define for if (0); else for

int n;
data p10[bmax];

void indx(int t, int ind)
{
	int f = 0;
	if (t % 2 == 1)
	{
		t++, f = 1;
	}
	int x = t / 2;
	data res = p10[x - 1] + ind - 1;
	cout << res;
	if (!f)
	{
		cout << res % 10;
	}
	res /= 10;
	while (res)
	{
		cout << res % 10;
		res /= 10;
	}
	cout << endl;
}
data iall(int t)
{
	if (t == 1)
	{
		return 9;
	}
	if (t % 2 == 1)
	{
		return iall(t - 1) * 10;
	}
	else
	{
		int x = t / 2;
		return p10[x] - p10[x - 1];
	}
}
void done()
{
	int m = n, t = 0;
	while (m > 0)
	{
		t++;
		int m1 = m - iall(t);
		if (m1 <= 0)
		{
			break;
		}
		m = m1;
	}
	indx(t, m);
}
int main()
{
	p10[0] = 1;
	for (int i = 1; i < bmax; ++i)
	{
		p10[i] = p10[i - 1] * 10;
	}
	/*  for (int i = 1; i < 10; ++i)
	    cout << iall(i) <<endl;
	    */
	while (cin >> n && n)
	{
		done();
	}
	return 0;
}

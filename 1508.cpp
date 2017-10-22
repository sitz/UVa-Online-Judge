#include <bits/stdc++.h>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX / 2
#define mod 1000000007
#define PI 2.0 * acos(0.0)
#define vsort(v) sort(v.begin(), v.end())

int ar[10001][5];
int pp[51], ad[5], sum[51];
int get(int bit, int nd)
{
	//cout<<bit<<" "<<nd<<endl;
	if (nd == 1)
	{
		return pp[bit];
	}
	int a = 0;
	for (int x = 1; x < bit; x++)
	{
		if ((x & (x ^ bit)) == 0)
		{
			a = max(a, pp[x] + get(x ^ bit, nd - 1));
		}
	}
	return a;
}
int main()
{
	int a, b, c, d, e, f, g, h, x, y, z;
	scanf("%d", &a);
	for (h = 1; h <= a; h++)
	{
		scanf("%d %d", &b, &c);
		memset(pp, 0, sizeof pp);
		memset(ad, 0, sizeof ad);
		for (x = 0; x < b; x++)
		{
			for (y = 0; y < 5; y++)
			{
				scanf("%d", &ar[x][y]);
				ad[y] = max(ad[y], ar[x][y]);
			}
			for (y = 1; y < 1 << 5; y++)
			{
				e = 0;
				for (z = 0; z < 5; z++)
					if ((y & (1 << z)) > 0)
					{
						e += ar[x][z];
					}
				pp[y] = max(pp[y], e);
			}
		}
		if (c > 1 && c < 5)
		{
			cout << get((1 << 5) - 1, c) << endl;
		}
		else if (c == 1)
		{
			d = 0;
			for (x = 0; x < b; x++)
			{
				e = 0;
				for (y = 0; y < 5; y++)
				{
					e += ar[x][y];
				}
				d = max(d, e);
			}
			printf("%d\n", d);
		}
		else
		{
			d = 0;
			for (x = 0; x < 5; x++)
			{
				d += ad[x];
			}
			printf("%d\n", d);
		}
	}
	return 0;
}
/*
2
4 2
30 30 30 30 0
50 0 0 0 0
0 50 0 50 10
0 0 50 0 20
5 1
10 20 60 0 0
0 0 20 50 30
30 50 20 20 0
10 10 10 20 30
30 0 20 10 20
*/

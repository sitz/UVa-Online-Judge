#include <bits/stdc++.h>

using namespace std;

#define FRE(i, a, b) for (i = a; i <= b; i++)
#define FRL(i, a, b) for (i = a; i < b; i++)
#define mem(t, v) memset((t), v, sizeof(t))
#define sqr(x) (x) * (x)
#define all(x) x.begin(), x.end()
#define un(x) x.erase(unique(all(x)), x.end())
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define D(x) cout << #x " = " << (x) << endl
#define pf printf
#define VI vector<int>
#define pii pair<int, int>
#define pll pair<LL, LL>
#define pb push_back
#define mp make_pair
#define pi acos(-1.00)
#define DBG pf("Hi\n")
#define sz size()
#define ins insert
#define fi first
#define se second
#define xx first
#define yy second
#define inf (1 << 29)
#define MOD 100007
#define eps 1e-9
#define MAX 100000

typedef long long int LL;
typedef double db;

int c[200], A[MAX + 10];

int main()
{
	int i, j, k, cs, t;
	int a, b, d, q, w, e, r, y;
	db nw, mn, n;
	sf(t);
	FRE(cs, 1, t)
	{
		mn = inf;
		sf(y);
		n = y;
		mem(c, 0);
		FRE(i, 1, n)
		{
			sf(A[i]);
			c[A[i]]++;
		}
		FRE(i, 1, 160)
		c[i] += c[i - 1];
		FRE(i, 0, 160)
		{
			FRE(j, i + 1, 160)
			{
				FRE(k, j + 1, 160)
				{
					a = c[i];
					b = c[j] - c[i];
					r = c[k] - c[j];
					d = c[160] - c[k];
					nw = fabs((n / 4.00) - a) + fabs((n / 4.00) - b) + fabs((n / 4.00) - r) + fabs((n / 4.00) - d);
					if (nw < mn)
					{
						mn = nw;
						q = i;
						w = j;
						e = k;
					}
				}
			}
		}
		pf("Case %d: %d %d %d\n", cs, q, w, e);
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define eps 1e-12
#define maxn 1100
#define maxm 1100000
#define inf 0x3f3f3f3f
#define PB push_back
#define MP make_pair

bitset<101> a[maxn], b, c, d, e, f;
int l[maxn];

int main()
{
	int m, q, i, j, k, ll, t, p, ans;
	char s[110];
	while (scanf("%d %d", &m, &q) != EOF)
	{
		for (i = 0; i < m; i++)
		{
			scanf("%s", s);
			for (k = 0; s[k]; k++)
			{
				a[i][k] = s[k] - '0';
			}
			l[i] = k;
		}
		while (q--)
		{
			scanf("%s", s);
			for (i = 0; s[i]; i++)
			{
				b[i] = s[i] - '0';
				c[i] = 1;
			}
			ll = i;
			for (; i < 101; i++)
			{
				c[i] = 0;
			}
			d = b;
			e = c;
			t = -1;
			for (i = 0; i < m; i++)
			{
				b = d;
				c = e;
				for (j = ll - 1; j < l[i]; j++)
				{
					f = (a[i] ^ b) & c;
					p = ll - f.count();
					if (t < p)
					{
						t = p;
						ans = i;
					}
					b <<= 1;
					c <<= 1;
				}
			}
			printf("%d\n", ans + 1);
		}
	}
}

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define RFOR(i, a, b) for (int(i) = (a), _b(b); (i) >= _b; --(i))

static char a[1000003], b[1000010], s[1000010];
static long n, m, i, j, k, t, c, sum, sp = 0;

int main()
{
	scanf("%ld", &n);
	FOREQ(t, 1, n)
	{
		scanf("%ld", &m);
		FOREQ(i, 0, m)
		a[i] = b[i] = s[i] = 0;
		FOR(i, 0, m)
		scanf("%ld %ld", &a[i], &b[i]);
		c = 0;
		k = 0;
		RFOR(j, m - 1, 0)
		{
			sum = a[j] + b[j] + c;
			s[k++] = sum % 10;
			c = sum / 10;
		}
		if (sp++)
		{
			printf("\n");
		}
		if (c)
		{
			s[k++] = c;
		}
		RFOR(i, k - 1, 0)
		printf("%d", s[i]);
		printf("\n");
	}
	return 0;
}

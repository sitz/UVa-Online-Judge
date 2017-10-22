#include <bits/stdc++.h>

using namespace std;

#define MAXI(a, b) (a) > (b) ? (a) : (b)
#define MINI(a, b) (a) < (b) ? (a) : (b)

int main()
{
	int i, j, r, c, ans, tst, cas = 1, state, pres, buff;
	scanf("%d", &tst);
	while (tst--)
	{
		scanf("%d%d", &r, &c);
		if ((r & 1) == (c & 1))
		{
			state = 0;
		}
		else
		{
			state = 1;
		}
		ans = 0;
		for (i = 0; i < r; i++)
		{
			pres = state + i;
			for (j = 0; j < c; j++, pres++)
			{
				scanf("%d", &buff);
				if (pres & 1)
				{
					ans ^= buff;
				}
			}
		}
		printf("Case %d: ", cas++);
		if (ans)
		{
			puts("win");
		}
		else
		{
			puts("lose");
		}
	}
	return 0;
}

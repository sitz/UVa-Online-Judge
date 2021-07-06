#include <bits/stdc++.h>

using namespace std;

int main()
{
	int c, t, n, r1, c1, r2, c2;
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d%d", &t, &n);
		while (t--)
		{
			scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			if ((r1 + c1 + r2 + c2) % 2)
			{
				printf("no move\n");
				continue;
			}
			n = 0;
			if (r1 + c1 == r2 + c2)
			{
				n |= 1;
			}
			if (r1 - c1 == r2 - c2)
			{
				n |= 2;
			}
			switch (n)
			{
			case 0:
				printf("2\n");
				break;
			case 3:
				printf("0\n");
				break;
			default:
				printf("1\n");
				break;
			}
		}
	}
	return 0;
}

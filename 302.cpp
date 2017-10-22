#include <bits/stdc++.h>

using namespace std;

const int INTMAX = 1000000000;
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int stk[1996], conmap[45][1996], constreet[45], top, maxstreet;
bool visit[1996];

void Euler(int s)
{
	int i;
	for (i = 1; i <= maxstreet; i++)
	{
		if (conmap[s][i] && !visit[i])
		{
			visit[i] = true;
			Euler(conmap[s][i]);
			stk[top++] = i;
		}
	}
}

int main()
{
	int x, y, z, home;
	while (scanf("%d %d", &x, &y) == 2 && x && y)
	{
		int i;
		memset(visit, 0, sizeof(visit));
		memset(conmap, 0, sizeof(conmap));
		memset(constreet, 0, sizeof(constreet));
		top = 0;
		maxstreet = 0;
		scanf("%d", &z);
		home = min(x, y);
		conmap[x][z] = y;
		constreet[x]++;
		conmap[y][z] = x;
		constreet[y]++;
		maxstreet = max(maxstreet, z);
		while (1)
		{
			scanf("%d %d", &x, &y);
			if (x == 0 && y == 0)
			{
				break;
			}
			scanf("%d", &z);
			conmap[x][z] = y;
			constreet[x]++;
			conmap[y][z] = x;
			constreet[y]++;
			maxstreet = max(maxstreet, z);
		}
		for (i = 1; i < 45; i++)
		{
			if (constreet[i] % 2)
			{
				break;
			}
		}
		if (i < 45)
		{
			printf("Round trip does not exist.\n\n");
		}
		else
		{
			Euler(home);
			for (i = top - 1; i >= 0; i--)
			{
				printf("%d", stk[i]);
				if (i > 0)
				{
					printf(" ");
				}
			}
			printf("\n\n");
		}
	}
	return 0;
}

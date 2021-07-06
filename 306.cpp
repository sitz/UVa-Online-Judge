#include <bits/stdc++.h>

using namespace std;

/**
306
**/
#define MAXN 215
char MS[MAXN], OUTPUT[MAXN];
int A[MAXN], TEMP[MAXN];
int K, N, L, C;
struct ss
{
	char color;
} V[MAXN];
void ReadMS()
{
	int m = 1, f = 1;
	char c;
	while (1)
	{
		c = getchar();
		if (f-- && c == ' ')
		{
			continue;
		}
		if (c == '\n')
		{
			break;
		}
		MS[m++] = c;
		f = 0;
	}
	L = m - 1;
}
void SET(int k)
{
	int m = 0, n, i, j;
	TEMP[m++] = k;
	V[k].color = 'r';
	C++;
	k = A[k];
	while (1)
	{
		if (V[k].color == 'r')
		{
			break;
		}
		C++;
		V[k].color = 'r';
		TEMP[m++] = k;
		k = A[k];
	}
	for (i = 0; i < m; i++)
	{
		n = (i + K) % m;
		k = TEMP[i];
		j = TEMP[n];
		if (k <= L)
		{
			OUTPUT[j] = MS[k];
		}
		else
		{
			OUTPUT[j] = ' ';
		}
	}
}
void Cal()
{
	int i;
	C = 0;
	for (i = 1; i <= N; i++)
	{
		if (C >= N)
		{
			break;
		}
		if (V[i].color == 'w')
		{
			SET(i);
		}
	}
	for (i = 1; i <= N; i++)
	{
		printf("%c", OUTPUT[i]);
	}
	printf("\n");
}
void INI()
{
	int i;
	for (i = 0; i <= N; i++)
	{
		V[i].color = 'w';
	}
}
int main()
{
	int i;
	while (scanf("%d", &N) == 1)
	{
		if (!N)
		{
			break;
		}
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &A[i]);
		}
		while (1)
		{
			scanf("%d", &K);
			if (!K)
			{
				break;
			}
			ReadMS();
			INI();
			Cal();
		}
		printf("\n");
	}
	return 0;
}

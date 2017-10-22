#include <bits/stdc++.h>

using namespace std;

#define MAXN 46345

char ss[MAXN + 2];
int Prime[7000], K, M;
int Store[1000];

void Prime_table()
{
	int i, j;
	K = 0;
	for (i = 2; i <= sqrt(MAXN);)
	{
		for (j = i + i; j <= MAXN; j += i)
		{
			ss[j] = 1;
		}
		for (i++; ss[i]; i++)
			;
	}
	for (i = 2; i <= MAXN; i++)
		if (!ss[i])
		{
			Prime[K++] = i;
		}
}
void FindValue(int n)
{
	int i;
	int Sum = 1;
	Sum = n - n / Store[0];
	for (i = 1; i < M; i++)
	{
		Sum = Sum - (Sum / Store[i]);
	}
	printf("%d\n", Sum);
}
void Com(int n)
{
	int i, temp = n;
	M = 0;
	for (i = 0; i < K && Prime[i] <= sqrt(n); i++)
	{
		if (n % Prime[i] == 0)
		{
			Store[M++] = Prime[i];
			while (n % Prime[i] == 0)
			{
				n /= Prime[i];
				if (n == 1)
				{
					goto done;
				}
			}
		}
	}
done:;
	if (n != 1)
	{
		Store[M++] = n;
	}
	FindValue(temp);
}

int main()
{
	int n;
	Prime_table();
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		if (n == 1)
		{
			printf("0\n");
			continue;
		}
		Com(n);
	}
	return 0;
}

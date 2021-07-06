#include <bits/stdc++.h>

using namespace std;

int S[100], MaxLen, found;
int T[100], N;
void Copy(int level)
{
	int i;
	for (i = 0; i <= level; i++)
	{
		S[i] = T[i];
	}
	MaxLen = level;
}
void Recur(int n, int level)
{
	int i, j, k = n, p = 0;
	if (level >= MaxLen)
	{
		return;
	}
	if (n > N)
	{
		return;
	}
	T[level] = n;
	if (N == n)
	{
		Copy(level);
		found = 1;
		return;
	}
	if (found)
	{
		for (j = 1; k < N; j++)
		{
			k *= 2;
			p++;
		}
		if (level + p >= MaxLen)
		{
			return;
		}
	}
	for (i = level; i >= 0; i--)
	{
		Recur(n + T[i], level + 1);
	}
}
void Print()
{
	int i;
	printf("1");
	for (i = 1; i <= MaxLen; i++)
	{
		printf(" %d", S[i]);
	}
	printf("\n");
}
int main()
{
	while (scanf("%d", &N), N)
	{
		MaxLen = 10000;
		found = 0;
		Recur(1, 0);
		Print();
	}
	return 0;
}

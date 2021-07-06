#include <bits/stdc++.h>

using namespace std;

#define maxn 20002

char sv[maxn];
int N;
int A[101];

void F(int f)
{
	int i, j, d;
	if (f)
	{
		printf("It is not a B2-Sequence.\n");
		return;
	}
	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; j++)
		{
			d = A[i] + A[j];
			if (sv[d])
			{
				printf("It is not a B2-Sequence.\n");
				return;
			}
			else
			{
				sv[d] = 1;
			}
		}
	}
	printf("It is a B2-Sequence.\n");
}
int main()
{
	int i, k = 1, f;
	while (scanf("%d", &N) == 1)
	{
		f = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &A[i]);
			if (i && A[i - 1] >= A[i])
			{
				f = 1;
			}
		}
		if (A[0] < 1)
		{
			f = 1;
		}
		printf("Case #%d: ", k++);
		F(f);
		printf("\n");
		for (i = 0; i < maxn; i++)
		{
			sv[i] = 0;
		}
	}
	return 0;
}

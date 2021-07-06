#include <bits/stdc++.h>

using namespace std;

typedef struct
{
	int NO, ac[30], dc[30], w;
} Cas;

Cas cas[21];
int len;
int N, K, Ar;
int arr[30][30];

int cmp(const void *a, const void *b)
{
	Cas *pa = (Cas *)a, *pb = (Cas *)b;
	if (pa->w == pb->w)
	{
		return pa->NO - pb->NO;
	}
	else
	{
		return pa->w - pb->w;
	}
}

int main()
{
	int i, j, k, D, flow;
	while (scanf("%d", &N), N != 0)
	{
		memset(arr, 0, sizeof(arr));
		memset(cas, 0, sizeof(cas));
		len = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%d%d", &Ar, &K);
			for (j = 0; j < K; j++)
			{
				scanf("%d%d", &D, &flow);
				arr[Ar][D] = flow;
			}
		}
		while (scanf("%d", &K), K != 0)
		{
			cas[len].NO = K;
			cas[len].w = 0;
			for (i = 0; i < N; i++)
			{
				scanf("%d", &cas[len].ac[i]);
			}
			for (i = 0; i < N; i++)
			{
				scanf("%d", &cas[len].dc[i]);
			}
			cas[len].w = 0;
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
				{
					cas[len].w += arr[cas[len].ac[i]][cas[len].dc[j]] * (1 + abs(i - j));
				}
			}
			len++;
		}
		qsort(cas, len, sizeof(cas[0]), cmp);
		printf("Configuration Load\n");
		for (i = 0; i < len; i++)
		{
			printf("%5d         %d\n", cas[i].NO, cas[i].w);
		}
	}
	return 0;
}

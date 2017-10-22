#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005

int A[1000002], lst[MAXN], H, T, N;

struct queue
{
	int st[MAXN];
	int H, T;
} ss[MAXN];

void Ini()
{
	int i;
	H = T = 0;
	for (i = 0; i < N; i++)
	{
		ss[i].H = ss[i].T = 0;
	}
}
void Push(int n)
{
	int t;
	t = A[n];
	if (ss[t].H != ss[t].T)
	{
		ss[t].st[ss[t].H++] = n;
	}
	else
	{
		ss[t].st[ss[t].H++] = n;
		lst[H++] = t;
	}
}
int Pop()
{
	int t, k;
	t = lst[T];
	k = ss[t].st[ss[t].T++];
	if (ss[t].H == ss[t].T)
	{
		T++;
	}
	return k;
}
void SolvedCase()
{
	char comm[100];
	int n;
	while (scanf("%s", comm) && strcmp(comm, "STOP"))
	{
		if (!strcmp(comm, "ENQUEUE"))
		{
			scanf("%d", &n);
			Push(n);
		}
		else
		{
			printf("%d\n", Pop());
		}
	}
}
int main()
{
	int i, j, n, k, kase = 1;
	while (scanf("%d", &N) && N)
	{
		Ini();
		for (i = 0; i < N; i++)
		{
			scanf("%d", &n);
			for (j = 0; j < n; j++)
			{
				scanf("%d", &k);
				A[k] = i;
			}
		}
		printf("Scenario #%d\n", kase++);
		SolvedCase();
		printf("\n");
	}
	return 0;
}

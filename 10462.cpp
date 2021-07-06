#include <bits/stdc++.h>

using namespace std;

#define MAXN 102
#define MAXE 202

struct ss
{
	int u, v;
	int weight;
} E[MAXE], MST[MAXE];

int P[MAXN], rank_[MAXN], N, M;

int cmp(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return x->weight - y->weight;
}
int Find(int n)
{
	if (n != P[n])
	{
		P[n] = Find(P[n]);
	}
	return P[n];
}
void Link(int x, int y)
{
	if (rank_[x] > rank_[y])
	{
		P[y] = x;
	}
	else
	{
		P[x] = y;
		if (rank_[x] == rank_[y])
		{
			rank_[y]++;
		}
	}
}
void MakeSet()
{
	int i;
	for (i = 0; i < N; i++)
	{
		rank_[i] = 0;
		P[i] = i;
	}
}
int mSt(int p)
{
	int sum = 0, i, x, y;
	int mstLen = 0;
	for (i = 0; i < M && mstLen < N - 1; i++)
	{
		if (i == p)
		{
			continue;
		}
		x = Find(E[i].u);
		y = Find(E[i].v);
		if (x != y)
		{
			Link(x, y);
			sum += E[i].weight;
			mstLen++;
		}
	}
	if (mstLen < N - 1)
	{
		return -1;
	}
	return sum;
}
void Cal()
{
	int i, mstLen = 0, x, y;
	int f = 1;
	int Best_1 = 0, Best_2 = 21474836;
	int flag[102];
	MakeSet();
	qsort(E, M, sizeof(ss), cmp);
	for (i = 0; i < M && mstLen < N - 1; i++)
	{
		x = Find(E[i].u);
		y = Find(E[i].v);
		if (x != y)
		{
			MST[mstLen++] = E[i];
			flag[mstLen - 1] = i;
			Link(x, y);
			Best_1 += E[i].weight;
		}
	}
	if (mstLen < N - 1)
	{
		printf("No way\n");
		return;
	}
	for (i = 0; i < mstLen; i++)
	{
		MakeSet();
		x = mSt(flag[i]);
		if (x != -1 && x < Best_2)
		{
			Best_2 = x;
			f = 0;
		}
	}
	if (f)
	{
		printf("No second way\n");
		return;
	}
	printf("%d\n", Best_2);
}

int main()
{
	int kase, i, c = 1;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d%d", &N, &M);
		for (i = 0; i < M; i++)
		{
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].weight);
			E[i].u--;
			E[i].v--;
		}
		printf("Case #%d : ", c++);
		Cal();
	}
	return 0;
}

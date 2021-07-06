#include <bits/stdc++.h>

using namespace std;

#define MAXN 102
#define MAXE 5055

struct ss {int u, v, weight;} E[MAXE], MST[MAXE];
int P[MAXN], rank_[MAXN], N, M;

int com(const void *a, const void *b)
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
		P[y] = x;
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
int mSt(int p, int c)
{
	int sum = 0, i, x, y;
	int mstLen = 0;
	for (i = 0; i < M && mstLen < N - 1; i++)
	{
		if ((E[i].u == MST[p].u && E[i].v == MST[p].v))
		{
			continue;
		}
		x = Find(E[i].u);
		y = Find(E[i].v);
		if (x != y)
		{
			Link(x, y);
			sum += E[i].weight;
			if (sum > c)
			{
				return -1;
			}
			mstLen++;
		}
	}
	if (mstLen == N - 1)
	{
		return sum;
	}
	return -1;
}
void Cal()
{
	int i, mstLen = 0, x, y, f = 0;
	int Best_1 = 0, Best_2 = 21474836;
	MakeSet();
	qsort(E, M, sizeof(ss), com);
	for (i = 0; i < M && mstLen < N - 1; i++)
	{
		x = Find(E[i].u);
		y = Find(E[i].v);
		if (x != y)
		{
			MST[mstLen++] = E[i];
			Link(x, y);
			Best_1 += E[i].weight;
		}
	}
	printf("%d", Best_1);
	for (i = 0; i < mstLen; i++)
	{
		MakeSet();
		x = mSt(i, Best_2);
		if (x != -1 && x < Best_2)
		{
			f = 1;
			Best_2 = x;
		}
	}
	if (f)
	{
		printf(" %d\n", Best_2);
	}
	else
	{
		printf(" %d\n", Best_1);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].weight);
			E[i].u--;
			E[i].v--;
		}
		Cal();
	}
	return 0;
}

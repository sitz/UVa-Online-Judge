#include <bits/stdc++.h>

using namespace std;

#define LIM 10010

int N, M, cases, i, error, r1, r2, h1, h2, root[LIM], rank_[LIM], countH[LIM], countW[LIM];

int findSet(int a)
{
	if (root[a] != a)
	{
		root[a] = findSet(root[a]);
	}
	return root[a];
}
int unionSet(int a, int b)
{
	if (rank_[a] < rank_[b])
	{
		root[a] = b;
		countH[b] += countH[a];
		countW[b] += countW[a];
		return b;
	}
	else
	{
		root[b] = a;
		countH[a] += countH[b];
		countW[a] += countW[b];
		if (rank_[a] == rank_[b])
		{
			rank_[a]++;
		}
		return a;
	}
}

int main()
{
	scanf("%d", &cases);
	while (cases--)
	{
		scanf("%d %d", &M, &N);
		for (i = 0; i < N; i++)
		{
			root[i] = i;
			rank_[i] = 0;
			countH[i] = 1;
			countW[i] = 0;
		}
		error = 0;
		for (i = 0; i < M; i++)
		{
			scanf("%d %d", &h1, &h2);
			r1 = findSet(h1);
			r2 = findSet(h2);
			if (r1 != r2)
			{
				r1 = unionSet(r1, r2);
			}
			countW[r1]++;
			if (countW[r1] > countH[r1])
			{
				error = 1;
			}
		}
		if (error == 1)
		{
			printf("rehash necessary\n");
		}
		else
		{
			printf("successful hashing\n");
		}
	}
	return 0;
}

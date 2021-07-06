#include <bits/stdc++.h>

using namespace std;

#define maxn 12

int RT[maxn], CT[maxn], RC[maxn], CC[maxn];
int RP[maxn], CP[maxn], B[maxn][maxn], N;
char Fg[1002];
vector<int> D[1002];

void Gen()
{
	int i, j;
	D[1].push_back(1);
	for (i = 2; i < 1001; i++)
	{
		for (j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				D[i].push_back(j);
				D[i].push_back(i / j);
			}
		}
		D[i].push_back(1);
		D[i].push_back(i);
	}
}
int Ok(int n, int c, int st)
{
	int i, d;
	if (c == 2)
		return 1;
	if (st >= N)
		return 1;
	for (i = st; i <= N; i++)
	{
		if (RT[i] % n == 0)
		{
			d = RT[i] / n;
			if (Fg[d] == 0)
				return 1;
		}
	}
	return 0;
}
void Print()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		printf("%d", B[i][1]);
		for (j = 2; j <= N; j++)
			printf(" %d", B[i][j]);
		printf("\n");
	}
	printf("\n");
}
int Recur(int r, int c1, int c2, int n, int m)
{
	int i, j, k, l, d, q, p;
	B[r][c1] = n;
	B[r][c2] = m;
	CC[c1]++;
	CC[c2]++;
	CP[c1] *= n;
	CP[c2] *= m;
	Fg[n] = Fg[m] = 1;
	if (r == N)
	{
		Print();
		return 1;
	}
	for (i = 1; i < N; i++)
	{
		if (CC[i] == 2)
			continue;
		p = CT[i];
		for (k = 0; k < D[p].size(); k++)
		{
			if (RT[r + 1] % D[p][k] != 0)
				continue;
			if (Fg[D[p][k]])
				continue;
			d = RT[r + 1] / D[p][k];
			if (Fg[d])
				continue;
			if (CC[i] > 0)
				if (CP[i] * D[p][k] != CT[i])
					continue;
			if (CC[i] == 0)
				if (Ok(CT[i] / D[p][k], 1, r + 2) == 0)
					continue;
			if (d == D[p][k])
				continue;
			for (j = i + 1; j <= N; j++)
			{
				if (CC[j] == 2)
					continue;
				if (CC[j] > 0)
					if ((CT[j] / CP[j]) != d)
						continue;
				if (CT[j] % d == 0)
					if (Ok(CT[j] / d, CC[j] + 1, r + 2))
						if (Recur(r + 1, i, j, D[p][k], d))
							return 1;
			}
		}
	}
	B[r][c1] = 0;
	B[r][c2] = 0;
	CC[c1]--;
	CC[c2]--;
	CP[c1] /= n;
	CP[c2] /= m;
	Fg[n] = Fg[m] = 0;
	return 0;
}
void Cal()
{
	int i, j, k, n, d, g;
	for (i = 1; i < N; i++)
	{
		n = CT[i];
		for (k = 0; k < D[n].size(); k++)
		{
			g = D[n][k];
			if (RT[1] % D[n][k] != 0)
				continue;
			d = RT[1] / D[n][k];
			if (d == D[n][k])
				continue;
			for (j = i + 1; j <= N; j++)
				if (CT[j] % d == 0)
					if (Ok(CT[j] / d, 1, 2))
						if (Recur(1, i, j, D[n][k], d))
							return;
		}
	}
}
void Ini()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		CC[i] = 0;
		CP[i] = 1;
		for (j = 1; j <= N; j++)
			B[i][j] = 0;
	}
	for (i = 0; i <= 1000; i++)
		Fg[i] = 0;
}
int main()
{
	int i;
	Gen();
	while (scanf("%d", &N) && N)
	{
		for (i = 1; i <= N; i++)
			scanf("%d", &CT[i]);
		for (i = 1; i <= N; i++)
			scanf("%d", &RT[i]);
		Ini();
		Cal();
	}
	return 0;
}

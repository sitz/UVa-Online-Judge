#include <bits/stdc++.h>

using namespace std;

int seq[20][2] = {0, 4, 1, 4, 2, 4, 3, 4, 4, 4, 4, 0, 4, 1, 4, 2, 4, 3,
									1, 1, 1, 3, 2, 2, 3, 1, 3, 3, 0, 1, 0, 2, 0, 3, 1, 0, 2, 0, 3, 0};
bool primes[100000];
struct Node
{
	int ans[5][5];
} n[200];
int ans[5][5], sum, ptr;
int row[5], col[5], freer[5], freec[5], freed[2], diag[2];
int compare(const void *a, const void *b)
{
	Node *c = (Node *)a, *d = (Node *)b;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (c->ans[i][j] != d->ans[i][j])
			{
				return c->ans[i][j] - d->ans[i][j];
			}
	return 0;
}
bool isprime(int n)
{
	return primes[n];
}
bool check(int depth)
{
	for (int i = 0; i < 5; i++)
	{
		if (freer[i] * 9 < row[i])
		{
			return false;
		}
		if (freec[i] * 9 < col[i])
		{
			return false;
		}
	}
	if (freed[0] * 9 < diag[0])
	{
		return false;
	}
	if (freed[1] * 9 < diag[1])
	{
		return false;
	}
	if (depth == 8)
	{
		if (!isprime(ans[0][4] * 10000 + ans[1][4] * 1000 + ans[2][4] * 100 +
								 ans[3][4] * 10 + ans[4][4]))
		{
			return false;
		}
		if (!isprime(ans[4][0] * 10000 + ans[4][1] * 1000 + ans[4][2] * 100 +
								 ans[4][3] * 10 + ans[4][4]))
		{
			return false;
		}
		if (row[4] != 0 || col[4] != 0)
		{
			return false;
		}
	}
	else if (depth == 13)
	{
		if (!isprime(ans[0][0] * 10000 + ans[1][1] * 1000 + ans[2][2] * 100 +
								 ans[3][3] * 10 + ans[4][4]))
		{
			return false;
		}
		if (!isprime(ans[4][0] * 10000 + ans[3][1] * 1000 + ans[2][2] * 100 +
								 ans[1][3] * 10 + ans[0][4]))
		{
			return false;
		}
		if (diag[0] != 0 || diag[1] != 0)
		{
			return false;
		}
	}
	else if (depth == 16)
	{
		if (!isprime(ans[0][0] * 10000 + ans[0][1] * 1000 + ans[0][2] * 100 +
								 ans[0][3] * 10 + ans[0][4]))
		{
			return false;
		}
		if (row[0] != 0)
		{
			return false;
		}
	}
	else if (depth == 19)
	{
		if (!isprime(ans[0][0] * 10000 + ans[1][0] * 1000 + ans[2][0] * 100 +
								 ans[3][0] * 10 + ans[4][0]))
		{
			return false;
		}
		if (col[0] != 0)
		{
			return false;
		}
	}
	return true;
}
void DFS(int depth)
{
	if (depth == 20)
	{
		ans[2][1] = col[1];
		ans[1][2] = row[1];
		ans[2][3] = col[3];
		ans[3][2] = row[3];
		if (ans[2][1] > 9 || ans[1][2] > 9 || ans[2][3] > 9 || ans[3][2] > 9)
		{
			return;
		}
		if (ans[2][0] + ans[2][1] + ans[2][2] + ans[2][3] + ans[2][4] != sum)
		{
			return;
		}
		if (ans[0][2] + ans[1][2] + ans[2][2] + ans[3][2] + ans[4][2] != sum)
		{
			return;
		}
		if (!isprime(ans[1][0] * 10000 + ans[1][1] * 1000 + ans[1][2] * 100 +
								 ans[1][3] * 10 + ans[1][4]))
		{
			return;
		}
		if (!isprime(ans[3][0] * 10000 + ans[3][1] * 1000 + ans[3][2] * 100 +
								 ans[3][3] * 10 + ans[3][4]))
		{
			return;
		}
		if (!isprime(ans[0][1] * 10000 + ans[1][1] * 1000 + ans[2][1] * 100 +
								 ans[3][1] * 10 + ans[4][1]))
		{
			return;
		}
		if (!isprime(ans[0][3] * 10000 + ans[1][3] * 1000 + ans[2][3] * 100 +
								 ans[3][3] * 10 + ans[4][3]))
		{
			return;
		}
		if (!isprime(ans[2][0] * 10000 + ans[2][1] * 1000 + ans[2][2] * 100 +
								 ans[2][3] * 10 + ans[2][4]))
		{
			return;
		}
		if (!isprime(ans[0][2] * 10000 + ans[1][2] * 1000 + ans[2][2] * 100 +
								 ans[3][2] * 10 + ans[4][2]))
		{
			return;
		}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				n[ptr].ans[i][j] = ans[i][j];
			}
		ptr++;
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			int nr = seq[depth][0], nc = seq[depth][1];
			if (depth < 9 && (i % 2 == 0 || i % 5 == 0))
			{
				continue;
			}
			if ((nr == 0 || nc == 0) && i == 0)
			{
				continue;
			}
			if (i > row[nr] || i > col[nc])
			{
				return;
			}
			if (nr == nc && i > diag[0])
			{
				return;
			}
			if (nr + nc == 4 && i > diag[1])
			{
				return;
			}
			ans[nr][nc] = i;
			row[nr] -= i;
			col[nc] -= i;
			freer[nr]--;
			freec[nc]--;
			if (nr == nc)
			{
				diag[0] -= i;
				freed[0]--;
			}
			if (nr + nc == 4)
			{
				diag[1] -= i;
				freed[1]--;
			}
			if (check(depth))
			{
				DFS(depth + 1);
			}
			row[nr] += i;
			col[nc] += i;
			freer[nr]++;
			freec[nc]++;
			if (nr == nc)
			{
				diag[0] += i;
				freed[0]++;
			}
			if (nr + nc == 4)
			{
				diag[1] += i;
				freed[1]++;
			}
		}
	}
}
void init()
{
	for (int i = 0; i < 100000; i++)
	{
		primes[i] = true;
	}
	for (int i = 2; i < 100000; i++)
	{
		if (primes[i])
		{
			for (int j = 2; i * j < 100000; j++)
			{
				primes[i * j] = false;
			}
		}
	}
}
int main()
{
	init();
	int t, lefttop;
	scanf("%d", &t);
	while (t--)
	{
		ptr = 0;
		scanf("%d %d", &sum, &lefttop);
		ans[0][0] = lefttop;
		for (int i = 0; i < 5; i++)
		{
			row[i] = col[i] = sum, freer[i] = 5, freec[i] = 5;
		}
		diag[0] = diag[1] = sum;
		freed[0] = freed[1] = 5;
		row[0] -= lefttop;
		col[0] -= lefttop;
		diag[0] -= lefttop;
		freer[0] = freec[0] = freed[0] = 4;
		DFS(0);
		qsort(n, ptr, sizeof(Node), compare);
		for (int i = 0; i < ptr; i++)
		{
			if (i)
			{
				puts("");
			}
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					printf("%d", n[i].ans[j][k]);
				}
				printf("\n");
			}
		}
		if (t != 0)
		{
			puts("");
		}
	}
	return 0;
}

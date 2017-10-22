#include <bits/stdc++.h>

using namespace std;

int ST[950], Store[100], PAIR2[440], K, Kase, N;
long PAIR1[440];
char FL[310][31];
struct Vertex
{
	char cl;
} V[320];

int com(const void *a, const void *s)
{
	return *(int *)a - *(int *)s;
}

// binary search
int B_search(int key)
{
	int up = K - 1, low = 0, mid;
	mid = (up + low) / 2;
	while (low <= up && Store[mid] != key)
	{
		if (key > Store[mid])
		{
			low = mid + 1;
		}
		else if (key < Store[mid])
		{
			up = mid - 1;
		}
		mid = (up + low) / 2;
	}
	if (Store[mid] == key)
	{
		return mid;
	}
	return -1;
}
void MAKELINK(int k, int N)
{
	int i, n, m;
	K = 0;
	qsort(ST, k, sizeof(int), com);
	for (i = 1; i < k; i++)
		if (ST[i] == ST[i - 1])
		{
			ST[i - 1] = -1;
		}
	qsort(ST, k, sizeof(int), com);
	for (i = 0; i < k; i++)
		if (ST[i] != -1)
		{
			Store[K++] = ST[i];
		}
	for (i = 0; i < N; i++)
	{
		m = B_search(PAIR1[i]);
		n = B_search(PAIR2[i]);
		FL[m][n] = 1;
	}
}
void DFS(int n)
{
	V[n].cl = 'B';
	for (int i = 0; i < K; i++)
	{
		if ((FL[n][i] || FL[i][n]) && V[i].cl == 'W')
		{
			DFS(i);
		}
	}
}
int Un()
{
	int i, g = 0;
	for (i = 0; i < K; i++)
		if (V[i].cl == 'W')
		{
			g++;
		}
	return g;
}
int Root()
{
	int i, j, k = 0;
	for (i = 0; i < K; i++)
	{
		for (j = 0; j < K; j++)
		{
			if (FL[j][i])
			{
				k++;
				break;
			}
		}
	}
	if (K - 1 != k)
	{
		return 1;
	}
	return 0;
}
void Com()
{
	int i;
	if (K != N + 1)
	{
		printf("Case %d is not a tree.\n", Kase++);
		return;
	}
	if (Root())
	{
		printf("Case %d is not a tree.\n", Kase++);
		return;
	}
	for (i = 0; i < K; i++)
	{
		V[i].cl = 'W';
	}
	DFS(0);
	if (Un())
	{
		printf("Case %d is not a tree.\n", Kase++);
		return;
	}
	printf("Case %d is a tree.\n", Kase++);
}

int main()
{
	int i, m, n, k, l, g;
	Kase = 1;
	while (1)
	{
		l = 0;
		g = 0;
		scanf("%d%d", &m, &n);
		if (m < 0 && n < 0)
		{
			break;
		}
		if (n == 0 && m == 0)
		{
			goto done;
		}
		if (n == m)
		{
			g = 1;
		}
		N = 1;
		k = 0;
		i = 1;
		ST[k] = m;
		PAIR1[0] = ST[k];
		k++;
		ST[k] = n;
		PAIR2[0] = ST[k];
		k++;
		while (1)
		{
			scanf("%d%d", &m, &n);
			if (n == 0 && m == 0)
			{
				break;
			}
			ST[k] = m;
			if (n == m)
			{
				g = 1;
			}
			PAIR1[i] = ST[k];
			k++;
			ST[k] = n;
			PAIR2[i] = ST[k];
			k++;
			N++;
			i++;
			l = 1;
		}
	done:;
		if (g == 1)
		{
			printf("Case %d is not a tree.\n", Kase++);
			continue;
		}
		if (l == 0 || g == 1)
		{
			printf("Case %d is a tree.\n", Kase++);
			continue;
		}
		MAKELINK(k, N);
		Com();
		for (i = 0; i < 32; i++)
		{
			memset(FL[i], 0, 320 * sizeof(char));
		}
	}
	return 0;
}

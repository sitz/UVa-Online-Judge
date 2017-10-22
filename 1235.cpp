#include <bits/stdc++.h>

using namespace std;

#define MAX 501

int abs(int a)
{
	return a > 0 ? a : -a;
}

int d(int a, int b)
{
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int aa = a % 10, bb = b % 10;
		result += min(abs(aa - bb), 10 - abs(aa - bb));
		a /= 10;
		b /= 10;
	}
	return result;
}

int K[MAX], G[MAX][MAX], D[MAX], n;
bool V[MAX];

int updateD(int i)
{
	D[i] = 0;
	for (int j = 0; j < n; j++)
	{
		if (G[i][j])
		{
			D[j] = min(D[j], G[i][j]);
		}
	}
}

int main()
{
	int _; scanf("%d", &_);
	while (scanf("%d", &n) != EOF)
	{
		memset(V, 0, sizeof(V));
		memset(D, 0x3f, sizeof(D));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &K[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				G[i][j] = G[j][i] = d(K[i], K[j]);
			}
		}
		int total = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			total = min(total, d(0, K[i]));
		}
		V[0] = true;
		updateD(0);
		for (int k = 1; k < n; k++)
		{
			int minn = INT_MAX, minv;
			for (int i = 0; i < n; i++)
			{
				if (!V[i] && D[i] < minn)
				{
					minn = D[i];
					minv = i;
				}
			}
			V[minv] = true;
			updateD(minv);
			total += minn;
		}
		printf("%d\n", total);
	}
	return 0;
}

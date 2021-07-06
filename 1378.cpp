#include <bits/stdc++.h>

using namespace std;

#define INF 100
#define NIM_SIZE 100

struct NIM
{
	int vis[NIM_SIZE], sg[NIM_SIZE];
	int _SG(int n)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
			{
				vis[sg[i] ^ sg[j]] = 1;
			}
		for (int i = 0; i < NIM_SIZE; i++)
			if (vis[i] == 0)
			{
				return i;
			}
	}
	void pre_sg(int n)
	{
		sg[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			sg[i] = _SG(i);
		}
	}
	void show(int n)
	{
		for (int i = 0; i <= n; i++)
		{
			printf("sg[%d] = %d\n", i, sg[i]);
		}
	}
	int find_period()
	{
		for (int res = 1, j; res * 2 < NIM_SIZE; res++)
		{
			for (j = NIM_SIZE / 2; j < NIM_SIZE; j++)
				if (sg[j] != sg[j - res])
				{
					break;
				}
			if (j == NIM_SIZE)
			{
				return res;
			}
		}
		return -1;
	}
} nim;
int N[INF];
void work(int &x, int &y, int &z, int n, int sg)
{
	for (int i = n; i; i--)
		for (int j = i - 1; j; j--)
			for (int k = j; k; k--)
				if (N[i] && (nim.sg[i - 1] ^ nim.sg[j - 1] ^ nim.sg[k - 1]) == sg)
				{
					x = n - i, y = n - j, z = n - k;
					return;
				}
}
int main()
{
	int cas = 0, n, i;
	nim.pre_sg(23);
	while (scanf("%d", &n), n)
	{
		int sg = 0, x, y, z;
		for (i = n; i; i--)
		{
			scanf("%d", &N[i]);
		}
		for (i = 1; i <= n; i++)
			if (N[i] & 1)
			{
				sg ^= nim.sg[i - 1];
			}
		if (sg)
		{
			work(x, y, z, n, sg);
		}
		else
		{
			x = -1, y = -1, z = -1;
		}
		printf("Game %d: %d %d %d\n", ++cas, x, y, z);
	}
	return 0;
}

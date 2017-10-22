#include <bits/stdc++.h>

using namespace std;

#define MAXN 1048576

int A[MAXN], B[MAXN];

int main()
{
	int T, N, M;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= M; i++)
		{
			scanf("%d", &A[i]);
			B[i] = 0;
		}
		map<int, int> prev;
		set<int> E;
		int err = 0;
		for (int i = 1; i <= M && !err; i++)
		{
			if (A[i] > 0)
			{
				int &v = prev[A[i]];
				set<int>::iterator it = E.lower_bound(v);
				if (it != E.end() && *it > v)
				{
					B[*it] = A[i];
					E.erase(it), v = i;
				}
				else
				{
					err = 1;
				}
			}
			else
			{
				E.insert(i);
			}
		}
		printf(err ? "NO\n" : "YES\n");
		if (!err)
		{
			int f = 0;
			for (int i = 1; i <= M; i++)
			{
				if (A[i] == 0)
				{
					if (f)
					{
						printf(" ");
					}
					f = 1;
					printf("%d", B[i]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

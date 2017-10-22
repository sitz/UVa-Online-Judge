#include <bits/stdc++.h>

using namespace std;

int primes[] = {101, 103, 107, 109, 11, 113, 127, 13, 131, 137, 139, 149, 151, 157, 163, 167, 17,
	173, 179, 181, 19, 191, 193, 197, 199, 2, 211, 223, 227, 229, 23, 233, 239, 241, 251, 257,
	263, 269, 271, 277, 281, 283, 29, 293, 3, 31, 37, 41, 43, 47, 5, 53, 59, 61, 67, 7, 71, 73, 79,
	83, 89, 97};
int p[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
	101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191,
	193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

int f[62], cnt[62], ans[14], ptr, n, t;

bool DFS(int depth, int sum, int last)
{
	if (f[ptr] == 0 && t % 2 != n % 2)
	{
		return false;
	}
	if (depth == t)
	{
		if (sum == 0)
		{
			printf("%d", ans[0]);
			for (int i = 1; i < depth; i++)
			{
				printf("+%d", ans[i]);
			}
		}
		return (sum == 0);
	}
	else
	{
		for (int i = last; i < 62; i++)
		{
			if (cnt[i] >= f[i])
			{
				continue;
			}
			if (primes[i] == 2 && sum % 2 == (t - depth) % 2)
			{
				continue;
			}
			if (primes[i] == 2 && sum % 2 != (t - depth) % 2)
			{
				ans[depth] = 2;
				cnt[i]++;
				if (sum >= 2 && DFS(depth + 1, sum - 2, i + 1))
				{
					return true;
				}
				cnt[i]--;
				return false;
			}
			ans[depth] = primes[i];
			cnt[i]++;
			if (sum - primes[i] >= 0 && DFS(depth + 1, sum - primes[i], i))
			{
				return true;
			}
			cnt[i]--;
		}
		return false;
	}
}

int main()
{
	int B, Q;
	scanf("%d", &B);
	for (int i = 1; i <= B; i++)
	{
		printf("Block %d:\n", i);
		for (int j = 0; j < 61; j++)
		{
			int x;
			for (x = 0; p[j] != primes[x]; x++)
				;
			scanf("%d", &f[x]);
		}
		for (ptr = 0; primes[ptr] != 2; ptr++)
			;
		scanf("%d", &Q);
		for (int j = 1; j <= Q; j++)
		{
			printf("Query %d:\n", j);
			scanf("%d %d %d", &n, &t, &f[ptr]);
			for (int k = 0; k < 62; k++)
			{
				cnt[k] = 0;
			}
			if (!DFS(0, n, 0))
			{
				printf("No Solution.\n");
			}
			else
			{
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}

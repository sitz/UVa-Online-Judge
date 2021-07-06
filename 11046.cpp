#include <bits/stdc++.h>

using namespace std;

#define M 50

inline bool dfs(int d, int *arr, int size, int T, int depth, char output[][M])
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == T)
		{
			return true;
		}
	}

	if (d >= depth)
	{
		return false;
	}

	int len = 0, tmp[10] = {0};
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			len = 1;
			for (int k = 0; k < size; k++)
			{
				if (k != i && k != j)
				{
					tmp[len++] = arr[k];
				}
			}
			tmp[0] = arr[i] + arr[j];
			if (dfs(d + 1, tmp, len, T, depth, output))
			{
				int MAX = max(arr[i], arr[j]), MIN = min(arr[i], arr[j]);
				sprintf(output[d], "%d + %d = %d", MAX, MIN, arr[i] + arr[j]);
				return true;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			len = 1;
			for (int k = 0; k < size; k++)
			{
				if (k != i && k != j)
				{
					tmp[len++] = arr[k];
				}
			}
			tmp[0] = arr[i] * arr[j];
			if (dfs(d + 1, tmp, len, T, depth, output))
			{
				int MAX = max(arr[i], arr[j]), MIN = min(arr[i], arr[j]);
				sprintf(output[d], "%d x %d = %d", MAX, MIN, arr[i] * arr[j]);
				return true;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			int MAX = max(arr[i], arr[j]), MIN = min(arr[i], arr[j]);
			if (MAX == MIN)
			{
				continue;
			}
			len = 1;
			for (int k = 0; k < size; k++)
			{
				if (k != i && k != j)
				{
					tmp[len++] = arr[k];
				}
			}
			tmp[0] = MAX - MIN;
			if (dfs(d + 1, tmp, len, T, depth, output))
			{
				sprintf(output[d], "%d - %d = %d", MAX, MIN, MAX - MIN);
				return true;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			int MAX = max(arr[i], arr[j]), MIN = min(arr[i], arr[j]);
			if (MAX % MIN != 0)
			{
				continue;
			}
			len = 1;
			for (int k = 0; k < size; k++)
			{
				if (k != i && k != j)
				{
					tmp[len++] = arr[k];
				}
			}
			tmp[0] = MAX / MIN;
			if (dfs(d + 1, tmp, len, T, depth, output))
			{
				sprintf(output[d], "%d / %d = %d", MAX, MIN, MAX / MIN);
				return true;
			}
		}
	}

	return false;
}

int main()
{
	int T, N, arr[10];
	char output[10][M];
	while (scanf("%d", &T) == 1, T)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", arr + i);
		}
		memset(output, '\0', sizeof(output[0][0]) * 10 * M);

		int depth = 1;
		for (int depth = 1; depth <= N; depth++)
		{
			if (depth == N)
			{
				puts("No solution");
				break;
			}
			if (dfs(0, arr, N, T, depth, output))
			{
				for (int i = 0; i < depth - 1; i++)
				{
					puts(output[i]);
				}
				printf("%s <-\n", output[depth - 1]);
				break;
			}
		}
	}
	return 0;
}

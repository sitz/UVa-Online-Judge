#include <bits/stdc++.h>

using namespace std;

char s[1030][1005], final[1030];
int SET[2055];

int main()
{
	int N, n, M, m, i, j;
	while (scanf(" %d %d", &N, &M) == 2 && (N + M))
	{
		for (n = 0; n < N; n++)
		{
			scanf(" %s", s[n]);
		}
		int ans = 0, N2 = N * 2;
		for (m = 0; m < M; m++)
		{
			for (n = N; n < N2; n++)
			{
				SET[n] = (1 << (s[n - N][m] - 'A'));
			}
			for (n = N - 1; n > 0; n--)
			{
				SET[n] = SET[n << 1] & SET[n << 1 | 1];
				if (SET[n] == 0)
				{
					ans++;
					SET[n] = SET[n << 1] | SET[n << 1 | 1];
				}
			}
			for (i = 0; i < 26; i++)
			{
				if (SET[1] & (1 << i))
				{
					final[m] = i + 'A';
					break;
				}
			}
		}
		final[m] = '\0';
		printf("%s %d\n", final, ans);
	}
	return 0;
}

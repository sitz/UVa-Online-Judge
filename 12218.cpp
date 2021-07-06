#include <bits/stdc++.h>

using namespace std;

bool is[10000005], visit[10000005];
char s[10];
int a[10], ans, N, lim;

void pri()
{
	memset(is, false, sizeof(is));
	int i, j;
	is[0] = is[1] = true;
	for (i = 2; i < 10000000; i++)
		if (!is[i])
			for (j = i * 2; j < 10000000; j += i)
			{
				is[j] = true;
			}
}
void brute(int mask, int now)
{
	int i, j;
	if (visit[now])
	{
		return;
	}
	visit[now] = true;
	if (!is[now])
	{
		//printf("%d %d\n",mask,now);
		ans++;
	}
	if (mask == lim)
	{
		return;
	}
	//printf("XD%d\n",now);
	for (i = 0; i < N; i++)
	{
		if (mask & (1 << i))
		{
			continue;
		}
		brute(mask | (1 << i), now * 10 + a[i]);
	}
}

int main()
{
	pri();
	int T, i, j;
	scanf(" %d", &T);
	gets(s);
	while (T--)
	{
		gets(s);
		for (i = 0; s[i]; i++)
		{
			a[i] = s[i] - '0';
		}
		ans = 0;
		N = strlen(s);
		lim = (1 << N) - 1;
		//printf("lim = %d\n",lim);
		memset(visit, false, sizeof(visit));
		brute(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}

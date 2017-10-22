#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
const int maxm = 11000;

int n, m, K, ans;
int V[maxn][maxm], C[maxn][maxm], f[maxn][maxm], sc[maxm], sv[maxm], q[maxm];

int get()
{
	int f = 0, v = 0;
	char ch;
	while (!isdigit(ch = getchar()))
		if (ch == '-')
			break;
	if (ch == '-')
		f = 1;
	else
		v = ch - 48;
	while (isdigit(ch = getchar()))
		v = v * 10 + ch - 48;
	if (f)
		return -v;
	else
		return v;
}

void init()
{
	n++;
	m++;
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= m; j++)
			V[i][j] = get();
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= m; j++)
			C[i][j] = get();
}

void work()
{
	for (int i = 1; i <= n; i++)
	{
		int head = 1, tail = 0;
		sc[0] = sv[0] = 0;
		for (int j = 1; j <= m; j++)
		{
			sc[j] = sc[j - 1] + C[i][j];
			sv[j] = sv[j - 1] + V[i][j];
			while (head <= tail && f[i - 1][j] - f[i - 1][q[tail]] >= sv[j] - sv[q[tail]])
				tail--;
			q[++tail] = j;
			while (head <= tail && sc[j] - sc[q[head]] > K)
				head++;
			f[i][j] = f[i - 1][q[head]] + sv[j] - sv[q[head]];
		}
		head = 1, tail = 1;
		q[head] = m;
		for (int j = m - 1; j >= 1; j--)
		{
			while (head <= tail && sc[q[head]] - sc[j] > K)
				head++;
			f[i][j] = max(f[i][j], f[i - 1][q[head]] + sv[q[head]] - sv[j]);
			while (head <= tail && f[i - 1][j] - f[i - 1][q[tail]] >= sv[q[tail]] - sv[j])
				tail--;
			q[++tail] = j;
		}
	}
	ans = 0;
	for (int i = 1; i <= m; i++)
		ans = max(ans, f[n][i]);
	printf("%d\n", ans);
}

int main()
{
	while ((n = get()) + (m = get()) + (K = get()) > 0)
	{
		init();
		work();
	}
	return 0;
}

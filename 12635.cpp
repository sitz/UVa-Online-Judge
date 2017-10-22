#include <bits/stdc++.h>

using namespace std;

struct NN
{
	int s, t, n;
	NN(int ss, int tt, int nn)
	{
		s = ss, t = tt, n = nn;
	}
};

queue<NN> q;
int s[11000];

int is(int i, int j)
{
	if (i == 0)
	{
		return s[j] % 2 && s[j] == s[j - 1];
	}
	return (s[j] - s[i - 1]) % 2 && s[j] == s[j - 1] && s[i] == s[i - 1];
}

void upd(int s, int t, int k)
{
	q.push(NN(s, t, k));
}
int bfs(int k)
{
	int ans = 0;
	int i, j, u;
	for (i = 0; i < k; i++)
		q.push(NN(i, k, 0));
	while (!q.empty())
	{
		NN n = q.front();
		q.pop();

		if (n.n == 0)
		{
			int l = n.t - n.s;
			if (l && n.t + l <= 10000)
				q.push(NN(n.s, n.t + l, 1));
			continue;
		}
		if (is(n.s, n.t) && n.n <= 7)
			ans++;
		else
			continue;
		int l = n.t - n.s;
		if (n.t + l <= 10000)
			upd(n.s, n.t + l, n.n + 1);
		if (n.s - l >= 0)
			upd(n.s - l, n.t, n.n + 1);
	}
	return ans;
}
inline void scan(int &u)
{
	char c;
	while (c = getchar(), c < '0' || c > '9')
		;
	u = c - '0';
	while (c = getchar(), c <= '9' && c >= '0')
		u = u * 10 + c - '0';
}

int main()
{
	int n, i, j, k;
	int t, ii = 0;

	scanf("%d", &t);
	while (t--)
	{
		memset(s, 0, sizeof(s));
		while (scan(i), i)
			s[i]++;
		for (i = 1; i <= 10000; i++)
			s[i] += s[i - 1];
		scan(i);
		printf("%d\n", bfs(i));
	}
	return 0;
}

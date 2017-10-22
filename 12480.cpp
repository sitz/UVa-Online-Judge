#include <bits/stdc++.h>

using namespace std;

const int Maxn = 22;

struct Stack
{
	int v[3], top;
	int operator[](int x)
	{
		return v[x];
	}
	int size()
	{
		return top;
	}
	void push(int x)
	{
		v[top++] = x;
	}
	void clear()
	{
		top = 0;
	}
	void pop()
	{
		top--;
	}
} stk[Maxn];

struct Array
{
	int v[Maxn], top;
	int operator[](int x)
	{
		return v[x];
	}
	void add(int x)
	{
		v[top++] = x;
	}
	void clear()
	{
		top = 0;
	}
	bool operator<(const Array &e) const
	{
		for (int i = 0; i < top; ++i)
			if (v[i] < e.v[i])
			{
				return 1;
			}
			else if (v[i] > e.v[i])
			{
				return 0;
			}
		return 0;
	}
};

vector<Array> ans[Maxn];
void add(int n, int s)
{
	int l = -1;
	Array a;
	a.clear();
	while (1)
	{
		a.add(s);
		if (a.top == n)
		{
			break;
		}
		bool flag = false;
		for (int i = 0; i < stk[s].size(); ++i)
		{
			int x1 = stk[s][i];
			if (x1 == l)
			{
				continue;
			}
			l = s;
			s = x1;
			flag = true;
			break;
		}
		if (!flag)
		{
			return;
		}
	}
	ans[n].push_back(a);
	reverse(a.v, a.v + n);
	ans[n].push_back(a);
}

void dfs(int n, int e)
{
	if (e == n)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (stk[i].size() == 1)
			{
				add(n, i);
				break;
			}
		}
		return;
	}
	for (int i = 0; i < e; ++i)
	{
		if (stk[e - i].size() < 2 && stk[n - i].size() < 2)
		{
			stk[e - i].push(n - i), stk[n - i].push(e - i);
			dfs(n, e + 1);
			stk[e - i].pop(), stk[n - i].pop();
		}
	}
}

int main()
{
	for (int i = 2; i < 20; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			stk[j].clear();
		}
		dfs(i, 1);
		sort(ans[i].begin(), ans[i].end());
	}
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		printf("Case %d:", cas);
		int n, k;
		scanf("%d%d", &n, &k);
		if (ans[n].size() < k)
		{
			printf(" -1");
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				printf(" %d", ans[n][k - 1][i]);
			}
		}
		puts("");
	}
	return 0;
}

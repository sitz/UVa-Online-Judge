#include <bits/stdc++.h>

using namespace std;

int const N = 100005;
long long oo = (1LL << 62) - 1LL;
int num[N], Node;

struct node
{
	int a, b, l, r;
	long long sum, ssum, Min, Max, add, setN;
	bool flag;
	void read(int a, int b)
	{
		this->a = a;
		this->b = b;
		flag = false;
		add = 0;
	}
	void Add(long long c)
	{
		Min += c;
		Max += c;
		ssum += sum * c * 2LL + c * c * (b - a + 1);
		sum += c * (b - a + 1);
		if (flag)
		{
			setN += c;
		}
		else
		{
			add += c;
		}
	}
	void Set(long long c)
	{
		flag = true;
		sum = ssum = setN = Min = Max = add = 0;
		Add(c);
	}
} tr[N * 2], tmp;

void update(int k, int l, int r)
{
	tmp = tr[k];
	tmp.Max = max(tr[l].Max, tr[r].Max);
	tmp.Min = min(tr[l].Min, tr[r].Min);
	tmp.sum = tr[l].sum + tr[r].sum;
	tmp.ssum = tr[l].ssum + tr[r].ssum;
	tr[k] = tmp;
}

void makeTree(int a, int b)
{
	int k = ++Node;
	tr[k].read(a, b);
	if (a == b)
	{
		tr[k].Set(num[a]);
		return;
	}
	tr[k].l = Node + 1;
	makeTree(a, (a + b) / 2);
	tr[k].r = Node + 1;
	makeTree((a + b) / 2 + 1, b);
	update(k, tr[k].l, tr[k].r);
}

void insert(int a, int b, long long c, int cmd, int k)
{
	if (tr[k].b <= b && tr[k].a >= a)
	{
		switch (cmd)
		{
		case 0:
			tr[k].Set(c);
			break;
		case 1:
			tr[k].Add(c);
			break;
		case 2:
			update(0, 0, k);
			break;
		}
	}
	else
	{
		if (tr[k].flag)
		{
			tr[tr[k].l].Set(tr[k].setN);
			tr[tr[k].r].Set(tr[k].setN);
			tr[k].flag = false;
		}
		if (tr[k].add)
		{
			tr[tr[k].l].Add(tr[k].add);
			tr[tr[k].r].Add(tr[k].add);
			tr[k].add = 0;
		}
		int m = (tr[k].a + tr[k].b) >> 1;
		if (a <= m)
		{
			insert(a, b, c, cmd, tr[k].l);
		}
		if (b > m)
		{
			insert(a, b, c, cmd, tr[k].r);
		}
		update(k, tr[k].l, tr[k].r);
	}
}

long long gcd(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
	int T, n, m;
	long long t, x, y, d;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		printf("Case %d:\n", cas);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
		}
		Node = 0;
		makeTree(1, n);
		int cmd, a, b, c;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &cmd);
			if (cmd == 0 || cmd == 1)
			{
				scanf("%d%d%d", &a, &b, &c);
				insert(a, b, c, cmd, 1);
			}
			else
			{
				scanf("%d%d", &a, &b);
				tr[0].Min = oo;
				tr[0].Max = -oo;
				tr[0].sum = 0;
				tr[0].ssum = 0;
				insert(a, b, 0, cmd, 1);
				t = b - a + 1;
				x = tr[0].ssum * t - tr[0].sum * tr[0].sum;
				y = t * t;
				d = gcd(x, y);
				printf("%lld/%lld ", x / d, y / d);
				printf("%lld\n", tr[0].Max - tr[0].Min);
			}
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;
int n;

struct Buy
{
	int num, p;
	bool operator<(const Buy &x) const
	{
		return p < x.p;
	}
} buy;
struct Sell
{
	int num, p;
	bool operator<(const Sell &x) const
	{
		return p > x.p;
	}
} sell;
priority_queue<Buy> b;
priority_queue<Sell> s;
int ai, bi, si;

void solve()
{
	int tmp;
	ai = bi = -1;
	while (b.size() && s.size())
	{
		buy = b.top();
		sell = s.top();
		if (buy.p >= sell.p)
		{
			b.pop();
			s.pop();
			tmp = min(buy.num, sell.num);
			si = sell.p;
			buy.num -= tmp, sell.num -= tmp;
			if (buy.num)
				b.push(buy);
			if (sell.num)
				s.push(sell);
		}
		else
			break;
	}
	if (b.size())
		bi = b.top().p;
	if (s.size())
		ai = s.top().p;
}

int main()
{
	int ca, x, y;
	char op[15], tmp[15];
	scanf("%d", &ca);
	while (ca--)
	{
		si = -1;
		scanf("%d", &n);
		while (!b.empty())
			b.pop();
		while (!s.empty())
			s.pop();
		while (n--)
		{
			scanf("%s%d%s%s%d", op, &x, tmp, tmp, &y);
			if (op[0] == 'b')
			{
				buy.num = x, buy.p = y;
				b.push(buy);
			}
			else
			{
				sell.num = x, sell.p = y;
				s.push(sell);
			}
			solve();
			if (ai > 0)
				printf("%d ", ai);
			else
				printf("- ");
			if (bi > 0)
				printf("%d ", bi);
			else
				printf("- ");
			if (si > 0)
				printf("%d\n", si);
			else
				printf("-\n");
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int C(int price)
{
	int cons = 0;
	cons += min(max(0, price / 2), 100);
	price -= 2 * 100;
	cons += min(max(0, price / 3), 9900);
	price -= 3 * 9900;
	cons += min(max(0, price / 5), 990000);
	price -= 5 * 990000;
	cons += max(0, price / 7);
	return cons;
}

int V(int cons)
{
	int price = 0;
	price += min(max(0, cons * 2), 2 * 100);
	cons -= 100;
	price += min(max(0, cons * 3), 3 * 9900);
	cons -= 9900;
	price += min(max(0, cons * 5), 5 * 990000);
	cons -= 990000;
	price += max(0, cons * 7);
	return price;
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2, a|b)
	{
		int total = C(a), begin = 0, end = total, ans = 0;
		while (begin < end)
		{
			int mine = (begin + end) / 2;
			int diff = V(total - mine) - V(mine);
			if (diff > b)
			{
				begin = mine;
			}
			else if (diff < b)
			{
				end = mine;
			}
			else
			{
				ans = mine;
				break;
			}
		}
		printf("%d\n", V(ans));
	}
	return 0;
}

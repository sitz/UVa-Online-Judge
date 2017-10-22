#include <bits/stdc++.h>

using namespace std;

struct MakingChange
{
	int coin_face[10], price, coin_used, min_coin;

	int readData();
	void solve(int index, int sum, int cnt);
	int min_coinChange(int change);
	void init();
	void print();
} mc;

int MakingChange::readData()
{
	bool all_zero = true;
	for (int loop = 0; loop < 6; loop++)
	{
		cin >> coin_face[loop];
		if (coin_face[loop])
		{
			all_zero = false;
		}
	}
	if (all_zero)
	{
		return 0;
	}
	else
	{
		double tmp;
		cin >> tmp;
		price = (int)(tmp * 100.0 + 0.5);
		return 1;
	}
}

void MakingChange::init()
{
	coin_used = 0;
	min_coin = 0x7fffffff;
}

int MakingChange::min_coinChange(int change)
{
	int value, cnt = 0;
	value = change;
	while (value)
	{
		if (value < 200)
		{
			break;
		}
		cnt++;
		value -= 200;
	}
	while (value)
	{
		if (value < 100)
		{
			break;
		}
		cnt++;
		value -= 100;
	}
	while (value)
	{
		if (value < 50)
		{
			break;
		}
		cnt++;
		value -= 50;
	}
	while (value)
	{
		if (value < 20)
		{
			break;
		}
		cnt++;
		value -= 20;
	}
	while (value)
	{
		if (value < 10)
		{
			break;
		}
		cnt++;
		value -= 10;
	}
	while (value)
	{
		cnt++;
		value -= 5;
	}
	return cnt;
}

void MakingChange::solve(int index, int sum, int cnt)
{
	if (sum >= price)
	{
		int temp;
		temp = cnt + min_coinChange(sum - price);
		if (temp < min_coin)
		{
			min_coin = temp;
		}
		if (index == 6)
		{
			return;
		}
	}
	else
	{
		int loop;
		for (loop = 0; loop <= coin_face[index]; loop++)
		{
			switch (index)
			{
			case 0:
				solve(index + 1, sum + loop * 5, cnt + loop);
				break;
			case 1:
				solve(index + 1, sum + loop * 10, cnt + loop);
				break;
			case 2:
				solve(index + 1, sum + loop * 20, cnt + loop);
				break;
			case 3:
				solve(index + 1, sum + loop * 50, cnt + loop);
				break;
			case 4:
				solve(index + 1, sum + loop * 100, cnt + loop);
				break;
			case 5:
				solve(index + 1, sum + loop * 200, cnt + loop);
				break;
			}
		}
	}
}

void MakingChange::print()
{
	printf("%3d\n", min_coin);
}

int main()
{
	while (mc.readData())
	{
		mc.init();
		mc.solve(0, 0, 0);
		mc.print();
	}
	return 0;
}

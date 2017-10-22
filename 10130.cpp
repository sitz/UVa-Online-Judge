#include <bits/stdc++.h>

using namespace std;

int numOfCase, numOfObj, numOfPeople;
int c[1001][31];

struct Object
{
	int price, weight;
} obj[1001];

void InputObj()
{
	int i;
	for (i = 1; i <= numOfObj; i++)
	{
		cin >> obj[i].price >> obj[i].weight;
	}
}

void KnapSack()
{
	memset(c, 0, sizeof(c));
	int i, w;
	for (i = 0; i <= 1000; i++)
	{
		c[i][0] = 0;
	}
	for (w = 0; w <= 30; w++)
	{
		c[0][w] = 0;
	}
	for (i = 1; i <= numOfObj; i++)
		for (w = 1; w <= 30; w++)
		{
			if (obj[i].weight > w)
			{
				c[i][w] = c[i - 1][w];
			}
			else
			{
				int temp = c[i - 1][w - obj[i].weight] + obj[i].price;
				c[i][w] = c[i - 1][w] > temp ? c[i - 1][w] : temp;
			}
		}
}

int main()
{
	cin >> numOfCase;
	while (numOfCase--)
	{
		cin >> numOfObj;
		InputObj();
		cin >> numOfPeople;
		int sum = 0;
		KnapSack();
		while (numOfPeople--)
		{
			int mw;
			cin >> mw;
			sum += c[numOfObj][mw];
		}
		cout << sum << endl;
	}
	return 0;
}

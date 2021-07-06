#include <bits/stdc++.h>

using namespace std;

struct game
{
	int win;
	int loss;
	int gm;
};
game P[102];

void Cal(int n, int k)
{
	string move1, move2;
	int p1, p2, y;
	y = k * (n * (n - 1)) / 2;
	while (y--)
	{
		cin >> p1 >> move1 >> p2 >> move2;
		if (move1 == "rock")
		{
			if (move2 == "paper")
			{
				P[p1].loss++;
				P[p1].gm++;
				P[p2].win++;
				P[p2].gm++;
			}
			else if (move2 == "scissors")
			{
				P[p1].win++;
				P[p1].gm++;
				P[p2].loss++;
				P[p2].gm++;
			}
		}
		else if (move1 == "paper")
		{
			if (move2 == "rock")
			{
				P[p1].win++;
				P[p1].gm++;
				P[p2].loss++;
				P[p2].gm++;
			}
			else if (move2 == "scissors")
			{
				P[p1].loss++;
				P[p1].gm++;
				P[p2].win++;
				P[p2].gm++;
			}
		}
		else
		{
			if (move2 == "paper")
			{
				P[p1].win++;
				P[p1].gm++;
				P[p2].loss++;
				P[p2].gm++;
			}
			else if (move2 == "rock")
			{
				P[p1].loss++;
				P[p1].gm++;
				P[p2].win++;
				P[p2].gm++;
			}
		}
	}
	double x;
	for (int i = 1; i <= n; i++)
	{
		x = (double)P[i].win / (double)P[i].gm;
		if (P[i].gm == 0)
			printf("-\n");
		else
			printf("%.3lf\n", x);
		P[i].gm = P[i].loss = P[i].win = 0;
	}
}

int main()
{
	int n, k, g = 0;
	while (cin >> n && n)
	{
		cin >> k;
		if (g++)
			printf("\n");
		Cal(n, k);
	}
	return 0;
}

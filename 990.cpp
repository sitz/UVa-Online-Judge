#include <bits/stdc++.h>

using namespace std;

/**
 * Dynamic Programming, 0/1 Knapsack
 */

enum
{
	MAX_TREASURE = 30,
	MAX_DIVING_TIME = 1000
};

struct Treasure
{
	int depth, gold, time_cost;
};

// tables for dynamic programming
int c[MAX_DIVING_TIME + 1];
bool p[MAX_TREASURE][MAX_DIVING_TIME + 1];

void solve_knapsack(int total_time, Treasure *trs, int num_trs)
{
	memset(c, 0, sizeof(c));
	memset(p, 0, sizeof(p));
	for (int i = num_trs - 1; i >= 0; --i)
	{
		for (int j = total_time; j >= trs[i].time_cost; --j)
		{
			if (c[j] < c[j - trs[i].time_cost] + trs[i].gold)
			{
				c[j] = c[j - trs[i].time_cost] + trs[i].gold;
				p[i][j] = true;
			}
		}
	}
}

void print_result(int total_time, Treasure *trs, int num_trs)
{
	std::ostringstream sout;// the output string
	int trs_count = 0;
	int total_gold = c[total_time];
	// count the total number of treasures
	int w = total_time;
	for (int i = 0; i < num_trs; ++i)
	{
		if (p[i][w])
		{
			sout << trs[i].depth << " " << trs[i].gold << "\n";
			w = w - trs[i].time_cost;
			trs_count++;
		}
	}
	printf("%d\n%d\n", total_gold, trs_count);
	printf("%s", sout.str().c_str());
}

int main()
{
	bool first_time = true;
	int total_time, speed;
	while (scanf("%d %d", &total_time, &speed) == 2)
	{
		if (!first_time)
			putchar('\n');
		first_time = false;
		int num_trs;
		Treasure trs[MAX_TREASURE];//treasure
		scanf("%d", &num_trs);
		for (int i = 0; i < num_trs; ++i)
			scanf("%d %d", &trs[i].depth, &trs[i].gold);
		for (int i = 0; i < num_trs; ++i)
			trs[i].time_cost = trs[i].depth * speed * 3;
		solve_knapsack(total_time, trs, num_trs);
		print_result(total_time, trs, num_trs);
	}
	return 0;
}

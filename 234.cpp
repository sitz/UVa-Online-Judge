#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

struct Align
{
	int priority, time;
};

bool compare(Align a1, Align a2)
{
	return a1.time < a2.time;
}

int main()
{
	int best_miss[10], curr_miss[10], best_arrange[10], prog[10], seg[10];
	Align align[10];
	int t = 0, p;
	while (scanf("%d", &p) == 1, p)
	{
		++t;
		for (int i = 0; i < p; ++i)
		{
			scanf("%d", &prog[i]);
		}
		int a;
		scanf("%d", &a);
		int max_p = 0;
		for (int i = 0; i < a; ++i)
		{
			scanf("%d%d", &align[i].priority, &align[i].time);
			max_p = max(max_p, align[i].priority);
		}
		sort(prog, prog + p);
		sort(align, align + a, compare);
		for (int i = 1; i <= max_p; ++i)
		{
			best_miss[i] = INF;
		}
		seg[p] = INF;

		do
		{
			for (int i = 1; i <= max_p; ++i)
			{
				curr_miss[i] = 0;
			}
			seg[0] = prog[0];
			for (int i = 1; i < p; ++i)
			{
				seg[i] = seg[i - 1] + prog[i];
			}
			int bef = 0, aft = seg[0], curr = 0;
			for (int i = 0; i < a; ++i)
			{
				int t = align[i].time;
				while (1)
				{
					if (t < aft)
					{
						break;
					}
					bef = aft;
					aft = seg[++curr];
				}
				curr_miss[align[i].priority] += min(t - bef, aft - t);
			}
			bool best = false;
			for (int i = 1; i <= max_p; ++i)
			{
				if (curr_miss[i] < best_miss[i])
				{
					best = true;
					break;
				}
				if (curr_miss[i] > best_miss[i])
				{
					break;
				}
			}
			if (best)
			{
				for (int i = 1; i <= max_p; ++i)
				{
					best_miss[i] = curr_miss[i];
				}
				for (int i = 0; i < p; ++i)
				{
					best_arrange[i] = prog[i];
				}
			}
		} while (next_permutation(prog, prog + p));

		printf("Data set %d\n  Order:", t);
		for (int i = 0; i < p; ++i)
		{
			printf(" %d", best_arrange[i]);
		}
		int sum_miss = 0;
		for (int i = 1; i <= max_p; ++i)
		{
			sum_miss += best_miss[i];
		}
		printf("\n  Error: %d\n", sum_miss);
	}
	return 0;
}

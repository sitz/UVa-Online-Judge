#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const ULL MAX_VAL = 1000000000ULL;

int main()
{
	int t = 1, c, r, q;
	while (scanf("%d%d%d", &c, &r, &q) == 3, c + r + q)
	{
		if (t != 1)
		{
			printf("\n");
		}
		++c;
		vector<vector<ULL> > worst_feast_costs(c, vector<ULL>(c, MAX_VAL));
		for (int i = 1; i < c; ++i)
		{
			scanf("%llu", &worst_feast_costs[i][i]);
		}

		vector<vector<ULL> > travel_costs(c, vector<ULL>(c, MAX_VAL));
		for (int i = 0; i < r; ++i)
		{
			int start, end;
			ULL curr;
			scanf("%d%d%llu", &start, &end, &curr);
			if (curr < travel_costs[start][end])
			{
				travel_costs[start][end] = curr;
				travel_costs[end][start] = curr;
				ULL feast_cost = max(worst_feast_costs[start][start],
														 worst_feast_costs[end][end]);
				worst_feast_costs[start][end] = feast_cost;
				worst_feast_costs[end][start] = feast_cost;
			}
		}

		// run floyd-warshall 2x because of interaction with worst_feast_costs
		for (int p = 0; p < 2; ++p)
		{
			for (int k = 1; k < c; ++k)
			{
				for (int i = 1; i < c; ++i)
				{
					for (int j = 1; j < c; ++j)
					{
						ULL worst_feast = max(worst_feast_costs[i][k], worst_feast_costs[k][j]);
						if (travel_costs[i][j] + worst_feast_costs[i][j] > travel_costs[i][k] + travel_costs[k][j] + worst_feast)
						{
							travel_costs[i][j] = travel_costs[i][k] + travel_costs[k][j];
							worst_feast_costs[i][j] = worst_feast;
						}
					}
				}
			}
		}

		printf("Case #%d\n", t++);
		for (int i = 0; i < q; ++i)
		{
			int start, end;
			scanf("%d%d", &start, &end);
			if (travel_costs[start][end] == MAX_VAL)
			{
				printf("-1\n");
			}
			else
			{
				printf("%llu\n", travel_costs[start][end] + worst_feast_costs[start][end]);
			}
		}
	}
}

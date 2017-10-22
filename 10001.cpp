#include <bits/stdc++.h>

using namespace std;

int automaton[2][2][2], state[40], map_[160][160], reachable[160], n, maxn;

void init_automaton(int identifier)
{
	memset(automaton, 0, sizeof(automaton));
	for (int i = 0; i <= 1; ++i)
	{
		for (int j = 0; j <= 1; ++j)
		{
			for (int k = 0; k <= 1; ++k)
			{
				automaton[i][j][k] = identifier & 1;
				identifier >>= 1;
			}
		}
	}
}

void init_state(char str_state[])
{
	memset(state, 0, sizeof(state));
	for (int i = 0; i < strlen(str_state); ++i)
	{
		state[i] = str_state[i] - '0';
	}
}

void add_edge(int id1, int cur1, int next1, int id2, int cur2, int next2)
{
	int node1 = id1 * 4 + cur1 * 2 + next1;
	int node2 = id2 * 4 + cur2 * 2 + next2;
	map_[node1][node2] = 1;
}

void init_map_(void)
{
	memset(map_, 0, sizeof(map_));
	maxn = n * 4;
	for (int id = 0; id < n; ++id)
	{
		for (int cur = 0; cur <= 1; ++cur)
		{
			for (int next = 0; next <= 1; ++next)
			{
				for (int next2 = 0; next2 <= 1; ++next2)
				{
					int next_id = (id + 1) % n;
					if (state[next_id] == automaton[cur][next][next2])
					{
						add_edge(id, cur, next, next_id, next, next2);
					}
				}
			}
		}
	}
}

int calc_state()
{
	for (int first = 0; first < 4; ++first)
	{
		memset(reachable, 0, sizeof(reachable));
		reachable[first] = 1;
		for (int id = 0; id < n - 1; ++id)
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (reachable[id * 4 + i] && map_[id * 4 + i][(id + 1) * 4 + j])
					{
						reachable[(id + 1) * 4 + j] = 1;
						if (id == n - 2)
						{
							if (map_[(id + 1) * 4 + j][first])
							{
								return 1;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	int identifier, is_reachable;
	char str_state[1000];
	while (scanf("%d%d%s", &identifier, &n, str_state) != EOF)
	{
		init_automaton(identifier);
		init_state(str_state);
		init_map_();
		is_reachable = calc_state();
		printf(is_reachable ? "REACHABLE\n" : "GARDEN OF EDEN\n");
	}
	return 0;
}

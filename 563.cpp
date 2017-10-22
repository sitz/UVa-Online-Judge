#include <bits/stdc++.h>

using namespace std;

#define MAX 5002
#define RESIDUE(s, t) (capacity[s][t] - flow[s][t])

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int bank[MAX][2], flow[MAX][MAX], capacity[MAX][MAX], prev_[MAX], s, a, b;

inline int getSourceID()
{
	return s * a * 2;
}
inline int getDestinationID()
{
	return s * a * 2 + 1;
}
inline int getIDByRowCol(int r, int c, int rank)
{
	return r * a + c + rank * s * a;
}
inline void getRowColByID(int id, int &row, int &col, int &rank)
{
	rank = id >= s * a;
	id %= s * a;
	row = id / a;
	col = id % a;
}
inline bool isValid(int r, int c)
{
	return 0 <= r && r < s && 0 <= c && c < a;
}
inline bool isOnEdge(int r, int c)
{
	return r == 0 || r == s - 1 || c == 0 || c == a - 1;
}

void display(int id)
{
	if (prev_[id] != id)
	{
		display(prev_[id]);
	}
	if (id == getSourceID())
	{
		cout << "source" << endl;
	}
	else if (id == getDestinationID())
	{
		cout << "destination" << endl;
	}
	else
	{
		int row, col, rank;
		getRowColByID(id, row, col, rank);
		cout << row + 1 << " " << col + 1;
		if (rank)
		{
			cout << " shadow";
		}
		cout << endl;
	}
}

main()
{
	int p;
	cin >> p;
	for (int P = 0; P < p; ++P)
	{
		// Input
		cin >> s >> a >> b;
		for (int i = 0; i < b; ++i)
		{
			cin >> bank[i][0] >> bank[i][1];
			bank[i][0]--, bank[i][1]--;
		}
		// Initialize
		memset(capacity, 0, sizeof(capacity));
		memset(flow, 0, sizeof(flow));
		// Source to banks
		for (int i = 0; i < b; ++i)
		{
			capacity[getSourceID()][getIDByRowCol(bank[i][0], bank[i][1], 0)] = 1;
		}
		// Adjacent grid
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < a; ++j)
			{
				int fromID = getIDByRowCol(i, j, 0);
				int _fromID = getIDByRowCol(i, j, 1);
				capacity[_fromID][fromID] = 1;
				for (int k = 0; k < 4; ++k)
				{
					int ni = i + dr[k];
					int nj = j + dc[k];
					if (!isValid(ni, nj))
					{
						continue;
					}
					int toID = getIDByRowCol(ni, nj, 1);
					capacity[fromID][toID] = 1;
				}
			}
		}
		// Grids on edge to destination
		for (int i = 0; i < s; ++i)
		{
			capacity[getIDByRowCol(i, 0, 0)][getDestinationID()] = 1;
			capacity[getIDByRowCol(i, a - 1, 0)][getDestinationID()] = 1;
		}
		for (int j = 0; j < a; ++j)
		{
			capacity[getIDByRowCol(0, j, 0)][getDestinationID()] = 1;
			capacity[getIDByRowCol(s - 1, j, 0)][getDestinationID()] = 1;
		}
		// If a bank exists on a corner, transition between
		// surface and shadow is forbidden.
		for (int i = 0; i < b; ++i)
		{
			capacity[getIDByRowCol(bank[i][0], bank[i][1], 1)][getIDByRowCol(bank[i][0], bank[i][1], 0)] = 0;
		}
		// Maxflow
		int total = 0;
		while (1)
		{
			queue<int> que;
			que.push(getSourceID());
			memset(prev_, -1, sizeof(prev_));
			prev_[getSourceID()] = getSourceID();
			while (!que.empty() && prev_[getDestinationID()] == -1)
			{
				int u = que.front();
				que.pop();
				vector<int> nextID;
				if (u == getSourceID())
				{
					for (int i = 0; i < b; ++i)
					{
						//cout << bank[i][0] << " " << bank[i][1] << ", id = " << getIDByRowCol(bank[i][0], bank[i][1], 0) << endl;
						nextID.push_back(getIDByRowCol(bank[i][0], bank[i][1], 0));
					}
				}
				else
				{
					int row, col, rank;
					getRowColByID(u, row, col, rank);
					//cout << u << " " << row << " " << col << " " << rank << endl;
					if (rank == 0 && isOnEdge(row, col))
					{
						nextID.push_back(getDestinationID());
					}
					else if (rank == 1)
					{
						nextID.push_back(getIDByRowCol(row, col, 0));
					}
					else
					{
						for (int i = 0; i < 4; ++i)
						{
							int nrow = row + dr[i];
							int ncol = col + dc[i];
							if (!isValid(nrow, ncol))
							{
								continue;
							}
							nextID.push_back(getIDByRowCol(nrow, ncol, 1));
						}
					}
				}
				for (int i = 0; i < nextID.size(); ++i)
				{
					int v = nextID[i];
					if (prev_[v] == -1 && RESIDUE(u, v) > 0)
					{
						prev_[v] = u;
						que.push(v);
					}
				}
			}
			if (prev_[getDestinationID()] == -1)
			{
				break;
			}
			int inc = INT_MAX;
			for (int j = getDestinationID(); prev_[j] != j; j = prev_[j])
			{
				inc = min(inc, RESIDUE(prev_[j], j));
			}
			for (int j = getDestinationID(); prev_[j] != j; j = prev_[j])
			{
				flow[prev_[j]][j] += inc, flow[j][prev_[j]] -= inc;
			}
			//display(getDestinationID()); cout << endl;
			total += inc;
		}
		//cout << total << endl;
		if (total == b)
		{
			cout << "possible" << endl;
		}
		else
		{
			cout << "not possible" << endl;
		}
	}
}

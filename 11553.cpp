#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 8;
const int INF = 1 << 29;

int N;
int board[MAX_N][MAX_N];
int memo[1 << MAX_N][1 << MAX_N];
bool visited[1 << MAX_N][1 << MAX_N];

void init()
{
	memset(visited, false, sizeof(visited));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", board[i] + j);
		}
	}
}

int rec(const int bit1, const int bit2)
{
	//メモ化処理
	if (visited[bit1][bit2])
	{
		return memo[bit1][bit2];
	}
	visited[bit1][bit2] = true;
	int &ret = memo[bit1][bit2];
	//基底
	if (__builtin_popcount(bit1) == N)
	{
		return ret = 0;
	}
	ret = -INF;
	for (int i = 0; i < N; i++)
		if (!((bit1 >> i) & 1))
		{
			int tmp = INF;
			for (int j = 0; j < N; j++)
				if (!((bit2 >> j) & 1))
				{
					tmp = min(tmp, board[i][j] + rec(bit1 | (1 << i), bit2 | (1 << j)));
				}
			ret = max(ret, tmp);
		}
	return ret;
}

int solve()
{
	return rec(0, 0);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		printf("%d\n", solve());
	}
	return 0;
}

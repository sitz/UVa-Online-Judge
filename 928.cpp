#include <bits/stdc++.h>

using namespace std;

#define VALID(I, J, N, M) (I) >= 0 && (J) >= 0 && (I) < (N) && (J) < (M)
#define INF 1 << 29

typedef pair<int, int> Point;

int main()
{
	int dx[] = {-1, 0, 0, 1};
	int dy[] = {0, -1, 1, 0};
	int T, N, M, i, j, sourceX, sourceY, endX, endY;
	int prevMoves = 0, curMoves = 1, curX, curY, nextX, nextY;
	int delta, bad, JUMP;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		char graph[N][M];
		int d[N][M][4];
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
			{
				cin >> graph[i][j];
				d[i][j][1] = d[i][j][2] = d[i][j][3] = INF;
				if (graph[i][j] == 'S')
				{
					sourceY = i;
					sourceX = j;
				}
				if (graph[i][j] == 'E')
				{
					endY = i;
					endX = j;
				}
			}
		queue<pair<Point, int>> que;
		d[sourceY][sourceX][0] = 0;
		que.push(pair<Point, int>(Point(sourceY, sourceX), 0));
		bool found = false;
		while (!que.empty() && !found)
		{
			curY = que.front().first.first, curX = que.front().first.second;
			prevMoves = que.front().second, curMoves = prevMoves % 3 + 1;
			que.pop();
			for (delta = 0; delta < 4; delta++)
			{
				nextY = curY + dy[delta] * curMoves, nextX = curX + dx[delta] * curMoves;
				if (VALID(nextY, nextX, N, M) && graph[nextY][nextX] != '#' && d[nextY][nextX][curMoves] == INF)
				{
					for (JUMP = 1, bad = false; JUMP <= curMoves; JUMP++)
					{
						bad = bad || graph[curY + dy[delta] * JUMP][curX + dx[delta] * JUMP] == '#';
					}
					if (bad)
					{
						continue;
					}
					d[nextY][nextX][curMoves] = d[curY][curX][prevMoves] + 1;
					if (nextY == endY && nextX == endX)
					{
						found = true;
					}
					que.push(pair<Point, int>(Point(nextY, nextX), curMoves));
				}
			}
		}
		if (!found)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << d[endY][endX][curMoves] << endl;
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int w, h;
bool board[64][64];

struct StepStruct
{
	int x, y, step;
	StepStruct(int a, int b, int c)
	{
		x = a;
		y = b;
		step = c;
	}
	bool operator<(const StepStruct &t) const
	{
		if (y != t.y)
		{
			return y > t.y;
		}
		return x < t.x;
	}
};

int main()
{
	int c = 0;
	int dx[] = {1 /*,-1,1*/, -1, 0 /*,0*/, 1, -1};
	int dy[] = {1 /*,-1,-1*/, 1, 1 /*,-1*/, 0, 0};
	while (scanf("%d %d", &h, &w) == 2)
	{
		assert(h > 0 && h <= 62 && w > 0 && w <= 62);
		memset(board, 0, 64 * 64);
		for (int i = 4 * w; --i >= 0;)
		{
			int x, y;
			scanf("%d %d", &y, &x);
			board[y][x] = true;
		}
		int ax, ay;
		scanf("%d %d", &ay, &ax);
		vector<StepStruct> ret;
		//one step
		if (ax > 1 && !board[ay][ax - 1])
		{
			ret.push_back(StepStruct(ax - 1, ay, 1));
		}
		if (ax < w && !board[ay][ax + 1])
		{
			ret.push_back(StepStruct(ax + 1, ay, 1));
		}
		//if (ay>1 && !board[ay-1][ax]) ret.push_back(StepStruct(ax,ay-1,1));
		if (ay < h && !board[ay + 1][ax])
		{
			ret.push_back(StepStruct(ax, ay + 1, 1));
		}
		//jump! BFS
		bool visited[64][64];
		memset(visited, 0, 64 * 64);
		queue<StepStruct> q;
		q.push(StepStruct(ax, ay, 0));
		visited[ay][ax] = true;
		while (!q.empty())
		{
			StepStruct now = q.front();
			q.pop();
			for (int i = 5; --i >= 0;)
			{
				StepStruct tmp = now;
				tmp.x += dx[i];
				tmp.y += dy[i];
				if (tmp.y < 1 || tmp.y > h || tmp.x < 1 || tmp.x > w || !board[tmp.y][tmp.x])//must have chess
				{
					continue;
				}
				tmp.x += dx[i];
				tmp.y += dy[i];
				if (tmp.y < 1 || tmp.y > h || tmp.x < 1 || tmp.x > w || board[tmp.y][tmp.x] || visited[tmp.y][tmp.x])//no chess
				{
					continue;
				}
				visited[tmp.y][tmp.x] = true;
				tmp.step++;
				q.push(tmp);
				ret.push_back(tmp);
			}
		}
		sort(ret.begin(), ret.end());
		//output
		if (c++)
		{
			putchar('\n');
		}
		for (int i = 0; i < ret.size(); i++)
		{
			printf("%d %d %d\n", ret[i].y, ret[i].x, ret[i].step);
		}
	}
}

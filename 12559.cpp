#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

const double PI = acos(-1);

struct point
{
	int x, y;
};

struct circle
{
	point c;
	int r;
	bool operator<(const circle &C) const
	{
		return make_pair(make_pair(r, c.x), c.y) < make_pair(make_pair(C.r, C.c.x), C.c.y);
	}
	bool operator==(const circle &C) const
	{
		return r == C.r && c.x == C.c.x && c.y == C.c.y;
	}
};

int h, w;
char B[100][101];

bool check(const circle &C)
{
	int cnt = 0;
	rep(t, 1000)
	{
		double theta = 2 * PI * t / 1000;
		int x = (int)(C.c.x + C.r * cos(theta) + 0.5);
		int y = (int)(C.c.y + C.r * sin(theta) + 0.5);
		if (0 <= y && y < h && 0 <= x && x < w && B[y][x] == '1')
		{
			cnt++;
		}
	}
	return cnt > 900;
}

void solve()
{
	scanf("%d%d", &w, &h);
	rep(i, h) scanf("%s", B[i]);
	vector<point> H, V;
	rep(i, h) rep(j, w) if (B[i][j] == '1')
	{
		int x = j;
		while (j < w && B[i][j] == '1' || j + 1 < w && B[i][j + 1] == '1')
		{
			j++;
		}
		if (j - x >= 5)
		{
			H.push_back((point){
					x, i});
		}
	}
	rep(j, w) rep(i, h) if (B[i][j] == '1')
	{
		int y = i;
		while (i < h && B[i][j] == '1' || i + 1 < h && B[i + 1][j] == '1')
		{
			i++;
		}
		if (i - y >= 5)
		{
			V.push_back((point){
					j, y});
		}
	}
	vector<circle> C;
	rep(j, H.size()) rep(i, j)
	{
		int d1 = abs(H[j].y - H[i].y);
		if (d1 % 2 != 0 || d1 < 10)
		{
			continue;
		}
		int r1 = d1 / 2;
		rep(l, V.size()) rep(k, l)
		{
			int d2 = abs(V[l].x - V[k].x);
			if (d2 % 2 != 0 || d2 < 10)
			{
				continue;
			}
			int r2 = d2 / 2;
			if (r1 == r2)
			{
				int y = min(H[i].y, H[j].y) + r1;
				int x = min(V[k].x, V[l].x) + r2;
				C.push_back((circle){
						(point){x, y}, r1});
			}
		}
	}
	sort(C.begin(), C.end());
	C.erase(unique(C.begin(), C.end()), C.end());
	rep(i, C.size()) if (!check(C[i]))
	{
		C.erase(C.begin() + i), i--;
	}
	printf("%d", C.size());
	rep(i, C.size()) printf(" (%d,%d,%d)", C[i].r, C[i].c.x, C[i].c.y);
	puts("");
}

int main()
{
	int T;
	scanf("%d ", &T);
	for (int cas = 1; cas <= T; cas++)
		printf("Case %d: ", cas), solve();
	return 0;
}

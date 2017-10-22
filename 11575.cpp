#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FILL(x, v) memset(x, v, sizeof(x))
#define FOREACH(i, v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
int N;
#define IN(x) ((x) >= 1 && (x) <= N)
#define MP0 make_pair(0, 0)
#define MAXN 22555
const int INF = (int)1E9;
int atk1, atk2, def1, def2;
int n1, n2;
struct zerg
{
	int hp;
	int x, y, a;
	zerg() {}
	zerg(int _x, int _y)
	{
		hp = 35;
		x = _x;
		y = _y;
		a = 0;
	}
} z1[MAXN], z2[MAXN];

char gd[200];
pair<int, int> fd[200][200], fdnxt[200][200], from[200][200];
int dst1[200][200], dst2[200][200];

bool v[200][200];
struct dij
{
	int x, y, d;
	dij(int _x, int _y, int _d)
	{
		x = _x;
		y = _y;
		d = _d;
	}
};

int dir8[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
int dir4[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void repack(int x, int y, int thatg, int thatid)
{
	if (fdnxt[x][y].first == 0)
	{
		zerg *z = thatg == 1 ? z1 : z2;
		z[thatid].x = x;
		z[thatid].y = y;
		fdnxt[x][y] = make_pair(thatg, thatid);
		//from[x][y] = MP0;
		return;
	}
	//if(from[x][y]==MP0) return;
	repack(from[x][y].first, from[x][y].second, fdnxt[x][y].first, fdnxt[x][y].second);
	from[x][y] = MP0;
	fdnxt[x][y] = make_pair(thatg, thatid);
	zerg *z = thatg == 1 ? z1 : z2;
	z[thatid].x = x;
	z[thatid].y = y;
}

void bfs(zerg *z, int n, int dst[200][200])
{
	//REP(i,1,N+1) REP(j,1,N+1) dst[i][j] = INF;
	FILL(v, 0);
	queue<dij> que;
	REP(i, 0, n)
	{
		que.push(dij(z[i].x, z[i].y, 0));
		v[z[i].x][z[i].y] = 1;
		dst[z[i].x][z[i].y] = 0;
	}
	while (!que.empty())
	{
		dij now = que.front();
		que.pop();
		REP(i, 0, 4)
		{
			int nx = now.x + dir4[i][0],
					ny = now.y + dir4[i][1];
			if (IN(nx) && IN(ny) && !v[nx][ny])
			{
				dst[nx][ny] = now.d + 1;
				v[nx][ny] = 1;
				que.push(dij(nx, ny, now.d + 1));
			}
		}
	}
}

int main()
{
	bool fst = 1;
	while (1)
	{
		scanf("%d", &N);
		if (!N)
			break;

		if (fst)
			fst = 0;
		else
			puts("");

		scanf("%d%d%d%d", &atk1, &def1, &atk2, &def2);
		n1 = n2 = 0;

		FILL(fd, 0);

		REP(i, 1, N + 1)
		{
			scanf("%s", &gd[1]);
			REP(j, 1, N + 1)
			{
				if (gd[j] == '1')
				{
					fd[i][j] = make_pair(1, n1);
					z1[n1++] = zerg(i, j);
				}
				else if (gd[j] == '2')
				{
					fd[i][j] = make_pair(2, n2);
					z2[n2++] = zerg(i, j);
				}
			}
		}
		int T;
		scanf("%d", &T);
		REP(t, 1, T + 1)
		{
			REP(i, 0, n1)
			z1[i].a = 0;
			REP(i, 0, n2)
			z2[i].a = 0;
			// atk zerg1
			REP(i, 0, n1)
			{
				int x = z1[i].x, y = z1[i].y;
				REP(d, 0, 8)
				{
					int nx = x + dir8[d][0], ny = y + dir8[d][1];
					if (fd[nx][ny].first == 2)
					{
						int id = fd[nx][ny].second;
						z2[id].hp -= 5 + atk1 - def2;
						z1[i].a = 1;
						break;
					}
				}
			}
			// atk zerg2
			REP(i, 0, n2)
			{
				int x = z2[i].x, y = z2[i].y;
				REP(d, 0, 8)
				{
					int nx = x + dir8[d][0], ny = y + dir8[d][1];
					if (fd[nx][ny].first == 1)
					{
						int id = fd[nx][ny].second;
						z1[id].hp -= 5 + atk2 - def1;
						z2[i].a = 1;
						break;
					}
				}
			}

			bfs(z2, n2, dst1);
			bfs(z1, n1, dst2);

			// remove dead zerg1
			REP(i, 0, n1)
			{
				int x = z1[i].x, y = z1[i].y;
				if (z1[i].hp <= 0)
				{
					fd[x][y] = MP0;

					int x2 = z1[n1 - 1].x, y2 = z1[n1 - 1].y;
					fd[x2][y2].second = i;

					swap(z1[i], z1[n1 - 1]);
					n1--;
					i--;
				}
			}
			// remove dead zerg2
			REP(i, 0, n2)
			{
				int x = z2[i].x, y = z2[i].y;
				if (z2[i].hp <= 0)
				{
					fd[x][y] = MP0;

					int x2 = z2[n2 - 1].x, y2 = z2[n2 - 1].y;
					fd[x2][y2].second = i;

					swap(z2[i], z2[n2 - 1]);
					n2--;
					i--;
				}
			}

			FILL(fdnxt, 0);
			FILL(from, 0);
			REP(i, 0, n1)
			if (z1[i].a == 1) fdnxt[z1[i].x][z1[i].y] = make_pair(1, i);
			REP(i, 0, n2)
			if (z2[i].a == 1) fdnxt[z2[i].x][z2[i].y] = make_pair(2, i);
			REP(i, 0, n1)
			if (z1[i].hp < 35) z1[i].hp++;
			REP(i, 0, n2)
			if (z2[i].hp < 35) z2[i].hp++;

			// move zerg
			REP(i, 1, N + 1)
			{
				REP(j, 1, N + 1)
				{
					int g = fd[i][j].first,
							id = fd[i][j].second;
					if (g == 0)
						continue;
					zerg *z = g == 1 ? z1 : z2;
					if (z[id].a)
						continue;
					int x = z[id].x, y = z[id].y;

					int ad = -1, mind = INF;
					REP(d, 0, 8)
					{
						int nx = x + dir8[d][0],
								ny = y + dir8[d][1];
						if (IN(nx) && IN(ny) && (g == 1 ? dst1[nx][ny] : dst2[nx][ny]) < mind)
						{
							mind = g == 1 ? dst1[nx][ny] : dst2[nx][ny];
							ad = d;
						}
					}
					int nx = x + dir8[ad][0],
							ny = y + dir8[ad][1];

					if (fdnxt[nx][ny].first == 0)
					{
						fdnxt[nx][ny] = make_pair(g, id);
						from[nx][ny] = make_pair(x, y);
						z[id].x = nx;
						z[id].y = ny;
					}
					else
					{
						// someone else moves here, not move
						repack(x, y, g, id);
					}
				}
			}
			memcpy(fd, fdnxt, sizeof(fd));
			if (n1 == 0 || n2 == 0)
				break;
		}

		REP(i, 1, N + 1)
		{
			REP(j, 1, N + 1)
			{
				if (fd[i][j].first)
				{
					printf("%d", fd[i][j].first);
				}
				else
					printf(".");
			}
			puts("");
		}
	}
	return 0;
}

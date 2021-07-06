#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

char map_[25][25];
int ptt, n, m, px[25], py[25], pnum, brig[2], con[25][25], dis[25][25];

typedef struct data
{
	int n, len, s;
	unsigned long long st;
	struct data *left, *right;
} data;

data pool[1000005], *queue_[1000005];

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int min(int p, int q)
{
	return p < q ? p : q;
}

int max(int p, int q)
{
	return p > q ? p : q;
}

int intersect(int nod, int dir, unsigned long long st)
{
	int i, j;
	int x1, x2, y1, y2, tx1, tx2, ty1, ty2;
	x1 = px[nod] + dx[dir];
	y1 = py[nod] + dy[dir];
	x2 = x1 + dx[dir] * (dis[nod][dir] - 2);
	y2 = y1 + dy[dir] * (dis[nod][dir] - 2);
	for (i = 0; i < pnum; i++)
	{
		if (i != nod)
		{
			for (j = 0; j < 4; j++)
			{
				if (con[i][j] != nod && (st & (1LLU << ((i << 2) + j))))
				{
					tx1 = px[i] + dx[j];
					ty1 = py[i] + dy[j];
					tx2 = tx1 + dx[j] * (dis[i][j] - 2);
					ty2 = ty1 + dy[j] * (dis[i][j] - 2);
					if (min(tx1, tx2) <= max(x1, x2) && max(tx1, tx2) >= min(x1, x2))
					{
						if (min(ty1, ty2) <= max(y1, y2) && max(ty1, ty2) >= min(y1, y2))
						{
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

data *get_node()
{
	return pool + ptt++;
}

data *search(data *ptr, int nod, int len, unsigned long long st, int s, data **r)
{
	int dif;
	if (ptr == NULL)
	{
		ptr = get_node();
		ptr->n = nod;
		ptr->len = len;
		ptr->st = st;
		ptr->s = s;
		ptr->left = ptr->right = NULL;
		*r = ptr;
		return ptr;
	}
	if (ptr->st != st)
	{
		dif = (ptr->st > st ? 1 : -1);
	}
	else if (ptr->n != nod)
	{
		dif = ptr->n - nod;
	}
	else if (ptr->len != len)
	{
		dif = ptr->len - len;
	}
	else
	{
		dif = 0;
	}
	if (dif == 0)
	{
		*r = NULL;
		return ptr;
	}
	else if (dif < 0)
	{
		ptr->left = search(ptr->left, nod, len, st, s, r);
		return ptr;
	}
	ptr->right = search(ptr->right, nod, len, st, s, r);
	return ptr;
}

int main()
{
	int count, i, j, k, x, y, sp, ep, nod, len, nlen, s;
	unsigned long long st, nst;
	data *head, *q, *res;
	brig[0] = '-';
	brig[1] = '|';
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i = 0, pnum = 0; i < n; i++)
		{
			scanf("%s", map_[i]);
			for (j = 0; j < m; j++)
			{
				if (map_[i][j] == 'S' || map_[i][j] == 'B' || map_[i][j] == 'E')
				{
					px[pnum] = i;
					py[pnum] = j;
					if (map_[i][j] == 'B')
					{
						sp = pnum;
					}
					else if (map_[i][j] == 'E')
					{
						ep = pnum;
					}
					pnum++;
				}
			}
		}
		memset(con, -1, sizeof(con));
		for (i = 0, st = 0; i < pnum; i++)
		{
			x = px[i];
			y = py[i];
			for (j = 0; j < pnum; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (x == px[j])
				{
					if (y < py[j])
					{
						if (con[i][0] == -1 || py[j] - y < dis[i][0])
						{
							con[i][0] = j;
							dis[i][0] = py[j] - y;
						}
					}
					else
					{
						if (con[i][2] == -1 || y - py[j] < dis[i][2])
						{
							con[i][2] = j;
							dis[i][2] = y - py[j];
						}
					}
				}
				else if (y == py[j])
				{
					if (x < px[j])
					{
						if (con[i][1] == -1 || px[j] - x < dis[i][1])
						{
							con[i][1] = j;
							dis[i][1] = px[j] - x;
						}
					}
					else
					{
						if (con[i][3] == -1 || x - px[j] < dis[i][3])
						{
							con[i][3] = j;
							dis[i][3] = x - px[j];
						}
					}
				}
			}
			for (j = 0; j < 4; j++)
			{
				if (con[i][j] != -1 && valid(x + dx[j], y + dy[j]) && map_[x + dx[j]][y + dy[j]] == brig[j % 2])
				{
					st += (1LLU << ((i << 2) + j));
				}
			}
		}
		ptt = 0;
		head = get_node();
		head->n = sp;
		head->len = 0;
		head->st = st;
		head->s = 0;
		head->left = head->right = NULL;
		queue_[0] = head;
		for (i = 0, j = 1; i < j; i++)
		{
			q = queue_[i];
			nod = q->n;
			len = q->len;
			st = q->st;
			s = q->s + 1;
			/*printf("%d: %d %d %I64d %d\n", i, nod, len, st, s);
			for(k=0; k<pnum; k++)
			{
			    for(x=0; x<4; x++)
			    {
			        printf("%d ", !!(st&(1<<((k<<2)+x))));
			    }
			    printf("\n");
			}*/
			if (nod == ep)
			{
				break;
			}
			for (k = 0; k < 4; k++)
			{
				if (con[nod][k] != -1)
				{
					if (st & (1LLU << ((nod << 2) + k)))
					{
						head = search(head, con[nod][k], len, st, s, &res);
						if (res)
						{
							queue_[j] = res;
							j++;
						}
						if (len == 0)
						{
							nst = st - (1LLU << ((nod << 2) + k)) - (1LLU << ((con[nod][k] << 2) + (k + 2) % 4));
							nlen = dis[nod][k];
							head = search(head, nod, nlen, nst, s, &res);
							if (res)
							{
								queue_[j] = res;
								j++;
							}
						}
					}
					else if (len == dis[nod][k])
					{
						if (intersect(nod, k, st) == 0)
						{
							nlen = 0;
							nst = st + (1LLU << ((nod << 2) + k)) + (1LLU << ((con[nod][k] << 2) + (k + 2) % 4));
							head = search(head, nod, nlen, nst, s, &res);
							if (res)
							{
								queue_[j] = res;
								j++;
							}
						}
					}
				}
			}
		}
		if (i == j)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", q->s);
		}
	}
	return 0;
}

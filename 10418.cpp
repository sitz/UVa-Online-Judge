#include <bits/stdc++.h>

using namespace std;

int diry[4] = {-1, 0, 1, 0}, dirx[4] = {0, 1, 0, -1};

int times, m, n, k, t, source = 0, dest, min_, size, h[101][101], r[101], dist[101][101], hp[101][101], c[204];

struct Point
{
	int x, y;
	Point(){};
	Point(int xx, int yy) : x(xx), y(yy){};
} red[50], green[50], gold, goal[101], heap[10000];

struct Edge
{
	int g, f, w, from, to;
	Edge *next, *back;
	Edge(int f, int t, int gg, int ww) : from(f), to(t), g(gg), f(0), w(ww), next(NULL), back(NULL){};
} *graph[204], *p[204];

void addEdge(int from, int to, int g, int w)
{
	Edge *p = new Edge(from, to, g, w), *q = new Edge(to, from, 0, -w), *s, *t;
	p->back = q;
	q->back = p;
	for (s = NULL, t = graph[from]; t; s = t, t = t->next)
		if (p->w < t->w)
		{
			break;
		}
	if (s == NULL)
	{
		p->next = graph[from];
		graph[from] = p;
	}
	else
	{
		p->next = s->next;
		s->next = p;
	}
	for (s = NULL, t = graph[to]; t; s = t, t = t->next)
		if (q->w < t->w)
		{
			break;
		}
	if (s == NULL)
	{
		q->next = graph[to];
		graph[to] = q;
	}
	else
	{
		q->next = s->next;
		s->next = q;
	}
}
void insert(Point p)
{
	int k = ++size;
	while (k != 1 && dist[heap[k / 2].x][heap[k / 2].y] > dist[p.x][p.y])
	{
		heap[k] = heap[k / 2];
		hp[heap[k].x][heap[k].y] = k;
		k /= 2;
	}
	heap[k] = p;
	hp[p.x][p.y] = k;
}
void vertify(int k)
{
	int m = k;
	if (2 * k <= size && dist[heap[2 * k].x][heap[2 * k].y] < dist[heap[k].x][heap[k].y])
	{
		m = 2 * k;
	}
	if (2 * k + 1 <= size && dist[heap[2 * k + 1].x][heap[2 * k + 1].y] < dist[heap[m].x][heap[m].y])
	{
		m = 2 * k + 1;
	}
	if (k != m)
	{
		Point temp = heap[k];
		heap[k] = heap[m];
		heap[m] = temp;
		hp[heap[k].x][heap[k].y] = k;
		hp[heap[m].x][heap[m].y] = m;
		vertify(m);
	}
}
Point deletemin_()
{
	Point ans = heap[1];
	heap[1] = heap[size--];
	vertify(1);
	return ans;
}
void adjust(int pos)
{
	Point temp = heap[pos];
	while (pos != 1 && dist[heap[pos / 2].x][heap[pos / 2].y] > dist[temp.x][temp.y])
	{
		heap[pos] = heap[pos / 2];
		hp[heap[pos].x][heap[pos].y] = pos;
		pos /= 2;
	}
	heap[pos] = temp;
	hp[heap[pos].x][heap[pos].y] = pos;
}
void BFS(int r, int c, int p)
{
	dist[r][c] = 0;
	size = 0;
	int d;
	Point u(r, c);
	insert(u);
	while (size != 0)
	{
		u = deletemin_();
		d = dist[u.x][u.y];
		for (int i = 0; i < 4; i++)
		{
			int tr = u.x + diry[i], tc = u.y + dirx[i];
			if (tr < 1 || tr > m || tc < 1 || tc > n)
			{
				continue;
			}
			if (p == d % 2)
			{
				if (h[tr][tc] >= h[u.x][u.y] && dist[tr][tc] > d)
				{
					if (dist[tr][tc] == 255)
					{
						dist[tr][tc] = d;
						Point v(tr, tc);
						insert(v);
					}
					else
					{
						dist[tr][tc] = d;
						adjust(hp[tr][tc]);
					}
				}
				else if (h[tr][tc] < h[u.x][u.y] && dist[tr][tc] > d + 1)
				{
					if (dist[tr][tc] == 255)
					{
						dist[tr][tc] = d + 1;
						Point v(tr, tc);
						insert(v);
					}
					else
					{
						dist[tr][tc] = d + 1;
						adjust(hp[tr][tc]);
					}
				}
			}
			else
			{
				if (h[tr][tc] <= h[u.x][u.y] && dist[tr][tc] > d)
				{
					if (dist[tr][tc] == 255)
					{
						dist[tr][tc] = d;
						Point v(tr, tc);
						insert(v);
					}
					else
					{
						dist[tr][tc] = d;
						adjust(hp[tr][tc]);
					}
				}
				else if (h[tr][tc] > h[u.x][u.y] && dist[tr][tc] > d + 1)
				{
					if (dist[tr][tc] == 255)
					{
						dist[tr][tc] = d + 1;
						Point v(tr, tc);
						insert(v);
					}
					else
					{
						dist[tr][tc] = d + 1;
						adjust(hp[tr][tc]);
					}
				}
			}
		}
	}
}
bool findpath()
{
	for (int i = 0; i < 204; i++)
	{
		c[i] = 999999, p[i] = NULL;
	}
	c[source] = 0;
	bool flag;
	do
	{
		flag = false;
		for (int i = 0; i <= dest; i++)
		{
			if (i != 0 && p[i] == NULL)
			{
				continue;
			}
			for (Edge *ptr = graph[i]; ptr; ptr = ptr->next)
			{
				if (ptr->w > min_)
				{
					break;
				}
				if (ptr->g - ptr->f > 0 && c[ptr->to] > max(c[i], ptr->w))
				{
					p[ptr->to] = ptr;
					c[ptr->to] = max(c[i], ptr->w);
					flag = true;
				}
			}
		}
	} while (flag);
	return p[dest] != NULL;
}
void update()
{
	Edge *ptr = p[dest];
	do
	{
		ptr->f += 1;
		ptr->back->f = -ptr->f;
		ptr = p[ptr->from];
	} while (ptr != NULL);
}
void freemem(Edge *&p)
{
	if (p)
	{
		freemem(p->next);
		delete p;
	}
	p = NULL;
}
int main()
{
	scanf("%d", &times);
	for (; times; times--)
	{
		scanf("%d %d %d %d", &m, &n, &k, &t);
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d", &red[i].x, &red[i].y);
		}
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d", &green[i].x, &green[i].y);
		}
		scanf("%d %d", &gold.x, &gold.y);
		for (int i = 0; i < t; i++)
		{
			scanf("%d %d %d", &goal[i].x, &goal[i].y, &r[i]);
		}
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &h[i][j]);
			}
		dest = 2 * k + t + 1;
		for (int i = 0; i < k; i++)
		{
			addEdge(source, i + 1, 1, 0);
			for (int x = 1; x <= m; x++)
				for (int y = 1; y <= n; y++)
				{
					dist[x][y] = 255;
				}
			BFS(red[i].x, red[i].y, 0);
			for (int j = 0; j < t; j++)
			{
				addEdge(i + 1, j + 1 + 2 * k, 1, dist[goal[j].x][goal[j].y]);
			}
		}
		for (int i = 0; i < k; i++)
		{
			addEdge(source, i + k + 1, 1, 0);
			for (int x = 1; x <= m; x++)
				for (int y = 1; y <= n; y++)
				{
					dist[x][y] = 255;
				}
			BFS(green[i].x, green[i].y, 1);
			for (int j = 0; j < t; j++)
			{
				addEdge(i + k + 1, j + 1 + 2 * k, 1, dist[goal[j].x][goal[j].y]);
			}
		}
		for (int j = 0; j < t; j++)
		{
			addEdge(j + 1 + 2 * k, dest, r[j], 0);
		}
		int s = 0;
		min_ = 0;
		while (true)
		{
			while (findpath() && s < 2 * k - min_)
			{
				update();
				s++;
			}
			if (s == 2 * k - min_)
			{
				break;
			}
			min_++;
		}
		printf("%d\n", min_);
		for (int i = 0; i < 204; i++)
		{
			freemem(graph[i]);
		}
	}
	return 0;
}

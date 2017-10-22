#include <bits/stdc++.h>

using namespace std;

#define MAXN 262144

typedef struct {int x,y;} pt_t;

int left_[MAXN], right_[MAXN], parent[MAXN], key[MAXN], cnt[MAXN], height[MAXN], score1[MAXN], score2[MAXN], line_s[MAXN], line_o[MAXN], total, root, n;
pt_t pt[MAXN];

int cmpx(const void *p, const void *q)
{
	pt_t *a = (pt_t *)p, *b = (pt_t *)q;
	return (a->x != b->x) ? (a->x - b->x) : (a->y - b->y);
}

int cmpi(const void *p, const void *q)
{
	return *(int *)p - *(int *)q;
}

void ptree(int x)
{
	if (x == 0)
	{
		printf(".");
	}
	else
	{
		printf("(");
		ptree(left_[x]);
		printf((cnt[x] == 1) ? " %d " : " %d:%d ", key[x], cnt[x]);
		ptree(right_[x]);
		printf(")");
	}
}

void print(int r)
{
	ptree(r);
	printf("\n");
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int rotl(int x)
{
	int a, b, c, y, t;
	y = right_[x];
	a = left_[x];
	b = left_[y];
	c = right_[y];
	right_[x] = b;
	parent[b] = x;
	t = parent[x];
	if (t == 0)
	{
		root = y;
	}
	else if (left_[t] == x)
	{
		left_[t] = y;
	}
	else
	{
		right_[t] = y;
	}
	parent[y] = t;
	left_[y] = x;
	parent[x] = y;
	t = cnt[x];
	cnt[x] = cnt[x] - cnt[y] + cnt[b];
	cnt[y] = t;
	height[x] = max(height[a], height[b]) + 1;
	height[y] = max(height[x], height[c]) + 1;
	return y;
}

int rotr(int y)
{
	int a, b, c, x, t;
	x = left_[y];
	a = left_[x];
	b = right_[x];
	c = right_[y];
	left_[y] = b;
	parent[b] = y;
	t = parent[y];
	if (t == 0)
	{
		root = x;
	}
	else if (left_[t] == y)
	{
		left_[t] = x;
	}
	else
	{
		right_[t] = x;
	}
	parent[x] = t;
	right_[x] = y;
	parent[y] = x;
	t = cnt[y];
	cnt[y] = cnt[y] - cnt[x] + cnt[b];
	cnt[x] = t;
	height[y] = max(height[b], height[c]) + 1;
	height[x] = max(height[a], height[y]) + 1;
	return x;
}

void insert(int k)
{
	int x;
	if (root == 0)
	{
		left_[0] = right_[0] = parent[0] = height[0] = key[0] = cnt[0] = 0;
		left_[1] = right_[1] = parent[1] = 0;
		cnt[1] = height[1] = total = root = 1;
		key[1] = k;
		return;
	}
	for (total++, x = root;;)
	{
		if (k < key[x])
		{
			if (left_[x] == 0)
			{
				left_[x] = total;
				break;
			}
			x = left_[x];
		}
		else if (k > key[x])
		{
			if (right_[x] == 0)
			{
				right_[x] = total;
				break;
			}
			x = right_[x];
		}
		else
		{
			for (; x != 0; x = parent[x])
			{
				cnt[x]++;
			}
			return;
		}
	}
	parent[total] = x;
	x = total;
	key[x] = k;
	left_[x] = 0;
	right_[x] = 0;
	cnt[x] = 1;
	height[x] = 1;
	for (x = parent[x]; x != 0; x = parent[x])
	{
		cnt[x]++;
		height[x] = max(height[left_[x]], height[right_[x]]) + 1;
		if (height[left_[x]] < (height[right_[x]] - 1))
		{
			x = rotl(x);
		}
		else if (height[right_[x]] < (height[left_[x]] - 1))
		{
			x = rotr(x);
		}
	}
}

int find_less(int k)
{
	int r, x;
	for (r = 0, x = root; x != 0;)
	{
		if (k < key[x])
		{
			x = left_[x];
		}
		else if (k > key[x])
		{
			r += cnt[x] - cnt[right_[x]];
			x = right_[x];
		}
		else
		{
			r += cnt[left_[x]];
			break;
		}
	}
	return r;
}

int find_greater(int k)
{
	int r, x;
	for (r = 0, x = root; x != 0;)
	{
		if (k < key[x])
		{
			r += cnt[x] - cnt[left_[x]];
			x = left_[x];
		}
		else if (k > key[x])
		{
			x = right_[x];
		}
		else
		{
			r += cnt[right_[x]];
			break;
		}
	}
	return r;
}

int main()
{
	int i, j, k, s;
	while (scanf("%d", &n) == 1 && n > 0)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &pt[i].x, &pt[i].y);
		}
		qsort(pt, n, sizeof(pt[0]), &cmpx);
		memset(score1, 0, n * sizeof(int));
		memset(score2, 0, n * sizeof(int));
		for (root = 0, i = 0; i < n; i = j)
		{
			for (j = i; j < n && pt[j].x == pt[i].x; j++)
			{
				score1[j] += find_less(pt[j].y);
				score2[j] += find_greater(pt[j].y);
			}
			for (j = i; pt[j].x == pt[i].x; j++)
			{
				insert(pt[j].y);
			}
		}
		for (root = 0, i = n - 1; i >= 0; i = j)
		{
			for (j = i; j >= 0 && pt[j].x == pt[i].x; j--)
			{
				score2[j] += find_less(pt[j].y);
				score1[j] += find_greater(pt[j].y);
			}
			for (j = i; j >= 0 && pt[j].x == pt[i].x; j--)
			{
				insert(pt[j].y);
			}
		}
		for (k = 0, i = 0; i < n; i = j, k++)
		{
			line_s[k] = score1[i];
			line_o[k] = score2[i];
			for (j = i; j < n && pt[j].x == pt[i].x; j++)
			{
				if (score1[j] < line_s[k])
				{
					line_s[k] = score1[j];
				}
				if (score2[j] > line_o[k])
				{
					line_o[k] = score2[j];
				}
			}
		}
		for (s = line_s[0], i = 0; i < k; i++)
		{
			if (line_s[i] > s)
			{
				s = line_s[i];
			}
		}
		for (j = 0, i = 0; i < k; i++)
		{
			if (line_s[i] == s)
			{
				key[j++] = line_o[i];
			}
		}
		qsort(key, j, sizeof(key[0]), &cmpi);
		printf("Stan: %d; Ollie:", s);
		for (i = 0; i < j; i++)
		{
			if (i == 0 || key[i - 1] != key[i])
			{
				printf(" %d", key[i]);
			}
		}
		printf(";\n");
	}
	return 0;
}

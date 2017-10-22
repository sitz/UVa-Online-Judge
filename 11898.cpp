#include <bits/stdc++.h>

using namespace std;

struct node
{
	int v, id;
} a[200100];
struct seg
{
	int l, r, ans, m, id;
} q[15010];
int N, M, pre[15010], net[15010], out[15010];
bool cmp(node a, node b)
{
	if (a.v == b.v)
	{
		return a.id < b.id;
	}
	return a.v < b.v;
}
bool cmp2(seg a, seg b)
{
	if (a.l == b.l)
	{
		return a.r < b.r;
	}
	return a.l < b.l;
}
int getint()
{
	int ret = 0;
	char tmp;
	while (!isdigit(tmp = getchar()))
		;
	do
	{
		ret = (ret << 3) + (ret << 1) + tmp - '0';
	} while (isdigit(tmp = getchar()));
	return ret;
}
int main()
{
	int T, i, j, head, p;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			//scanf("%d",&a[i].v);
			a[i].v = getint();
			a[i].id = i + 1;
		}
		sort(a, a + N, cmp);
		scanf("%d", &M);
		for (i = 0; i < M; i++)
		{
			//scanf("%d %d",&q[i].l,&q[i].r);
			q[i].l = getint();
			q[i].r = getint();
			q[i].ans = 999999999;
			q[i].m = -999999999;
			pre[i] = max(0, i - 1);
			net[i] = i + 1;
			q[i].id = i;
		}
		head = 0;
		sort(q, q + M, cmp2);
		for (i = 0; i < N; i++)
		{
			p = head;
			while (q[p].l <= a[i].id && p < M)
			{
				if (q[p].r < a[i].id)
				{
					p = net[p];
					continue;
				}
				if (q[p].r - q[p].l + 1 > 10000)
				{
					q[p].ans = 0;
					if (p == head)
					{
						head = net[p];
					}
					else
					{
						net[pre[p]] = net[p];
						pre[net[p]] = pre[p];
					}
				}
				else
				{
					if (q[p].m == -999999999)
					{
						q[p].m = a[i].v;
					}
					else if (q[p].m == a[i].v)
					{
						q[p].ans = 0;
						if (p == head)
						{
							head = net[p];
						}
						else
						{
							net[pre[p]] = net[p];
							pre[net[p]] = pre[p];
						}
					}
					else if (q[p].m < a[i].v)
					{
						q[p].ans = min(q[p].ans, a[i].v - q[p].m);
						q[p].m = a[i].v;
					}
				}
				p = net[p];
			}
		}
		for (i = 0; i < M; i++)
		{
			out[q[i].id] = q[i].ans;
		}
		for (i = 0; i < M; i++)
		{
			printf("%d\n", out[i]);
		}
	}
	return 0;
}

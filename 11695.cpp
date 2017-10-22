#include <bits/stdc++.h>

using namespace std;

int n, m, ii, ret, x[3000], y[3000], dep[3000], pre[3000], c[3000], cc[3000];
vector<int> v[3000];

void dfs(int kk, int de)
{
	int i;
	if (dep[kk] >= de || c[kk] == 1)
	{
		return;
	}
	dep[kk] = de;
	c[kk] = 1;
	for (i = 0; i < v[kk].size(); i++)
		if ((kk == x[ii] && v[kk][i] == y[ii]) || (kk == y[ii] && v[kk][i] == x[ii]))
			;
		else if (c[v[kk][i]] == 0)
		{
			pre[v[kk][i]] = kk;
			dfs(v[kk][i], de + 1);
		}
}

int max(int aa, int bb)
{
	if (aa < bb)
	{
		return aa;
	}
	return bb;
}

int solve(int kk)
{
	int i, j, k, l;
	for (i = 1; i <= n; i++)
	{
		c[i] = 0;
		dep[i] = 0;
	}
	dfs(kk, 1);
	k = 1;
	for (i = 1; i <= n; i++)
		if (dep[i] > dep[k])
		{
			k = i;
		}
	//printf("sol  %d %d\n",k,dep[k]);
	for (i = 1; i <= n; i++)
	{
		c[i] = 0;
		dep[i] = 0;
	}
	dfs(k, 1);
	k = 1;
	for (i = 1; i <= n; i++)
		if (dep[i] > dep[k])
		{
			k = i;
		}
	//printf("sol  %d %d\n",k,dep[k]);
	//for(i=1;i<=n;i++) printf("pre %d %d\n",i,pre[i]);
	l = k;
	while (dep[l] > dep[k] - dep[l] + 1)
	{
		//if(l != 0)printf("test %d %d\n",l,dep[l]);
		l = pre[l];
	}
	//printf("ll = %d %d\n",l,dep[l]);
	for (i = 1; i <= n; i++)
		if (c[i] != 0)
		{
			cc[i] = c[i];
		}
	ret += max(dep[l], dep[k] - dep[l]);
	return l;
}

int add1, add2;

void dfss(int kk, int de)
{
	int i;
	if (dep[kk] >= de || c[kk] == 1)
	{
		return;
	}
	dep[kk] = de;
	c[kk] = 1;
	for (i = 0; i < v[kk].size(); i++)
		if ((kk == x[ii] && v[kk][i] == y[ii]) || (kk == y[ii] && v[kk][i] == x[ii]))
			;
		else if (c[v[kk][i]] == 0)
		{
			pre[v[kk][i]] = kk;
			dfss(v[kk][i], de + 1);
		}
	if (kk == add1)
	{
		if (c[add2] == 0)
		{
			pre[add2] = kk;
			dfss(add2, de + 1);
		}
	}
	if (kk == add2)
	{
		if (c[add1] == 0)
		{
			pre[add1] = kk;
			dfss(add1, de + 1);
		}
	}
}

int maxtop()
{
	int i, j, k, l;
	for (i = 1; i <= n; i++)
	{
		c[i] = 0;
		dep[i] = 0;
	}
	dfss(1, 1);
	k = 1;
	for (i = 1; i <= n; i++)
		if (dep[i] > dep[k])
		{
			k = i;//for(i=1;i<=n;i++) printf("  %d %d\n",i,dep[i]);
		}
	//printf("sol  %d %d\n",k,dep[k]);
	for (i = 1; i <= n; i++)
	{
		c[i] = 0;
		dep[i] = 0;
	}
	dfss(k, 1);
	k = 1;
	for (i = 1; i <= n; i++)
		if (dep[i] > dep[k])
		{
			k = i;
		}
	//for(i=1;i<=n;i++) printf("  %d %d\n",i,dep[i]);
	return dep[k];
}

int main()
{
	int i, j, k, l, ans, a1, a2, a3, a[7];
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			v[i].clear();
		}
		for (i = 1; i < n; i++)
		{
			scanf("%d %d", &x[i], &y[i]);
			v[x[i]].push_back(y[i]);
			v[y[i]].push_back(x[i]);
		}
		ans = 1000000000;
		for (ii = 1; ii < n; ii++)
		{
			for (i = 1; i <= n; i++)
			{
				cc[i] = 0;
			}
			k = 0;
			ret = 0;
			for (i = 1; i <= n; i++)
				if (cc[i] == 0)
				{
					a[k++] = solve(i);
				}
			add1 = a[0];
			add2 = a[1];
			ret = maxtop();
			//printf("ii = %d  %d %d\n",ii,x[ii],y[ii]);
			//printf("%d %d %d %d   %d %d\n\n",ret,k,a[0],a[1],add1,add2);
			if (ret < ans)
			{
				ans = ret;
				a1 = ii;
				a2 = a[0];
				a3 = a[1];
			}
		}
		printf("%d\n", ans - 1);
		printf("%d %d\n", x[a1], y[a1]);
		printf("%d %d\n", a2, a3);
	}
	return 0;
}

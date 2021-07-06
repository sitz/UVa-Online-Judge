#include <bits/stdc++.h>

using namespace std;

struct node {string s; int tot;} q[1000007], qq[1000007];

int n, a[10], Find;
string sta, end_;
map<string, int> hash_, hash_1;

string tran(string a)
{
	return a;
}

void bfs1()
{
	int front = 0, rear = 1;
	qq[front].s = end_;
	qq[front].tot = 0;
	hash_1[tran(end_)] = 0;
	while (front < rear && qq[front].tot < 2)
	{
		string t = qq[front].s;
		for (int i = 0; i < t.size(); i++)
		{
			for (int j = i; j < t.size(); j++)
			{
				string b = "", c = "", d = "";
				for (int r = i; r <= j; r++)
				{
					b += t[r];
				}
				for (int r = 0; r < i; r++)
				{
					c += t[r];
				}
				for (int r = j + 1; r < t.size(); r++)
				{
					c += t[r];
				}
				for (int ss = 0; ss <= c.size(); ss++)
				{
					d = "";
					for (int r = 0; r < ss; r++)
					{
						d += c[r];
					}
					d += b;
					for (int r = ss; r < c.size(); r++)
					{
						d += c[r];
					}
					if (!hash_1[tran(d)] && d != end_)
					{
						qq[rear].s = d;
						qq[rear].tot = qq[front].tot + 1;
						hash_1[tran(d)] = qq[rear].tot;
						if (d == sta)
						{
							Find = qq[rear].tot;
							return;
						}
						rear++;
					}
				}
			}
		}
		front++;
	}
}
void bfs()
{
	int front = 0, rear = 1;
	q[front].s = sta;
	q[front].tot = 0;
	hash_[tran(sta)] = 0;
	while (front < rear)
	{
		string t = q[front].s;
		for (int i = 0; i < t.size(); i++)
		{
			for (int j = i; j < t.size(); j++)
			{
				string b = "", c = "", d = "";
				for (int r = i; r <= j; r++)
				{
					b += t[r];
				}
				for (int r = 0; r < i; r++)
				{
					c += t[r];
				}
				for (int r = j + 1; r < t.size(); r++)
				{
					c += t[r];
				}
				for (int ss = 0; ss <= c.size(); ss++)
				{
					d = "";
					for (int r = 0; r < ss; r++)
					{
						d += c[r];
					}
					d += b;
					for (int r = ss; r < c.size(); r++)
					{
						d += c[r];
					}
					if (!hash_[tran(d)] && d != sta)
					{
						q[rear].s = d;
						q[rear].tot = q[front].tot + 1;
						hash_[tran(d)] = q[rear].tot;
						if (d == end_)
						{
							Find = q[rear].tot;
							return;
						}
						if (hash_1[tran(d)])
						{
							Find = min(Find, q[rear].tot + hash_1[tran(d)]);//之所以这样写是因为逆向时为处理搜到可行解的情况
							return;
						}
						rear++;
					}
				}
			}
		}
		front++;
	}
}

int main()
{
	int T = 1;
	while (scanf("%d", &n) != EOF && n)
	{
		sta = "";
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sta += (a[i] + '0');
		}
		end_ = "";
		for (int i = 1; i <= n; i++)
		{
			end_ += (i + '0');
		}
		if (sta == end_)
		{
			Find = 0;
		}
		else
		{
			hash_.clear();
			hash_1.clear();
			Find = 100;
			bfs1();
			bfs();
		}
		printf("Case %d: %d\n", T++, Find);
	}
	return 0;
}

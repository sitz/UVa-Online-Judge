#include <bits/stdc++.h>

using namespace std;

struct Pt
{
	long long x, y;
};
Pt arr[110], ans[110];

bool visit[111][111][111];
double dp[111][111][111];
int P, K, cnt;
stack<Pt> S;

double area_poly(vector<Pt> lst)
{
	double area = 0;
	for (int i = 1; i + 1 < lst.size(); i++)
	{
		area += (lst[i].y - lst[0].y) * (lst[i + 1].x - lst[i].x) - (lst[i].x - lst[0].x) * (lst[i + 1].y - lst[i].y);
	}
	return fabs(area / 2.0f);
}

long long dist(Pt P, Pt Q)
{
	return hypot(P.x - Q.x, P.y - Q.y);
}

int orient(Pt P, Pt Q, Pt R)
{
	long long ret = (Q.y - P.y) * (R.x - Q.x) - (Q.x - P.x) * (R.y - Q.y);
	if (ret < 0)
	{
		return 2;
	}
	if (ret > 0)
	{
		return 1;
	}
	return ret;
}

bool cmp(Pt X, Pt Y)
{
	int ret = orient(arr[0], X, Y);
	if (ret == 0)
	{
		return dist(arr[0], X) < dist(arr[0], Y);
	}
	return ret == 2;
}

Pt nxt_to_top()
{
	Pt P = S.top();
	S.pop();
	Pt res = S.top();
	S.push(P);
	return res;
}

double solve(int idx, int first, int prev, int how)
{
	if (idx < 0 || how == 0)
	{
		return 0.0f;
	}
	if (visit[idx][prev][how])
	{
		return dp[idx][prev][how];
	}
	visit[idx][prev][how] = true;
	double &ret = dp[idx][prev][how];
	ret = 0.0f;
	vector<Pt> V{ans[first], ans[prev], ans[idx]};
	ret = max(ret, area_poly(V) + solve(idx - 1, first, idx, how - 1));
	ret = max(ret, solve(idx - 1, first, prev, how));
	return ret;
}

double convex_hull(int N)
{
	int ymin = arr[0].y, idx = 0;
	for (int i = 1; i < N; i++)
	{
		if (arr[i].y < ymin || (arr[i].y == ymin && arr[i].x < arr[idx].x))
		{
			ymin = arr[i].y;
			idx = i;
		}
	}
	swap(arr[0], arr[idx]);
	sort(&arr[1], &arr[N], cmp);
	S.push(arr[0]);
	for (int i = 1; i < N; i++)
	{
		while (S.size() > 1 && orient(nxt_to_top(), S.top(), arr[i]) != 2)
		{
			S.pop();
		}
		S.push(arr[i]);
	}
	cnt = 0;
	while (!S.empty())
	{
		ans[cnt++] = S.top();
		S.pop();
	}
	if (cnt <= K)
	{
		vector<Pt> V;
		for (int i = cnt - 1; i >= 0; i--)
		{
			V.push_back(ans[i]);
		}
		return area_poly(V);
	}
	double ans = 0.0f;
	for (int i = cnt - 1; i >= 0; i--)
	{
		memset(visit, false, sizeof(visit));
		ans = max(ans, solve(i - 1, i, i, K - 1));
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d%d", &P,&K);
		for (int i = 0; i < P; i++)
		{
			scanf("%lld%lld", &arr[i].x,&arr[i].y);
		}
		printf("Case %d: %.3lf\n", t,convex_hull(P));
	}
	return 0;
}

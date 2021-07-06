#include <bits/stdc++.h>

using namespace std;

struct Home
{
	int h, r;
	Home(int a = 0, int b = 0) : h(a), r(b) {}
};
vector<Home> home;

int A, B, C, E, F, G, H, I, J, NP, NH;
vector<int> pillar;

bool cmp1(int a, int b)
{
	return a < b;
}

bool cmp2(Home h1, Home h2)
{
	return h1.h < h2.h;
}

struct cmp
{
	bool operator()(Home h1, Home h2)
	{
		return h1.r > h2.r;
	}
};

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		home.clear();
		pillar.clear();

		scanf("%d%d%d%d%d%d%d%d%d%d%d", &NP, &NH, &A, &B, &C, &E, &F, &G, &H, &I, &J);
		pillar.push_back(C % 10000 + 1);
		if (NP >= 2)
		{
			pillar.push_back((A * pillar[0] + C) % 10000 + 1);
		}
		for (int i = 2; i < NP; i++)
		{
			pillar.push_back((A * pillar[i - 1] + B * pillar[i - 2] + C) % 10000 + 1);
		}
		home.push_back(Home(G % 10000 + 1, J % 100000 + 1));
		for (int i = 1; i < NH; i++)
		{
			home.push_back(Home((E * home[i - 1].h + F * home[i - 1].r + G) % 10000 + 1, (H * home[i - 1].r + I * home[i - 1].h + J) % 100000 + 1));
		}
		sort(pillar.begin(), pillar.end(), cmp1);
		sort(home.begin(), home.end(), cmp2);

		printf("Case %d: ", i);

		priority_queue<Home, vector<Home>, cmp> q;
		int h_idx = 0, p_idx = 0, ans = 0;
		while (p_idx < NP)
		{
			while (h_idx < NH && home[h_idx].h <= pillar[p_idx])
			{
				if (home[h_idx].r <= NP - p_idx)
				{
					q.push(home[h_idx]);
				}
				h_idx++;
			}
			if (!q.empty())
			{
				Home home_t = q.top();
				q.pop();
				home_t.r--;
				if (home_t.r <= 0)
				{
					ans++;
				}
				else
				{
					q.push(home_t);
				}
			}
			p_idx++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

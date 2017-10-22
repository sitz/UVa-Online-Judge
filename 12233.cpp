#include <bits/stdc++.h>

using namespace std;

const int INF = 100000008;
const string name[4] = {"Y", "H", "L", "M"};
int sy_jing, xx_su, sy_su, yurun_jing, yurun_shen, shuerguo_shen;
int maxjing[4], maxshen[4], su[4], d1x[4], d2x[4], d1s[4], d2s[4], wad[4];
int ssd[4], ssq[4], ssp[4], q1[4], q2[4], jing[4], qi[4], shen[4];
int xxt, syt;
int maxt, who, pos, sudo;
map<long long, int> MAP[13];
vector<string> ans;

int dfs1(int t, int j, int q, int s)
{
	if (j <= 0)
	{
		return -INF;
	}
	if (t > maxt)
	{
		return 0;
	}
	j = min(j, maxjing[who]), q = min(q, 100), s = min(s, maxshen[who]);
	long long h = (long long)j * 1000000 + q * 1000 + s;
	if (MAP[t].find(h) != MAP[t].end())
	{
		return MAP[t][h];
	}
	int dj = 0, dq = 0;
	if (t % xxt == 0)
	{
		int cnt = t / xxt;
		if (cnt % 4 == pos + 1)
		{
			dj -= d1x[who];
			dq += q2[who];
		}
		else if (cnt % 4 == 0 && cnt > 0)
		{
			dj -= d2x[who];
		}
	}
	if (t % syt == 0)
	{
		int cnt = t / syt;
		if (cnt % 4 == pos + 1)
		{
			dj -= d1s[who];
			dq += q2[who];
		}
		else if (cnt % 4 == 0 && cnt > 0)
		{
			dj -= d2s[who];
		}
	}
	int ans = -INF;
	if (t == maxt)
	{
		ans = 0;
		if (t % sudo != 0)
		{
			return 0;//return j+dj>0 ? 0 : -INF;
		}
		if (j - wad[who] > 0)
		{
			ans = max(ans, wad[who]);
		}
		if (q - ssq[who] >= 0)
		{
			int dj2 = ssp[who] == 1 ? -ssd[who] : 0;
			if (j + dj2 > 0)
			{
				ans = max(ans, ssd[who]);
			}
		}
		return MAP[t][h] = ans;
	}
	else
	{
		if (t % sudo != 0)
		{
			return MAP[t][h] = dfs1(t + 1, j + dj, q + dq, s);
		}
		ans = max(ans, dfs1(t + 1, j + dj, q + dq + q1[who], s));
		ans = max(ans, dfs1(t + 1, j + dj - wad[who], q + dq + q1[who], s) + wad[who]);
		if (s >= yurun_shen && j < maxjing[who])
		{
			ans = max(ans, dfs1(t + 1, min(j + yurun_jing, maxjing[who]) + dj, q + dq, s - yurun_shen));
		}
		if (s < maxshen[who])
		{
			ans = max(ans, dfs1(t + 1, j + dj, q + dq, s + shuerguo_shen));
		}
		if (q - ssq[who] >= 0)
		{
			int dj2 = ssp[who] == 1 ? -ssd[who] : 0;
			ans = max(ans, dfs1(t + 1, j + dj + dj2, q + dq - ssq[who], s) + ssd[who]);
		}
		return MAP[t][h] = ans;
	}
}
bool ok(int max_time)
{
	//printf("---------round : %d--------------\n",max_time);
	int dmg[4][4];
	ans.clear();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			maxt = max_time, who = i, pos = j, sudo = 5 - su[i];
			for (int k = 0; k < 13; k++)
			{
				MAP[k].clear();
			}
			dmg[i][j] = dfs1(1, jing[i], qi[i], shen[i]);
		}
	}
	/*for(int i=0;i<4;i++){
		for(int j=0;j<3;j++)
			printf("%d ",dmg[i][j]);
		printf("\n");
	}*/
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				continue;
			}
			for (int k = 0; k < 4; k++)
			{
				if (i == k || j == k)
				{
					continue;
				}
				//printf("(%d,%d,%d) = %d\n",i,j,k,dmg[i][0]+dmg[j][1]+dmg[k][2]);
				if (dmg[i][0] + dmg[j][1] + dmg[k][2] >= sy_jing)
				{
					ans.push_back(name[i] + name[j] + name[k]);
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	return ans.size() > 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	for (int t = 0; scanf(" %d", &sy_jing) == 1 && sy_jing; t++)
	{
		scanf(" %d %d %d %d %d", &xx_su, &sy_su, &yurun_jing, &yurun_shen, &shuerguo_shen);
		for (int i = 0; i < 4; i++)
		{
			scanf(" %d %d %d %d %d %d %d", &maxjing[i], &maxshen[i], &su[i], &d1x[i], &d2x[i], &d1s[i], &d2s[i]);
			scanf(" %d %d %d %d %d %d", &wad[i], &ssd[i], &ssq[i], &ssp[i], &q1[i], &q2[i]);
			scanf(" %d %d %d", &jing[i], &qi[i], &shen[i]);
		}
		xxt = 5 - xx_su, syt = 5 - sy_su;
		printf("Case %d: ", t + 1);
		int re = 0;
		for (int round = 1; round <= 12 && re == 0; round++)
			if (ok(round))
			{
				printf("%d", round);
				for (int i = 0; i < ans.size(); i++)
				{
					cout << " " << ans[i];
				}
				printf("\n");
				re = 1;
			}
		if (re == 0)
		{
			printf("-1\n");
		}
		printf("\n");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define MAX 53

typedef long long ll;

ll a, m, r, s, po[MAX], tmp[MAX], p, q, gl;
bool sol;

struct s1
{
	ll cnt;
	char ch;
};

void btrack(ll rem, ll now, ll lim)
{
	ll i, j;
	//if (gl==2) printf("%lld %lld %lld\n",now,rem,po[rem]);
	if (rem == -1)
	{
		if (now >= r && now + (q - p) * po[gl] <= s)
		{
			sol = 1;
		}
		return;
	}
	if (now < r)
	{
		if ((r - now) % (po[rem] * a) == 0)
		{
			i = j = (r - now) / (po[rem] * a);
		}
		else
		{
			i = j = (r - now) / (po[rem] * a) + 1;
		}
	}
	else
	{
		i = j = 0;
	}
	for (; i >= j - 1 && i >= 0; i--)
	{
		btrack(rem - 1, now + i * po[rem] * a, lim);
		if (sol)
		{
			tmp[rem] = i;
			break;
		}
	}
}

vector<s1> gen()
{
	ll i;
	vector<s1> ret;
	s1 tmp1;
	for (i = gl; i >= 0; i--)
	{
		tmp1.cnt = tmp[i];
		tmp1.ch = 'A';
		ret.push_back(tmp1);
		if (i)
		{
			tmp1.cnt = 1;
			tmp1.ch = 'M';
			ret.push_back(tmp1);
		}
	}
	for (i = 0; i < ret.size(); i++)
	{
		if (ret[i].cnt == 0)
		{
			ret.erase(ret.begin() + i);
			i--;
		}
	}
	for (i = 0; i < (int)ret.size() - 1; i++)
	{
		while (i < (int)ret.size() - 1 && ret[i + 1].ch == ret[i].ch)
		{
			ret[i].cnt += ret[i + 1].cnt;
			ret.erase(ret.begin() + i + 1);
		}
	}
	return ret;
}

bool lesser(vector<s1> &a, vector<s1> &b)
{
	ll sum1, sum2, i;
	sum1 = sum2 = 0;
	for (i = 0; i < a.size(); i++)
	{
		sum1 += a[i].cnt;
	}
	for (i = 0; i < b.size(); i++)
	{
		sum2 += b[i].cnt;
	}
	if (sum1 != sum2)
	{
		return sum1 < sum2;
	}
	for (i = 0; i < a.size() && i < b.size(); i++)
	{
		if (a[i].cnt == b[i].cnt && a[i].ch == b[i].ch)
		{
			continue;
		}
		if (a[i].cnt == b[i].cnt)
		{
			return a[i].ch < b[i].ch;
		}
		else if (a[i].cnt < b[i].cnt)
		{
			if (a[i].ch == b[i].ch)
			{
				return a[i].ch == 'M';
			}
			return a[i].ch == 'A';
		}
		else
		{
			if (a[i].ch == b[i].ch)
			{
				return a[i].ch == 'A';
			}
			return a[i].ch == 'A';
		}
	}
}

int main()
{
	//freopen("text1.txt","r",stdin);
	//freopen("my.txt","w",stdout);
	ll i, init, cnt, j, lim, k, cas = 0;
	bool d;
	while (scanf("%lld%lld%lld%lld%lld%lld", &a, &m, &p, &q, &r, &s) == 6 && a)
	{
		vector<s1> cand, ans;
		po[0] = 1;
		for (i = 1; i <= 30; i++)
		{
			po[i] = po[i - 1] * m;
		}
		d = 0;
		for (i = 0; i <= 30; i++)
		{
			//if (m==1&&i) break;
			gl = i;
			if (po[i] > s / p)
			{
				break;
			}
			init = po[i] * p;
			if (q > p && po[i] > (s - init) / (q - p))
			{
				break;
			}
			lim = s - po[i] * (q - p);
			//printf("here %lld %lld %lld\n",i,init,lim);
			sol = 0;
			btrack(i, init, lim);
			if (sol)
			{
				cand = gen();
				if (!d)
				{
					ans = cand;
					d = 1;
				}
				else if (lesser(cand, ans))
				{
					ans = cand;
				}
			}
		}
		if (!d)
		{
			printf("Case %lld: impossible\n", ++cas);
		}
		else if (ans.size() == 0)
		{
			printf("Case %lld: empty\n", ++cas);
		}
		else
		{
			printf("Case %lld:", ++cas);
			for (i = 0; i < ans.size(); i++)
			{
				printf(" %lld%c", ans[i].cnt, ans[i].ch);
			}
			printf("\n");
		}
	}
	return 0;
}

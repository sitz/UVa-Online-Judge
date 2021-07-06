#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define REP(i, a) for (i = 0; i < (a); i++)
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SZ(a) ((int)(a).size())
#define CL(a) ((a).clear())
#define SORT(x) sort(ALL(x))
#define mp make_pair
#define pb push_back
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int n, val[111], len[111], vst[(1 << 22)][22][2], True = 0, vs[111][25];

int main()
{
	int i, j, u, v, ks = 0;
	char s[100], str[100];
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
			break;
		ks++;
		True++;
		REP(i, n)
		{
			scanf("%s %s", s, str);
			len[i] = strlen(str);
			val[i] = 0;
			REP(j, len[i])
			{
				vs[i][j] = str[j] - '0';
				val[i] |= (vs[i][j]);
				val[i] <<= 1;
			}
			val[i] >>= 1;
		}
		queue<int> Q, L, T;
		REP(i, n)
		{
			Q.push(val[i]);
			L.push(len[i]);
			T.push(0);
			if (vst[val[i]][len[i]][0] == True)
			{
				break;
			}
			vst[val[i]][len[i]][0] = True;
		}
		if (i != n)
		{
			printf("Case #%d: Ambiguous.\n", ks);
			continue;
		}
		int ul, vl, nl, nu, mn, mx, j, ut, id, tu;
		int uss[33], *vss;
		while (!Q.empty())
		{
			u = Q.front();
			ul = L.front();
			ut = T.front();
			if (u == 0 && ul == 0)
				break;
			SET(uss, 0);
			id = ul - 1;
			tu = u;
			while (tu)
			{
				uss[id--] = tu % 2;
				tu /= 2;
			}
			Q.pop();
			L.pop();
			T.pop();
			REP(i, n)
			{
				v = val[i];
				vl = len[i];
				vss = &vs[i][0];
				if (u == v && ul == vl)
				{
					if (ut)
					{
						if (vst[0][0][1] == True)
						{
							continue;
						}
						vst[0][0][1] = True;
						Q.push(0);
						L.push(0);
						T.push(1);
					}
					continue;
				}
				if (ul > vl)
				{
					nl = ul - vl;
					REP(j, vl)
					{
						if (vss[j] != uss[j])
							break;
					}
					if (j != vl)
						continue;
					nu = 0;
					for (; j < ul; j++)
					{
						nu |= (uss[j]);
						nu <<= 1;
					}
					nu >>= 1;
				}
				else
				{
					nl = vl - ul;
					REP(j, ul)
					{
						if (vss[j] != uss[j])
							break;
					}
					if (j != ul)
						continue;
					nu = 0;
					for (; j < vl; j++)
					{
						nu |= (vss[j]);
						nu <<= 1;
					}
					nu >>= 1;
				}
				if (vst[nu][nl][1] == True)
					continue;
				vst[nu][nl][1] = True;
				Q.push(nu);
				L.push(nl);
				T.push(1);
			}
		}
		if (Q.empty())
		{
			printf("Case #%d: Not ambiguous.\n", ks);
			continue;
		}
		else
			printf("Case #%d: Ambiguous.\n", ks);
	}
	return 0;
}

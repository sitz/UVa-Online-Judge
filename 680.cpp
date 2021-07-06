#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define RFOR(i, a, b) for (int(i) = (a), _b(b); (i) >= _b; --(i))
#define FOREACH(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

int K, N, L[15], PF[15], acc[15], P;

inline int dist(int fr_l, int fr_i, int to_l, int to_i)
{
	if (fr_l < to_l)
	{
		int ret = 0;
		if (to_l - fr_l > 1)
		{
			ret += acc[to_l - 1] - acc[fr_l];
		}
		return ret + L[fr_l] - fr_i + to_i;
	}
	else if (fr_l == to_l)
	{
		return abs(fr_i - to_i);
	}
	else//fr_l > to_l
	{
		int ret = 0;
		if (fr_l - to_l > 1)
		{
			ret += acc[fr_l - 1] - acc[to_l];
		}
		return ret + L[to_l] - to_i + fr_i;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	FOREQ(t, 1, T)
	{
		scanf("%d%d", &K, &N);
		FOR(i, 0, K)
		{
			scanf("%d", &L[i]);
		}
		acc[0] = L[0];
		FOR(i, 1, K)
		{
			acc[i] = acc[i - 1] + L[i];
		}

		// FOR(i,0,K)
		// {
		// 	fprintf(stderr, "acc[%d]=%d ", i,acc[i]);
		// }
		// fprintf(stderr, "\n");

		FOR(i, 0, K)
		{
			scanf("%d", &PF[i]);
		}
		scanf("%d", &P);
		// fprintf(stderr, "P=%d\n", P);

		if (P == 1)
		{
			printf("0\n");
			continue;
		}

		int tb = 0, posl = 0;
		int last[K];
		FOR(i, 0, K)
		{
			last[i] = PF[i] - 1;
		}
		FOR(i, 0, P - 1)
		{
			int nxtl = (posl + 1) % K;
			if (posl == nxtl)
			{
				int curr = last[posl];
				int nxt = (last[posl] + 1) % L[posl];
				tb += dist(posl, curr, nxtl, nxt);
			}
			else
			{
				tb += dist(posl, last[posl], nxtl, last[nxtl]);
			}
			// fprintf(stderr, "(%d,%d) -> (%d,%d); tb=%d\n", posl+1,last[posl]+1,nxtl+1,last[nxtl]+1, tb);
			last[posl] = (last[posl] + 1) % L[posl];
			posl = (posl + 1) % K;
		}
		printf("%d\n", tb);
	}
	int _;
	scanf("%d", &_);//-1
	return 0;
}

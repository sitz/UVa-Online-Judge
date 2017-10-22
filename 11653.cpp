#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define MP make_pair
#define PB push_back
#define SZ(v) (v).size()
#define ALL(v) (v).begin(), (v).end()
#define FOREACH(it, v) \
	for (__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORE(i, a, b) for (int i = a; i <= b; i++)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

#define MAX 1000010
ll p[4];
// ll vals[MAX];
ll QQ[100010];

struct interv
{
	int a;
	char beg;
	char val;
	int last;
};

interv pts[200010];
int npts;

bool compar(const interv &a,
						const interv &b)
{
	return a.a < b.a;
}

int main()
{
	int tst;
	scanf("%d", &tst);
	FORE(f, 1, tst)
	{
		memset(p, 0, sizeof(p));
		int N, M;
		scanf("%d %d", &N, &M);
		npts = 0;
		while (M--)
		{
			int v, a, b;
			scanf("%d %d %d", &v, &a, &b);
			pts[npts].a = a;
			pts[npts].beg = 1;
			pts[npts].val = v;
			pts[npts].last = a;
			npts++;
			pts[npts].a = b + 1;
			pts[npts].beg = -1;
			pts[npts].val = v;
			pts[npts].last = a;
			npts++;
		}
		sort(pts, pts + npts, compar);
		printf("Case %d:\n", f);
		int Q;
		scanf("%d", &Q);
		FOR(i, 0, Q)
		scanf("%lld", &QQ[i]);
		int nq = 0;
		int ind = 0;
		ll vals = 0;
		FORE(i, 0, N)
		{
			if (nq >= Q)
			{
				break;
			}
			while (ind < npts &&
						 pts[ind].a <= i)
			{
				ll A = pts[ind].last;
				if (pts[ind].val == 1)
				{
					if (pts[ind].beg == 1)
					{
						p[0] -= A;
						p[1] += 1;
					}
					else
					{
						p[0] += A;
						p[1] -= 1;
					}
				}
				else if (pts[ind].val == 2)
				{
					if (pts[ind].beg == 1)
					{
						p[0] += A * A;
						p[1] -= 2 * A;
						p[2] += 1;
					}
					else
					{
						p[0] -= A * A;
						p[1] += 2 * A;
						p[2] -= 1;
					}
				}
				else
				{
					if (pts[ind].beg == 1)
					{
						p[0] -= A * A * A;
						p[1] += 3 * A * A;
						p[2] -= 3 * A;
						p[3] += 1;
					}
					else
					{
						p[0] += A * A * A;
						p[1] -= 3 * A * A;
						p[2] += 3 * A;
						p[3] -= 1;
					}
				}
				ind++;
			}
			long long calc = 0;
			for (int j = 3; j >= 0; j--)
			{
				calc *= i;
				calc += (long long)p[j];
			}
			vals = calc + vals;
			while ((int)QQ[nq] == i)
			{
				cout << vals << endl, nq++;
			}
		}
	}
	return 0;
}

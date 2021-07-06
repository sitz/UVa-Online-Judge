#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forsn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define forall(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define dforn(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define dforsn(i, s, n) for (int i = ((int)(n)-1); i >= (int)(n); i--)
#define esta(i, c) ((c).find(i) != (c).end())
#define estal(i, c) (find((c).begin(), (c).end(), (i)) != (c).end())
#define all(c) (c).begin(), (c).end()

#define dbg(x) cerr << #x << " = " << x << endl;
#define raya cerr << string(80, '=') << endl;

typedef long long tint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

const int MAXN = 10000;
const double eps = 1e-10;
struct Interval
{
	double st, en;
	Interval() {}
	Interval(double s, double e)
	{
		st = s, en = e;
	}
	bool operator<(const Interval &i) const
	{
		return (i.en == en) ? (st < i.st) : (en < i.en);
	}
};
long double x[MAXN], y[MAXN];
Interval inter[MAXN];

int main()
{
	int n, d, testcase = 0;
	while (scanf("%d%d", &n, &d) == 2 && !(n == 0 && d == 0))
	{
		forn(i, n) scanf("%Lf %Lf", &x[i], &y[i]);
		int count = 0, ok = true;
		forn(i, n)
		{
			if (d < y[i])
			{
				ok = false;
				break;
			}
			else
			{
				long double sqrtd = sqrt((1.0 * d) * d - y[i] * y[i]);
				inter[i] = Interval(x[i] - sqrtd, x[i] + sqrtd);
			}
		}
		if (!ok)
		{
			printf("Case %d: %d\n", ++testcase, -1);
			continue;
		}
		sort(inter, inter + n);
		for (int i = 0; i < n;)
		{
			int j;
			for (j = 0; j < n; j++)
			{
				if (inter[j].st - eps > inter[i].en)
					break;
			}
			i = j;
			count++;
		}
		printf("Case %d: %d\n", ++testcase, count);
	}
	return 0;
}

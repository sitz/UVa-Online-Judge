#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
const double eps = 1e-7;
const int inf = 0x3f3f3f3f;
const int hinf = 0x3f3f3f3f;
const ll mod = 1000000007;

#define out(x) cout << x << '\n';
#define fio                         \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define fino freopen("input.txt", "r", stdin);
#define sz(a) sizeof(a)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ms(a, i) memset((a), (i), sz(a))
#define clr(x) memset(x, 0, sz(x))
#define cdp(x) memset((x), -1, sizeof(x))
#define infi(x) memset(x, 0x3f, sz(x))
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)

int cal0[60], cal1[60];
int sum0[60], sum1[60];
int ans[60];

int t;
int n, wei;

int main()
{
	clr(sum0);
	clr(sum1);
	cal0[1] = cal1[1] = 1;
	sum0[1] = sum1[1] = 1;
	for (int i = 2; i <= 55; i++)
	{
		cal0[i] = cal0[i - 1] + cal1[i - 1];
		cal1[i] = cal0[i - 1];
		sum0[i] = cal0[i] + sum0[i - 1];
		sum1[i] = cal1[i] + sum1[i - 1];
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		clr(ans);
		for (int i = 0; i <= 55; i++)
		{
			if (sum1[i] < n)
			{
				wei = i + 1;
			}
			else
			{
				break;
			}
		}
		ans[wei] = 1;
		n -= sum1[wei - 1];
		int now = wei - 1;
		while (n != 0)
		{
			int pos;
			for (int i = 0; i <= 55; i++)
			{
				if (cal0[i] < n)
				{
					pos = i;
				}
				else
				{
					break;
				}
			}
			if (pos > 0)
			{
				ans[pos] = 1;
			}
			else
			{
				break;
			}
			now = pos - 1;
			n -= cal0[pos];
		}
		for (int i = wei; i > 0; i--)
		{
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}

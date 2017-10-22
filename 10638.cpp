#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;
const int M = 200010;
const int mod = 1e6 + 7;
const int inf = 0x3f3f3f3f;
const ll oo = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-6;

#define pb push_back
#define sz(x) ((x).size())

int n, a[N];

int dfs(const vector<int> &A, int a, vector<int> B)
{
	if (a >= sz(A))
	{
		return 0;
	}
	int ret = inf;
	for (int i = 0; i < (1 << sz(B)); i++)
	{
		int sum = 0, mx = 0, c = 0;
		vector<int> T;
		for (int j = 0; j < sz(B); j++)
		{
			if (i & (1 << j))
			{
				sum += B[j];
				mx = max(mx, B[j]);
				c++;
			}
			else if (B[j])
			{
				T.pb(B[j]);
			}
		}
		if (sum >= A[a] && mx > sum - A[a])
		{
			if (sum - A[a])
			{
				T.pb(sum - A[a]);
			}
			ret = min(ret, dfs(A, a + 1, T) + c);
		}
	}
	return ret;
}

int main()
{
	while (scanf("%d", &n), n)
	{
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d.%d", &x, &y);
			a[i] = x * 100 + y;
			sum += a[i];
		}
		int l = sum / n;
		int r = sum / n + 1;
		int k = sum % n;
		int ret = inf;
		for (int i = 0; i < (1 << n); i++)
		{
			int c = 0;
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
				{
					c++;
				}
			if (c != k)
			{
				continue;
			}
			vector<int> A, B;
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
				{
					if (a[j] > r)
					{
						A.pb(a[j] - r);
					}
					else if (a[j] < r)
					{
						B.pb(r - a[j]);
					}
				}
				else
				{
					if (a[j] > l)
					{
						A.pb(a[j] - l);
					}
					else if (a[j] < l)
					{
						B.pb(l - a[j]);
					}
				}
			//for(int j = 0; j < sz(A); j++)
			//cout << A[j] << " ";cout << endl;
			//for(int j = 0; j < sz(B); j++)
			//cout << B[j] << " ";cout << endl;
			ret = min(ret, dfs(A, 0, B));
		}
		cout << ret << endl;
	}
	return 0;
}

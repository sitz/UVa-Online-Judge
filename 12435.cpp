#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
const int N_MAX = 1000003;
struct hash_table
{
	int a[N_MAX];
	short id[N_MAX], id_now;

	bool insert(int aa)
	{
		int i = aa % N_MAX;
		while (id[i] == id_now && a[i] != aa)
		{
			i = (i + 1) % N_MAX;
		}
		if (id[i] != id_now)
		{
			a[i] = aa;
			id[i] = id_now;
			return true;
		}
		else
		{
			return false;
		}
	}
};

hash_table H;

#define sq(x) (x) * (x)
#define sqsum(x, y) (sq(x) + sq(y))
int main()
{
	int T0;
	scanf("%d", &T0);
	for (int T = 1; T <= T0; T++)
	{
		int n;
		scanf("%d", &n);
		int x[1000], y[1000];
		rep(i, n) scanf("%d%d", x + i, y + i);
		int ans = 1;
		H.id_now = T;
		rep(j, n) rep(i, j) if (H.insert(sqsum(x[i] - x[j], y[i] - y[j])))
		{
			ans++;
		}
		printf("Case %d: %d\n", T, ans);
	}
	return 0;
}

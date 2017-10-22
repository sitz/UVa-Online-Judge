#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MAX 1000000

int main()
{
	long long int n, m;
	while (scanf("%lld %lld", &n, &m) && (n || m))
	{
		int a, val = 0;
		map<int, int> check;
		for (long long int i = 1; i <= n; i++)
		{
			scanf("%d", &a);
			check[a] = 1;
		}
		for (long long int i = 1; i <= m; i++)
		{
			scanf("%d", &a);
			if (check[a] == 1)
			{
				val++;
			}
		}
		cout << val << endl;
	}
	return 0;
}

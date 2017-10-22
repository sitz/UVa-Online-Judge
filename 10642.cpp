#include <bits/stdc++.h>

using namespace std;

int main()
{
	int kase, n;
	long long x1, y1, x2, y2, dis1, dis2;
	cin >> n;
	for (kase = 1; kase <= n; kase++)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		dis1 = (x1 + y1 - 1) * (x1 + y1) / 2 + x1 + y1 + y1;
		dis2 = (x2 + y2 - 1) * (x2 + y2) / 2 + x2 + y2 + y2;
		cout << "Case " << kase << ": " << dis2 - dis1 << endl;
	}
	return 0;
}

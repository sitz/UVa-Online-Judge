#include <bits/stdc++.h>

using namespace std;

int main()
{
	for (int n, pos[1000]; scanf("%d %d", &n, pos) == 2;)
	{
		int ans = -1, arc, len;
		for (int i = 1; i < n; ++i)
			scanf("%d", &arc), pos[i] = pos[i - 1] + arc;
		len = pos[n - 1];
		for (int side = 3; side <= n; ++side)
			if (len % side == 0)
			{
				bool ok = false;
				for (int i = 0, size = len / side; i < n && pos[i] <= size && !ok; ++i)
				{
					bool now = true;
					for (int j = 2; j <= side && now; ++j)
						now &= *std::lower_bound(pos + i, pos + n, size * j) == size * j;
					ok |= now;
				}
				if (ok)
					ans = side;
			}
		printf("%d\n", ans);
	}
}

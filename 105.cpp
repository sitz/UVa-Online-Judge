#include <bits/stdc++.h>

using namespace std;

int main()
{
	int hs[10001] = {0}, l, h, r;
	while (scanf("%d%d%d", &l, &h, &r) == 3)
	{
		for (int i = l; i < r; ++i)
		{
			if (h > hs[i])
			{
				hs[i] = h;
			}
		}
	}

	// only show preceeding space on non-first cases
	bool not_fst = false;
	int curr_h = 0;
	for (int pos = 0; pos != 10000; ++pos)
	{
		if (hs[pos] != curr_h)
		{
			if (not_fst)
			{
				printf(" ");
			}
			else
			{
				not_fst = true;
			}
			printf("%d %d", pos, hs[pos]);

			curr_h = hs[pos];
		}
	}
	printf("\n");
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

/**
 * UVa 11311 Exclusively Edible
 *
 * A nim-game played with 4 stacks, represented by the number of
 * cells to the left, right, up, and down of the bad piece.
 */
int main()
{
	setvbuf(stdin, NULL, _IOFBF, 10000);
	setvbuf(stdout, NULL, _IOFBF, 10000);
	int n_cases;
	scanf("%d", &n_cases);
	for (int ctr = 0; ctr < n_cases; ++ctr)
	{
		int m, n, r, c;
		scanf("%d %d %d %d", &m, &n, &r, &c);
		int nimsum = r ^ c ^ (m - r - 1) ^ (n - c - 1);
		if (!nimsum)
		{
			puts("Hansel");
		}
		else
		{
			puts("Gretel");
		}
	}
	return 0;
}

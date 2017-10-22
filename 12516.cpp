#include <bits/stdc++.h>

using namespace std;


int main()
{
	int row, col, other, our, c;
	char r, use;

	while (scanf("%d %d", &row, &col) && row + col)
	{
		bool cola[row][col + 1], seat[row][col + 1], opp[row][col + 1], ok = true;
		memset(cola, false, sizeof(cola));
		memset(seat, false, sizeof(seat));
		memset(opp, false, sizeof(opp));

		for (scanf("%d\n", &other); other; --other)
		{
			scanf("%c %d %c\n", &r, &c, &use);
			opp[r - 'A'][c] = seat[r - 'A'][c] = cola[r - 'A'][c + (use == '+')] = true;
		}
		for (scanf("%d\n", &our); our; --our)
		{
			scanf("%c %d\n", &r, &c);
			seat[r - 'A'][c] = true;
		}
		for (int i = 0; i < row && ok; ++i)
			for (int j = 0; j < col && ok; ++j)
				if (seat[i][j] ^ opp[i][j])
					if (!cola[i][j])
						cola[i][j] = true;
					else if (!cola[i][j + 1])
						cola[i][j + 1] = true;
					else
						ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}

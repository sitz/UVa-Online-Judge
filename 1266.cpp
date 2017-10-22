#include <bits/stdc++.h>

using namespace std;

template <class T>
int ndigit(T N)
{
	int digits = 0;
	// remove this if '-' counts as a digit
	if (N < 0)
	{
		digits = 1;
	}
	while (N)
	{
		N /= 10;
		digits++;
	}
	return digits;
}

int main()
{
	int n, i, j, t = 0;
	while (scanf("%d", &n) == 1)
	{
		if (t > 0)
		{
			printf("\n");
		}
		printf("n=%d, sum=%d\n", n, n * (n * n + 1) / 2);
		int map_[15][15], x = 0, y = n / 2;
		memset(map_, 0, sizeof(map_));
		for (i = 1; i <= n * n; i++)
		{
			if (map_[x][y])
			{
				x += 2, y--;
				if (x >= n)
				{
					x -= n;
				}
				if (y < 0)
				{
					y += n;
				}
				map_[x][y] = i;
			}
			else
			{
				map_[x][y] = i;
			}
			x--, y++;
			if (x < 0)
			{
				x += n;
			}
			if (y >= n)
			{
				y -= n;
			}
		}

		int l = ndigit(n * n);
		// fprintf(stderr, "width = %d\n", l);

		for (i = 0; i < n; i++, puts(""))
		{
			for (j = 0; j < n; j++)
			{
				cout << setw(l + 1) << map_[i][j];
			}
		}
		t++;
	}
	return 0;
}

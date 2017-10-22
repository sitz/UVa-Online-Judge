#include <bits/stdc++.h>

using namespace std;

#define INF 0x7fffffff
#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)

static int n, j, i, l, k, length, num_of_cut, cutPos[55], table[55][55];

void readData()
{
	scanf("%d", &num_of_cut);
	FOREQ(i, 1, num_of_cut)
	scanf("%d", &cutPos[i]);
	cutPos[0] = 0;
	cutPos[num_of_cut + 1] = length;
}

void solve()
{
	n = num_of_cut + 1;
	FOREQ(i, 0, n)
	table[i][i] = 0;
	FOREQ(l, 2, n)
	{
		FOREQ(i, 1, n - l + 1)
		{
			j = i + l - 1;
			table[i][j] = INF;
			FOR(k, i, j)
			{
				int temp;
				temp = table[i][k] + table[k + 1][j] + cutPos[j] - cutPos[i - 1];
				if (temp < table[i][j])
				{
					table[i][j] = temp;
				}
			}
		}
	}
}

int main()
{
	while (scanf("%d", &length) && length)
	{
		readData();
		solve();
		printf("The minimum cutting is %d.\n", table[1][num_of_cut + 1]);
	}
	return 0;
}

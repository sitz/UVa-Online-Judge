#include <bits/stdc++.h>

using namespace std;

int diag(bool b[5][5])
{
	int r = 0;
	for (int i = 0; i < 5; ++i)
		r += b[i][i], r += b[i][4 - i];
	return r;
}

int main()
{
	int t, ball, tic, all[75], prize[4], N[] = {0, 35, 40, 45, 75};
	scanf("%d", &t);

	for (int n = 0; n < t; ++n)
	{
		printf("%sCase %d:\n", n ? "\n" : "", n + 1);
		scanf("%d %d", &ball, &tic);
		for (int i = 0; i < ball; ++i)
			scanf("%d", all + i);
		scanf("%d %d %d %d", prize, prize + 1, prize + 2, prize + 3);

		for (int s = 0; s < tic; ++s)
		{
			int won = 0, brd[5][5];
			bool mark[5][5] = {{false}};

			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					scanf("%d", &brd[i][j]);
			for (int t = 0; t < 4; ++t)
			{
				for (int i = N[t]; i < N[t + 1] && i < ball; ++i)
					for (int p = 0; p < 5; ++p)
						for (int q = 0; q < 5; ++q)
							if (brd[p][q] == all[i])
								mark[p][q] = true;
				if (t == 0 && mark[0][0] && mark[0][4] && mark[4][0] && mark[4][4] ||
						t == 1 && std::count(mark[2], mark[2] + 5, true) == 5 ||
						t == 2 && diag(mark) == 10 ||
						t == 3 && std::count(&mark[0][0], &mark[5][0], true) == 25)
					won += prize[t];
			}
			printf("%d\n", won);
		}
	}
}

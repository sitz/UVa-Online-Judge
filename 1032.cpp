#include <bits/stdc++.h>

using namespace std;

const int MAXN = 128;

map<int, int> R;

int day_prev(int x)
{
	// mday[] will be modified
	int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int yy = x / 10000, mm = x % 10000 / 100, dd = x % 100;
	if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
	{
		mday[2] = 29;
	}
	if (mm == 1 && dd == 1)
	{
		yy--;
		mm = 12;
		dd = 31;
	}
	else
	{
		dd--;
		if (dd < 1)
		{
			mm--;
			dd = mday[mm];
		}
	}
	return yy * 10000 + mm * 100 + dd;
}

int day_nxt(int x)
{
	// mday[] will be modified
	int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int yy = x / 10000, mm = x % 10000 / 100, dd = x % 100;
	if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
	{
		mday[2] = 29;
	}
	dd++;
	if (dd > mday[mm])
	{
		dd = 1;
		mm++;
	}
	if (mm == 13)
	{
		mm = 1;
		yy++;
	}
	return yy * 10000 + mm * 100 + dd;
}

void record(int x)
{
	R[x] = 0, R[day_nxt(x)] = 0, R[day_prev(x)] = 0;
}

void print(int x)
{
	int yy = x / 10000, mm = x % 10000 / 100, dd = x % 100;
	printf("%d/%d/%d", mm, dd, yy);
}

int main()
{
	int cases = 0, N, M, aSt[MAXN], aEd[MAXN], bSt[MAXN], bEd[MAXN];
	while (scanf("%d%d", &N, &M) == 2, N, M)
	{
		R.clear();
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d", &aSt[i], &aEd[i]);
			record(aSt[i]);
			record(aEd[i]);
		}
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d", &bSt[i], &bEd[i]);
			record(bSt[i]);
			record(bEd[i]);
		}

		int size = 0;
		vector<int> date;
		for (map<int, int>::iterator it = R.begin();
				 it != R.end(); it++)
		{
			it->second = size++;
			date.push_back(it->first);
		}

		vector<int> mark(size, 0);
		for (int i = 0; i < M; i++)
		{
			int l = R[bSt[i]], r = R[bEd[i]];
			for (int j = l; j <= r; j++)
			{
				mark[j] = 1;
			}
		}
		for (int i = 0; i < N; i++)
		{
			int l = R[aSt[i]], r = R[aEd[i]];
			for (int j = l; j <= r; j++)
			{
				mark[j] = 0;
			}
		}

		if (cases)
		{
			printf("\n");
		}
		printf("Case %d:\n", ++cases);
		int has = 0;
		for (int i = 0; i < mark.size(); i++)
		{
			if (mark[i] == 1)
			{
				has = 1;
				printf("    ");
				print(date[i]);
				if (i + 1 < mark.size() && mark[i + 1] == 1)
				{
					printf(" to ");
					while (i + 1 < mark.size() && mark[i + 1] == 1)
					{
						i++;
					}
					print(date[i]);
				}
				printf("\n");
			}
		}

		if (!has)
		{
			printf("    No additional quotes are required.\n");
		}
	}
	return 0;
}

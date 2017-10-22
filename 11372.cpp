#include <bits/stdc++.h>

using namespace std;

struct Problem
{
	int no;
	int type;
	int favor;
} p;
Problem cat[3][200];
int sets[3], n, choose[4], count[3], ans[7], t[7], bestfavor;
char name[30], cate[2], diff[2];

int compare(const void *a, const void *b)
{
	Problem *c = (Problem *)a, *d = (Problem *)b;
	if (c->favor != d->favor)
	{
		return d->favor - c->favor;
	}
	else
	{
		return c->no - d->no;
	}
}

void DFS(int depth, int favor)
{
	if (depth == 3)
	{
		if (!(choose[0] >= 2 && choose[1] >= 1 && choose[2] >= 1))
			return;
		if (favor < bestfavor)
			return;
		int temp[7];
		for (int i = 0; i < 6; i++)
			temp[i] = t[i];
		for (int i = 0; i < 6; i++)
			for (int j = i + 1; j < 6; j++)
				if (temp[i] > temp[j])
				{
					int t1 = temp[i];
					temp[i] = temp[j];
					temp[j] = t1;
				}
		if (favor > bestfavor)
			for (int i = 0; i < 6; i++)
				ans[i] = temp[i];
		else
		{
			bool update = false;
			for (int i = 0; i < 6; i++)
				if (temp[i] < ans[i])
					update = true;
				else if (temp[i] > ans[i])
					break;
			if (update)
				for (int i = 0; i < 6; i++)
					ans[i] = temp[i];
		}
		bestfavor = favor;
	}
	else
	{
		for (int i = 0; i < sets[depth] && i < 8; i++)
		{
			Problem &p1 = cat[depth][i];
			choose[p1.type]++;
			t[2 * depth] = p1.no;
			for (int j = i + 1; j < sets[depth] && j < 8; j++)
			{
				Problem &p2 = cat[depth][j];
				choose[p2.type]++;
				t[2 * depth + 1] = p2.no;
				DFS(depth + 1, favor + p1.favor + p2.favor);
				choose[p2.type]--;
			}
			choose[p1.type]--;
		}
	}
}

int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < 3; i++)
			sets[i] = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%03d %s %s %s %d", &p.no, name, diff, cate, &p.favor);
			if (cate[0] == 'D')
				p.type = 0;
			else if (cate[0] == 'M')
				p.type = 1;
			else if (cate[0] == 'G')
				p.type = 2;
			else
				p.type = 3;

			if (diff[0] == 'E')
				cat[0][sets[0]++] = p;
			else if (diff[0] == 'M')
				cat[1][sets[1]++] = p;
			else
				cat[2][sets[2]++] = p;
		}

		for (int i = 0; i < 3; i++)
			qsort(cat[i], sets[i], sizeof(Problem), compare);
		for (int i = 0; i < 4; i++)
			choose[i] = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
				choose[j] = 0;
			int sols = 0;
			for (int j = 0; j < sets[i]; j++)
			{
				Problem &p = cat[i][j];
				int type = p.type;
				if (choose[type] >= 2)
					continue;
				choose[type]++;
				cat[i][sols++] = p;
			}
			sets[i] = sols;
		}
		for (int i = 0; i < 4; i++)
			choose[i] = 0;
		bestfavor = 0;
		DFS(0, 0);
		if (bestfavor > 0)
		{
			for (int i = 0; i < 6; i++)
			{
				if (i)
					putchar(' ');
				printf("%03d", ans[i]);
			}
			puts("");
		}
		else
			puts("No solution.");
	}
	return 0;
}

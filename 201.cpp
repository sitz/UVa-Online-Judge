#include <bits/stdc++.h>

using namespace std;

//HKUST - ZHANG Xiongqi
//Using C++

void check(const int &i, const int &j, const int &num, int square[]);
bool h[100][100];
bool v[100][100];
int main()
{
	int num;
	int count = 1;
	while (scanf("%d", &num) == 1)
	{
		int square[num - 1];
		memset(square, 0, sizeof(square));
		memset(v, 0, sizeof(v));
		memset(h, 0, sizeof(h));
		int line;
		scanf("%d", &line);
		char temp;
		int d1, d2;
		for (int i = 0; i < line; i++)
		{
			cin >> temp;
			scanf("%d%d", &d1, &d2);
			if (temp == 'V')
			{
				v[d2 - 1][d1 - 1] = true;
			}
			else if (temp == 'H')
			{
				h[d1 - 1][d2 - 1] = true;
			}
		}
		for (int i = 0; i < num - 1; i++)
			for (int j = 0; j < num - 1; j++)
			{
				check(i, j, num, square);
			}
		if (count > 1)
		{
			printf("\n**********************************\n\n");
		}
		printf("Problem #%d\n\n", count);
		count++;
		bool have = false;
		for (int i = 0; i < num - 1; i++)
			if (square[i] != 0)
			{
				have = true;
			}
		if (!have)
		{
			printf("No completed squares can be found.\n");
		}
		else
		{
			for (int i = 0; i < num - 1; i++)
			{
				if (square[i] != 0)
				{
					printf("%d square (s) of size %d\n", square[i], i + 1);
				}
			}
		}
	}
}
void check(const int &i, const int &j, const int &num, int square[])
{
	int maxp = max(i, j);
	int maxs = num - 1 - maxp;
	for (int size = 1; size <= maxs; size++)
	{
		bool ok = true;
		for (int a = 0; ok && a < size; a++)
			if (!v[i + a][j] || !v[i + a][j + size] || !h[i][j + a] || !h[i + size][j + a])
			{
				ok = false;
			}
		if (ok)
		{
			square[size - 1]++;
		}
	}
	return;
}

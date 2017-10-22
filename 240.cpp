#include <bits/stdc++.h>

using namespace std;

int r, n, nn, p;
int pass[30][30];
bool alive[30][30];
int parent[30][30], weight[30][30];
char small[30][30];
int seq[30][30], l[30];
double total, s;
int main()
{
	int caseno = 1;
	while (scanf("%d", &r), r)
	{
		scanf("%d", &n);
		s = total = 0;
		memset(pass, 0, sizeof(pass));
		memset(alive, true, sizeof(alive));
		memset(parent, -1, sizeof(parent));
		memset(weight, -1, sizeof(weight));
		memset(small, 26 + 'A', sizeof(small));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &pass[0][i]);
			s += pass[0][i];
			small[0][i] = i + 'A';
		}
		int k = (int)ceil((double)(n - r) / (double)(r - 1));
		nn = k * (r - 1) + r;
		for (p = 1; nn != 1; p++)
		{
			int sum = 0;
			for (int i = 0; i < r; i++)
			{
				int min = 100000000, ptr;
				for (int j = 0; j < nn; j++)
					if (alive[p - 1][j])
					{
						if ((pass[p - 1][j] < min) || (pass[p - 1][j] == min && small[p - 1][j] < small[p - 1][ptr]))
						{
							min = pass[p - 1][j];
							ptr = j;
						}
					}
				alive[p - 1][ptr] = false;
				weight[p - 1][ptr] = i;
				parent[p - 1][ptr] = nn - r;
				if (small[p - 1][ptr] < small[p][nn - r])
				{
					small[p][nn - r] = small[p - 1][ptr];
				}
				sum += pass[p - 1][ptr];
			}
			int s = 0;
			for (int i = 0; i < nn; i++)
				if (alive[p - 1][i])
				{
					pass[p][s] = pass[p - 1][i];
					small[p][s] = small[p - 1][i];
					weight[p - 1][i] = -1;
					parent[p - 1][i] = s++;
				}
			pass[p][nn - r] = sum;
			nn -= r - 1;
		}
		parent[p - 1][0] = -1;
		for (int i = 0; i < n; i++)
		{
			l[i] = 0;
			int x = i, k = 0;
			while (parent[k][x] != -1)
			{
				if (weight[k][x] != -1)
				{
					seq[i][l[i]++] = weight[k][x];
				}
				x = parent[k++][x];
			}
			total += l[i] * pass[0][i];
		}
		printf("Set %d; average length %.2lf\n", caseno++,
					 total / s);
		for (int i = 0; i < n; i++)
		{
			printf("    %c: ", i + 'A');
			for (int j = l[i] - 1; j >= 0; j--)
			{
				printf("%d", seq[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

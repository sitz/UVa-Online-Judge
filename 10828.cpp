#include <bits/stdc++.h>

using namespace std;

#define MAXN 116
#define EPS 1E-8

vector<int> a[MAXN];
int degree[MAXN];
double ans[MAXN];
double matrix[MAXN][MAXN];
bool inf[MAXN];
int n, testnum;

void Read()
{
	int i, u, v;
	memset(degree, 0, sizeof(degree));
	memset(matrix, 0, sizeof(matrix));
	memset(ans, 0, sizeof(ans));
	for (i = 0; i < MAXN; i++)
	{
		a[i].clear();
	}
	while (1)
	{
		scanf("%d%d", &u, &v);
		if (!u || !v)
		{
			break;
		}
		degree[u]++;
		a[v].push_back(u);
	}
}
void Init()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		matrix[i][i] = 1;
		for (j = 0; j < a[i].size(); j++)
		{
			matrix[i][a[i][j]] -= 1 / (degree[a[i][j]] + 0.0);
		}
	}
	matrix[1][n + 1] = 1;
}
void Debug()
{
	int i, j;
	cerr << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n + 1; j++)
		{
			cerr << matrix[i][j] << ' ';
		}
		cerr << endl;
	}
}
void Myswap(int i, int j)
{
	int k;
	for (k = 1; k <= n + 1; k++)
	{
		swap(matrix[i][k], matrix[j][k]);
	}
}
double myfabs(double x)
{
	return x < 0 ? -x : x;
}
void Gauss_jordan()
{
	int row, col;
	int ret, i, j;
	for (row = col = 1; row <= n && col <= n; row++, col++)
	{
		ret = row;
		for (i = row + 1; i <= n; i++)
			if (myfabs(matrix[i][col]) > myfabs(matrix[ret][col]))
			{
				ret = i;
			}
		if (myfabs(matrix[ret][col]) < EPS)
		{
			continue;
		}
		if (ret != row)
		{
			Myswap(row, ret);
		}
		for (i = 1; i <= n; i++)
			if (i != row)
				for (j = n + 1; j >= col; j--)
				{
					matrix[i][j] -= matrix[i][col] * matrix[row][j] / matrix[row][col];
				}
	}
}
void Process_Ans()
{
	int i, j;
	memset(inf, false, sizeof(inf));
	for (i = n; i >= 1; i--)
	{
		if (myfabs(matrix[i][i]) > EPS)
		{
			for (j = i + 1; j <= n; j++)
				if (myfabs(matrix[i][j]) > EPS && inf[j])
				{
					inf[i] = true;
					break;
				}
			if (!inf[i])
			{
				ans[i] = matrix[i][n + 1] / matrix[i][i];
			}
		}
		else
		{
			if (myfabs(matrix[i][n + 1]) > EPS)
			{
				inf[i] = true;
			}
			else
			{
				ans[i] = 0;
			}
		}
	}
}
void Print()
{
	int x, q;
	scanf("%d", &q);
	if (!q)
	{
		return;
	}
	printf("Case #%d:\n", testnum);
	while (q--)
	{
		scanf("%d", &x);
		if (inf[x])
		{
			printf("infinity\n");
		}
		else
		{
			printf("%.3lf\n", myfabs(ans[x]) < EPS ? 0.0 : ans[x]);
		}
	}
}

int main()
{
	while (1)
	{
		++testnum;
		scanf("%d", &n);
		if (!n)
		{
			break;
		}
		Read();
		Init();
		Gauss_jordan();
		Process_Ans();
		Print();
	}
	return 0;
}

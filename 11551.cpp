#include <bits/stdc++.h>

using namespace std;

int n;
struct mat
{
	int m[60][60];
	mat operator*(const mat &m2) const
	{
		mat ret;
		memset(ret.m, 0, sizeof(ret.m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					ret.m[i][j] += m[i][k] * m2.m[k][j];
				}
				ret.m[i][j] %= 1000;
			}
		}
		return ret;
	}
	void p()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", m[i][j]);
			}
			printf("\n");
		}
	}
} a, pot[33];
int r;
int read()
{
	scanf("%d%d", &n, &r);
	memset(a.m, 0, sizeof(a.m));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a.m[i][0]);
		a.m[i][0] %= 1000;
	}
	int temp;
	memset(pot[0].m, 0, sizeof(pot[0].m));
	int t;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		for (int j = 0; j < t; j++)
		{
			scanf("%d", &temp);
			//printf ("temp = %d\n", temp);
			pot[0].m[i][temp]++;
		}
	}
	return 1;
}
void process()
{
	//pot[0].p();
	for (int i = 1; (1 << i) <= r; i++)
	{
		pot[i] = pot[i - 1] * pot[i - 1];
		//pot[i].p();
	}
	int i = 0;
	while (r)
	{
		if (r & 1)
		{
			//printf ("aki i = %d\n", i);
			a = pot[i] * a;
			//a.p();
		}
		i++;
		r >>= 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (i)
		{
			printf(" ");
		}
		printf("%d", a.m[i][0]);
	}
	printf("\n");
}
int main()
{
	int casos;
	scanf("%d", &casos);
	while (casos--)
	{
		read();
		process();
	}
	return 0;
}

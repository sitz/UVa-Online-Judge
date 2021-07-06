#include <bits/stdc++.h>

using namespace std;

int fibonacci[500][110];

void get_fibonacci()
{
	memset(fibonacci, 0, sizeof(fibonacci));
	fibonacci[0][0] = 1;
	fibonacci[1][0] = 1;
	fibonacci[1][1] = 1;
	int i, j, jinwei, tmp;
	for (i = 2; i < 500; i++)
	{
		jinwei = 0;
		fibonacci[i][0] = fibonacci[i - 1][0];
		for (j = 1; j <= fibonacci[i - 1][0]; j++)
		{
			tmp = fibonacci[i - 2][j] + fibonacci[i - 1][j] + jinwei;
			if (tmp > 9)
			{
				fibonacci[i][j] = tmp % 10;
				jinwei = 1;
			}
			else
			{
				jinwei = 0;
				fibonacci[i][j] = tmp % 10;
			}
		}
		if (jinwei == 1)
		{
			fibonacci[i][j] = 1;
			fibonacci[i][0]++;
		}
	}
}

int compare(int *a, int *b) /*return 1 if a>b*/
{
	if (a[0] > b[0])
	{
		return 1;
	}
	if (a[0] < b[0])
	{
		return -1;
	}
	int i;
	for (i = a[0]; i > 0; i--)
	{
		if (a[i] > b[i])
		{
			return 1;
		}
		if (a[i] < b[i])
		{
			return -1;
		}
	}
	return 0;
}

int main()
{
	get_fibonacci();
	char pa[110], pb[110];
	int a[110], b[110], i, j;
	while (cin >> pa >> pb)
	{
		if (!strcmp(pa, "0") && !strcmp(pb, "0"))
		{
			break;
		}
		//get a and b;
		a[0] = strlen(pa);
		for (i = 0, j = a[0]; i < a[0]; i++, j--)
		{
			a[j] = pa[i] - '0';
		}
		b[0] = strlen(pb);
		for (i = 0, j = b[0]; i < b[0]; i++, j--)
		{
			b[j] = pb[i] - '0';
		}
		//
		int cnt = 0;
		for (i = 2; i < 500; i++)
		{
			if (compare(fibonacci[i], b) == 1)
			{
				break;
			}
			if (compare(fibonacci[i], a) != -1)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

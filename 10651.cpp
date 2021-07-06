#include <bits/stdc++.h>

using namespace std;

#define MAXN 1500

struct ss
{
	char str[15];
	int len;
} Q[MAXN];

char ini[15];
int qh, qt, min_;

void Push(char temp[], int len)
{
	strcpy(Q[qh].str, temp);
	Q[qh++].len = len;
	qh %= MAXN;
}
void BFS(int t)
{
	int i, j, pre;
	char xx[15], yy[15];
	qh = qt = 0;
	min_ = t;
	Push(ini, t);
	while (qh != qt)
	{
		strcpy(xx, Q[qt].str);
		pre = Q[qt++].len;
		if (pre < min_)
		{
			min_ = pre;
		}
		for (i = 0; i < 12; i++)
		{
			if (xx[i] == 'o')
			{
				continue;
			}
			if (i <= 9 && xx[i + 1] == 'o' && xx[i + 2] == 'o')
			{
				for (j = 0; j < i; j++)
				{
					yy[j] = xx[j];
				}
				yy[j] = 'o';
				yy[i + 1] = yy[i + 2] = '-';
				for (j = i + 3; j < 12; j++)
				{
					yy[j] = xx[j];
				}
				yy[12] = '\0';
				Push(yy, pre - 1);
			}
			if (i >= 2 && xx[i - 1] == 'o' && xx[i - 2] == 'o')
			{
				for (j = 11; j > i; j--)
				{
					yy[j] = xx[j];
				}
				yy[j] = 'o';
				yy[i - 1] = yy[i - 2] = '-';
				for (j = 0; j < i - 2; j++)
				{
					yy[j] = xx[j];
				}
				yy[12] = '\0';
				Push(yy, pre - 1);
			}
		}
	}
}
void cal()
{
	int i, t = 0;
	for (i = 0; ini[i]; i++)
	{
		if (ini[i] == 'o')
		{
			t++;
		}
	}
	if (t == 12 || t == 0 || t == 1)
	{
		printf("%d\n", t);
		return;
	}
	BFS(t);
	printf("%d\n", min_);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", ini);
		cal();
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

void find(const int &S, const int &N, const int stamp[], const int st[][10], int &choice, int &coverage, int &stnum);
int main()
{
	while (true)
	{
		int S, N;
		scanf("%d", &S);
		if (S == 0)
		{
			return 0;
		}
		scanf("%d", &N);
		int stamp[N];
		int st[N][10];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &stamp[i]);
			for (int j = 0; j < stamp[i]; ++j)
			{
				scanf("%d", &st[i][j]);
			}
		}
		int choice = 0;
		int coverage = 0;
		int stnum = 100;
		////////////////////////////////////
		find(S, N, stamp, st, choice, coverage, stnum);//
		////////////////////////////////////
		//cout<<"choice:"<<choice<<endl;
		printf("max coverage =%4d :", coverage);
		for (int i = 0; i < stamp[choice]; ++i)
		{
			printf("%3d", st[choice][i]);
		}
		putchar(10);
	}
}
void find(const int &S, const int &N, const int stamp[], const int st[][10], int &choice, int &coverage, int &stnum)
{
	for (int i = 0; i < N; ++i)
	{
		//cout<<"Now is testing stamp series "<<i+1<<":"<<endl;
		int tcover;
		int total;
		int a[1002];
		memset(a, 23, sizeof(a));
		a[0] = 0;
		int j = 1;
		do
		{
			for (int k = 0; k < stamp[i]; k++)
			{
				if (j >= st[i][k])
				{
					a[j] = min(a[j], a[j - st[i][k]] + 1);
				}
			}
		} while (a[j++] <= S);
		tcover = j - 2;
		//cout<<tcover<<endl;
		if (tcover > coverage)
		{
			coverage = tcover;
			choice = i;
			stnum = stamp[i];
		}
		else if (tcover == coverage)
		{
			if (stamp[i] == stnum)
			{
				for (int j = 1; j < stamp[i] && j < stamp[choice]; j++)
				{
					if (st[i][stamp[i] - j] == st[choice][stamp[choice] - j])
					{
						continue;
					}
					else if (st[i][stamp[i] - j] > st[choice][stamp[choice] - j])
					{
						break;
					}
					else
					{
						choice = i;
						break;
					}
				}
			}
			else if (stamp[i] < stnum)
			{
				choice = i;
				stnum = stamp[i];
			}
		}
	}
}

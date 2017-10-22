#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 29

int lev, all[1000005], top = 0, cnt = 1;
bool is[1000005];
vector<int> v;

void generate();
void getall();
void dfs(long long now, int which, int level);
void output(int n);

int main()
{
	generate();
	getall();
	int T, t, A, B, K, i, j, pos;
	scanf(" %d", &T);
	for (t = 0; t < T; t++)
	{
		scanf(" %d %d %d", &A, &B, &K);
		if (K > (B - A) / 2)
		{
			for (i = top - 1, K = B - A - K + 2; K; i--)
				if (all[i] >= A && all[i] <= B)
				{
					K--;
				}
			i++;
		}
		else
		{
			for (i = 0; K; i++)
				if (all[i] >= A && all[i] <= B)
				{
					K--;
				}
			i--;
		}
		/*for(i=0;i<top && K;i++)
		    if(all[i]>=A && all[i]<=B)
		        K--;*/
		//printf("%d %d\n",all[i-1]);
		output(all[i]);
	}
	return 0;
}
void generate()
{
	v.clear();
	int i, j;
	for (i = 2; i < 1000005; i++)
		if (!is[i])
		{
			for (j = i * 2; j < 1000005; j += i)
			{
				is[j] = true;
			}
			v.push_back(i);
		}
}
void getall()
{
	for (lev = 1; lev < 20; lev++)
	{
		dfs(1, 0, 0);
	}
}
void dfs(long long now, int which, int level)
{
	if (level == lev)
	{
		if (now <= 1000000)
		{
			all[top++] = now;
		}
		return;
	}
	while (which < v.size())
	{
		if (now * v[which] > 1000000)
		{
			return;
		}
		dfs(now * v[which], which, level + 1);
		which++;
	}
}
void output(int n)
{
	printf("Case %d:", cnt++);
	int i = 0;
	while (n != 1)
	{
		while (n % v[i] == 0)
		{
			printf(" %d", v[i]);
			n /= v[i];
			if (n == 1)
			{
				break;
			}
		}
		if (n == 1)
		{
			break;
		}
		i++;
	}
	printf("\n");
}

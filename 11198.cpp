#include <bits/stdc++.h>

using namespace std;

/*
Author:银志圆
State:Ac
题意:求最小的交换次数使得序列有序
思路：广度搜索+map判重
*/

typedef int pii[8];
struct node
{
	pii a;//b用来记录为负数的下标
	int len;
	int state;
	void preInit(int from, int to)
	{
		int tfrom = getPos(from, 8);
		for (int i = tfrom + 1; i < 8; i++)
		{
			a[i - 1] = a[i];
		}
		int tto = getPos(to, 7);
		for (int i = 6; i >= tto; i--)
		{
			a[i + 1] = a[i];
		}
		a[tto] = from;
	}
	void nextInit(int from, int to)
	{
		int tfrom = getPos(from, 8);
		for (int i = tfrom + 1; i < 8; i++)
		{
			a[i - 1] = a[i];
		}
		int tto = getPos(to, 7);
		for (int i = 6; i >= (tto + 1); i--)
		{
			a[i + 1] = a[i];
		}
		a[tto + 1] = from;
	}
	int getPos(int valu, int len)
	{
		for (int i = 0; i < len; i++)
		{
			if (a[i] == valu)
			{
				return i;
			}
		}
	}
};
map<int, bool> mark;
bool nprime[20];
int male[9], female[9], tmp, judge = 12345678;
pii start;
int toint(pii a)
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		sum = sum * 10 + a[i];
	}
	return sum;
}
int main()
{
	memset(nprime, false, sizeof(nprime));
	nprime[4] = true;
	nprime[6] = true;
	nprime[8] = true;
	nprime[9] = true;
	nprime[10] = true;
	nprime[12] = true;
	nprime[14] = true;
	nprime[15] = true;
	int cases = 0;
	while (1)
	{
		cases++;
		mark.clear();
		male[0] = female[0] = 0;
		for (int i = 0; i < 8; i++)
		{
			scanf("%d", &start[i]);
			if (start[i] == 0)
			{
				system("pause");
				return 0;
			}
			if (start[i] > 0)
			{
				male[++male[0]] = start[i];
			}
			else
			{
				start[i] = -start[i];
				female[++female[0]] = start[i];
			}
		}
		tmp = toint(start);
		mark[tmp] = true;
		node tq;
		for (int i = 0; i < 8; i++)
		{
			tq.a[i] = start[i];
		}
		tq.len = 0;
		tq.state = tmp;
		queue<node> q;
		q.push(tq);
		int k = 0, ok = 0;
		while (!q.empty())
		{
			tq = q.front();
			q.pop();
			if (tq.state == judge)
			{
				ok = 1;
				printf("Case %d: %d\n", cases, tq.len);
				break;
			}
			for (int i = 1; i <= female[0]; i++)
			{
				for (int j = 1; j <= male[0]; j++)
				{
					if (!nprime[female[i] + male[j]])
					{
						node tp = tq;
						tp.len++;
						tp.preInit(female[i], male[j]);
						tmp = toint(tp.a);
						tp.state = tmp;
						if (!mark[tmp])
						{
							q.push(tp);
							mark[tmp] = true;
						}
						tp = tq;
						tp.len++;
						tp.nextInit(female[i], male[j]);
						tmp = toint(tp.a);
						tp.state = tmp;
						if (!mark[tmp])
						{
							q.push(tp);
							mark[tmp] = true;
						}
					}
				}
			}
			for (int i = 1; i <= female[0]; i++)
			{
				for (int j = 1; j <= male[0]; j++)
				{
					if (!nprime[female[i] + male[j]])
					{
						node tp = tq;
						tp.len++;
						tp.preInit(male[j], female[i]);
						tmp = toint(tp.a);
						tp.state = tmp;
						if (!mark[tmp])
						{
							q.push(tp);
							mark[tmp] = true;
						}
						tp = tq;
						tp.len++;
						tp.nextInit(male[j], female[i]);
						tmp = toint(tp.a);
						tp.state = tmp;
						if (!mark[tmp])
						{
							q.push(tp);
							mark[tmp] = true;
						}
					}
				}
			}
		}
		if (!ok)
		{
			printf("Case %d: -1\n", cases);
		}
	}
	return 0;
}

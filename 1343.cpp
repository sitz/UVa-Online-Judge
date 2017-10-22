#include <bits/stdc++.h>

using namespace std;

#define MAXN 50
int a[MAXN + 10], maxd;
char ans[1000];
int line[8][7] =
		{
				{0, 2, 6, 11, 15, 20, 22},	 // A
				{1, 3, 8, 12, 17, 21, 23},	 // B
				{10, 9, 8, 7, 6, 5, 4},			 // C
				{19, 18, 17, 16, 15, 14, 13},// D
};
const int rev[8] = {5, 4, 7, 6, 1, 0, 3, 2};			 //éè¿A,B,C,Dï¼åæ¨å¶ä»æ¹åãæåååï¼ç¨æ¥è¿åç°åºã
const int final[8] = {6, 7, 8, 11, 12, 15, 16, 17};//æåç­æ¡è¦æ±çç¹
bool ok()
{
	for (int i = 0; i < 8; i++)
		if (a[final[i]] != a[final[0]])
		{
			return false;
		}
	return true;
}
int dis(int k)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		if (a[final[i]] != k)
		{
			cnt++;
		}
	return cnt;
}
void move(int i)
{
	int tmp = a[line[i][0]];
	for (int j = 0; j < 6; j++)
	{
		a[line[i][j]] = a[line[i][j + 1]];
	}
	a[line[i][6]] = tmp;
}
int h()
{
	return min(dis(1), min(dis(2), dis(3)));
}
void init()//åæ¨æ¹å
{
	for (int i = 4; i < 8; i++)
		for (int j = 0; j < 7; j++)
		{
			line[i][j] = line[rev[i]][6 - j];
		}
}
bool dfs(int cur, int maxd)
{
	if (ok())
	{
		ans[cur] = 0;
		printf("%s\n", ans);
		return true;
	}
	if (cur + h() > maxd)
	{
		return false;
	}
	for (int i = 0; i < 8; i++)
	{
		ans[cur] = 'A' + i;
		move(i);
		if (dfs(cur + 1, maxd))
		{
			return true;
		}
		move(rev[i]);
	}
	return false;
}
int main()
{
	for (int i = 4; i < 8; i++)
		for (int j = 0; j < 7; j++)
		{
			line[i][j] = line[rev[i]][6 - j];
		}
	while (scanf("%d", &a[0]) == 1 && a[0])
	{
		for (int i = 1; i < 24; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < 24; i++)
			if (!a[i])
			{
				return 0;
			}
		if (ok())
		{
			printf("No moves needed\n%d\n", a[6]);
			continue;
		}
		for (maxd = 1;; maxd++)
			if (dfs(0, maxd))
			{
				break;
			}
		printf("%d\n", a[6]);
	}
}

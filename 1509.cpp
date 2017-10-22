#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
char str[maxn], mapStr[maxn];
map<char, char *> mp;
int k, len1, len2;

int dfs(int pos1, int pos2)
{
	if (pos1 == len1 && pos2 == len2)
	{
		return 1;
	}
	if (pos1 == len1 && pos2 != len2)
	{
		return 0;
	}
	if (mp[str[pos1]])//如果已经有值
	{
		char *tmp = mp[str[pos1]];
		int len = strlen(tmp);
		int tmpPos = pos2;
		for (int i = 0; i < len; i++)
		{
			if (tmp[i] != mapStr[tmpPos])
			{
				return 0;
			}
			tmpPos++;
		}
		if (dfs(pos1 + 1, tmpPos))
		{
			return 1;
		}
	}
	else//还没有值
	{
		char tmp[maxn];
		for (int i = 1; i <= k; i++)
		{
			memset(tmp, '\0', sizeof(tmp));
			int pos = 0;
			for (int j = pos2; j < pos2 + i; j++)
			{
				tmp[pos++] = mapStr[j];
			}
			mp[str[pos1]] = tmp;
			if (dfs(pos1 + 1, pos2 + i))
			{
				return 1;
			}
			mp[str[pos1]] = 0;
		}
	}
	return 0;
}

int main()
{
	int Case;
	scanf("%d", &Case);
	while (Case--)
	{
		scanf("%d%*c", &k);
		gets(str);
		gets(mapStr);
		len1 = strlen(str);
		len2 = strlen(mapStr);
		mp.clear();
		printf("%d\n", dfs(0, 0));
	}
	return 0;
}

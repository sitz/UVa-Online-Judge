#include <bits/stdc++.h>

using namespace std;

char str[1005];
int sum[129];

typedef struct
{
	int ascii, cnt;
} kind;
kind data[128];
int cmp(kind a, kind b)
{
	if (a.cnt != b.cnt)
	{
		return a.cnt < b.cnt;
	}
	return a.ascii > b.ascii;
}

int main()
{
	int total = 0;
	while (gets(str))
	{
		if (total++)
		{
			printf("\n");
		}
		memset(sum, 0, sizeof(sum));
		for (int i = 0; str[i]; ++i)
		{
			sum[str[i]]++;
		}
		int cnt = 0;
		for (int i = 32; i < 128; ++i)
		{
			if (sum[i])
			{
				data[cnt].ascii = i;
				data[cnt].cnt = sum[i];
				cnt++;
			}
		}
		sort(data, data + cnt, cmp);
		for (int i = 0; i < cnt; ++i)
		{
			printf("%d %d\n", data[i].ascii, data[i].cnt);
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 30;
const int C[10] = {1, 9, 36, 84, 126, 126, 84, 36, 9, 1};
const int calu[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
char str[N];
LL len, num, sum, state[N];

void dfs(int ind, int cnt)
{
	if (cnt > num + 1 || str[ind] == '0')
	{
		return;
	}
	if (cnt == num + 1)
	{
		if (ind != len)
		{
			return;
		}
		LL res = calu[num], tmp = 1;
		for (int i = 1; i < cnt; i++)
		{
			//printf("%lld ",state[i]);
			if (state[i] != state[i - 1])
			{
				res /= calu[tmp];
				tmp = 1;
			}
			else
			{
				tmp++;
			}
		}
		//puts("");
		if (tmp != 1)
		{
			res /= tmp;
		}
		sum += res;
	}
	LL data = 0;
	for (int i = ind; i < len; i++)
	{
		data = data * 10 + str[i] - '0';
		state[cnt] = data;
		if (data >= state[cnt - 1])
		{
			dfs(i + 1, cnt + 1);
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		sum = 0;
		scanf("%s", str);
		len = (int)strlen(str);
		num = str[0] - '0';
		dfs(1, 1);
		cout << sum * C[num] << endl;
	}
	return 0;
}

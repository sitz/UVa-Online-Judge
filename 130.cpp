#include <bits/stdc++.h>

using namespace std;

int queue_[101];
int n, k;

void roman()
{
	int cnt, i, nxt = -1, killed;
	for (i = 0; i < n; i++)
	{
		queue_[i] = i + 1;
	}
	cnt = 0;
	i = n;
	while (i > 1)
	{
		cnt = 0;
		while (cnt < k)
		{
			nxt = (nxt + 1) % n;
			if (queue_[nxt])
			{
				cnt++;
			}
		}
		killed = nxt;
		queue_[nxt] = 0;
		cnt = 0;
		nxt--;
		while (cnt < k)
		{
			nxt = (nxt + 1) % n;
			if (queue_[nxt])
			{
				cnt++;
			}
		}
		queue_[killed] = queue_[nxt];
		queue_[nxt] = 0;
		nxt = killed;
		i--;
	}
	for (i = 0; i < n; i++)
		if (queue_[i])
		{
			if (queue_[i] == 1)
			{
				printf("1\n");
			}
			else
			{
				printf("%d\n", n - queue_[i] + 2);
			}
			break;
		}
}

int main()
{
	while (scanf("%d%d", &n, &k))
	{
		if (n == 0 && k == 0)
		{
			break;
		}
		roman();
	}
	return 0;
}

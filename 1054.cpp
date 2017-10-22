#include <bits/stdc++.h>

using namespace std;

struct node
{
	char s[10];
	int p;
	int v;
} a[50];
vector<int> ans;
int n;
bool check(int now)
{
	int i;
	bool flag = false;
	int sum = 0;
	for (i = 0; i < n; ++i)
	{
		if (a[i].p == 0)
		{
			sum += a[i].v;
		}
		else if (a[i].p == 1)
		{
			if (flag)
			{
				if (sum % now != 0)
				{
					return false;
				}
			}
			flag = true;
			now += a[i].v;
			sum = 0;
		}
		else if (a[i].p == 2)
		{
			if (flag)
			{
				if (sum % now != 0)
				{
					return false;
				}
			}
			flag = true;
			now -= a[i].v;
			if (now <= 0)
			{
				return false;
			}
			sum = 0;
		}
	}
	return true;
}
int main()
{
	int i;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		for (i = 0; i < n; ++i)
		{
			scanf("%s%d", a[i].s, &a[i].v);
			if (strcmp(a[i].s, "PAY") == 0)
			{
				a[i].p = 0;
			}
			else if (strcmp(a[i].s, "IN") == 0)
			{
				a[i].p = 1;
			}
			else if (strcmp(a[i].s, "OUT") == 0)
			{
				a[i].p = 2;
			}
			else
			{
				a[i].p = -1;
			}
		}
		ans.clear();
		for (i = 1; i <= 100000; ++i)
		{
			if (check(i))
			{
				ans.push_back(i);
			}
		}
		if (ans.size() == 0)
		{
			printf("IMPOSSIBLE\n");
		}
		else if (ans[ans.size() - 1] == 100000)
		{
			printf("SIZE >= %d\n", ans[0]);
		}
		else
		{
			for (i = 0; i < ans.size(); ++i)
			{
				if (i)
				{
					printf(" ");
				}
				printf("%d", ans[i]);
			}
			puts("");
		}
	}
}

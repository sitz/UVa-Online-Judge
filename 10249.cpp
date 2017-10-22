#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

struct seat
{
	int val, id;
};
struct team
{
	int val, id;
};

bool cmp(seat a, seat b)
{
	return a.val > b.val;
};
bool cmp1(team a, team b)
{
	return a.val > b.val;
};

int main()
{
	bool flag;
	int m, n, tmp, tmp1;
	VVI ans;
	seat s[75];
	team t[75];

	while (scanf("%d%d", &m, &n) == 2, (m | n))
	{
		ans.assign(m, VI());
		flag = true;

		for (int i = 0; i < m; i++)
		{
			scanf("%d", &t[i].val);
			t[i].id = i + 1;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &s[i].val);
			s[i].id = i + 1;
		}

		sort(t, t + m, cmp1);
		sort(s, s + n, cmp);

		for (int i = 0; i < m; i++)
		{
			tmp = t[i].val;
			for (int j = 0; j < n; j++)
			{
				if (!tmp)
				{
					break;
				}
				if (s[j].val)
				{
					ans[t[i].id - 1].push_back(s[j].id);
					tmp--;
					s[j].val--;
				}
				else
				{
					continue;
				}
			}
			if (tmp)
			{
				flag = false;
				break;
			}
		}

		if (!flag)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
			for (int i = 0; i < m; i++)
			{
				sort(ans[i].begin(), ans[i].end());
				for (int j = 0; j < ans[i].size(); j++)
				{
					printf("%d ", ans[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int INF = 700000;
const int SZ = 780;

int arr[600100];
vector<int> vect[SZ];

void upd(int idx, int tmp, int li)
{
	int pos = idx / SZ;
	for (int i = 0; i < vect[pos].size(); i++)
	{
		if (vect[pos][i] == tmp)
		{
			vect[pos].erase(vect[pos].begin() + i);
			break;
		}
	}
	vect[pos].push_back(li);
	sort(vect[pos].begin(), vect[pos].end());
}

int query(int s, int e, int li)
{
	int pos1 = s / SZ, pos2 = e / SZ, tmp, cnt = 0;
	if (pos1 == pos2)
	{
		int cnt = 0;
		for (int i = s; i <= e; i++)
		{
			if (arr[i] <= li)
			{
				cnt++;
			}
		}
		return cnt;
	}
	pos1++;
	tmp = pos1 * SZ;
	for (int i = s; i < tmp; i++)
	{
		if (arr[i] <= li)
		{
			cnt++;
		}
	}
	tmp = pos2 * SZ;
	for (int i = tmp; i <= e; i++)
	{
		if (arr[i] <= li)
		{
			cnt++;
		}
	}
	for (int i = pos1; i < pos2; i++)
	{
		cnt += upper_bound(vect[i].begin(), vect[i].end(), li) - vect[i].begin();
	}
	return cnt;
}

int main()
{
	int n, m, k, s, e, tmp;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (int i = 0; i <= n + 2; i++)
		{
			arr[i] = INF;
		}
		while (m--)
		{
			scanf("%d", &k);
			if (k == 0)
			{
				scanf("%d%d", &s, &tmp);
				upd(s, arr[s], tmp);
				arr[s] = tmp;
			}
			else
			{
				scanf("%d%d%d", &s, &e, &tmp);
				printf("%d\n", query(s, e, tmp));
			}
		}
		for (int i = 0; i < SZ; i++)
		{
			vect[i].clear();
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool is[100005];
vector<int> p;

void pri()
{
	memset(is, false, sizeof(is));
	int i, j;
	p.clear();
	for (i = 2; i < 100005; i++)
	{
		if (!is[i])
		{
			for (j = i + i; j < 100005; j += i)
			{
				is[j] = true;
			}
			p.push_back(i);
		}
	}
}

int main()
{
	pri();
	int M, A, B, i, j, m;
	while (scanf(" %d %d %d", &M, &A, &B) == 3 && (M + A + B))
	{
		m = sqrt(M);
		int maxi = 0, ap, aq;
		for (i = 0; i < p.size() && p[i] <= m; i++)
		{
			for (j = i; j < p.size(); j++)
			{
				if (A * p[j] > B * p[i])
				{
					break;
				}
				if (p[i] * p[j] > M)
				{
					break;
				}
				if (p[i] * p[j] > maxi)
				{
					maxi = p[i] * p[j];
					ap = p[i];
					aq = p[j];
				}
			}
		}
		printf("%d %d\n", ap, aq);
	}
	return 0;
}

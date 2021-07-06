#include <bits/stdc++.h>

using namespace std;

vector<int> people;

int main()
{
	int N, k, m, lc, lw;
	while (1)
	{
		scanf("%d%d%d", &N, &k, &m);
		if (!N && !k && !m)
		{
			break;
		}
		people.clear();
		for (int i = 1; i <= N; i++)
		{
			people.push_back(i);
		}
		lc = 0;
		lw = N - 1;
		while (int(people.size()) > 0)
		{
			lc += k - 1;
			lw -= m - 1;
			while (lc >= people.size())
			{
				lc -= people.size();
			}
			while (lw < 0)
			{
				lw += people.size();
			}
			if (lc == lw)
			{
				printf("%3d", people[lc]);
				people.erase(people.begin() + lc);
				lw--;
			}
			else
			{
				printf("%3d%3d", people[lc], people[lw]);
				if (lc > lw)
				{
					people.erase(people.begin() + lc);
					lc--;
					people.erase(people.begin() + lw);
					lw--;
				}
				else
				{
					people.erase(people.begin() + lw);
					people.erase(people.begin() + lc);
					lw -= 2;
				}
			}
			if (int(people.size()) > 0)
			{
				printf(",");
			}
		}
		printf("10");
	}
	return 0;
}

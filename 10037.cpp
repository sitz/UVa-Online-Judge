#include <bits/stdc++.h>

using namespace std;

vector<int> people;

int main()
{
	int temp;
	bool first = true;
	int st;
	int N, total;
	int s1, s2;
	scanf("%d", &N);
	scanf("\n");
	for (int i = 0; i < N; i++)
	{
		people.clear();
		scanf("%d", &st);
		for (int j = 0; j < st; j++)
		{
			scanf("%d", &temp);
			people.push_back(temp);
		}
		if (first)
		{
			first = false;
		}
		else
		{
			putchar(10);
		}
		sort(people.begin(), people.end());
		if (st == 1)
		{
			printf("%d\n%d\n", people[0], people[0]);
			continue;
		}
		else if (st == 2)
		{
			printf("%d\n%d %d\n", people[1], people[0], people[1]);
			continue;
		}
		total = 0;
		if (st % 2 == 0)
		{
			for (int j = 1; j < st / 2; j++)
			{
				int score = min(people[2 * j + 1] + people[0] + people[1] * 2, people[0] * 2 + people[2 * j] + people[2 * j + 1]);
				total += score;
			}
			total += people[1];
			printf("%d\n", total);
			for (int j = st / 2 - 1; j > 0; j--)
			{
				if (people[2 * j + 1] + people[0] + people[1] * 2 <= people[0] * 2 + people[2 * j] + people[2 * j + 1])
				{
					printf("%d %d\n%d\n%d %d\n%d\n", people[0], people[1], people[0], people[2 * j], people[2 * j + 1], people[1]);
				}
				else
				{
					printf("%d %d\n%d\n%d %d\n%d\n", people[0], people[2 * j + 1], people[0], people[0], people[2 * j], people[0]);
				}
			}
			printf("%d %d\n", people[0], people[1]);
		}
		else if (st % 2 == 1)
		{
			for (int j = 2; j <= st / 2; j++)
			{
				int score = min(people[2 * j] + people[0] + people[1] * 2, people[0] * 2 + people[2 * j] + people[2 * j - 1]);
				total += score;
			}
			total += people[1] + people[0] + people[2];
			printf("%d\n", total);
			for (int j = st / 2; j > 1; j--)
			{
				if (people[2 * j] + people[0] + people[1] * 2 < people[0] * 2 + people[2 * j] + people[2 * j - 1])
				{
					printf("%d %d\n%d\n%d %d\n%d\n", people[0], people[1], people[0], people[2 * j - 1], people[2 * j], people[1]);
				}
				else
				{
					printf("%d %d\n%d\n%d %d\n%d\n", people[0], people[2 * j - 1], people[0], people[0], people[2 * j], people[0]);
				}
			}
			printf("%d %d\n%d\n%d %d\n", people[0], people[1], people[0], people[0], people[2]);
		}
	}
	return 0;
}

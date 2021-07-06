#include <bits/stdc++.h>

using namespace std;

#define NUM_PLAYERS 10
#define NUM_FEATURES 12

int P[NUM_PLAYERS + 1][NUM_FEATURES + 1];

long double getScore(const vector<int> &team)
{
	long double geoMean = 1.0;
	for (int i = 0; i < NUM_FEATURES; ++i)
	{
		int maxFeature = -1;
		for (int j = 0; j < team.size(); ++j)
		{
			if (P[team[j]][i] > maxFeature)
			{
				maxFeature = P[team[j]][i];
			}
		}
		geoMean *= double(maxFeature);
	}
	geoMean = pow(geoMean, 1.0 / double(NUM_FEATURES));
	return geoMean;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < NUM_PLAYERS; ++i)
		{
			for (int j = 0; j < NUM_FEATURES; ++j)
			{
				scanf("%d", &P[i][j]);
			}
		}
		int base_team[NUM_PLAYERS] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
		vector<vector<int>> teams;
		do
		{
			vector<int> team;
			for (int i = 0; i < NUM_PLAYERS; ++i)
			{
				if (base_team[i])
				{
					team.push_back(i);
				}
			}
			teams.push_back(team);
		} while (next_permutation(base_team, base_team + NUM_PLAYERS));
		int bestTeam = -1;
		long double maxScore = -1.0;
		for (int i = teams.size() - 1; i >= 0; --i)
		{
			const vector<int> &team = teams[i];
			long double currentScore = getScore(team);
			if (currentScore > maxScore)
			{
				bestTeam = i;
				maxScore = currentScore;
			}
		}
		bool first = true;
		for (int i = 0; i < teams[bestTeam].size(); ++i)
		{
			if (!first)
			{
				printf(" ");
			}
			else
			{
				first = false;
			}
			printf("%d", 4 + teams[bestTeam][i]);
		}
		printf("\n");
	}
	return 0;
}

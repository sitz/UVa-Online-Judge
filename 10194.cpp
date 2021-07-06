#include <bits/stdc++.h>

using namespace std;

bool issame(const char *t1, const char *t2)
{
	int len1 = strlen(t1), len2 = strlen(t2);
	if (len1 != len2)
	{
		return false;
	}
	for (int i = 0; i < len1; i++)
		if (toupper(t1[i]) != toupper(t2[i]))
		{
			return false;
		}
	return true;
}
//  be careful with the CASE INSENSITIVE COMPARISON
int compare(const char *t1, const char *t2)
{
	int i;
	for (i = 0; (t1[i] != '\0') && (t2[i] != '\0'); i++)
	{
		if (toupper(t1[i]) > toupper(t2[i]))
		{
			return 1;
		}
		else if (toupper(t1[i]) < toupper(t2[i]))
		{
			return -1;
		}
	}
	if (t1[i] == '\0')
	{
		if (t2[i] == '\0')
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return 1;
	}
}

struct TEAM
{
	//  name of teams
	char name[31];
	//  total points earned, game played, wins, ties, losses, goals scored, goals against
	int ttal;
	int game;
	int wins;
	int ties;
	int loss;
	int scor;
	int agan;
	//  initializing
	void init()
	{
		ttal = 0, game = 0, wins = 0, ties = 0, loss = 0, scor = 0, agan = 0;
	}
	friend bool operator<=(const TEAM &t1, const TEAM &t2)
	{
		if (t1.ttal != t2.ttal)
		{
			return (t1.ttal > t2.ttal);
		}
		if (t1.wins != t2.wins)
		{
			return (t1.wins > t2.wins);
		}
		if (t1.scor - t1.agan != t2.scor - t2.agan)
		{
			return (t1.scor - t1.agan > t2.scor - t2.agan);
		}
		if (t1.scor != t2.scor)
		{
			return (t1.scor > t2.scor);
		}
		if (t1.game != t2.game)
		{
			return (t1.game < t2.game);
		}
		return (compare(t1.name, t2.name) < 0);
	}
};

void merge_sort(TEAM array[], int begin_p, int end_p)
{
	if (begin_p >= end_p - 1)
	{
		return;
	}
	int temp = (end_p + begin_p) / 2, i, j, k;
	TEAM array2[end_p - begin_p];
	merge_sort(array, begin_p, temp);
	merge_sort(array, temp, end_p);
	for (i = begin_p, j = temp, k = 0; (i < temp) && (j < end_p); k++)
	{
		if (array[i] <= array[j])
		{
			array2[k] = array[i++];
		}
		else
		{
			array2[k] = array[j++];
		}
	}
	while (i < temp)
	{
		array2[k++] = array[i++];
	}
	while (j < end_p)
	{
		array2[k++] = array[j++];
	}
	copy(array2, array2 + end_p - begin_p, array + begin_p);
}

int main()
{
	//  number of tournaments, number of teams, number of games
	int num_of_tour, num_of_team, num_of_game;
	//  name of tournaments, game playing
	char name_of_tour[101], game_play[1001];
	//  information of teams
	TEAM info[30];
	int team1, team2, score1, score2;
	char *temp;
	cin >> num_of_tour, getchar();
	for (int cnt_tour = 0; cnt_tour < num_of_tour; cnt_tour++)
	{
		if (cnt_tour != 0)
		{
			printf("\n");
		}
		cin.getline(name_of_tour, 101, '\n');
		cin >> num_of_team, getchar();
		for (int cnt_team = 0; cnt_team < num_of_team; cnt_team++)
		{
			info[cnt_team].init(), cin.getline(info[cnt_team].name, 31, '\n');
		}
		cin >> num_of_game, getchar();
		for (int cnt_game = 0; cnt_game < num_of_game; cnt_game++)
		{
			cin.getline(game_play, 1001, '\n');
			temp = strtok(game_play, "#@");
			for (int i = 0; i < num_of_team; i++)
			{
				if (issame(info[i].name, temp))
				{
					team1 = i;
					break;
				}
			}
			temp = strtok(NULL, "#@");
			score1 = atoi(temp);
			temp = strtok(NULL, "#@");
			score2 = atoi(temp);
			temp = strtok(NULL, "#@");
			for (int i = 0; i < num_of_team; i++)
			{
				if (issame(info[i].name, temp))
				{
					team2 = i;
					break;
				}
			}
			info[team1].game++, info[team2].game++;
			info[team1].scor += score1, info[team2].scor += score2;
			info[team1].agan += score2, info[team2].agan += score1;
			if (score1 > score2)
			{
				info[team1].wins++, info[team2].loss++, info[team1].ttal += 3;
			}
			else if (score1 < score2)
			{
				info[team1].loss++, info[team2].wins++, info[team2].ttal += 3;
			}
			else
			{
				info[team1].ties++, info[team2].ties++, info[team1].ttal++, info[team2].ttal++;
			}
		}
		merge_sort(info, 0, num_of_team);
		printf("%s\n", name_of_tour);
		for (int i = 0; i < num_of_team; i++)
		{
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i + 1, info[i].name, info[i].ttal, info[i].game, info[i].wins, info[i].ties, info[i].loss, info[i].scor - info[i].agan, info[i].scor, info[i].agan);
		}
	}
	return 0;
}

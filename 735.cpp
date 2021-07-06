#include <bits/stdc++.h>

using namespace std;

const int Max_Pos = 20, Min = 0, Max_Posx3 = 60;
int C[181], P[181];
int Dart1, Dart2, Dart3, Score, PCount, Count;
bool Possible_Scores[80];
inline int Minimum(int i, int j)
{
	return (i < j) ? i : j;
}
int temp[3], len;
void Add(int v)
{
	for (int i = 0; i < len; i++)
		if (temp[i] == v)
		{
			return;
		}
	temp[len++] = v;
}
int main()
{
	Possible_Scores[50] = true;
	for (Dart1 = Min; Dart1 <= Max_Pos; Dart1++)
	{
		if (Dart1 <= 80)
		{
			Possible_Scores[Dart1] = true;
		}
		if (2 * Dart1 <= 80)
		{
			Possible_Scores[2 * Dart1] = true;
		}
		if (3 * Dart1 <= 80)
		{
			Possible_Scores[3 * Dart1] = true;
		}
	}
	for (Score = 1; Score <= 180; Score++)
	{
		PCount = Count = 0;
		int bound1, bound2, bound3;
		bound1 = Minimum(Score, Max_Posx3);
		for (Dart1 = Min; Dart1 <= bound1; Dart1++)
		{
			bound2 = Minimum(Score - Dart1, Max_Posx3);
			for (Dart2 = Dart1; Dart2 <= bound2; Dart2++)
			{
				bound3 = Minimum(Score - Dart1 - Dart2, Max_Posx3);
				for (Dart3 = Dart2; Dart3 <= bound3; Dart3++)
					if (Possible_Scores[Dart1] && Possible_Scores[Dart2] && Possible_Scores[Dart3] && Dart1 + Dart2 + Dart3 == Score)
					{
						Count++;
						len = 0;
						Add(Dart1);
						Add(Dart2);
						Add(Dart3);
						if (len == 3)
						{
							PCount += 6;
						}
						else if (len == 2)
						{
							PCount += 3;
						}
						else
						{
							PCount++;
						}
					}
			}
		}
		C[Score] = Count;
		P[Score] = PCount;
	}
	while (scanf("%d", &Score), Score > 0)
	{
		PCount = Count = 0;
		if (Score <= 180)
		{
			PCount = P[Score];
			Count = C[Score];
		}
		if (Count != 0)
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", Score, Count);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", Score, PCount);
		}
		else
		{
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", Score);
		}
		puts("**********************************************************************");
	}
	puts("END OF OUTPUT");
}

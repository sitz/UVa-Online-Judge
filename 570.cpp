#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int HIT[56] = {0};
	int ERR[56] = {0};
	int DIG[56] = {0};
	int KILL[56] = {0};
	int BLOCK[56] = {0};
	int GAMES[56] = {0};
	char key;
	int GameCount = 0;
	int CurrentPlayerNumber;
	while (cin >> key)
	{
		if (key == 'C')
		{
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> CurrentPlayerNumber;
				GAMES[CurrentPlayerNumber]++;
			}
			GameCount++;
			continue;
		}
		if (key == 'H')
		{
			cin >> CurrentPlayerNumber;
			HIT[CurrentPlayerNumber]++;
			continue;
		}
		if (key == 'K')
		{
			cin >> CurrentPlayerNumber;
			KILL[CurrentPlayerNumber]++;
			continue;
		}
		if (key == 'E')
		{
			cin >> CurrentPlayerNumber;
			ERR[CurrentPlayerNumber]++;
			continue;
		}
		if (key == 'B')
		{
			cin >> CurrentPlayerNumber;
			BLOCK[CurrentPlayerNumber]++;
			continue;
		}
		if (key == 'D')
		{
			cin >> CurrentPlayerNumber;
			DIG[CurrentPlayerNumber]++;
			continue;
		}
		//key == 'R'
		cout << "Player  Hit Pct    KPG      BPG      DPG" << endl;
		cout << "-----------------------------------------" << endl;
		for (int i = 0; i <= 55; i++)
			if (GAMES[i])
			{
				double HitPct = 0.0;
				if (KILL[i] + ERR[i] + HIT[i])
				{
					HitPct = double(KILL[i] - ERR[i]) / (KILL[i] + ERR[i] + HIT[i]);
				}
				double KPG = double(KILL[i]) / GAMES[i];
				double BPG = double(BLOCK[i]) / GAMES[i];
				double DPG = double(DIG[i]) / GAMES[i];
				printf("%02d      %+5.3f  % 7.3f  % 7.3f  % 7.3f", i, HitPct, KPG, BPG, DPG);
				cout << endl;
			}
		int SumBLOCK = 0;
		int SumKILL = 0;
		int SumERR = 0;
		int SumDIG = 0;
		int SumHIT = 0;
		for (int i = 0; i <= 55; i++)
			if (GAMES[i])
			{
				SumBLOCK += BLOCK[i];
				SumKILL += KILL[i];
				SumERR += ERR[i];
				SumDIG += DIG[i];
				SumHIT += HIT[i];
			}
		double HitPct = 0.0;
		if (SumKILL + SumERR + SumHIT)
		{
			HitPct = double(SumKILL - SumERR) / (SumKILL + SumERR + SumHIT);
		}
		double KPG = double(SumKILL) / GameCount;
		double BPG = double(SumBLOCK) / GameCount;
		double DPG = double(SumDIG) / GameCount;
		printf("team    %+5.3f  % 7.3f  % 7.3f  % 7.3f", HitPct, KPG, BPG, DPG);
		cout << endl
				 << endl;
		memset(HIT, 0, sizeof(HIT));
		memset(ERR, 0, sizeof(ERR));
		memset(DIG, 0, sizeof(DIG));
		memset(KILL, 0, sizeof(KILL));
		memset(BLOCK, 0, sizeof(BLOCK));
		memset(GAMES, 0, sizeof(GAMES));
		GameCount = 0;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct Card
{
	char suit;
	int rank;
};

struct ClockPatience
{
	char buf[100];
	int cntExposed, cntPile[14];
	Card card[52], pile[14][5];

	int readData();
	void dealtOut();
	void play();
	void outPut();
	void printCard();
} cp;

int ClockPatience::readData()
{
	int cntCard, loop;
	cntCard = 0;
	for (loop = 0; loop < 4; loop++)
	{
		cin.getline(buf, 100);
		if (!strcmp(buf, "#"))
		{
			return 0;
		}
		int index;
		for (index = 0; buf[index]; index++)
		{
			if (isalpha(buf[index]))
			{
				switch (buf[index])
				{
				case 'T':
					card[cntCard].rank = 10;
					break;
				case 'J':
					card[cntCard].rank = 11;
					break;
				case 'Q':
					card[cntCard].rank = 12;
					break;
				case 'K':
					card[cntCard].rank = 13;
					break;
				case 'A':
					card[cntCard].rank = 1;
					break;
				}
			}
			if (isdigit(buf[index]))
			{
				card[cntCard].rank = buf[index] - '0';
			}
			index++;
			card[cntCard].suit = buf[index];
			index++;
			cntCard++;
		}
	}
	return 1;
}

void ClockPatience::dealtOut()
{
	int level, loopCard, loop;
	loopCard = 51;
	for (level = 0; level < 4; level++)
	{
		int loopPile;
		for (loopPile = 1; loopPile <= 13; loopPile++)
		{
			pile[loopPile][level] = card[loopCard--];
		}
	}
	for (loop = 1; loop <= 13; loop++)
	{
		cntPile[loop] = 3;
	}
	cntExposed = 0;
}

void ClockPatience::play()
{
	Card now;
	now = pile[13][3];
	cntPile[13]--;
	cntExposed = 1;
	while (true)
	{
		if (cntPile[now.rank] < 0)
		{
			break;
		}
		//      cout<<now.rank<<now.suit<<endl;
		cntExposed++;
		Card tmp;
		tmp = pile[now.rank][cntPile[now.rank]--];
		now = tmp;
	}
	//print result:
	if (cntExposed > 9)
	{
		cout << cntExposed;
	}
	else
	{
		cout << "0" << cntExposed;
	}
	cout << ",";
	if (now.rank > 9 || now.rank == 1)
	{
		switch (now.rank)
		{
		case 1:
			cout << 'A';
			break;
		case 10:
			cout << 'T';
			break;
		case 11:
			cout << 'J';
			break;
		case 12:
			cout << 'Q';
			break;
		case 13:
			cout << 'K';
			break;
		}
	}
	else
	{
		cout << now.rank;
	}
	cout << now.suit << endl;
}

void ClockPatience::printCard()
{
	int loop;
	for (loop = 1; loop <= 13; loop++)
	{
		cout << "Pile " << loop << " : ";
		for (int j = 0; j < 4; j++)
		{
			cout << pile[loop][j].rank << pile[loop][j].suit << " ";
		}
		cout << endl;
	}
}

int main()
{
	while (cp.readData())
	{
		cp.dealtOut();
		cp.play();
	}
	return 0;
}

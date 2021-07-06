#include <bits/stdc++.h>

using namespace std;

char change_card[3], value[5], suit[5], rem_cards[13];
bool stay;
void input(char *s)
{
	// puts(s);
	for (int i = 0; i < 5; i++)
	{
		value[i] = s[3 * i];
		suit[i] = s[3 * i + 1];
	}
}
inline int encode(char c)
{
	if (c >= '2' && c <= '9')
	{
		return c - '1';
	}
	else if (c == 'A')
	{
		return 0;
	}
	else if (c == 'T')
	{
		return 9;
	}
	else if (c == 'J')
	{
		return 10;
	}
	else if (c == 'Q')
	{
		return 11;
	}
	else
	{
		return 12;
	}
}
inline char decode(int i)
{
	if (i >= 1 && i <= 8)
	{
		return i + '1';
	}
	else if (i == 0)
	{
		return 'A';
	}
	else if (i == 9)
	{
		return 'T';
	}
	else if (i == 10)
	{
		return 'J';
	}
	else if (i == 11)
	{
		return 'Q';
	}
	else
	{
		return 'K';
	}
}
inline double payment(int runs[])
{
	if (runs[5])
	{
		return 100.0;
	}
	if (runs[4])
	{
		return 10.0;
	}
	if (runs[3] && runs[2])
	{
		return 5.0;
	}
	if (runs[3])
	{
		return 3.0;
	}
	if (runs[2] == 2)
	{
		return 1.0;
	}
	return 0.0;
}
double can_get()
{
	int cards[13] = {0}, runs[6] = {0};
	int rest = 5;
	for (int i = 0; i < 5; i++)
	{
		cards[encode(value[i])]++;
	}
	//for(int i=0;i<13;i++)printf("%d ",cards[i]);
	int i, count = 0;
	for (i = 0; cards[i] != 0; i++)
		;
	while (rest)
	{
		if (cards[i])
		{
			count++;
			cards[i]--;
			rest--;
		}
		else if (count)
		{
			runs[count]++;
			count = 0;
		}
		i = (i + 1) % 13;
	}
	if (count)
	{
		runs[count]++;
	}
	//for(int i=0;i<=5;i++)printf("%d ",runs[i]);putchar(10);
	//printf("result%.1lf \n",payment(runs));
	return payment(runs);
}
inline double max(double a, double b)
{
	return a > b ? a : b;
}
double expectation(int x)
{
	char t = value[x];
	double best, res = 0.0;
	for (int i = 0; i < 13; i++)
		if (rem_cards[i])
		{
			value[x] = decode(i);
			best = can_get() - 1.0;
			res += (double)rem_cards[i] * best / 47;
		}
	value[x] = t;
	return res;
}
void solve()
{
	stay = true;
	double current = can_get();
	double expect;
	for (int i = 0; i < 13; i++)
	{
		rem_cards[i] = 4;
	}
	for (int i = 0; i < 5; i++)
	{
		rem_cards[encode(value[i])]--;
	}
	for (int i = 0; i < 5; i++)
	{
		expect = expectation(i);
		if (expect > current)
		{
			current = expect;
			change_card[0] = value[i];
			change_card[1] = suit[i];
			stay = false;
		}
	}
	change_card[2] = 0;
}
int main()
{
	char s[100];
	while (1)
	{
		gets(s);
		if (s[0] == '#')
		{
			break;
		}
		input(s);
		solve();
		if (stay)
		{
			printf("Stay\n");
		}
		else
		{
			printf("Exchange %s\n", change_card);
		}
	}
	return 0;
}

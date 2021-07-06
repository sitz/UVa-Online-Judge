#include <bits/stdc++.h>

using namespace std;

#define DIVINE 0
#define EVIL 1
#define HUMAN 2
#define DAY 0
#define NIGHT 1
#define MAXPERSONS 5
#define STATENUM 3 * 3 * 3 * 3 * 3 * 2
char state[STATENUM];
void init()
{
	for (int i = 0; i < STATENUM; i++)
	{
		state[i] = true;
	}
}
int type(int state, int p)
{
	state /= 2;
	while (p--)
	{
		state /= 3;
	}
	return state % 3;
}
int lying(int state, int p)
{
	int daynight = state % 2;
	int t = type(state, p);
	return (t == EVIL || (t == HUMAN && daynight == NIGHT));
}
void read()
{
	int i, neg, speaker, target, t, truth;
	char s[50];
	gets(s);
	speaker = s[0] - 'A';
	if (s[3] == 'I' && s[4] == 't')
	{
		for (i = 0; i < STATENUM; i++)
		{
			truth = ((i % 2 == DAY && s[9] == 'd') || (i % 2 == NIGHT && s[9] == 'n'));
			if (lying(i, speaker) == truth)
			{
				state[i] = 0;
			}
		}
		return;
	}
	if (s[5] == 'a')
	{
		target = speaker;
	}
	else
	{
		target = s[3] - 'A';
	}
	neg = (s[8] == 'n');
	switch (s[8 + 4 * neg])
	{
	case 'd':
		t = DIVINE;
		break;
	case 'h':
		t = HUMAN;
		break;
	case 'e':
		t = EVIL;
		break;
	case 'l':
		for (i = 0; i < STATENUM; i++)
		{
			truth = neg ^ lying(i, target);
			if (lying(i, speaker) == truth)
			{
				state[i] = 0;
			}
		}
		return;
	}
	for (i = 0; i < STATENUM; i++)
	{
		truth = neg ^ (type(i, target) == t);
		if (lying(i, speaker) == truth)
		{
			state[i] = 0;
		}
	}
	return;
}
void output()
{
	int deduction, i, j, possible[MAXPERSONS], daynight;
	char *names[] = {"divine", "evil", "human"};
	for (i = 0; i < MAXPERSONS; i++)
	{
		possible[i] = -1;
	}
	daynight = -1;
	for (i = 0; i < STATENUM; i++)
	{
		if (state[i])
		{
			if (daynight != -1 && daynight != i % 2)
			{
				daynight = -2;
			}
			else if (daynight == -1)
			{
				daynight = i % 2;
			}
			for (j = 0; j < MAXPERSONS; j++)
			{
				if (possible[j] != -1 && possible[j] != type(i, j))
					possible[j] =
							-2;
				else if (possible[j] == -1)
				{
					possible[j] = type(i, j);
				}
			}
		}
	}
	if (daynight == -1)
	{
		printf("This is impossible.\n\n");
		return;
	}
	deduction = 0;
	for (i = 0; i < MAXPERSONS; i++)
		if (possible[i] >= 0)
		{
			printf("%c is %s.\n", i + 'A', names[possible[i]]);
			deduction = 1;
		}
	if (daynight >= 0)
	{
		printf("It is %s.\n", daynight == DAY ? "day" : "night");
		deduction = 1;
	}
	if (!deduction)
	{
		printf("No facts are deducible.\n");
	}
	printf("\n");
}
int main()
{
	int n, count = 1;
	while (scanf("%d ", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		init();
		for (int i = 0; i < n; i++)
		{
			read();
		}
		printf("Conversation #%d\n", count++);
		output();
	}
}

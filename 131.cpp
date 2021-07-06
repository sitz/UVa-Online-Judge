#include <bits/stdc++.h>

using namespace std;

struct poke
{
	char f;
	char s;
	int v;
};

poke hand[5], deck[5], temp[5];

char Ans[][20] =
		{
				"straight-flush",
				"four-of-a-kind",
				"full-house",
				"flush",
				"straight",
				"three-of-a-kind",
				"two-pairs",
				"one-pair",
				"highest-card"};

int data[1100][5];
int c = 0;

void print_subset(int s, int n)
{
	for (int i = 0; i < n; ++i)
		if (s & 1 << i)
		{
			data[c][i] = 1;
		}
		else
		{
			data[c][i] = 0;
		}
	c++;
	return;
}

void subset(int n)
{
	for (int i = 0; i < 1 << n; ++i)
	{
		print_subset(i, n);
	}
	return;
}

void output(int ans)
{
	cout << "Hand: ";
	for (int i = 0; i < 5; ++i)
	{
		cout << hand[i].f << hand[i].s << " ";
	}
	cout << "Deck: ";
	for (int i = 0; i < 5; ++i)
	{
		cout << deck[i].f << deck[i].s << " ";
	}
	cout << "Best hand: ";
	cout << Ans[ans] << endl;
	return;
}

int cmp(const void *_a, const void *_b)
{
	poke *a = (poke *)_a;
	poke *b = (poke *)_b;
	return a->v - b->v;
}

bool is_straight_flush(poke p[])
{
	int v = p[0].v;
	char s = p[0].s;
	for (int i = 1; i < 5; ++i)
		if (p[i].s != s)
		{
			return false;
		}
	for (int i = 1; i < 4; ++i)
		if (p[i - 1].v + 1 != p[i].v)
		{
			return false;
		}
	if (v == 2 && p[4].v == 14)
	{
		return true;
	}
	if (p[4].v == p[3].v + 1)
	{
		return true;
	}
}

bool is_four_of_a_kind(poke p[])
{
	int cc1 = 0, cc2 = 0, v1 = p[0].v, v2 = p[4].v;
	for (int i = 0; i < 5; ++i)
		if (p[i].v == v1)
		{
			cc1++;
		}
		else if (p[i].v == v2)
		{
			cc2++;
		}
	return cc1 == 4 || cc2 == 4;
}

bool is_full_house(poke p[])
{
	int cc1 = 0, cc2 = 0, v1 = p[0].v, v2 = p[4].v;
	for (int i = 0; i < 5; ++i)
		if (p[i].v == v1)
		{
			cc1++;
		}
		else if (p[i].v == v2)
		{
			cc2++;
		}
	return (cc1 == 2 && cc2 == 3) || (cc1 == 3 && cc2 == 2);
}

bool is_flush(poke p[])
{
	char s = p[0].s;
	for (int i = 1; i < 5; ++i)
		if (p[i].s != s)
		{
			return false;
		}
	return true;
}

bool is_straight(poke p[])
{
	int v = p[0].v;
	for (int i = 1; i < 4; ++i)
		if (p[i - 1].v + 1 != p[i].v)
		{
			return false;
		}
	if (v == 2 && p[4].v == 14)
	{
		return true;
	}
	if (p[4].v == p[3].v + 1)
	{
		return true;
	}
	return false;
}

bool is_three_of_a_kind(poke p[])
{
	int cc1 = 0, cc2 = 0, v1 = p[0].v, v2 = p[4].v;
	for (int i = 0; i < 5; ++i)
		if (p[i].v == v1)
		{
			cc1++;
		}
		else if (p[i].v == v2)
		{
			cc2++;
		}
	return cc1 == 3 || cc2 == 3;
}

bool is_two_pairs(poke p[])
{
	int cc1 = 1, v = p[0].v;
	for (int i = 1; i < 5; ++i)
	{
		if (p[i - 1].v != p[i].v)
		{
			cc1++;
		}
	}
	return cc1 == 3;
}

bool is_one_pair(poke p[])
{
	int cc1 = 1, v = p[0].v;
	for (int i = 1; i < 5; ++i)
	{
		if (p[i - 1].v != p[i].v)
		{
			cc1++;
		}
	}
	return cc1 == 4;
}

int match(poke p[])
{
	if (is_straight_flush(p))
	{
		return 0;
	}
	if (is_four_of_a_kind(p))
	{
		return 1;
	}
	if (is_full_house(p))
	{
		return 2;
	}
	if (is_flush(p))
	{
		return 3;
	}
	if (is_straight(p))
	{
		return 4;
	}
	if (is_three_of_a_kind(p))
	{
		return 5;
	}
	if (is_two_pairs(p))
	{
		return 6;
	}
	if (is_one_pair(p))
	{
		return 7;
	}
	return 8;
}

int main()
{
	subset(5);
	char str[100];
	while (gets(str))
	{
		int c1 = 0, c2 = 0;
		int len = strlen(str);
		for (int i = 0; i < len; i += 3)
		{
			if (i < len / 2)
			{
				if (isalpha(str[i]))
				{
					switch (str[i])
					{
					case 'T':
						hand[c1].f = str[i];
						hand[c1].s = str[i + 1];
						hand[c1].v = 10;
						break;
					case 'J':
						hand[c1].f = str[i];
						hand[c1].s = str[i + 1];
						hand[c1].v = 11;
						break;
					case 'Q':
						hand[c1].f = str[i];
						hand[c1].s = str[i + 1];
						hand[c1].v = 12;
						break;
					case 'K':
						hand[c1].f = str[i];
						hand[c1].s = str[i + 1];
						hand[c1].v = 13;
						break;
					case 'A':
						hand[c1].f = str[i];
						hand[c1].s = str[i + 1];
						hand[c1].v = 14;
						break;
					}
				}
				else
				{
					hand[c1].v = str[i] - '0', hand[c1].s = str[i + 1], hand[c1].f = str[i];
				}
				c1++;
			}
			else
			{
				if (isalpha(str[i]))
				{
					switch (str[i])
					{
					case 'T':
						deck[c2].f = str[i];
						deck[c2].s = str[i + 1];
						deck[c2].v = 10;
						break;
					case 'J':
						deck[c2].f = str[i];
						deck[c2].s = str[i + 1];
						deck[c2].v = 11;
						break;
					case 'Q':
						deck[c2].f = str[i];
						deck[c2].s = str[i + 1];
						deck[c2].v = 12;
						break;
					case 'K':
						deck[c2].f = str[i];
						deck[c2].s = str[i + 1];
						deck[c2].v = 13;
						break;
					case 'A':
						deck[c2].f = str[i];
						deck[c2].s = str[i + 1];
						deck[c2].v = 14;
						break;
					}
				}
				else
				{
					deck[c2].v = str[i] - '0', deck[c2].s = str[i + 1], deck[c2].f = str[i];
				}
				c2++;
			}
		}
		int ans = 8;
		for (int i = 0; i < c; ++i)
		{
			int cc = 0;
			for (int j = 0; j < 5; ++j)
			{
				if (data[i][j])
				{
					temp[j] = deck[cc++];
				}
				else
				{
					temp[j] = hand[j];
				}
			}
			qsort(temp, 5, sizeof(poke), cmp);
			int t = match(temp);
			if (ans > t)
			{
				ans = t;
			}
			memset(temp, 0, sizeof(temp));
		}
		output(ans);
	}
	return 0;
}

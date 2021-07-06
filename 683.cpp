#include <bits/stdc++.h>

using namespace std;

char map_[26], zero[26], str[300], left_[10], right_[10][5], sign[10][5], s;
int len[10], l, p, i, ll, rl;

bool R(int depth, int choose, int sum);
bool L(int d, int carry)
{
	if (d == ll)
		return carry == 0;
	else
	{
		char c = left_[d], tempmap_[26];
		if (isdigit(c))
			return R(d, 0, carry);
		if (map_[c - 'A'] != -1)
			return R(d, 0, carry);
		for (int i = (zero[c - 'A']) ? 1 : 0; i < 10; i++)
		{
			map_[c - 'A'] = i;
			if (R(d, 0, carry))
				return true;
			map_[c - 'A'] = -1;
		}
		return false;
	}
}

bool R(int depth, int choose, int sum)
{
	if (choose == len[depth])
	{
		int value = isdigit(left_[depth]) ? left_[depth] - '0' : map_[left_[depth] - 'A'];
		if ((sum % 10) != value)
			return false;
		return L(depth + 1, sum / 10);
	}
	else
	{
		char c = right_[depth][choose];
		if (isdigit(c))
			return R(depth, choose + 1, sum + c - '0');
		if (map_[c - 'A'] != -1)
		{
			if (sign[depth][choose] == '+')
				return R(depth, choose + 1, sum + map_[c - 'A']);
			if (sign[depth][choose] == '-')
				return R(depth, choose + 1, sum - map_[c - 'A']);
		}
		for (int i = zero[c - 'A'] ? 1 : 0; i < 10; i++)
		{
			map_[c - 'A'] = i;
			if (sign[depth][choose] == '+' && R(depth, choose + 1, sum + i))
				return true;
			if (sign[depth][choose] == '-' && R(depth, choose + 1, sum - i))
				return true;
			map_[c - 'A'] = -1;
		}
		return false;
	}
}

int main()
{
	while (gets(str) != NULL && strcmp(str, "*") != 0)
	{
		memset(map_, 0xff, sizeof(map_));
		memset(len, 0, sizeof(len));
		memset(zero, 0, sizeof(zero));
		ll = rl = 0;
		for (p = 0; isalpha(str[p]) || isdigit(str[p]); p++, ll++)
			;
		bool first = true;
		for (i = 0; isalpha(str[i]) || isdigit(str[i]); i++)
		{
			left_[p - 1 - i] = str[i];
			if (first)
			{
				if (isalpha(str[i]))
					zero[str[i] - 'A'] = true;
				first = false;
			}
		}
		for (; !isalpha(str[p]) && !isdigit(str[p]); p++)
			;
		s = '+';
		while (str[p])
		{
			for (i = p, l = 0; isalpha(str[p]) || isdigit(str[p]); p++, l++)
				;
			bool first = true;
			for (; i < p; i++)
			{
				int x = p - i - 1;
				right_[x][len[x]] = str[i];
				sign[x][len[x]] = s;
				len[x]++;
				if (first)
				{
					if (isalpha(str[i]))
						zero[str[i] - 'A'] = 1;
					first = false;
				}
			}
			if (l > rl)
				rl = l;
			for (; str[p] != '+' && str[p] != '-' && str[p] != '\0'; p++)
				;
			if (str[p] == '+' || str[p] == '-')
				s = str[p];
			while (!isalpha(str[p]) && !isdigit(str[p]) && str[p] != '\0')
				p++;
		}

		for (int i = 0; i < rl; i++)
		{
			int order[10], loc;
			for (int j = 0; j < len[i]; j++)
				order[j] = -1;
			for (int j = 0; j < len[i]; j++)
			{
				for (loc = ll - 1; loc >= 0 && left_[loc] != right_[i][j]; loc--)
					;
				order[j] = loc;
			}
			for (int j = 0; j < len[i]; j++)
				for (int k = j + 1; k < len[i]; k++)
					if (order[j] < order[k])
					{
						swap(right_[i][j], right_[i][k]);
						swap(sign[i][j], sign[i][k]);
						swap(order[i], order[j]);
					}
		}

		if (!L(0, 0))
			puts("?");
		else
		{
			char c;
			for (int i = ll - 1; i >= 0; i--)
			{
				if (isalpha(left_[i]))
					printf("%c", map_[left_[i] - 'A'] + '0');
				else
					putchar(left_[i]);
			}
			puts("");
		}
	}
	return 0;
}

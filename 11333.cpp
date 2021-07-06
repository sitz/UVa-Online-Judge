#include <bits/stdc++.h>

using namespace std;

#define FOREACH(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

const int MAXN = 19;

char canBeZero[256];
long long power[MAXN], coef[256];
set<char> digits;

bool bruteforce()
{
	char assign[11];
	int k = 0;
	for (; k < 10 - digits.size(); ++k)
	{
		assign[k] = '*';
	}
	FOREACH(digits, c)
	{
		assign[k++] = *c;
	}
	assign[10] = 0;
	sort(assign, assign + 10);
	do
	{
		if (assign[0] != '*' and !canBeZero[assign[0]])
		{
			continue;
		}
		long long sum = 0;
		for (int i = 0; i < 10; ++i)
		{
			char digit = assign[i];
			if (digit == '*')
			{
				continue;
			}
			long long value = i;
			assert('A' <= digit and digit <= 'Z');
			sum += coef[digit] * value;
		}
		if (sum == 0)
		{
			puts(assign);
			return true;
		}
	} while (next_permutation(assign, assign + 10));
	return false;
}

int main()
{
	power[0] = 1;
	for (int i = 1; i < MAXN; ++i)
	{
		power[i] = power[i - 1] * 10;
	}
	string s;
	while (getline(cin, s))
	{
		for (char c = 'A'; c <= 'Z'; ++c)
		{
			canBeZero[c] = true;
			coef[c] = 0;
		}
		digits.clear();
		stringstream sin(s);
		int sign = +1;
		bool invert = false;
		while (sin >> s)
		{
			assert(s.size() <= 16);
			if (s == "+")
			{
				sign = +1;
				if (invert)
				{
					sign = -1;
				}
			}
			else if (s == "-")
			{
				sign = -1;
				if (invert)
				{
					sign = +1;
				}
			}
			else if (s == "=")
			{
				invert = true;
				sign = -1;
			}
			else
			{
				if (s.size() >= 2)
				{
					canBeZero[s[0]] = false;
				}
				reverse(s.begin(), s.end());
				for (int i = 0; i < s.size(); ++i)
				{
					assert('A' <= s[i] and s[i] <= 'Z');
					coef[s[i]] += power[i] * sign;
					digits.insert(s[i]);
				}
			}
		}
		if (!bruteforce())
		{
			for (int k = 0; k < 10; ++k)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}

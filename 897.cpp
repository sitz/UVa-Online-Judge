#include <bits/stdc++.h>

using namespace std;

enum
{
	MAX = 1000
};

bitset<MAX> p;

void sieve()
{
	p.flip();
	p[0] = p[1] = 0;
	for (int i = 2; i * i < MAX; i++)
		if (p[i])
			for (int j = i * i; j < MAX; j += i)
			{
				p[j] = 0;
			}
}

bool is_anagramatic_prime(int n)
{
	if (!p[n])
	{
		return false;
	}
	char str[16];
	int len = sprintf(str, "%d", n);
	sort(str, str + len);
	do
	{
		if (!p[atoi(str)])
		{
			return false;
		}
	} while (next_permutation(str, str + len));
	return true;
}

set<int> find_all_anagramatic_primes()
{
	set<int> anag;
	for (int i = 2; i < MAX; ++i)
		if (is_anagramatic_prime(i))
		{
			anag.insert(i);
		}
	return anag;
}

int max_value(set<int> &anag)
{
	return (*anag.rbegin());
}

int next_power_of_10(int lower)
{
	int upper = 1;
	while (upper <= lower)
	{
		upper = upper * 10;
	}
	return upper;
}

int main()
{
	sieve();
	set<int> anag = find_all_anagramatic_primes();
	int lower;
	while (scanf("%d", &lower) == 1)
	{
		if (lower == 0)
		{
			break;
		}
		if (lower > max_value(anag))
		{
			printf("0\n");
			continue;
		}
		int upper = next_power_of_10(lower);
		int next = *anag.lower_bound(lower + 1);
		if (next < upper)
		{
			printf("%d\n", next);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}

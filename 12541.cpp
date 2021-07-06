#include <bits/stdc++.h>

using namespace std;

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long

inline LL Power(int b, int p)
{
	LL ret = 1;
	for (int i = 1; i <= p; i++)
	{
		ret *= b;
	}
	return ret;
}

#define F(i, a, b) for (int i = (a); i < (b); i++)
#define Fs(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fe(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define Set(a, s) memset(a, s, sizeof(a))
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)

struct person
{
	char name[20];
	int day, month, year;
	person() {}
	person(char *n, int d, int m, int y)
	{
		strcpy(name, n);
		day = d;
		month = m;
		year = y;
	}
};

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		person youngest("", 0, 0, 0);
		person oldest("", 31, 12, 9999);
		person input;
		for (int i = 0; i < n; i++)
		{
			scanf("%s %d %d %d", input.name, &input.day, &input.month, &input.year);

			// youngest
			if (input.year > youngest.year)
				youngest = input;
			else if (input.year == youngest.year && input.month > youngest.month)
				youngest = input;
			else if (input.year == youngest.year && input.month == youngest.month && input.day > youngest.day)
				youngest = input;

			// oldest
			if (input.year < oldest.year)
				oldest = input;
			else if (input.year == oldest.year && input.month < oldest.month)
				oldest = input;
			else if (input.year == oldest.year && input.month == oldest.month && input.day < oldest.day)
				oldest = input;
		}
		printf("%s\n%s\n", youngest.name, oldest.name);
	}
	return 0;
}

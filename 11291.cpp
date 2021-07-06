#include <bits/stdc++.h>

using namespace std;

double calc(char *begin)
{
	if (isdigit(*begin) || *begin == '.' || *begin == '-')
	{
		return atof(begin);
	}
	else if (*begin == '(')
	{
		double rate, p1, p2, paren = 1;
		char *first = strchr(begin, ' ') + 1, *second;
		if (isdigit(*first) || *first == '.' || *first == '-')
		{
			second = strchr(first, ' ');
		}
		else
		{
			for (second = first + 1; paren != 0; ++second)
			{
				if (*second == '(')
				{
					++paren;
				}
				else if (*second == ')')
				{
					--paren;
				}
			}
		}
		++second;
		rate = atof(begin + 1);
		p1 = calc(first);
		p2 = calc(second);
		return rate * (p1 + p2) + (1 - rate) * (p1 - p2);
	}
}

int main()
{
	char *expr;
	string tmp;

	while (getline(cin, tmp) && tmp != "()")
	{
		expr = strdup(tmp.c_str());
		printf("%.2f\n", calc(expr));
		free(expr);
	}
}

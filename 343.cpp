#include <bits/stdc++.h>

using namespace std;

typedef long long big_int;

inline int CharToDigit(char c)
{
	if (isdigit(c))
		return c - '0';
	return c - 'A' + 10;
}

inline char DigitToChar(int n)
{
	return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n];
}

bool checkIllegal(int base1, string &in)
{
	for (int i = 0; i < in.length(); ++i)
		if (CharToDigit(in[i]) >= base1)
			return true;
	return false;
}

// convert string 'in' to int 'value'
big_int parseValue(int base, string &in)
{
	if (checkIllegal(base, in))
		return -1;
	big_int value = 0, curBase = 1;
	for (int i = in.length() - 1; i >= 0; --i)
	{
		value += CharToDigit(in[i]) * curBase;
		curBase *= base;
	}
	return value;
}

void match(string &num1, string &num2)
{
	for (int i = 2; i <= 36; ++i)
	{
		for (int j = 2; j <= 36; ++j)
		{
			big_int value1 = parseValue(i, num1);
			big_int value2 = parseValue(j, num2);
			if (value1 < 0 || value2 < 0)
				continue;
			if (value1 == value2)
			{
				printf("%s (base %d) = %s (base %d)\n", num1.c_str(), i, num2.c_str(), j);
				return;
			}
		}
	}
	// fail
	printf("%s is not equal to %s in any base 2..36\n", num1.c_str(), num2.c_str());
}

int main()
{
	string num1, num2;
	while (cin >> num1 >> num2)
		match(num1, num2);
	return 0;
}

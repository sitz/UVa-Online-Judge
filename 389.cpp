#include <bits/stdc++.h>

using namespace std;

inline int CharToDigit(char c)
{
	if (isdigit(c))
		return c - '0';
	return c - 'A' + 10;
}

inline char DigitToChar(int n)
{
	return "0123456789ABCDEF"[n];
}

// convert string 'in' to int 'value'
long long parseValue(int base1, string &in)
{
	long long value = 0, curBase = 1;
	for (int i = in.length() - 1; i >= 0; --i)
	{
		value += CharToDigit(in[i]) * curBase;
		curBase *= base1;
	}
	return value;
}

// convert int 'value' to string 'out'
string toBase(int base2, long long value)
{
	if (value == 0)
		return "0";
	string out;
	while (value > 0)
	{
		out += DigitToChar(value % base2);
		value /= base2;
	}
	reverse(out.begin(), out.end());
	return out;
}

string convert(string &in, int base1, int base2)
{
	string out = toBase(base2, parseValue(base1, in));
	if (out.length() > 7)
		return "ERROR";
	return out;
}

int main()
{
	int base1, base2;
	string in;
	while (cin >> in >> base1 >> base2)
		printf("%7s\n", convert(in, base1, base2).c_str());
	return 0;
}

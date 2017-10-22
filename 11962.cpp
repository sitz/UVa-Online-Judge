#include <bits/stdc++.h>

using namespace std;

long long pow_(int a, int b)
{
	long long res = 1;
	while (b--)
	{
		res *= a;
	}
	return res;
}

long long calc(string &input, int start)
{
	long long res = 0;
	if (start == input.size() - 1)
	{
		switch (input[start])
		{
		case 'A':
			return 0;
		case 'C':
			return 1;
		case 'G':
			return 2;
		case 'T':
			return 3;
		}
	}
	switch (input[start])
	{
	case 'A':
		res = calc(input, start + 1);
		break;
	case 'C':
		res = pow_(4, input.size() - start - 1) + calc(input, start + 1);
		break;
	case 'G':
		res = 2 * pow_(4, input.size() - start - 1) + calc(input, start + 1);
		break;
	case 'T':
		res = 3 * pow_(4, input.size() - start - 1) + calc(input, start + 1);
		break;
	}
	return res;
}

int main()
{
	int t;
	string input;
	cin >> t;
	cin.ignore(100, '\n');
	for (int i = 0; i < t; i++)
	{
		getline(cin, input);
		cout << "Case " << i + 1 << ": (" << input.size() << ":" << calc(input, 0) << ")" << endl;
	}
	return 0;
}

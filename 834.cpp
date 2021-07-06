#include <bits/stdc++.h>

using namespace std;

int main()
{
	bool first;
	unsigned int numerator, denominator;
	while (cin >> numerator >> denominator)
	{
		first = true;
		cout << "[" << numerator / denominator;
		if (numerator % denominator == 0)
		{
			cout << "]" << endl;
			continue;
		}
		if (numerator > denominator)
		{
			numerator = numerator - denominator * (numerator / denominator);
		}
		do
		{
			if (first)
			{
				cout << ";";
				first = false;
			}
			else
			{
				cout << ",";
			}
			swap(numerator, denominator);
			cout << numerator / denominator;
			numerator = numerator - denominator * (numerator / denominator);
		} while (denominator != 1);
		cout << "]" << endl;
	}
	return 0;
}

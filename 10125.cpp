#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &set)
{
	for (int d = set.size() - 1; d >= 0; --d) // find the largest d
	{
		for (int a = 0; a < set.size(); ++a)
		{
			for (int b = a + 1; b < set.size(); ++b)
			{
				for (int c = b + 1; c < set.size(); ++c)
				{
					if ((set[d] == set[a] + set[b] + set[c]) &&
							a != d && b != d && c != d)
					{
						return set[d];
					}
				}
			}
		}
	}
	return INT_MAX;
}

int main()
{
	int numElement;
	while (cin >> numElement)
	{
		if (numElement == 0)
		{
			break;
		}
		/* input */
		vector<int> set(numElement);
		for (int i = 0; i < numElement; ++i)
		{
			cin >> set[i];
		}
		sort(set.begin(), set.end());
		/* find d = a + b + c */
		int d = find(set);
		if (d == INT_MAX)
		{
			cout << "no solution\n";
		}
		else
		{
			cout << d << "\n";
		}
	}
	return 0;
}

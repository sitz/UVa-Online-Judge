#include <bits/stdc++.h>

using namespace std;

int cache[101][101];

int getDistance(const string &s1, const string &s2, int i, int j)
{
	if (cache[i][j] != -1)
	{
		return cache[i][j];
	}
	else if (i == 0)
	{
		cache[i][j] = j;
	}
	else if (j == 0)
	{
		cache[i][j] = i;
	}
	else if (s1[i - 1] == s2[j - 1])
	{
		cache[i][j] = getDistance(s1, s2, i - 1, j - 1);
	}
	else
	{
		cache[i][j] = min(min(1 + getDistance(s1, s2, i - 1, j - 1),
													1 + getDistance(s1, s2, i - 1, j)),
											1 + getDistance(s1, s2, i, j - 1));
	}

	return cache[i][j];
}

int main()
{
	int tests = 0;
	cin >> tests;

	cin.ignore();

	string s1, s2;

	while (tests--)
	{
		for (int i = 0; i < 101; ++i)
		{
			for (int j = 0; j < 101; ++j)
			{
				cache[i][j] = -1;
			}
		}

		getline(cin, s1);
		getline(cin, s2);

		int distance = getDistance(s1, s2, s1.length(), s2.length());
		cout << distance << endl;
	}

	return 0;
}

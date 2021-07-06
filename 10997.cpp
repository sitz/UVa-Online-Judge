#include <bits/stdc++.h>

using namespace std;

int numOfCountry, canada;
double N = 100;

struct Country
{
	char name[50];
	int g, s, b;
} country[256];

void Input()
{
	canada = -1;
	for (int i = 0; i < numOfCountry; i++)
	{
		cin >> country[i].name >> country[i].g >> country[i].s >> country[i].b;
		if (!strcmp(country[i].name, "Canada"))
		{
			canada = i;
		}
	}
}

bool Win(double j, double k, double l)
{
	double caScore = j * country[canada].g + k * country[canada].s + l * country[canada].b;
	double best = -1;
	for (int i = 0; i < numOfCountry; i++)
	{
		if (i == canada)
		{
			continue;
		}
		double score = j * country[i].g + k * country[i].s + l * country[i].b;
		if (score > best)
		{
			best = score;
		}
	}
	return caScore >= best;
}

void Solve()
{
	int j, k, l;
	for (j = 0; j <= 0; j++)
		for (k = -2; k <= 2; k++)
			for (l = -3; l <= 3; l++)
			{
				if (Win(pow(N, (double)-j), pow(N, (double)-k), pow(N, (double)-l)))
				{
					cout << "Canada wins!" << endl;
					return;
				}
			}
	cout << "Canada cannot win." << endl;
}

int main()
{
	while (cin >> numOfCountry && numOfCountry)
	{
		Input();
		if (canada < 0)
		{
			cout << "Canada cannot win." << endl;
		}
		else
		{
			Solve();
		}
	}
	return 0;
}

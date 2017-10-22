#include <bits/stdc++.h>

using namespace std;

#define MAXN 200

struct point
{
	double x, y;
};

point chips[MAXN], center, median;
int totalChips;

int chipsInCutter()
{
	int nCount = 0;
	for (int i = 0; i < totalChips; i++)
	{
		double distance = sqrt(pow(chips[i].x - center.x, 2) +
													 pow(chips[i].y - center.y, 2));
		if (distance <= 2.50)
		{
			nCount++;
		}
	}
	return nCount;
}

int main(int ac, char *av[])
{
	istringstream iss;
	string line;
	int cases;
	bool printEmptyLine = false;
	cin >> cases;
	cin.ignore();
	getline(cin, line);
	while (cases--)
	{
		totalChips = 0;
		while (getline(cin, line), line.length())
		{
			iss.clear();
			iss.str(line);
			iss >> chips[totalChips].x >> chips[totalChips].y;
			totalChips++;
		}
		int maxChips = 1;
		for (int i = 0; i < totalChips - 1; i++)
			for (int j = i + 1; j < totalChips; j++)
			{
				double distance = sqrt(pow(chips[i].x - chips[j].x, 2) +
															 pow(chips[i].y - chips[j].y, 2));
				if (distance > 5.0)
				{
					continue;
				}
				if (chips[i].x == chips[j].x)
				{
					center.x = chips[i].x + sqrt(2.50 * 2.50 -
																			 pow(fabs(chips[i].y - chips[j].y) / 2.0, 2));
					center.y = (chips[i].y + chips[j].y) / 2.0;
					maxChips = max(maxChips, chipsInCutter());
					center.x = chips[i].x - sqrt(2.50 * 2.50 -
																			 pow((chips[i].y - chips[j].y) / 2.0, 2));
					maxChips = max(maxChips, chipsInCutter());
					continue;
				}
				if (chips[i].y == chips[j].y)
				{
					center.x = (chips[i].x + chips[j].x) / 2.0;
					center.y = chips[i].y + sqrt(2.50 * 2.50 -
																			 pow(fabs(chips[i].x - chips[j].x) / 2.0, 2));
					maxChips = max(maxChips, chipsInCutter());
					center.y = chips[i].y - sqrt(2.50 * 2.50 -
																			 pow(fabs(chips[i].x - chips[j].x) / 2.0, 2));
					maxChips = max(maxChips, chipsInCutter());
					continue;
				}
				point median;
				median.x = (chips[i].x + chips[j].x) / 2.0;
				median.y = (chips[i].y + chips[j].y) / 2.0;
				double slope = -(chips[j].x - chips[i].x) /
											 (chips[j].y - chips[i].y);
				double segment = sqrt(2.50 * 2.50 -
															(pow(chips[i].x - chips[j].x, 2) +
															 pow(chips[i].y - chips[j].y, 2)) /
																	4.0);
				double A = atan(slope);
				center.x = median.x + segment * cos(A);
				center.y = median.y + segment * sin(A);
				maxChips = max(maxChips, chipsInCutter());
				center.x = median.x - segment * cos(A);
				center.y = median.y - segment * sin(A);
				maxChips = max(maxChips, chipsInCutter());
			}
		if (printEmptyLine)
		{
			cout << endl;
		}
		else
		{
			printEmptyLine = true;
		}
		cout << maxChips << endl;
	}
	return 0;
}

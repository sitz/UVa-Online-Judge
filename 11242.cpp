#include <bits/stdc++.h>

using namespace std;

// calc all poss ratios and place them in an arr[]
// sort ratios[]
// loop over the arr[] and calc spread between each two adjacent ratios
// get max val among those
// forgetting to fix the decimal places gives WA
// rst indices on each input

double ratio_[100], maxSpread;
int front[10], nFront, rear[10], nRear, ratioI;

int main()
{
	while (cin >> nFront)
	{
		if (nFront == 0)
		{
			break;
		}
		cin >> nRear;
		for (int i = 0; i < nFront; ++i)
		{
			cin >> front[i];
		}
		for (int i = 0; i < nRear; ++i)
		{
			cin >> rear[i];
		}
		ratioI = 0;
		for (int i = 0; i < nFront; ++i)
		{
			for (int j = 0; j < nRear; ++j)
			{
				ratio_[ratioI++] = 1.0 * rear[j] / front[i];
			}
		}
		sort(&ratio_[0], &ratio_[ratioI]);
		maxSpread = 0;
		for (int i = 0; i < ratioI - 1; ++i)
		{
			maxSpread = max(maxSpread, ratio_[i + 1] / ratio_[i]);
		}
		cout << fixed << setprecision(2) << round(maxSpread * 100) / 100 << endl;
	}
	return 0;
}

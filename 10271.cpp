#include <bits/stdc++.h>

using namespace std;

#define NCHOPSTICKS 5000

int main()
{
	int nc;												 /* number of cases */
	int nge;											 /* numger of guests */
	int nch;											 /* number of chopsticks */
	int diff[NCHOPSTICKS + 1];		 /* smallest differences between chopsticks */
	int chop[NCHOPSTICKS + 1];		 /* chopsticks */
	long badness[NCHOPSTICKS + 1]; /* badness for each pair of chopsticks */
	cin >> nc;
	for (int t = 0; t < nc; t++)
	{
		cin >> nge >> nch;
		nge += 8; /* add family members */
		diff[0] = 0;
		for (int i = 0; i < nch; i++)
		{
			cin >> chop[i + 1];
			diff[i + 1] = 0;
			/* calculate badness as (A-B)^2 */
			badness[i + 1] = pow(chop[i + 1] - chop[i], 2);
		}
		/* dynamic programming */
		for (int i = 1; i <= nge; i++)
		{
			for (int j = (nch - 3 * (nge - i) - 1); j >= 2 * i; j--)
			{
				diff[j] = diff[j - 2] + badness[j];
			}
			/* find the neighbouring pairs with smallest difference */
			for (int j = (2 * i) + 1; j <= (nch - 3 * (nge - i) - 1); j++)
			{
				if (diff[j - 1] < diff[j])
				{
					diff[j] = diff[j - 1];
				}
			}
			/* the third chopstick */
			diff[nch - 3 * (nge - i)] = diff[nch - 3 * (nge - i) - 1];
		}
		cout << diff[nch] << endl;
	}
	return 0;
}

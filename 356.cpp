#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int f = 0;
	while (cin >> n)
	{
		if (f)
		{
			cout << endl;
		}
		f = 1;
		int cmp = 0, k;
		double r = (2 * (double)n - 1) / 2;
		for (k = 1; k < n; k++)
		{
			cmp += (int)sqrt(r * r - (double)(k * k));
		}
		printf("In the case n = %d, %d cells contain segments of the circle.\n", n, 8 * n - 4);
		printf("There are %d cells completely contained in the circle.\n", 4 * cmp);
	}
	return 0;
}

//Reference to Concrete Mathematics [Knuth] Exercise 3.33

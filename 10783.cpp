#include <bits/stdc++.h>

using namespace std;

int numOfCase;

int main()
{
	int leftRange, rightRange;
	while (cin >> numOfCase)
	{
		int kase;
		for (kase = 0; kase < numOfCase; kase++)
		{
			cin >> leftRange >> rightRange;
			int index, sum = 0;
			for (index = leftRange; index <= rightRange; index++)
				if (index % 2 == 1)
				{
					sum += index;
				}
			cout << "Case " << kase + 1 << ": " << sum << endl;
		}
	}
	return 0;
}

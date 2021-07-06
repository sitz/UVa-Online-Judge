#include <bits/stdc++.h>

using namespace std;

int main()
{
	int numOfFriends, numOfBox, kase, k;
	int cho;
	cin >> kase;
	while (kase)
	{
		kase--;
		cin >> numOfFriends >> numOfBox;
		int t, sum = 0;
		for (t = 0; t < numOfBox; t++)
		{
			cin >> k;
			int i, r = 1;
			for (i = 0; i < k; i++)
			{
				cin >> cho;
				r = (r * (cho % numOfFriends)) % numOfFriends;
			}
			sum += r;
		}
		cout << sum % numOfFriends << endl;
	}
	return 0;
}

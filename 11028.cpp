#include <bits/stdc++.h>

using namespace std;

int main()
{
	int val[] = {0, 0, 1, 1, 3, 8, 21, 43, 69, 102, 145, 197, 261, 336, 425, 527, 645, 778, 929, 1097, 1285};
	for (int i = 1;; i++)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		cout << "Case #" << i << ": " << val[n] << endl;
	}
	return 0;
}

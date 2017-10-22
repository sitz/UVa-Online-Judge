#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, t, l, i, j;
	int array[100];
	cin >> n;
	for (t = 0; t < n; t++)
	{
		cin >> l;
		int cnt = 0, tmp;
		for (i = 0; i < l; i++)
		{
			cin >> array[i];
		}
		for (i = 1; i < l; i++)
			for (j = 1; j < l; j++)
				if (array[j] < array[j - 1])
				{
					tmp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = tmp;
					cnt++;
				}
		cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
	}
	return 0;
}

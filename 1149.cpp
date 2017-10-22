#include <bits/stdc++.h>

using namespace std;

int n, l, L[100010];

int main()
{
	int i, j, count, T;
	cin >> T;
	int a = 0;
	while (T--)
	{
		a++;
		scanf("%d", &n);
		scanf("%d", &l);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &L[i]);
		}
		sort(L, L + n);
		count = 0;
		int j = 0;
		for (i = n - 1; i >= 0, i >= j; i--)
		{
			if (L[i] != -1)
			{
				count++;
				int num = l - L[i];
				L[i] = -1;
				if (L[j] != -1 && L[j] <= num)
				{
					L[j++] = -1;
				}
			}
		}
		if (a != 1)
		{
			cout << endl;
		}
		cout << count << endl;
	}
	return 0;
}

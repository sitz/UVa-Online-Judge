#include <bits/stdc++.h>

using namespace std;

int numOfInteger, numOfQuery, kase = 1, arr[1001];

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void solve(int value)
{
	int min_, record, i, j;
	min_ = 0x7fffffff;
	for (i = 0; i < numOfInteger - 1; i++)
		for (j = i + 1; j < numOfInteger; j++)
		{
			int sum;
			sum = arr[i] + arr[j];
			if (fabs(value - sum) < min_)
			{
				min_ = (int)fabs(value - sum);
				record = sum;
			}
		}
	cout << "Closest sum to " << value << " is " << record << "." << endl;
}

int main()
{
	while (cin >> numOfInteger && numOfInteger)
	{
		cout << "Case " << kase++ << ":" << endl;
		int index, value;
		for (index = 0; index < numOfInteger; index++)
		{
			cin >> arr[index];
		}
		qsort(arr, numOfInteger, sizeof(int), cmp);
		cin >> numOfQuery;
		while (numOfQuery--)
		{
			cin >> value;
			solve(value);
		}
	}
	return 0;
}

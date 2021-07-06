#include <bits/stdc++.h>

using namespace std;

int arr[1000000];

int qsort_cmp(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
	{
		return 1;
	}
	else if (*(int *)a == *(int *)b)
	{
		return 0;
	}
	else if (*(int *)a < *(int *)b)
	{
		return -1;
	}
}

int bin_srch(int key, int n)
{
	int low, high, mid;
	low = 0;
	high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == arr[mid])
		{
			while (arr[mid] == arr[mid - 1])
			{
				mid--;
			}
			return mid;
		}
		else if (key < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int N, Q, kase = 1, i, key, tmp;
	while (cin >> N >> Q)
	{
		if (N == 0 && Q == 0)
		{
			break;
		}
		cout << "CASE# " << kase++ << ":" << endl;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		qsort(arr, N, sizeof(int), qsort_cmp);
		for (i = 0; i < Q; i++)
		{
			cin >> key;
			tmp = bin_srch(key, N);
			if (tmp < 0)
			{
				cout << key << " not found" << endl;
			}
			else
			{
				cout << key << " found at " << tmp + 1 << endl;
			}
		}
	}
	return 0;
}

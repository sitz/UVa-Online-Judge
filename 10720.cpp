#include <bits/stdc++.h>

using namespace std;

int main()
{
	setvbuf(stdin, NULL, _IOFBF, 10000);
	setvbuf(stdout, NULL, _IOFBF, 10000);
	int n;
	int arr[10240];// Degree sequence
	int c[10240];	// Conjugate sequence (as per exercise 105, Chapter 7 of TAOCP)
	while (scanf("%d", &n) == 1 && n)
	{
		int parity = 0;
		bool possible = true;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			parity ^= arr[i] & 1;
			if (arr[i] >= n)
			{
				possible = false;
			}
		}
		if (possible && !parity)
		{
			sort(arr, arr + n);
			int curr = n;
			int run_len = 1;
			int idx = 0;
			int x = 0;
			for (int i = 1; i < n; ++i)
			{
				if (arr[i] != arr[i - 1])
				{
					for (int j = 0; j < arr[i - 1] - x; ++j)
					{
						c[idx++] = curr;
					}
					curr -= run_len;
					run_len = 0;
					x = arr[i - 1];
				}
				++run_len;
			}
			for (; idx < arr[n - 1]; ++idx)
			{
				c[idx] = curr;
			}
			reverse(arr, arr + n);
			int d_sum = 0;// degree sum
			int c_sum = 0;// conjugate sum
			for (int i = 0; i < n; ++i)
			{
				if (arr[i] < i + 1)
				{
					break;
				}
				d_sum += arr[i];
				c_sum += c[i];
				if (d_sum > c_sum - (i + 1))
				{
					possible = false;
					break;
				}
			}
		}
		if (!possible || parity)
		{
			puts("Not possible");
		}
		else
		{
			puts("Possible");
		}
	}
	return 0;
}

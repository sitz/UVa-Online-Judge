#include <bits/stdc++.h>

using namespace std;

bool p[1000010];
int prime[80000], numOfPrime = 0;
int amount, kase = 1;

void sieve()
{
	int i, j;
	memset(p, 1, sizeof(p));
	p[0] = p[1] = false;
	for (i = 2; i <= 1000;)
	{
		for (j = i + i; j <= 1000000; j += i)
		{
			p[j] = false;
		}
		for (i++; !p[i]; i++)
			;
	}
	for (i = 0; i < 1000000; i++)
		if (p[i])
		{
			prime[numOfPrime++] = i;
		}
}

int bin_search(int key)
{
	int low, mid, high;
	low = 0;
	high = numOfPrime - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == prime[mid])
		{
			return mid;
		}
		else if (key < prime[mid])
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

void solve()
{
	int index, cnt = 0;
	for (index = 0; prime[index] <= amount / 2; index++)
	{
		int tail;
		for (tail = amount - prime[index];; tail--)
		{
			int th;
			th = bin_search(tail);
			if (th >= 0)
			{
				cnt += th - index;
				break;
			}
		}
	}
	cout << cnt << endl;
}

int main()
{
	sieve();
	while (cin >> amount && amount)
	{
		cout << "Case " << kase++ << ": ";
		solve();
	}
	return 0;
}

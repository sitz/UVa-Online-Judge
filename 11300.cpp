#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000001
#define u64 unsigned long long
#define i64 long long
#define rep(i, n) for (i = 0; i < (n); i++)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define mabs(x) (((x) < 0) ? (-x) : (x))

int n;
u64 a[MAXN];
i64 A[MAXN];
u64 sum, per;

int get_random(int a, int b)//returns a random number between a & b
{
	int x = rand();
	int y = b - a;
	x = (int)((x / (double)RAND_MAX) * y) + a;
	if (x < a)
	{
		x = a;
	}
	if (x > b)
	{
		x = b;
	}
	return x;
}

// partition the array A[p], A[p+1] ... A[r] in such a way so that
// all the elements left to the pivot element are smaller than it and all the elements right to it are larger than it
// return the pivot element's index
int partition(int p, int r)
{
	int x = A[r];
	int i, j;
	i = p - 1;
	for (j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

// same functionality as partition(), but selects the pivot element randomly so that no particular input can always expose the O(n^2) worst case behaviour
int randomized_partition(int p, int r)
{
	int i = get_random(p, r);
	swap(A[r], A[i]);
	return partition(p, r);
}

// select the i-th element largest from the array A[p], A[p+1] ... A[r]
i64 randomized_select(int p, int r, int i)
{
	if (p == r)
	{
		return A[p];
	}
	int q = randomized_partition(p, r);
	int k = q - p + 1;
	if (i == k)
	{
		return A[q];
	}
	else if (i < k)
	{
		return randomized_select(p, q - 1, i);
	}
	else
	{
		return randomized_select(q + 1, r, i - k);
	}
}

int main()
{
	int i;
	u64 res;
	i64 mid;
	srand(time(NULL));
	while (scanf(" %d", &n) == 1)
	{
		sum = 0;
		rep(i, n)
		{
			scanf(" %llu", &a[i]);
			sum += a[i];
		}
		per = sum / n;
		rep(i, n) A[i] = (i64)per - (i64)a[i];
		for (i = n - 2; i > 0; i--)
		{
			A[i] = A[i + 1] + A[i];
		}
		A[0] = 0;
		//sort(A, A+n);
		//mid = ( A[n/2] + A[(n-1)/2] ) / 2;
		mid = randomized_select(0, n - 1, n / 2 + 1);
		mid += randomized_select(0, n - 1, (n - 1) / 2 + 1);
		mid /= 2;
		res = 0;
		rep(i, n)
		{
			A[i] -= mid;
			res += mabs(A[i]);
		}
		printf("%llu\n", res);
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define mx 200015

typedef long long i64;

int arr[mx], kas = 0;
i64 res, First, Second;
int n;

void call()
{
	sort(arr, arr + n);
	queue<int> Q;
	for (int i = 0, j = 0; i < n && arr[i] <= 180000; i++)
	{
		if (arr[i] >= 180000)
			return;
		while (j < n && arr[j] <= arr[i] + 180000)
			Q.push(arr[j]), j++;
		while (!Q.empty() && Q.front() <= arr[i])
			Q.pop();
		i64 temp1 = Q.size(), temp2 = n - temp1 - 1;
		if (j > 0 && arr[j - 1] == arr[i] + 180000)
			temp1--, Second += temp1 + temp2;
		First += (temp1 * (temp1 - 1) / 2) + (temp2 * (temp2 - 1) / 2);
	}
}

int main()
{
	int r;
	while (scanf("%d %d", &n, &r) == 2)
	{
		if (!n)
			break;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d.%d", &x, &y);
			arr[i] = x * 1000 + y;
		}
		First = Second = 0, res = (i64(n) * (n - 1) * (n - 2)) / 6;
		call();
		for (int i = 0; i < n; i++)
			arr[i] = (arr[i] + 180000) % 360000;
		call();
		First >>= 1, Second >>= 1;
		res -= (First + Second);
		printf("Case %d: %lld\n", ++kas, res);
	}
	return 0;
}

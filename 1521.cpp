#include <bits/stdc++.h>

using namespace std;

/* **********************************************
Author      : JayYe
Created Time: 2013-9-10 16:12:01
File Name   : JayYe.cpp
*********************************************** */

const int maxn = 10000 + 10;

bool vis[maxn];
int a[maxn];

void get_prime()
{
	vis[1] = 1;
	for (int i = 2; i * i <= 10000; i++)
		if (!vis[i])
			for (int j = i * i; j <= 10000; j += i)
				vis[j] = 1;
}

int main()
{
	get_prime();
	int n;
	while (scanf("%d", &n) != -1)
	{
		int sum = 0;
		for (int i = 2; i <= n; i++)
			if (!vis[i])
				a[++sum] = i;
		int l = 1, r = sum;
		int ans = 0;
		while (l <= r)
		{
			ans++;
			int cur = a[r];
			while (l < r && cur * a[l] <= n)
				cur *= a[l++];
			r--;
		}
		printf("%d\n", ans);
	}
	return 0;
}

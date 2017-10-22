#include <bits/stdc++.h>

using namespace std;

const int maxn = 5001;
int n, a[maxn], b[maxn];
bool check(int k)
{
	int suma = 0, sumb = 0, count = 0, coua = 0, coub = 0;
	for (int i = 0; i < n; i++)
	{
		suma += a[i];
		sumb += b[i];
		if (a[i] > k + 1 || b[i] > k + 1)
		{
			return false;
		}
		while (suma > k)
		{
			if (count == 0 || coua == 0)
			{
				return false;
			}
			count--;
			coua--;
			suma--;
		}
		while (sumb > k)
		{
			if (count == 0 || coub == 0)
			{
				return false;
			}
			count--;
			coub--;
			sumb--;
		}
		if (coua + 1 <= suma)
		{
			coua++;
		}
		if (coub + 1 <= sumb)
		{
			coub++;
		}
		if (count + 1 <= suma + sumb)
		{
			count++;
		}
	}
	return true;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int suma = 0, sumb = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i], &b[i]);
			suma += a[i];
			sumb += b[i];
		}
		int l = 0, r = max(suma, sumb) * 2, ans = 0;
		while (l + 1 < r)
		{
			int mid = l + ((r - l) >> 1);
			// printf("lr %d %d %d\n",l,r,mid);
			if (check(mid))
			{
				ans = mid;
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		printf("%d\n", l);
	}
	return 0;
}

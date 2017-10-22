#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) (a > b ? b : a)
typedef long long ss;
ss N, M, O;
void Cal()
{
	ss f, l, total, point;
	if (N <= 1)
	{
		printf("0\n");
		return;
	}
	f = (M * (M - 1)) / 2;
	total = N - 1;
	l = f * total;
	point = ((f + l) * total) / 2;
	printf("%lld\n", point);
}
int main()
{
	ss k = 1;
	while (1)
	{
		scanf("%lld%lld", &N, &M);
		if (!N && !M)
		{
			break;
		}
		printf("Case %lld: ", k++);
		O = N + M;
		N = MIN(N, M);
		M = O - N;
		Cal();
	}
	return 0;
}

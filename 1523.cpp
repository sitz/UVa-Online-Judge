#include <bits/stdc++.h>

using namespace std;

#define INF 999999999
typedef long long ll;
int seat[8];
double ans;
double get_M()
{
	double sum1(0), sum2(0), sum;
	sum1 += seat[0] - seat[6] + seat[1] - seat[5] + seat[2] - seat[4];
	sum2 += seat[0] - seat[2] + seat[7] - seat[3] + seat[6] - seat[4];
	sum = sqrt(sum1 * sum1 + sum2 * sum2);
	return sum;
}
void solve()
{
	do
	{
		ans = min(ans, get_M());
	} while (next_permutation(seat, seat + 8));
	return;
}
int main()
{
	while (true)
	{
		int sum(0);
		for (int i = 0; i < 8; i++)
			scanf("%d", &seat[i]), sum += seat[i];
		if (sum == 0)
			break;
		ans = 999999999;
		sort(seat, seat + 8);
		solve();
		printf("%.3lf\n", ans);
	}
	return 0;
}

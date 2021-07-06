#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		int diff = -160000;
		int max_;
		scanf("%d", &max_);
		for (int i = 1; i < N; i++)
		{
			int n;
			scanf("%d", &n);
			diff = max(diff, max_ - n);
			max_ = max(max_, n);
		}
		printf("%d\n", diff);
	}
	return 0;
}

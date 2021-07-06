#include <bits/stdc++.h>

using namespace std;

char s[1024];

int main()
{
	double gmol[128];
	gmol['C'] = 12.01f;
	gmol['H'] = 1.008f;
	gmol['O'] = 16.00f;
	gmol['N'] = 14.01f;

	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		double res = 0.0f;
		int n = strlen(s);
		for (int i = 0; i < n;)
		{
			int ele = s[i], num = 0;
			i++;
			while (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + s[i] - '0', i++;
			}
			if (num == 0)
			{
				num = 1;
			}
			res += gmol[ele] * num;
		}
		printf("%.3lf\n", res);
	}
	return 0;
}

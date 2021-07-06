#include <bits/stdc++.h>

using namespace std;

const double esp = 1e-6;
int h1, m1, h2, m2;
double t1, t2, s[25];

int main()
{
	s[0] = 0;
	for (int i = 1; i < 25; i++)
	{
		s[i] = s[i - 1] + 720.0 / 11;
	}
	printf("Program 3 by team X\n");
	printf("Initial time  Final time  Passes\n");
	while (~scanf("%d%d%d%d", &h1, &m1, &h2, &m2))
	{
		t1 = h1 * 60 + m1;
		t2 = h2 * 60 + m2;
		if (t2 < t1)
		{
			t2 += 720;
		}
		int ans1, ans2;
		for (int i = 0; i < 24; i++)
		{
			if (s[i] < t1)
			{
				ans1 = i;
			}
			if (s[i] < t2)
			{
				ans2 = i;
			}
		}
		printf("       %02d:%02d       %02d:%02d%8d\n", h1, m1, h2, m2, ans2 - ans1);
	}
	printf("End of program 3 by team X\n");
	return 0;
}

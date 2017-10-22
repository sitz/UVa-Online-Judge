#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i, j, time;
	double T[5], x, y, rt, a, b;
	char in[10];
	while (scanf("%s", in) == 1)
	{
		if (in[0] == '-')
		{
			break;
		}
		T[0] = (in[0] - '0') * 36000 + (in[1] - '0') * 3600 + (in[3] - '0') * 600 + (in[4] - '0') * 60 + (in[6] - '0') * 10 + (in[7] - '0');
		for (i = 1; i < 5; i++)
		{
			scanf("%s", in);
			T[i] = (in[0] - '0') * 36000 + (in[1] - '0') * 3600 + (in[3] - '0') * 600 + (in[4] - '0') * 60 + (in[6] - '0') * 10 + (in[7] - '0');
		}
		x = (T[1] - T[2]) / (T[0] - T[2]);
		y = (T[3] - T[2]) / (T[4] - T[2]);
		a = (x - x * y) / (1 - x * y);
		b = (y - x * y) / (1 - x * y);
		rt = T[2] + (T[0] - T[2]) * a + (T[4] - T[2]) * b;
		time = (int)(rt + 0.5);
		printf("%02d:%02d:%02d\n", time / 3600, time / 60 % 60, time % 60);
	}
	return 0;
}

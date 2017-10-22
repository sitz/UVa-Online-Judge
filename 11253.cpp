#include <bits/stdc++.h>

using namespace std;

int rx[32] = {0, 1}, ry[32] = {0, 0};
int px, py, rot;
int main()
{
	int n, x, y, px, py, rot, i;
	for (i = 2; i < 32; i++)
	{
		rx[i] = rx[i - 1] - ry[i - 1];
		ry[i] = rx[i - 1] + ry[i - 1];
	}
	while (1)
	{
		scanf("%d", &n);
		if (n < 0)
		{
			break;
		}
		px = py = rot = 0;
		while (1)
		{
			if (!n)
			{
				break;
			}
			for (i = 0; i < 32; i++)
				if ((1 << i) >= n)
				{
					break;
				}
			x = rx[i + 1];
			y = ry[i + 1];
			if (rot % 4 == 0)
			{
				px += x;
				py += y;
			}
			else if (rot % 4 == 1)
			{
				px += y;
				py += -x;
			}
			else if (rot % 4 == 2)
			{
				px += -x;
				py += -y;
			}
			else
			{
				px += -y;
				py += x;
			}
			rot++;
			n = (1 << i) - n;
		}
		printf("(%d,%d)\n", px, py);
	}
	return 0;
}

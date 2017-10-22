#include <bits/stdc++.h>

using namespace std;

#define STEP 1e-3

const double HALFPI = acos(0.0);
char buf[2008];

int main()
{
	int p, q, px, py;
	double angle, height;
	char *ptr;
	while (gets(buf))
	{
		ptr = strtok(buf, " ");
		sscanf(ptr, "%d,%d", &px, &py);
		if (px > py)
		{
			px ^= py ^= px ^= py;
		}
		while (ptr = strtok(NULL, " "))
		{
			sscanf(ptr, "%d,%d", &p, &q);
			for (angle = 0.0; angle <= HALFPI; angle += STEP)
			{
				height = px * sin(angle) + py * cos(angle) - q;
				height *= tan(angle);
				height += px * cos(angle);
				if (height > p)
				{
					break;
				}
			}
			if (angle > HALFPI)
			{
				printf("Y");
			}
			else
			{
				printf("N");
			}
		}
		printf("\n");
	}
	return 0;
}

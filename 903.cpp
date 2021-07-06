#include <bits/stdc++.h>

using namespace std;

void set_(int n, int *x, int *y)
{
	if (n == 1)
	{
		*x = *y = 0;
		return;
	}
	int len, side = sqrt(--n), r;
	if (side & 1)
	{
		side++;
	}
	r = n - (side - 1) * (side - 1);
	len = side / 2;
	switch (r / side)
	{
	case 0:
		*x = len, *y = len - 1 - r % side;
		break;
	case 1:
		*x = len - 1 - r % side, *y = -len;
		break;
	case 2:
		*x = -len, *y = r % side - len + 1;
		break;
	case 3:
		*x = r % side - len + 1, *y = len;
		break;
	}
}
void put(int x, int y)
{
	if ((x | y) == 0)
	{
		printf("1;");
		return;
	}
	int len, side, r, type;
	if (x - y > 0)
	{
		type = ((x + y > 0) ? 0 : 1);
	}
	else
	{
		type = ((x + y > 0) ? 3 : 2);
	}
	switch (type)
	{
	case 0:
		len = x, r = len - y;
		break;
	case 1:
		len = -y, r = len - x;
		break;
	case 2:
		len = -x, r = y + len;
		break;
	case 3:
		len = y, r = x + len;
		break;
	}
	side = len * 2;
	printf("%d;", (side - 1) * (side - 1) + r + type * side);
}

int main()
{
	int n, x, y;
	while (scanf("%d", &n) == 1)
	{
		set_(n, &x, &y);
		put(x - 1, y + 1);
		put(x, y + 1);
		put(x + 1, y + 1);
		printf("\n");
		put(x - 1, y);
		printf("%d;", n);
		put(x + 1, y);
		printf("\n");
		put(x - 1, y - 1);
		put(x, y - 1);
		put(x + 1, y - 1);
		printf("\n");
	}
	return 0;
}

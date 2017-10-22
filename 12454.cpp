#include <bits/stdc++.h>

using namespace std;

#define _USE_MATH_DEFINES
#define EPS std::numeric_limits<double>::epsilon()
#define epsilon 0.000001

int arr[100], i, numCases, num, x, y, diameter, sum;

void checkIntersect(int x, int y, int diameter, int fig)
{
	double r, m, a, b, c, d;
	r = diameter / 2.0;
	for (int i = 0; i < 9; i++)
	{
		m = tan(i * M_PI / 18.0);
		a = 1.0 + m * m;
		b = (-2.0 * x) - (2.0 * y * m);
		c = (x * x) + (y * y) - (r * r);
		d = (b * b) - (4.0 * a * c);
		if ((d >= 0.0) || (fabs(d) < epsilon))
		{
			arr[i]++;
			return;
		}
	}
	if (x == 0 ||
			(x < 0 && x + r < epsilon) ||
			(x > 0 && x - r < epsilon))
	{
		arr[9]++;
	}
}

int main()
{
	scanf("%d", &numCases);
	while (numCases--)
	{
		memset(arr, 0, sizeof(arr));
		scanf("%d", &num);
		for (int i = 0; i < num; i++)
		{
			scanf("%d %d %d", &x, &y, &diameter);
			checkIntersect(x, y, diameter, i + 1);
		}
		sum = 0;
		for (int i = 0; i <= 9; i++)
		{
			if (arr[i] == 0)
			{
				continue;
			}
			printf("Fire laser at %d degrees.\n", i * 10);
			sum += arr[i];
		}
		if (sum == 0)
		{
			printf("No balloon burst.\n");
		}
		else if (sum == 1)
		{
			printf("1 burst balloon.\n");
		}
		else
		{
			printf("%d burst balloons.\n", sum);
		}
	}
	return 0;
}

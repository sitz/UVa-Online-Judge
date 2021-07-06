#include <bits/stdc++.h>

using namespace std;

double min_, max_;
int p[20], ptr, temp[3];

void print(int i, int a, int b, int c)
{
	printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n", (double)i / 100,
				 (double)a / 100, (double)b / 100, (double)c / 100,
				 (double)a / 100, (double)b / 100, (double)c / 100);
}
bool find()
{
	for (int i = 0; i < ptr; i++)
		if (p[i] == temp[0])
		{
			return true;
		}
	p[ptr++] = temp[0];
	return false;
}

int main()
{
	while (scanf("%lf %lf", &min_, &max_) == 2)
	{
		int min_i = (int)(min_ * 100 + 0.01), max_i = (int)(max_ * 100 + 0.01);
		if (min_i > max_i)
		{
			swap(min_i, max_i);
		}
		for (int i = min_i; i <= max_i; i += 1)
		{
			ptr = 0;
			for (int j = 1; j * j * j <= i * 10000; j += 1)
			{
				if (i * 10000 % j != 0)
				{
					continue;
				}
				int d = i * 10000 / j, c = i - j;
				if (c * c - 4 * d < 0)
				{
					continue;
				}
				int sq = (int)sqrt(c * c - 4 * d);
				if (sq * sq != (c * c - 4 * d))
				{
					continue;
				}
				if ((c + sq) % 2 != 0)
				{
					continue;
				}
				int a = (c + sq) / 2, b = (c - sq) / 2;
				temp[0] = j;
				temp[1] = a;
				temp[2] = b;
				if (temp[0] > temp[1])
				{
					swap(temp[0], temp[1]);
				}
				if (temp[0] > temp[2])
				{
					swap(temp[0], temp[2]);
				}
				if (temp[1] > temp[2])
				{
					swap(temp[1], temp[2]);
				}
				if (find())
				{
					continue;
				}
				print(i, temp[0], temp[1], temp[2]);
			}
		}
	}
	return 0;
}

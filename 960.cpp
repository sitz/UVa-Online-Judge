#include <bits/stdc++.h>

using namespace std;

int casos, a, b;
int read()
{
	scanf("%d%d", &a, &b);
	return 1;
}
void process()
{
	int norma = (int)floor(sqrt(a * a + b * b) + 0.000001);
	int rnorma = (int)floor(sqrt(norma));
	for (int i = -rnorma; i <= rnorma; i++)
	{
		for (int j = -rnorma; j <= rnorma; j++)
		{
			if ((i == 0 && j == 0) || (i * i + j * j == 1))
			{
				continue;
			}
			if ((a * i + b * j) % (i * i + j * j) == 0 && (b * i - a * j) % (i * i + j * j) == 0)
			{
				//printf ("%d %d => %d %d\n", a, b, i, j);
				printf("C\n");
				return;
			}
		}
	}
	printf("P\n");
}
int main()
{
	scanf("%d", &casos);
	while (casos--)
	{
		read();
		process();
	}
	return 0;
}

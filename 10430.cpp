#include <bits/stdc++.h>

using namespace std;

void normal(int *a)
{
	for (int i = 0; i < 100; ++i)
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
}

int main()
{
	int times, round;
	printf("Dear GOD, Pardon Me");

	while (scanf("%d %d", &times, &round) != EOF)
	{
		int tree[100] = {1}, temple[100] = {1}, out = 100;

		for (int i = 1; i < round; ++i)
		{
			for (int k = 0; k < 100; ++k)
				temple[k] = temple[k] * times;
			normal(temple);
			for (int k = 0; k < 100; ++k)
				tree[k] += temple[k];
			normal(tree);
		}
		for (int k = 0; k < 100; ++k)
			temple[k] = temple[k] * times;
		normal(temple);
		while (!tree[--out])
			;
		printf("\nX = ");
		for (; out >= 0; --out)
			printf("%d", tree[out]);
		printf("\nK = ");
		out = 100;
		while (!temple[--out])
			;
		for (; out >= 0; --out)
			printf("%d", temple[out]);
		puts("");
	}

	return 0;
}

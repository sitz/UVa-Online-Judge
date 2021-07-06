#include <bits/stdc++.h>

using namespace std;

//HKUST - ZHANG Xiongqi
//Using C++

int main()
{
	unsigned int digits = 0;
	unsigned int fenzi = 1, fenmu = 1;
	int count = 0;
	while (scanf("%d%d", &fenzi, &fenmu) == 2)
	{
		if (fenzi == 0 || fenmu == 0)
		{
			break;
		}
		int *p = new int[fenmu];
		putchar('.');
		count++;
		for (int i = 0; i < fenmu; i++)
		{
			fenzi *= 10;
			*(p + i) = fenzi;
			if (i > 0 && fenzi != 0)
			{
				for (int j = 0; j < i; j++)
				{
					if (*(p + j) == *(p + i))
					{
						digits = i - j;
						break;
					}
				}
			}
			if (fenzi == 0)
			{
				printf("\nThis expansion terminates.\n\n");
				count = 0;
				break;
			}
			if (digits != 0)
			{
				printf("\nThe last %d digits repeat forever.\n\n", digits);
				count = 0;
				break;
			}
			count++;
			if (count == 51)
			{
				putchar(10);
				count = 1;
			}
			printf("%d", fenzi / fenmu);
			fenzi = fenzi % fenmu;
		}
		digits = 0;
		delete[] p;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

//HKUST - ZHANG Xiongqi
//Using C++
int main()
{
	int temp;
	while (scanf("%d", &temp) == 1)
	{
		bool first = true;
		if (temp > 0)
		{
			first = false;
			if (temp != 1)
			{
				printf("%dx^8", temp);
			}
			else
			{
				printf("x^8");
			}
		}
		else if (temp < 0)
		{
			first = false;
			if (temp != -1)
			{
				printf("%dx^8", temp);
			}
			else
			{
				printf("-x^8");
			}
		}
		for (int i = 7; i > 1; i--)
		{
			scanf("%d", &temp);
			if (temp > 0)
			{
				if (first)
				{
					first = false;
					if (temp != 1)
					{
						printf("%dx^%d", temp, i);
					}
					else
					{
						printf("x^%d", i);
					}
				}
				else
				{
					if (temp != 1)
					{
						printf(" + %dx^%d", temp, i);
					}
					else
					{
						printf(" + x^%d", i);
					}
				}
			}
			else if (temp < 0)
			{
				if (first)
				{
					first = false;
					if (temp != -1)
					{
						printf("%dx^%d", temp, i);
					}
					else
					{
						printf("-x^%d", i);
					}
				}
				else
				{
					if (temp != -1)
					{
						printf(" - %dx^%d", -1 * temp, i);
					}
					else
					{
						printf(" - x^%d", i);
					}
				}
			}
		}
		scanf("%d", &temp);
		if (temp > 0)
		{
			if (first)
			{
				first = false;
				if (temp != 1)
				{
					printf("%dx", temp);
				}
				else
				{
					printf("x");
				}
			}
			else
			{
				if (temp != 1)
				{
					printf(" + %dx", temp);
				}
				else
				{
					printf(" + x");
				}
			}
		}
		else if (temp < 0)
		{
			if (first)
			{
				first = false;
				if (temp != -1)
				{
					printf("%dx", temp);
				}
				else
				{
					printf("-x");
				}
			}
			else
			{
				if (temp != -1)
				{
					printf(" - %dx", -1 * temp);
				}
				else
				{
					printf(" - x");
				}
			}
		}
		scanf("%d", &temp);
		if (temp > 0)
		{
			if (first)
			{
				first = false;
				printf("%d", temp);
			}
			else
			{
				printf(" + %d", temp);
			}
		}
		else if (temp < 0)
		{
			if (first)
			{
				first = false;
				printf("%d", temp);
			}
			else
			{
				printf(" - %d", -1 * temp);
			}
		}
		else if (first)
		{
			printf("0");
		}
		putchar(10);
	}
}

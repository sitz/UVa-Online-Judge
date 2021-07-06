#include <bits/stdc++.h>

using namespace std;

/*
 * Author: Phillip LeBlanc
 * Problem: Calculus Simplified 11890
 *
 */

#define DEBUG 1
#define printd \
	if (DEBUG)   \
	printf
#define POS 1
#define NEG 0

int neg(const int last_sign, const int mode)
{
	if ((last_sign == NEG && mode == POS) ||
			(last_sign == POS && mode == NEG))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int count_negs(char *input, int *start, const int mode)
{
	int negs = 0;
	int last_sign = POS;
	while (input[*start] != 0)
	{
		if (input[*start] == '(')
		{
			(*start)++;
			negs += count_negs(input, start, mode);
		}
		if (input[*start] == '-')
		{
			if (input[*start + 1] == '(')
			{
				*start = *start + 2;
				negs += count_negs(input, start, mode ^ 1);
				continue;
			}
			last_sign = NEG;
			(*start)++;
		}
		if (input[*start] == '+')
		{
			last_sign = POS;
			(*start)++;
		}
		if (input[*start] == 'x')
		{
			negs += neg(last_sign, mode);
			(*start)++;
		}
		if (input[*start] == ')')
		{
			(*start)++;
			return negs;
		}
	}
	return negs;
}

int compare(const void *a, const void *b)
{
	return (*(int *)b) - (*(int *)a);
}

void run()
{
	int num, i, *a, negs, tot = 0, start = 0;
	char input[100001];
	scanf("%s", input);
	scanf("%d", &num);
	a = (int *)malloc(sizeof(int) * num);
	for (i = 0; i < num; ++i)
	{
		scanf("%d", &a[i]);
	}
	qsort(a, num, sizeof(int), compare);
	negs = count_negs(input, &start, POS);
	for (i = 0; i < (num - negs); i++)
	{
		tot += a[i];
	}
	for (; i < num; i++)
	{
		tot -= a[i];
	}
	printf("%d\n", tot);
}

int main()
{
	int count, j;
	scanf("%d", &count);
	for (j = 0; j < count; j++)
	{
		run();
	}
	return 0;
}

/*
  for (i = 0; i < num; ++i)
  {
    printd("%d ", a[i]);
  }
  printd("\n");
*/

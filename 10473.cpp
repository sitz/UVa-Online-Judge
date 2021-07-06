#include <bits/stdc++.h>

using namespace std;

long K;
char DIGIT[] = {"0123456789ABCDEF"};
int A[200];
char input[50];
void VALUE()
{
	for (int i = 0; i < 16; i++)
	{
		A[DIGIT[i]] = i;
	}
}
void HEXA()
{
	int p = 0;
	long sum = 0;
	for (int i = strlen(input) - 1; i >= 2; i--)
	{
		sum += pow(16, p++) * A[input[i]];
	}
	printf("%ld\n", sum);
}
main()
{
	VALUE();
	long k;
	while (1)
	{
		gets(input);
		if (input[0] == '-')
		{
			break;
		}
		if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X'))
		{
			HEXA();
			continue;
		}
		sscanf(input, "%ld", &K);
		printf("0x");
		printf("%lX\n", K);
	}
	return 0;
}

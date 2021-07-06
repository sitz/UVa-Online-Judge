#include <bits/stdc++.h>

using namespace std;

unsigned long Min(long Hasil2, long Hasil3, long Hasil5, long Hasil7)
{
	long Temp[4], max;
	int i;
	Temp[0] = Hasil2;
	Temp[1] = Hasil3;
	Temp[2] = Hasil5;
	Temp[3] = Hasil7;
	max = Temp[0];
	for (i = 1; i < 4; i++)
	{
		if (Temp[i] < max)
		{
			max = Temp[i];
		}
	}
	return max;
}

int main()
{
	long ugly[5842];
	int k = 5842;
	long index2 = 0, index3 = 0, index5 = 0, index7 = 0;
	long Hasil2, Hasil3, Hasil5, Hasil7, target;
	long i;
	Hasil2 = 1;
	Hasil3 = 1;
	Hasil5 = 1;
	Hasil7 = 1;
	ugly[0] = 1;
	for (i = 1; i < k; i++)
	{
		target = ugly[i - 1] + 1;
		while ((Hasil2 = 2 * ugly[index2]) < target)
		{
			index2++;
		}
		while ((Hasil3 = 3 * ugly[index3]) < target)
		{
			index3++;
		}
		while ((Hasil5 = 5 * ugly[index5]) < target)
		{
			index5++;
		}
		while ((Hasil7 = 7 * ugly[index7]) < target)
		{
			index7++;
		}
		ugly[i] = Min(Hasil2, Hasil3, Hasil5, Hasil7);
	}
	while (scanf("%ld", &i))
	{
		if (i == 0)
		{
			break;
		}
		if ((i % 100) >= 10 && (i % 100) <= 20)
		{
			printf("The %ldth humble number is %ld.\n", i, ugly[i - 1]);
		}
		else if ((i % 10) == 1)
		{
			printf("The %ldst humble number is %ld.\n", i, ugly[i - 1]);
		}
		else if ((i % 10) == 2)
		{
			printf("The %ldnd humble number is %ld.\n", i, ugly[i - 1]);
		}
		else if ((i % 10) == 3)
		{
			printf("The %ldrd humble number is %ld.\n", i, ugly[i - 1]);
		}
		else if ((i % 10) == 4)
		{
			printf("The %ldth humble number is %ld.\n", i, ugly[i - 1]);
		}
		else
		{
			printf("The %ldth humble number is %ld.\n", i, ugly[i - 1]);
		}
	}
	return 0;
}

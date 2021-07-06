#include <bits/stdc++.h>

using namespace std;

char Digit[] = "0123456789ABCDE";
int Val[200], MXB;
char Num[1000000], Rev[1000000], Temp[1000000], ss[1000000], tt[1000000], temp[1000000];

void Ini()
{
	int i, j;
	for (i = 0; Digit[i]; i++)
	{
		j = Digit[i];
		Val[j] = i;
	}
}
int Mbase()
{
	int max = -1, i, j;
	for (i = 0; Num[i]; i++)
	{
		j = Num[i];
		if (max < Val[j])
		{
			max = Val[j];
		}
	}
	return max;
}
void REV()
{
	int i, m = 0;
	for (i = strlen(Temp) - 1; i >= 0; i--)
	{
		Rev[m++] = Temp[i];
	}
	Rev[m] = '\0';
}
void ADD(int base)
{
	int i, j, sum, k, m = 0;
	int carry = 0, d;
	for (i = strlen(Num) - 1; i >= 0; i--)
	{
		j = Num[i];
		k = Rev[i];
		sum = Val[j] + Val[k] + carry;
		d = sum % base;
		Temp[m++] = Digit[d];
		carry = sum / base;
	}
	if (carry)
	{
		Temp[m++] = Digit[carry];
	}
	Temp[m] = '\0';
}
int STEP(int base)
{
	int step = 0, i, m = 0;
	for (i = strlen(Num) - 1; i >= 0; i--)
	{
		ss[m++] = Num[i];
	}
	ss[m] = '\0';
	if (!strcmp(ss, Num))
	{
		return 0;
	}
	strcpy(Temp, Num);
	REV();
	while (1)
	{
		ADD(base);
		step++;
		REV();
		if (!strcmp(Temp, Rev))
		{
			break;
		}
		strcpy(Num, Rev);
		strcpy(Rev, Temp);
	}
	return step;
}
void Cal()
{
	int i, step;
	strcpy(temp, Num);
	for (i = 15; i >= MXB + 1; i--)
	{
		step = STEP(i);
		printf("%d", step);
		if (i > MXB + 1)
		{
			printf(" ");
		}
		strcpy(Num, temp);
	}
}

int main()
{
	int i;
	Ini();
	while (scanf("%s", Num) != EOF)
	{
		MXB = Mbase();
		if (MXB == 0)
		{
			MXB = 1;
		}
		Cal();
		for (i = MXB; i >= 2; i--)
		{
			printf(" ?");
		}
		printf("\n");
	}
	return 0;
}

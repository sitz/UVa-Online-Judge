#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000000000000LL
#define SHIFT 100000000

int type[4] = {10, 20, 25, 50};
char buf[1005];
long long times[20];

int ab(int now)
{
	if (now < 0)
		return -now;
	return now;
}

int main()
{
	int count, n, m, i, j, len, buf1, buf2, maxdiff, diff, degtmp, typetmp, right, left, shift;
	long long minnum, maxnum, temp, num;
	times[0] = 1;
	for (i = 1; i < 18; i++)
		times[i] = times[i - 1] * 10;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i = 0, minnum = INF, maxnum = -INF; i < n; i++)
		{
			scanf("%s", buf);
			if (sscanf(buf, "%d.%d", &buf1, &buf2) == 1)
				temp = (long long)buf1 * 100000000;
			else
			{
				buf2 *= times[8 - strlen(strstr(buf, ".") + 1)];
				if (buf[0] == '-')
					temp = (long long)buf1 * 100000000 - buf2;
				else
					temp = (long long)buf1 * 100000000 + buf2;
			}
			if (temp < minnum)
				minnum = temp;
			if (temp > maxnum)
				maxnum = temp;
		}
		for (i = 0, maxdiff = 1000; i < 18; i++)
		{
			for (j = 0; j < 4; j++)
			{
				temp = times[i] * type[j];
				if (maxnum > 0)
					right = (maxnum - 1) / temp + 1;
				else
					right = 0;

				if (minnum < 0)
					left = (-minnum - 1) / temp + 1;
				else
					left = 0;
				if ((diff = ab(left + right + 1 - m)) < maxdiff)
				{
					maxdiff = diff;
					degtmp = i;
					typetmp = j;
				}
			}
		}
		temp = times[degtmp] * type[typetmp];
		shift = degtmp + 1;
		len = 7 - degtmp;
		if (typetmp == 2)
		{
			shift--;
			len++;
		}
		for (num = 0; num > minnum; num -= temp)
			;
		if (maxnum < 0)
			maxnum = 0;
		for (; num < maxnum; num += temp)
		{
			if (num < 0)
			{
				if (len <= 0)
					printf("-%lld ", (-num) / SHIFT);
				else
					printf("-%lld.%0*lld ", (-num) / SHIFT, len, ((-num) % SHIFT) / times[shift]);
			}
			else
			{
				if (len <= 0)
					printf("%lld ", num / SHIFT);
				else
					printf("%lld.%0*lld ", num / SHIFT, len, (num % SHIFT) / times[shift]);
			}
		}
		if (num < 0)
		{
			if (len <= 0)
				printf("-%lld\n", (-num) / SHIFT);
			else
				printf("-%lld.%0*lld\n", (-num) / SHIFT, len, ((-num) % SHIFT) / times[shift]);
		}
		else
		{
			if (len <= 0)
				printf("%lld\n", num / SHIFT);
			else
				printf("%lld.%0*lld\n", num / SHIFT, len, (num % SHIFT) / times[shift]);
		}
	}
	return 0;
}

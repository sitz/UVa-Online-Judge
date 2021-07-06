#include <bits/stdc++.h>

using namespace std;

/*
10706
Number sequence
*/
typedef long long bg;
bg N;
struct ss
{
	bg len, total;
	bg st, end;
} digit[10];
void Ini()
{
	bg i, st = 9, k = 10, l = 99, total, d, g = 9;
	digit[1].st = 1;
	digit[1].end = 9;
	digit[1].total = 45;
	for (i = 2; i < 6; i++)
	{
		st += i;
		digit[i].st = st;
		digit[i].end = (l - k) * i + st;
		d = st + digit[i].end;
		total = ((digit[i].end - st) / i) + 1;
		digit[i].total = (d * total) / 2;
		k *= 10;
		l = l * 10 + 9;
		g += digit[i].len;
		st = g;
	}
}
void GetLen()
{
	bg i, f = 1, s = 9, d;
	for (i = 1; i < 6; i++)
	{
		d = s - f;
		d = (d * i) + i;
		digit[i].len = d;
		f = f * 10;
		s = s * 10 + 9;
	}
}
bg digitNo()
{
	bg i, sum = 0;
	for (i = 1; i < 6; i++)
	{
		sum += digit[i].total;
		if (sum >= N)
		{
			break;
		}
	}
	if (sum == N)
	{
		return -1;
	}
	return i;
}
bg Sum(bg f, bg s, bg d)
{
	bg sum;
	sum = ((f + s) * d) / 2;
	return sum;
}
bg Binary(bg ndigit, bg total)
{
	bg lo, up, sum, mid, k, temp, g;
	lo = digit[ndigit].st;
	up = digit[ndigit].end;
	if (lo >= total)
	{
		return 0;
	}
	k = ((up - lo) / ndigit) + 1;
	k /= 2;
	mid = lo + k * ndigit;
	sum = Sum(lo, mid, k + 1);
	while (1)
	{
		if (sum > total)
		{
			temp = sum - mid;
			if (temp < total)
			{
				return temp;
			}
			if (temp == total)
			{
				return temp - (mid - ndigit);
			}
			up = mid - ndigit;
		}
		if (sum < total)
		{
			temp = sum + (mid + ndigit);
			if (temp >= total)
			{
				return sum;
			}
			lo = mid + ndigit;
		}
		else if (sum == total)
		{
			return sum - mid;
		}
		k = ((up - lo) / ndigit) + 1;
		k /= 2;
		mid = lo + k * ndigit;
		g = ((mid - digit[ndigit].st) / ndigit) + 1;
		sum = Sum(digit[ndigit].st, mid, g);
	}
	return 0;
}
bg dis(bg nn)
{
	int i, sum = 0;
	for (i = 1; i < 6; i++)
	{
		sum += digit[i].len;
		if (sum >= nn)
		{
			break;
		}
	}
	return i;
}
void Final(bg n, bg dig)
{
	bg A[10];
	bg a, b = 1, c, d, k = 0;
	for (a = 1; a < dig; a++)
	{
		b *= 10;
	}
	d = (n + dig - 1) / dig;
	d--;
	c = b + d;
	b = d * dig + 1;
	while (c)
	{
		A[k++] = c % 10;
		c /= 10;
	}
	for (a = k - 1; a >= 0; a--)
	{
		if (b == n)
		{
			printf("%lld\n", A[a]);
			return;
		}
		b++;
	}
}
void Cal()
{
	bg i, j, k, nodigit, sum = 0, before, xx;
	nodigit = digitNo();
	if (nodigit < 0)
	{
		puts("9");
		return;
	}
	for (i = 1; i < nodigit; i++)
	{
		sum += digit[i].total;
	}
	before = Binary(nodigit, N - sum);
	before = N - sum - before;
	sum = 0;
	for (i = 1; i < 6; i++)
	{
		sum += digit[i].len;
		if (sum >= before)
		{
			break;
		}
	}
	sum -= digit[i].len;
	Final(before - sum, i);
}
int main()
{
	GetLen();
	Ini();
	bg kases;
	scanf("%lld", &kases);
	while (kases--)
	{
		scanf("%lld", &N);
		Cal();
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define BASE 10000
char str[1500];
void updateodd(int *oddarray, int &arraylen, int *outputarray, int originlen)
{
	int carry = 0;
	arraylen = originlen;
	for (int i = 0; i < originlen; i++)
	{
		int t = outputarray[i] * 20 + carry;
		oddarray[i] = t % BASE;
		carry = t / BASE;
	}
	if (carry)
	{
		oddarray[arraylen++] = carry;
	}
	carry = 1;
	for (int i = 0; i < arraylen; i++)
	{
		int t = oddarray[i] + carry;
		oddarray[i] = t % BASE;
		carry = t / BASE;
		if (!carry)
		{
			break;
		}
	}
	if (carry)
	{
		oddarray[arraylen++] = carry;
	}
}
void update(int *odd, int &lenodd)
{
	int carry, i;
	for (i = 0, carry = 2; i < lenodd; i++)
	{
		int t = odd[i] + carry;
		odd[i] = t % BASE;
		carry = t / BASE;
		if (!carry)
		{
			break;
		}
	}
	if (carry)
	{
		odd[lenodd++] = carry;
	}
}
bool compare(int *remain, int lenrem, int *odd, int lenodd)
{
	if (lenodd > lenrem)
	{
		return false;
	}
	if (lenrem > lenodd)
	{
		return true;
	}
	for (int i = lenrem - 1; i >= 0; i--)
	{
		if (remain[i] > odd[i])
		{
			return true;
		}
		if (remain[i] < odd[i])
		{
			return false;
		}
	}
	return true;
}
void sub(int *remain, int &lenrem, int *odd, int lenodd)
{
	int borrow, t, i;
	for (i = borrow = 0; i < lenrem; i++)
	{
		t = remain[i] + borrow;
		if (i < lenodd)
		{
			t -= odd[i];
		}
		if (t < 0)
		{
			t += BASE;
			borrow = -1;
		}
		else
		{
			borrow = 0;
		}
		remain[i] = t;
	}
	while (remain[lenrem - 1] == 0)
	{
		lenrem--;
	}
}
void updateoutput(int *output, int &len, int c)
{
	int carry, i;
	for (i = carry = 0; i < len; i++)
	{
		int t = output[i] * 10 + carry;
		output[i] = t % BASE;
		carry = t / BASE;
	}
	if (carry)
	{
		output[len++] = carry;
	}
	for (i = 0, carry = c; i < len; i++)
	{
		output[i] += carry;
		carry = output[i] / BASE;
		output[i] %= BASE;
		if (!carry)
		{
			break;
		}
	}
	if (carry)
	{
		output[len++] = carry;
	}
}
void updaterem(int *remainarray, int &arraylen, int c)
{
	int carry, i;
	if (arraylen <= 0)
	{
		arraylen = 1;
	}
	for (i = carry = 0; i < arraylen; i++)
	{
		int t = remainarray[i] * 100 + carry;
		remainarray[i] = t % BASE;
		carry = t / BASE;
	}
	if (carry)
	{
		remainarray[arraylen++] = carry;
	}
	for (i = 0, carry = c; i < arraylen; i++)
	{
		remainarray[i] += carry;
		carry = remainarray[i] / BASE;
		remainarray[i] %= BASE;
		if (!carry)
		{
			break;
		}
	}
	if (carry)
	{
		remainarray[arraylen++] = carry;
	}
}
void BigSqrt(char *input, int inputlen, int *output, int &outputlen)
{
	int start, s, t, count;
	int remain[150], lenrem = 0;
	int odd[150], lenodd = 0;
	outputlen = 1;
	if (inputlen % 2 == 1)
	{
		start = 1;
		s = (input[0] - '0');
	}
	else
	{
		start = 2;
		s = (input[0] - '0') * 10 + (input[1] - '0');
	}
	for (count = 0, t = 1; s >= t; s -= t, t += 2, count++)
		;
	output[0] = count;
	remain[0] = 0;
	if (s)
	{
		remain[lenrem++] = s;
	}
	for (int i = start; i < inputlen; i += 2)
	{
		updateodd(odd, lenodd, output, outputlen);
		s = (input[i] - '0') * 10 + (input[i + 1] - '0');
		updaterem(remain, lenrem, s);
		for (count = 0; compare(remain, lenrem, odd, lenodd); count++)
		{
			sub(remain, lenrem, odd, lenodd);
			update(odd, lenodd);
		}
		updateoutput(output, outputlen, count);
	}
}
void BigNumToString(int *input, int inputlen, char *output, int &outputlen)
{
	char temp[50];
	sprintf(temp, "%d", input[inputlen - 1]);
	output[0] = '\0';
	strcat(output, temp);
	for (int i = inputlen - 2; i >= 0; i--)
	{
		sprintf(temp, "%04d", input[i]);
		strcat(output, temp);
	}
	outputlen = strlen(output);
}
void StringToBigNum(char *input, int inputlen, int *output, int &outputlen)
{
	int s = inputlen % 4, temp, i, j, seg = inputlen / 4;
	char *p = input;
	outputlen = 0;
	if (s)
	{
		for (i = temp = 0; i < s; i++)
		{
			temp = temp * 10 + (*p++) - '0';
		}
		output[outputlen++] = temp;
	}
	for (i = 0; i < seg; i++)
	{
		for (j = temp = 0; j < 4; j++)
		{
			temp = temp * 10 + (*p++) - '0';
		}
		output[outputlen++] = temp;
	}
	for (i = 0, j = outputlen - 1; i <= j; i++, j--)
	{
		int t = output[i];
		output[i] = output[j];
		output[j] = t;
	}
}
int ToNumber(char *input, int len)
{
	int result = 0;
	for (int i = 0; i < len; i++)
	{
		result = result * 10 + input[i] - '0';
	}
	return result;
}
void Decode(char *input, int inputlen, char *r, int &rlen, char *c, int &clen)
{
	char temp[1500];
	int d[150], lend, d2[300], lend2, p[150], lenp;
	int tempr[150], temprlen, tempc[150], tempclen;
	StringToBigNum(input, inputlen, p, lenp);
	temp[0] = '0';
	strcpy(temp + 1, input);
	for (int i = inputlen, carry = 0; i >= 0; i--)
	{
		int v = (temp[i] - '0') * 8 + carry;
		carry = v / 10;
		temp[i] = (v % 10) + '0';
	}
	for (int i = inputlen, carry = 1; i >= 0 && carry; i--)
	{
		int v = (temp[i] - '0') + carry;
		carry = v / 10;
		temp[i] = (v % 10) + '0';
	}
	BigSqrt(temp, inputlen + 1, d, lend);
	for (int i = 0, borrow = -1; i < lend && borrow != 0; i--)
	{
		d[i] += borrow;
		if (d[i] < 0)
		{
			d[i] += BASE;
			borrow = -1;
		}
		else
		{
			borrow = 0;
		}
	}
	for (int i = lend - 1, rem = 0; i >= 0; i--)
	{
		rem = rem * BASE + d[i];
		d[i] = rem / 2;
		rem %= 2;
	}
	while (d[lend - 1] == 0 && lend > 1)
	{
		lend--;
	}
	memset(d2, 0, sizeof(d2));
	for (int i = 0; i < lend; i++)
		for (int j = 0; j < lend; j++)
		{
			int v = d[i] * d[j] + d2[i + j];
			d2[i + j] = v % BASE;
			d2[i + j + 1] += v / BASE;
		}
	lend2 = 2 * lend;
	int carry = 0;
	for (int i = 0; i < lend2; i++)
	{
		int t = d2[i] + carry;
		if (i < lend)
		{
			t += d[i];
		}
		carry = t / BASE;
		d2[i] = t % BASE;
		if (i >= lend && !carry)
		{
			break;
		}
	}
	if (carry)
	{
		d2[lend2++] = carry;
	}
	for (int i = lend2 - 1, rem = 0; i >= 0; i--)
	{
		rem = rem * BASE + d2[i];
		d2[i] = rem / 2;
		rem %= 2;
	}
	while (d2[lend2 - 1] == 0 && lend2 > 1)
	{
		lend2--;
	}
	for (int i = 0, borrow = 0; i < lenp; i++)
	{
		int t = p[i] + borrow;
		if (i < lend2)
		{
			t -= d2[i];
		}
		if (t < 0)
		{
			t += BASE;
			borrow = -1;
		}
		else
		{
			borrow = 0;
		}
		tempc[i] = t;
	}
	tempclen = lenp;
	while (tempc[tempclen - 1] == 0 && tempclen > 1)
	{
		tempclen--;
	}
	for (int i = 0, borrow = 0; i < lend; i++)
	{
		int t = d[i] + borrow;
		if (i < tempclen)
		{
			t -= tempc[i];
		}
		if (t < 0)
		{
			t += BASE;
			borrow = -1;
		}
		else
		{
			borrow = 0;
		}
		tempr[i] = t;
	}
	temprlen = lend;
	while (tempr[temprlen - 1] == 0 && temprlen > 1)
	{
		temprlen--;
	}
	BigNumToString(tempr, temprlen, r, rlen);
	BigNumToString(tempc, tempclen, c, clen);
}
int X[500], Y[500], n;
int main()
{
	int t;
	while (scanf("%s", str) == 1)
	{
		if (strcmp(str, "*") == 0)
		{
			break;
		}
		char r[1500], c[1500];
		int rlen, clen;
		char x[1500], y[1500];
		int xlen, ylen;
		Decode(str, strlen(str), r, rlen, c, clen);
		n = ToNumber(r, rlen);
		strcpy(str, c);
		for (int i = 0; i < n - 2; i++)
		{
			Decode(str, strlen(str), r, rlen, c, clen);
			Decode(r, rlen, x, xlen, y, ylen);
			X[i] = ToNumber(x, xlen);
			Y[i] = ToNumber(y, ylen);
			strcpy(str, c);
		}
		Decode(str, strlen(str), r, rlen, c, clen);
		Decode(r, rlen, x, xlen, y, ylen);
		X[n - 2] = ToNumber(x, xlen);
		Y[n - 2] = ToNumber(y, ylen);
		Decode(c, clen, x, xlen, y, ylen);
		X[n - 1] = ToNumber(x, xlen);
		Y[n - 1] = ToNumber(y, ylen);
		X[n] = X[0];
		Y[n] = Y[0];
		int area = 0;
		for (int i = 0; i < n; i++)
		{
			area += X[i] * Y[i + 1] - X[i + 1] * Y[i];
		}
		if (area < 0)
		{
			area = -area;
		}
		printf("%.1lf\n", (double)(area)*0.5);
	}
}

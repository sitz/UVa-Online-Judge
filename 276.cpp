#include <bits/stdc++.h>

using namespace std;

const char trans[] = {"|n98r"};
int acnt[6], bcnt[6], ccnt[6], dcnt[6], A, B;
char a[50], b[50];
int calcul(char s[], int cnt[])//将字符串记录成数组，返回十进制的值
{
	int i = 0, num = 0, len = strlen(s);
	while (i < len)
	{
		while (i < len && s[i] == '|')
		{
			cnt[0]++, i++;
		}
		while (i < len && s[i] == 'n')
		{
			cnt[1]++, i++;
		}
		while (i < len && s[i] == '9')
		{
			cnt[2]++, i++;
		}
		while (i < len && s[i] == '8')
		{
			cnt[3]++, i++;
		}
		while (i < len && s[i] == 'r')
		{
			cnt[4]++, i++;
		}
		i++;
	}
	for (i = 4; i >= 0; i--)
	{
		num = num * 10 + cnt[i];
	}
	return num;
}
bool lessthan(const int c[], const int b[])//ccnt是否小于bcnt，结束乘法
{
	for (int i = 4; i >= 0; i--)
		if (b[i] > c[i])
		{
			return 1;
		}
		else if (b[i] < c[i])
		{
			return 0;
		}
	return 1;
}
int Print(const int x[])//打印x[]，每组结尾均有空格，包括末尾
{
	int i, j, tot = 0;
	for (i = 0; i <= 4; i++)
	{
		if (x[i] == 0)
		{
			continue;
		}
		for (j = 0; j < x[i]; j++)
		{
			printf("%c", trans[i]);
			tot++;
		}
		printf(" ");
		tot++;
	}
	return tot;
}
void Carry(int x[])//处理进位，高于万位省略
{
	for (int i = 0; i <= 4; i++)
		if (x[i] > 9)
		{
			x[i + 1] += (x[i] / 10);
			x[i] %= 10;
		}
}
void solve()
{
	int i, len;
	bool f;
	memset(acnt, 0, sizeof(acnt));//初始化,乘数
	memset(bcnt, 0, sizeof(bcnt));//被乘数
	memset(ccnt, 0, sizeof(ccnt));//a的double
	memset(dcnt, 0, sizeof(dcnt));//最后结果
	A = calcul(a, acnt);
	B = calcul(b, bcnt);
	ccnt[0] = 1;
	while (lessthan(ccnt, bcnt))
	{
		f = (B % 2) ? 1 : 0;
		B /= 2;
		len = Print(ccnt);
		if (f)
		{
			printf("*");
			len++;
		}
		for (; len < 34; len++)
		{
			printf(" ");
		}
		len = Print(acnt);
		printf("\n");
		if (f)
			for (i = 0; i <= 4; i++)
			{
				dcnt[i] += acnt[i];
			}
		for (i = 0; i <= 4; i++)//Double
		{
			ccnt[i] *= 2, acnt[i] *= 2;
		}
		Carry(ccnt);
		Carry(acnt);
	}
	Carry(dcnt);
	printf("The solution is: ");
	Print(dcnt);
	printf("\n");
}
int main()
{
	fgets(a, 50, stdin);
	while (fgets(b, 50, stdin) != NULL)
	{
		solve();
		fgets(a, 50, stdin);
	}
	return 0;
}

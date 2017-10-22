#include <bits/stdc++.h>

using namespace std;

int Prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int Len, Odd, tos, Factor[31][15], Fre[30], Sym[30];
char SS[100];

void PreDefine()
{
	int i, j, k, d;
	for (i = 2; i < 31; i++)
		for (j = 0; j < 10 && Prime[j] <= i; j++)
		{
			d = 0;
			for (k = Prime[j]; k <= i; k *= Prime[j])
				d += i / k;
			Factor[i][j] = d;
		}
}

int Count(int len)
{
	int i, j, d;
	int T[11] = {0};
	if (len <= 1)
		return 1;
	for (i = 0; i < 10; i++)
		T[i] = Factor[len][i];
	for (i = 0; i < tos; i++)
	{
		d = Fre[Sym[i]];
		if (!d)
			continue;
		for (j = 0; j < 10 && Prime[j] <= d; j++)
			T[j] -= Factor[d][j];
	}
	d = 1;
	for (i = 0; i < 10 && Prime[i] <= len; i++)
		d *= (int)pow(Prime[i], T[i]);
	return d;
}

void Setting()
{
	for (int i = 0; i < tos; i++)
		Fre[Sym[i]] /= 2;
}

void Gen(int nth)
{
	int i, j, r = 0, s, val, d, pre = 0;
	char ch, Res[40];
	for (i = 0; i < Len / 2; i++)
	{
		val = 0;
		for (j = 0; j < tos; j++)
		{
			s = Sym[j];
			if (!Fre[s])
				continue;
			Fre[s]--;
			d = Count(Len / 2 - i - 1);
			val += d;
			if (pre + val >= nth)
			{
				Res[r++] = s + 'a';
				cout << Res[r - 1];
				val -= d;
				pre += val;
				break;
			}
			Fre[s]++;
		}
	}
	if (Len % 2)
	{
		ch = Odd + 'a';
		cout << ch;
	}
	for (i = r - 1; i >= 0; i--)
		cout << Res[i];
	cout << endl;
}

void Cal(int nth)
{
	int maxx;
	Setting();
	maxx = Count(Len / 2);
	if (maxx < nth)
	{
		cout << "XXX\n";
		return;
	}
	Gen(nth);
}

int isPalin()
{
	int i, odd = 0, d = 0, k;
	tos = 0;
	Len = strlen(SS);
	for (i = 0; SS[i]; i++)
	{
		k = SS[i] - 'a';
		Fre[k]++;
	}
	for (i = 0; i < 26; i++)
	{
		if (Fre[i] % 2 != 0)
		{
			odd++;
			Odd = i;
		}
		if (Fre[i] > 0)
			Sym[tos++] = i;
	}
	if (Len % 2 == 0)
		if (odd)
			return 0;
		else
			return 1;
	else if (odd != 1)
		return 0;
	return 1;
}

void Free()
{
	for (int i = 0; i < 26; i++)
		Fre[i] = 0;
}

int main()
{
	int kase, nth, k = 1;
	PreDefine();
	cin >> kase;
	while (kase--)
	{
		cin >> SS >> nth;
		cout << "Case " << k++ << ": ";
		if (isPalin() == 0)
		{
			cout << "XXX\n";
			Free();
			continue;
		}
		Cal(nth);
		Free();
	}
	return 0;
}

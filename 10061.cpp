#include <bits/stdc++.h>

using namespace std;

#define maxn 1048579

char sv[maxn + 2];
int N, B;
vector<int> P;

void Primetable()
{
	int i, j;
	for (i = 2; i * i < maxn;)
	{
		for (j = i + i; j <= maxn; j += i)
		{
			sv[j] = 1;
		}
		for (++i; sv[i]; i++)
			;
	}
	P.push_back(2);
	for (i = 3; i < maxn; i += 2)
		if (sv[i] == 0)
		{
			P.push_back(i);
		}
}
int times(int n)
{
	int i, sum = 0;
	for (i = n; i <= N; i *= n)
	{
		sum += N / i;
	}
	return sum;
}
int Zeros()
{
	int i, k, n = B, zero = 2147483647, t, a, m;
	for (i = 0; i < P.size() && n > 1; i++)
	{
		m = P[i];
		m *= m;
		if (m > n)
		{
			break;
		}
		if (n % P[i] == 0)
		{
			k = 0;
			while (n % P[i] == 0)
			{
				k++;
				n /= P[i];
			}
			t = times(P[i]);
			a = t / k;
			if (zero > a)
			{
				zero = a;
			}
		}
	}
	if (n > 1)
	{
		t = times(n);
	}
	if (zero > t)
	{
		zero = t;
	}
	return zero;
}
int digit()
{
	int i, dig;
	double sum = 0;
	for (i = 1; i <= N; i++)
	{
		sum += log10(i) / log10(B);
	}
	sum += 1e-5;
	dig = ceil(sum);
	return dig;
}
void Cal()
{
	int z, dig;
	if (N == 0)
	{
		cout << "0 "
				 << "1\n";
		return;
	}
	if (N == 1)
	{
		cout << "0 "
				 << "1\n";
		return;
	}
	z = Zeros();
	dig = digit();
	cout << z << " " << dig << endl;
}

int main()
{
	Primetable();
	while (cin >> N >> B)
	{
		Cal();
	}
	return 0;
}

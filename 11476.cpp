#include <bits/stdc++.h>

using namespace std;

#define mabs(a) (((a) > 0) ? (a) : -(a))
#define LL long long
#define SIZE 500001
LL pr[80600];
bool p[SIZE];
int gene(int n)
{
	int i, j;
	for (i = 3; i * i <= n; i += 2)
		if (!p[i / 2])
			for (j = i * i; j < n + 1; j += (2 * i))
			{
				p[j / 2] = 1;
			}
	j = 1;
	pr[0] = 2;
	for (i = 1; i < n / 2; i++)
		if (!p[i])
		{
			pr[j] = i * 2 + 1, j++;
		}
	return j;
}
typedef pair<LL, int> pli;
vector<pli> vv;
LL binsearch(LL n)
{
	LL low = 1, high = 1000000000, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (mid * mid == n)
		{
			return mid;
		}
		else if (mid * mid < n)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
void print(LL a, int b)
{
	if (b == 1)
	{
		printf("%lld", a);
	}
	else
	{
		printf("%lld^%d", a, b);
	}
}
LL mulmod(LL a, LL b, LL c)
{
	LL x = 0, y = a % c;
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			x = (x + y) % c;
		}
		y = (y * 2) % c;
		b /= 2;
	}
	return x % c;
}
LL gcd(LL a, LL b)
{
	if (!b)
	{
		return a;
	}
	return gcd(b, a % b);
}
LL pollard_rho(LL n)
{
	int i = 0, k = 2;
	LL x = 3, y = 3;
	while (1)
	{
		i++;
		x = (mulmod(x, x, n) + n - 1) % n;
		LL d = gcd(mabs(y - x), n);
		if (d != 1 && d != n)
		{
			//      printf("->>%d\n",i);
			return d;
		}
		if (i == k)
		{
			y = x, k *= 2;
		}
	}
}
LL powmod(LL a, LL b, LL c)//(a^b)%c
{
	LL temp;
	if (!b)
	{
		return 1;
	}
	if (b == 1)
	{
		return a % c;
	}
	if (b % 2)
	{
		temp = powmod(a, b - 1, c);
		return mulmod(temp, a, c);
	}
	temp = powmod(a, b / 2, c);
	return mulmod(temp, temp, c);
}
bool miller_rabin(LL P)
{
	if (P != 2 && P % 2 == 0)
	{
		return false;
	}
	LL s = P - 1;
	while (s % 2 == 0)
	{
		s /= 2;
	}
	for (int i = 0; i < 25; i++)
	{
		LL a = rand() % (P - 1) + 1, temp = s;
		LL mod = powmod(a, temp, P);
		while (temp != (P - 1) && mod != 1 && mod != (P - 1))
		{
			mod = mulmod(mod, mod, P);
			temp *= 2;
		}
		if (mod != (P - 1) && temp % 2 == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int t, i, m = gene(2 * SIZE);
	LL n, temp, now;
	LL lim = 1000000;
	lim *= lim;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld", &n);
		vv.clear();
		temp = n;
		for (i = 0; i < m && pr[i] * pr[i] <= n; i++)
			if (n % pr[i] == 0)
			{
				int f = 0;
				while (n % pr[i] == 0)
				{
					n /= pr[i], f++;
				}
				vv.push_back(make_pair((LL)pr[i], f));
			}
		if (n < lim && n > 1)
		{
			vv.push_back(make_pair(n, 1)), n /= n;
		}
		if (n == 1)
		{
			goto done;
		}
		now = binsearch(n);
		if (now != -1)
		{
			vv.push_back(make_pair(now, 2));
			goto done;
		}
		if (miller_rabin(n))
		{
			vv.push_back(make_pair(n, 1));
			goto done;
		}
		now = pollard_rho(n);
		if (now > n / now)
		{
			now = n / now;
		}
		vv.push_back(make_pair(now, 1));
		vv.push_back(make_pair(n / now, 1));
	done:
		printf("%lld = ", temp);
		print(vv[0].first, vv[0].second);
		for (i = 1; i < (int)vv.size(); i++)
		{
			printf(" * "), print(vv[i].first, vv[i].second);
		}
		printf("\n");
	}
	return 0;
}

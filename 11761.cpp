#include <bits/stdc++.h>

using namespace std;

#define SIDE_MAX 40001
#define P_MAX 26458
#define sq(a) ((a) * (a))
typedef long long int LL;

vector<int> eratos(P_MAX, 0);

LL GCD(LL a, LL b)
{
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return GCD(b, a % b);
	}
}
inline LL SquaredRadiusOfCircumcircle(LL a, LL b, LL c)
{
	if (a < b + c && b < a + c && c < a + b)
	{
		LL numer1 = a * b * c, numer2 = a * b * c;
		LL denom1 = a + b + c, denom2 = -a + b + c, denom3 = a - b + c, denom4 = a + b - c;
		LL gcd1, gcd2, gcd3, gcd4;
		gcd1 = GCD(numer1, denom1);
		numer1 /= gcd1;
		denom1 /= gcd1;
		gcd2 = GCD(numer2, denom2);
		numer2 /= gcd2;
		denom2 /= gcd2;
		gcd3 = GCD(numer1, denom3);
		numer1 /= gcd3;
		denom3 /= gcd3;
		gcd4 = GCD(numer2, denom4);
		numer2 /= gcd4;
		denom4 /= gcd4;
		if ((numer1 * numer2) % (denom1 * denom2 * denom3 * denom4) == 0)
		{
			return (numer1 * numer2) / (denom1 * denom2 * denom3 * denom4);
		}
	}
	return -1;
}
void MakePrimes()
{
	for (int i = 2; i < P_MAX; ++i)
	{
		if (eratos[i] == 0)
		{
			for (int j = 2; i * j < P_MAX; ++j)
			{
				eratos[i * j] = 1;
			}
		}
	}
}
int ExamineMaxPrime(int N)
{
	for (int i = (int)sqrt((double)N); i >= 2; --i)
	{
		if (eratos[i] == 0 && N % i == 0)
		{
			return i;
		}
	}
	return N;
}
int main()
{
	MakePrimes();
	while (true)
	{
		LL R, A, M;
		int maxprime = 2;
		int min_side = SIDE_MAX;
		int min_side_ind = -1;
		bool bFound = false;
		vector<vector<int>> vanses;
		cin >> R >> A;
		if (R == 0 && A == 0)
		{
			break;
		}
		M = 4 * A * R;
		maxprime = max(maxprime, ExamineMaxPrime((int)R));
		maxprime = max(maxprime, ExamineMaxPrime((int)A));
		for (int a = 1; a < SIDE_MAX && !bFound; a++)
		{
			if (M % a != 0)
			{
				continue;
			}
			LL t = M / a;
			if (t > sq(SIDE_MAX))
			{
				continue;
			}
			for (int b = maxprime; b < SIDE_MAX && !bFound; b += maxprime)
			{
				if (t % b != 0)
				{
					continue;
				}
				LL c = t / b;
				if (sq(R) == SquaredRadiusOfCircumcircle(a, b, c) && c < SIDE_MAX)
				{
					vector<int> vans;
					vans.push_back(a);
					vans.push_back(b);
					vans.push_back((int)c);
					sort(vans.begin(), vans.end());
					vanses.push_back(vans);
				}
			}
		}
		for (unsigned int i = 0; i < vanses.size(); ++i)
		{
			for (unsigned int j = 0; j < vanses[i].size(); ++j)
			{
				if (min_side > vanses[i][j])
				{
					min_side = vanses[i][j];
					min_side_ind = i;
				}
			}
		}
		if (min_side_ind >= 0)
		{
			cout << vanses[min_side_ind][0] << ' ' << vanses[min_side_ind][1] << ' ' << vanses[min_side_ind][2] << endl;
		}
		else
		{
			cout << "-1 -1 -1\n";
		}
	}
	return 0;
}

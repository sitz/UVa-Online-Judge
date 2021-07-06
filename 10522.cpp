#include <bits/stdc++.h>

using namespace std;

typedef long double elem;

const elem pi = acos(-1);
const elem eps = 1.0e-8;

bool eq(elem a, elem b)
{
	return abs(b - a) < eps;
}
bool eqlt(elem a, elem b)
{
	return eq(a, b) || a < b;
}
bool eqgt(elem a, elem b)
{
	return eq(a, b) || a > b;
}

bool isInvalidTriangle(elem Ha, elem Hb, elem Hc, elem &S)
{
	if (eqlt(Ha, 0) || eqlt(Hb, 0) || eqlt(Hc, 0))
	{
		return true;
	}
	elem s = 1. / pow(Hb, 2) + 1. / pow(Hc, 2) - 1. / pow(Ha, 2);
	elem CosA = ((Hb * Hc) * (s / 2));
	if (eqlt(CosA, -1) || eqgt(CosA, 1))
	{
		return true;
	}
	elem SinA = sin(acos(CosA));
	S = (Hb * Hc) / (2 * SinA);
	elem a = 2 * S / Ha;
	elem b = 2 * S / Hb;
	elem c = 2 * S / Hc;
	if (eqlt(a + b, c) || eqlt(a + c, b) || eqlt(b + c, a))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int n;
	int n_invalid = 0;
	scanf("%d", &n);
	while (true)
	{
		bool bInvalid;
		elem Ha, Hb, Hc, S;
		assert(n > 0);
		if (3 != scanf("%Lf%Lf%Lf", &Ha, &Hb, &Hc))
		{
			break;
		}
		bInvalid = isInvalidTriangle(Ha, Hb, Hc, S);
		if (bInvalid)
		{
			n_invalid++;
			printf("These are invalid inputs!\n");
			if (n_invalid >= n)
			{
				break;
			}
		}
		else
		{
			printf("%.3Lf\n", S);
		}
	}
	return 0;
}

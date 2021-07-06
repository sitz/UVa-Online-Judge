#include <bits/stdc++.h>

using namespace std;

#define db(a) cout << #a << " = " << a << endl;
#define db2(a, b) cout << #a << " = " << a << " -- " << #b << " = " << b << endl;
#define foreach(it, l) for (typeof(l.begin()) it = l.begin(); it != l.end(); it++)

typedef pair<int, int> punto;
#define x(p) p.first
#define y(p) p.second

long long producto_cruz(punto a, punto b)
{
	return x(a) * y(b) - y(a) * x(b);
}
long long producto_punto(punto a, punto b)
{
	return x(a) * x(b) + y(a) * y(b);
}
long long norma(punto a)
{
	return (x(a) * x(a) + y(a) * y(a));
}
int main()
{
	int t = 0;
	int r1, r2, r3, r4;
	long long tama, tamb, tamc, tamd;
	bool exito;
	punto a, b, c, d;
	punto v1, v2, v3, v4;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d", &x(a), &y(a), &x(b), &y(b), &x(c), &y(c), &x(d), &y(d));
		int buscar[] = {1, 2, 3};
		vector<punto> puntos;
		puntos.push_back(a);
		puntos.push_back(b);
		puntos.push_back(c);
		puntos.push_back(d);
		do
		{
			x(v1) = x(puntos[buscar[0]]) - x(a);
			y(v1) = y(puntos[buscar[0]]) - y(a);
			x(v2) = x(puntos[buscar[1]]) - x(puntos[buscar[0]]);
			y(v2) = y(puntos[buscar[1]]) - y(puntos[buscar[0]]);
			x(v3) = x(puntos[buscar[2]]) - x(puntos[buscar[1]]);
			y(v3) = y(puntos[buscar[2]]) - y(puntos[buscar[1]]);
			x(v4) = x(a) - x(puntos[buscar[2]]);
			y(v4) = y(a) - y(puntos[buscar[2]]);
			r1 = producto_cruz(v1, v2);
			r2 = producto_cruz(v2, v3);
			r3 = producto_cruz(v3, v4);
			r4 = producto_cruz(v4, v1);
			if ((r1 > 0 && r2 > 0 && r3 > 0 && r4 > 0) || (r1 < 0 && r2 < 0 && r3 < 0 && r4 < 0))
			{
				exito = true;
			}
			else
			{
				exito = false;
			}
		} while (!exito && next_permutation(buscar, buscar + 3));
		tama = norma(v1);
		tamb = norma(v2);
		tamc = norma(v3);
		tamd = norma(v4);
		if (producto_punto(v1, v2) == 0 && producto_punto(v2, v3) == 0 && producto_punto(v3, v4) == 0 && producto_punto(v4, v1) == 0)
		{
			if (tama == tamb && tamb == tamc && tamc == tamd)
			{
				printf("Case %d: Square\n", i + 1);
			}
			else
			{
				printf("Case %d: Rectangle\n", i + 1);
			}
		}
		else
		{
			if (tama == tamb && tamb == tamc && tamc == tamd)
			{
				printf("Case %d: Rhombus\n", i + 1);
			}
			else
			{
				if (tama == tamc && tamb == tamd)
				{
					printf("Case %d: Parallelogram\n", i + 1);
				}
				else
				{
					if (producto_cruz(v1, v3) == 0 || producto_cruz(v2, v4) == 0)
					{
						printf("Case %d: Trapezium\n", i + 1);
					}
					else
					{
						printf("Case %d: Ordinary Quadrilateral\n", i + 1);
					}
				}
			}
		}
	}
	return 0;
}

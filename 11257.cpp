#include <bits/stdc++.h>

using namespace std;

#define EPS 1E-6

struct Ponto
{
	double x, y;
	Ponto(double x = 0, double y = 0) : x(x), y(y) {}
	Ponto operator-(Ponto p)
	{
		return Ponto(x - p.x, y - p.y);
	}
	double operator*(Ponto p)
	{
		return x * p.x + y * p.y;
	}
	double operator%(Ponto p)
	{
		return x * p.y - y * p.x;
	}
	double dist(Ponto p)
	{
		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
	}
} pontos[120], dif[120];
int n;
double mini, maxi, dista[120];
int read()
{
	scanf("%d", &n);
	if (!n)
	{
		return 0;
	}
	mini = 10000;
	maxi = -10000;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
		if (pontos[i].x < mini)
		{
			mini = pontos[i].x;
		}
		if (pontos[i].x > maxi)
		{
			maxi = pontos[i].x;
		}
	}
	return 1;
}
double dist(int i1, int i2, Ponto p)
{
	if ((p - pontos[i1]) * (dif[i1]) > 0)
	{
		return p.dist(pontos[i1]);
	}
	else if ((p - pontos[i2]) * (dif[i1]) < 0)
	{
		return p.dist(pontos[i2]);
	}
	double ar = (p - pontos[i2]) % (dif[i1]);
	return (ar * ar) / dista[i1];
}
double g(double x, double y)
{
	int ant = n - 1;
	double ret = 1000000000, d;
	Ponto p(x, y);
	for (int i = 0; i < n; i++)
	{
		d = dist(i, ant, p);
		if (d < ret)
		{
			ret = d;
		}
		ant = i;
	}
	return ret;
}
double f(double x)
{
	int ant = n - 1;
	double y1 = -10000, y2, y, g1, g2;
	for (int i = 0; i < n; i++)
	{
		if (x >= min(pontos[i].x, pontos[ant].x) &&
				x <= max(pontos[i].x, pontos[ant].x))
		{
			if (y1 < -5000)
			{
				y1 = pontos[i].y + ((pontos[ant].y - pontos[i].y) / (pontos[ant].x - pontos[i].x)) * (x - pontos[i].x);
			}
			else
			{
				y2 = pontos[i].y + ((pontos[ant].y - pontos[i].y) / (pontos[ant].x - pontos[i].x)) * (x - pontos[i].x);
			}
		}
		ant = i;
	}
	if (y1 > y2)
	{
		y = y1;
		y1 = y2;
		y2 = y;
	}
	//printf("x= %lf, y1 = %lf, y2 = %lf\n", x, y1,y2);
	while (y1 < y2 - EPS)
	{
		g1 = g(x, (2 * y1 + y2) / 3);
		g2 = g(x, (y1 + 2 * y2) / 3);
		if (g1 < g2)
		{
			y1 = (2 * y1 + y2) / 3;
		}
		else
		{
			y2 = (y1 + 2 * y2) / 3;
		}
	}
	//  printf("g[%lf] = %lf\n", y1,g(x,y1));
	return g(x, y1);
}
void process()
{
	double f1, f2;
	int a = n - 1;
	for (int i = 0; i < n; i++)
	{
		dif[i] = pontos[i] - pontos[a];
		dista[i] = pontos[i].dist(pontos[a]);
		a = i;
	}
	while (mini < maxi - EPS)
	{
		f1 = f((2 * mini + maxi) / 3);
		f2 = f((mini + 2 * maxi) / 3);
		//printf("f[%lf] =  %lf, f[%lf] = %lf\n",(mini+2*maxi)/3,f1, (2*mini+maxi)/3,f2);
		if (f1 < f2)
		{
			mini = (2 * mini + maxi) / 3;
		}
		else
		{
			maxi = (mini + 2 * maxi) / 3;
		}
	}
	printf("%.3lf\n", sqrt(f(mini)));
}
int main()
{
	while (read())
	{
		process();
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define EPS 0.000000001

struct Ponto
{
	int x, y;
	Ponto() {}
	Ponto(int _x, int _y) : x(_x), y(_y) {}
	Ponto operator-(Ponto a)
	{
		return Ponto(x - a.x, y - a.y);
	}
	double operator%(Ponto a)
	{
		return x * a.y - a.x * y;
	}
	double operator*(Ponto b)
	{
		return x * b.x + y * b.y;
	}
};
Ponto pontos[100010], atual, eixoX(1, 0);
int p, indiceMinimo, xMin, yMin;
int pilha[100010], top, degenerado;
int mod(Ponto a)
{
	return a.x * a.x + a.y * a.y;
}
int read()
{
	if (scanf("%d", &p) == EOF)
	{
		return 0;
	}
	xMin = yMin = 200000;
	for (int i = 0; i < p; i++)
	{
		scanf("%d%d", &pontos[i].x, &pontos[i].y);
		if (pontos[i].y < yMin)
		{
			xMin = pontos[i].x;
			yMin = pontos[i].y;
			indiceMinimo = i;
		}
		else if (pontos[i].y == yMin && pontos[i].x < xMin)
		{
			xMin = pontos[i].x;
			yMin = pontos[i].y;
			indiceMinimo = i;
		}
	}
	atual = pontos[indiceMinimo];
	//  printf("%d\n", indiceMinimo);
	return 1;
}
int cmp(double a, double b)
{
	if (fabs(a - b) < EPS)
	{
		return 0;
	}
	return a > b ? 1 : -1;
}
double angle2(Ponto a, Ponto b)
{
	return atan2(a % b, a * b);
}
double angle(Ponto a)
{
	//  printf("%d %d com %d %d = %lf\n", a.x, a.y, b.x, b.y, atan2(a%b, a*b));
	if (a.x == 0 && a.y == 0)
	{
		return -1;
	}
	return atan2(a.y, a.x);
}
int compare(const void *a, const void *b)
{
	Ponto pa = *((Ponto *)a), pb = *((Ponto *)b);
	if (cmp(angle(pa - atual), angle(pb - atual)))
	{
		return cmp(angle(pa - atual), angle(pb - atual));
	}
	return cmp(mod(pa - atual), mod(pb - atual));
}
int direction(Ponto a, Ponto b)
{
	return cmp(a % b, 0);
}
void convexHull()
{
	qsort(pontos, p, sizeof(Ponto), compare);
	//  for(int i = 0; i < p; i++)printf("opa %d %d\n", pontos[i].x, pontos[i].y);
	top = 0;
	int aux = 2;
	pilha[top++] = 0;
	pilha[top++] = 1;
	while (direction(pontos[1] - pontos[0], pontos[aux] - pontos[0]) == 0 && aux < p)
	{
		aux++;
	}
	if (aux == p)
	{
		degenerado = 1;
		return;
	}
	degenerado = 0;
	top--;
	pilha[top++] = aux - 1;
	pilha[top++] = aux;
	for (int i = aux + 1; i < p; i++)
	{
		while (top > 1 && direction(pontos[i] - pontos[pilha[top - 2]], pontos[pilha[top - 1]] - pontos[pilha[top - 2]]) >= 0)
		{
			top--;
		}
		pilha[top++] = i;
	}
}
int inside()
{
	double total = 0;
	for (int i = 0; i < top; i++)
	{
		total += angle2(pontos[pilha[i]] - atual, pontos[pilha[(i + 1) % top]] - atual);
	}
	return cmp(total, 0);
}
void process()
{
	int r;
	convexHull();
	//  for(int i = 0; i < top; i++)printf("opa %d %d\n", pontos[pilha[i]].x, pontos[pilha[i]].y);
	scanf("%d", &r);
	while (r--)
	{
		scanf("%d%d", &atual.x, &atual.y);
		if (!degenerado && inside())
		{
			printf("inside\n");
		}
		else
		{
			printf("outside\n");
		}
	}
}
int main()
{
	while (read())
	{
		process();
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct Nodo
{
	int numero;
	Nodo *anterior;
	Nodo *siguiente;
	Nodo(int n)
	{
		numero = n;
		anterior = NULL;
		siguiente = NULL;
	}
	~Nodo()
	{
		if (siguiente != NULL)
		{
			delete siguiente;
		}
	}
};
struct lista
{
	Nodo *cabeza;
	int suma;
	int tam;
	lista()
	{
		cabeza = NULL;
		suma = 0;
		tam = 0;
	}
};
lista lists[100001];
lista *where[100001];
Nodo *nodo[100001];
int main()
{
	int n, m;
	while (scanf("%i %i", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			where[i] = &lists[i];
			if (lists[i].cabeza != NULL)
			{
				delete lists[i].cabeza;
			}
			lists[i].suma = i;
			lists[i].tam = 1;
			lists[i].cabeza = new Nodo(i);
			nodo[i] = lists[i].cabeza;
		}
		for (int i = 1; i <= m; i++)
		{
			int o;
			scanf("%i", &o);
			if (o == 1)
			{
				int p, q;
				scanf("%i %i", &p, &q);
				lista *a = where[p];
				lista *b = where[q];
				if (a == b)
				{
					continue;
				}
				lista *mayor;
				lista *menor;
				if (a->tam > b->tam)
				{
					mayor = a;
					menor = b;
				}
				else
				{
					mayor = b;
					menor = a;
				}
				Nodo *ultimo = menor->cabeza;
				Nodo *primero = menor->cabeza;
				Nodo *actual = menor->cabeza;
				while (actual != NULL)
				{
					where[actual->numero] = mayor;
					actual = actual->siguiente;
					if (actual != NULL)
					{
						ultimo = actual;
					}
				}
				mayor->suma += menor->suma;
				mayor->tam += menor->tam;
				ultimo->siguiente = mayor->cabeza;
				mayor->cabeza->anterior = ultimo;
				mayor->cabeza = primero;
				mayor->cabeza->anterior = NULL;
				menor->suma = 0;
				menor->tam = 0;
				menor->cabeza = NULL;
			}
			else if (o == 2)
			{
				int p, q;
				scanf("%i %i", &p, &q);
				lista *li = where[p];
				Nodo *no = nodo[p];
				lista *destino = where[q];
				if (li == destino)
				{
					continue;
				}
				if (no == li->cabeza && li->tam == 1)
				{
					li->cabeza = NULL;
				}
				else if (no == li->cabeza)
				{
					li->cabeza = li->cabeza->siguiente;
				}
				li->tam--;
				li->suma -= p;
				destino->tam++;
				destino->suma += p;
				if (no->anterior != NULL)
				{
					no->anterior->siguiente = no->siguiente;
				}
				if (no->siguiente != NULL)
				{
					no->siguiente->anterior = no->anterior;
				}
				no->anterior = NULL;
				no->siguiente = destino->cabeza;
				destino->cabeza->anterior = no;
				destino->cabeza = no;
				where[p] = destino;
			}
			else
			{
				int p;
				scanf("%i", &p);
				lista *li = where[p];
				printf("%i %i\n", li->tam, li->suma);
			}
		}
	}
}

#include <bits/stdc++.h>

using namespace std;

const int maxlen = 40000;

char str[maxlen + 2];
int n, mintimes;

// suffix tree ~ Ukkonen
const int sigma = 27;

#define char2num(c) ((c) ? (c) <= 'Z' ? (c) - 'A' + 27 : (c) - 'a' + 1 : 0)

struct suftree // 4·(3 + sigma) bytes / node, total 2n + 1 nodes
{
	int ini, fin;								// la transición ha sido cad[ini..fin)
	suftree *hijo[sigma], *fail;// fail está definido sólo para nodos internos
	suftree(int a = 0, int b = 0, suftree *f = 0) : ini(a), fin(b), fail(f)
	{
		memset(hijo, 0, sizeof(hijo));
	}
};

/* Calcula la forma canónica de la cadena dada por el sufijo s concatenado con cad[ini..fin);
 * es decir, (s, (ini, fin)) será el antecesor explícito más cercano */
inline void canonize(const char *cad, suftree *&s, int &ini, int fin)
{
	while (ini < fin)
	{
		suftree *sp = s->hijo[char2num(cad[ini])];
		if (sp->fin - sp->ini > fin - ini)
		{
			break;
		}
		s = sp;
		ini += s->fin - s->ini;
	}
}

// Supone que la cadena acaba en 0 (para marcar los sufijos al final)
suftree *hazsuftree(const char *cad, int longit)
{
	suftree *root = new suftree(), *s = root;
	int ini = 0, i;
	for (i = 0; i <= longit; i++)// <= longit para que cada sufijo acabe en una hoja
	{
		/* (s, [ini, i)) es la referencia canónica del punto activo;
		 * es decir, todos los nodos del trie correspondientes a sufijos más largos
		 * de cad[0..i) son hojas */
		suftree *ant = root, *r;// (ant, [i, i + 1)) es la última nueva letra añadida
		int letra = char2num(cad[i]);
		for (;;)
		{
			/* Comprueba si ya existe una transición con la letra cad[i] */
			r = s;// punto donde crear la nueva transición, si hace falta
			if (ini < i)
			{
				int l = char2num(cad[ini]);
				suftree *sp = s->hijo[l];
				int k = sp->ini + i - ini;
				if (cad[i] == cad[k])
				{
					break;// no es necesario partir, ya existe
				}
				r = new suftree(sp->ini, k);	 // parte común
				r->hijo[char2num(cad[k])] = sp;// sp es la rama anterior
				sp->ini = k;
				s->hijo[l] = r;
			}
			else if (s->hijo[letra])
			{
				break;// ya existe
			}
			// Añade una nueva hoja (en realidad esto aumenta en longit - i letras)
			r->hijo[letra] = new suftree(i, longit + 1);// el +1 es para la última pasada
			if (ant != root)
			{
				ant->fail = r;
			}
			ant = r;
			if (s->fail)
			{
				s = s->fail;
			}
			else if (ini++ == i)
			{
				break;// si es la raíz, aumenta un carácter
			}
			canonize(cad, s, ini, i);// se podría poner if (r != s)
		}
		if (ant != root)
		{
			ant->fail = r;
		}
		canonize(cad, s, ini, i + 1);
	}
	return root;
}

int longest, best;

int dfs(suftree *t, int depth = 0)
{
	int children = 0, times = 0;
	depth += min(n, t->fin) - t->ini;
	for (int i = 0; i < sigma; ++i)
		if (t->hijo[i])
		{
			times += dfs(t->hijo[i], depth);
			++children;
		}
	if (children == 0)
	{
		++times;// leave = suffix
	}
	int start = min(n, t->fin) - depth;
	if (depth > 0 && times >= mintimes && (depth > longest || depth == longest && start < best))
	{
		longest = depth;
		best = start;
	}
	delete t;
	return times;
}

int main()
{
	while (scanf("%i\n", &mintimes), mintimes)
	{
		gets(str);
		n = strlen(str);
		reverse(&str[0], &str[n]);
		suftree *tree = hazsuftree(str, n);
		longest = 0;
		dfs(tree);
		if (longest == 0)
		{
			puts("none");
		}
		else
		{
			printf("%i %i\n", longest, n - best - longest);
		}
	}
	return 0;
}

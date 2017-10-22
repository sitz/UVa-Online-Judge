#include <bits/stdc++.h>

using namespace std;

struct Entrada
{
	int suma;
	int fila;
	Entrada(int s, int f)
	{
		suma = s;
		fila = f;
	}
	const bool operator<(const Entrada o) const
	{
		return suma == o.suma ? fila < o.fila : suma > o.suma;
	}
};
vector<int> vect[800];
int pos[800];
priority_queue<Entrada> pq;
int main()
{
	int k;
	while (scanf("%i", &k) != EOF)
	{
		while (!pq.empty())
		{
			pq.pop();
		}
		for (int i = 0; i < k; i++)
		{
			vect[i].clear();
			for (int j = 0; j < k; j++)
			{
				int num;
				scanf("%i", &num);
				vect[i].push_back(num);
			}
		}
		int suma = 0;
		for (int i = 0; i < k; i++)
		{
			sort(vect[i].begin(), vect[i].end());
			int primero = vect[i][0];
			suma += primero;
			for (int j = 0; j < k; j++)
			{
				vect[i][j] -= primero;
			}
		}
		for (int i = 0; i < k; i++)
		{
			pq.push(Entrada(vect[0][i], 0));
			pos[i] = 0;
		}
		int cuenta = 0;
		int maximo = 0;
		for (int i = 0; i < k; i++)
		{
			maximo = max(maximo, vect[i][1]);
		}
		while (true)
		{
			Entrada actual = pq.top();
			pq.pop();
			if (actual.fila == k - 1)
			{
				if (cuenta == 0)
				{
					printf("%i", actual.suma + suma);
				}
				else
				{
					printf(" %i", actual.suma + suma);
				}
				cuenta++;
				if (cuenta == k)
				{
					printf("\n");
					break;
				}
			}
			else
			{
				for (int i = 0; i < k; i++)
				{
					Entrada siguiente(actual.suma + vect[actual.fila + 1][i], actual.fila + 1);
					if (siguiente.suma > maximo)
					{
						break;
					}
					pq.push(siguiente);
				}
			}
		}
	}
}

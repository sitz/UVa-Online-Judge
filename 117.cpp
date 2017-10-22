#include <bits/stdc++.h>

using namespace std;

const int oo = 0x3fffffff;
const int MAXSIZE = 26;

struct Graph
{
	int matrix[MAXSIZE][MAXSIZE];
	int degree[MAXSIZE];
	bool HaveOddDegree;
	int OddDegree[2];
	int dist[MAXSIZE], path[MAXSIZE];
	void CheckOddDegree();
	void Dijkstra(int start);

	Graph();
	void Init();
	void ReadGraph(char *);
	int Solve();
	void Print();
};

Graph::Graph()
{
	this->Init();
}
void Graph::Init()
{
	int i, j;
	for (i = 0; i < MAXSIZE; i++)
	{
		for (j = 0; j < MAXSIZE; j++)
		{
			matrix[i][j] = oo;
		}
	}
	memset(degree, 0, sizeof(degree));
	HaveOddDegree = false;
}
void Graph::ReadGraph(char *str)
{
	char from = str[0];
	char dest = str[strlen(str) - 1];
	int weight = strlen(str);
	matrix[from - 'a'][dest - 'a'] = matrix[dest - 'a'][from - 'a'] = weight;
	degree[from - 'a']++;
	degree[dest - 'a']++;
}
void Graph::CheckOddDegree()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (degree[i] % 2 == 1)
		{
			if (HaveOddDegree == false)
			{
				OddDegree[0] = i;
			}
			else
			{
				OddDegree[1] = i;
			}
			HaveOddDegree = true;
		}
	}
}
void Graph::Dijkstra(int start)
{
	bool vis[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		dist[i] = matrix[start][i];
		path[i] = start;
		vis[i] = false;
	}
	dist[start] = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		int min = oo;
		int k = 0;
		for (int j = 0; j < MAXSIZE; j++)
			if (!vis[j] && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		vis[k] = true;
		for (int j = 0; j < MAXSIZE; j++)
			if (!vis[j] && dist[k] + matrix[k][j] < dist[j])
			{
				dist[j] = dist[k] + matrix[k][j];
				path[j] = k;
			}
	}
}
int Graph::Solve()
{
	CheckOddDegree();
	if (HaveOddDegree)
	{
		Dijkstra(OddDegree[0]);
	}
	int i, j;
	int sum = 0;
	for (i = 0; i < MAXSIZE; i++)
		for (j = 0; j < MAXSIZE; j++)
		{
			if (matrix[i][j] == oo)
			{
				continue;
			}
			sum += matrix[i][j];
		}
	sum /= 2;
	if (HaveOddDegree)
	{
		sum += dist[OddDegree[1]];
	}
	return sum;
}
void Graph::Print()
{
	for (int k = 0; k < MAXSIZE; k++)
	{
		printf("%c %4d\n", 'a' + k, degree[k]);
	}
	if (!HaveOddDegree)
	{
		return;
	}
	printf("The Shortest Path from %c to %c is %d\n",
				 OddDegree[0] + 'a', OddDegree[1] + 'a', dist[OddDegree[1]]);
	for (int k = 0; k < MAXSIZE; k++)
	{
		printf("%c ", k + 'a');
	}
	printf("\n");
	for (int k = 0; k < MAXSIZE; k++)
	{
		printf("%c ", path[k] + 'a');
	}
	printf("\n");
}

int main()
{
	Graph g;
	char buffer[100];
	while (cin >> buffer)
	{
		if (!strcmp(buffer, "deadend"))
		{
			int result = g.Solve();
			cout << result << endl;
			g.Init();
			continue;
		}
		g.ReadGraph(buffer);
	}
	return 0;
}

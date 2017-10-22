#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
ifstream fin("test.in");
#else
#define fin cin
#endif

int n, m;
int row;
const int maxn = 105;
double graph[maxn][maxn];
int invalid[maxn];

int themax()
{
	for (int i = n; i >= 1; i--)
		if (invalid[i] == 0)
		{
			return i;
		}
}
int themin()
{
	for (int i = 1; i <= n; i++)
		if (invalid[i] == 0)
		{
			return i;
		}
}
int main()
{
	int ncase = 0;
	while (fin >> n >> m)
	{
		if (ncase == 0)
		{
			ncase++;
		}
		else
		{
			cout << endl;
		}
		memset(invalid, 0, sizeof(invalid));
		memset(graph, 0, sizeof(graph));
		row = (int)sqrt(n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				double x1;
				if (i % row == 0)
				{
					x1 = i / row;
				}
				else
				{
					x1 = i / row + 1;
				}
				double y1;
				if (i % row == 0)
				{
					y1 = row;
				}
				else
				{
					y1 = i % row;
				}
				double x2;
				if (j % row == 0)
				{
					x2 = j / row;
				}
				else
				{
					x2 = j / row + 1;
				}
				double y2;
				if (j % row == 0)
				{
					y2 = row;
				}
				else
				{
					y2 = j % row;
				}
				graph[i][j] = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
			}
		}
		int guess = 1;
		double lastdist = INT_MAX;
		int lastguess;
		bool guessthemax = true;//??·???×??ó??
		while (guess != m)
		{
			//            cout<<"  "<<guess<<"? - ";
			printf("%3d? - ", guess);
			invalid[guess] = 1;
			if (graph[guess][m] < lastdist)
			{
				cout << "CLOSER" << endl;
				if (guess != 1)
				{
					for (int i = 1; i <= n; i++)
					{
						if (graph[guess][i] >= graph[lastguess][i])
						{
							invalid[i] = 1;
						}
					}
				}
			}
			else
			{
				if (lastdist == graph[guess][m])
				{
					cout << "SAME" << endl;
					{
						for (int i = 1; i <= n; i++)
						{
							if (graph[i][guess] != graph[i][lastguess])
							{
								invalid[i] = 1;
							}
						}
					}
				}
				else
				{
					cout << "FARTHER" << endl;
					for (int i = 1; i <= n; i++)
					{
						if (graph[guess][i] <= graph[lastguess][i])
						{
							invalid[i] = 1;
						}
					}
				}
			}
			lastdist = graph[guess][m];
			lastguess = guess;
			if (guessthemax)
			{
				guess = themax();
			}
			else
			{
				guess = themin();
			}
			guessthemax = !guessthemax;
		}
		//        cout<<"  "<<guess<<"? - YES!!"<<endl;
		printf("%3d? - YES!!\n", guess);
	}
	return 0;
}

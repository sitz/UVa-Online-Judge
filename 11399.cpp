#include <bits/stdc++.h>

using namespace std;

#define LIM 3000
char m[LIM][LIM];
char s[LIM];
int tam;
int minX, minY, maxX, maxY;
int rec(int x, int y, int pos, int dirH, int dirV)
{
	int i, j, k;
	for (i = pos; i < tam; i++)
	{
		if (s[i] == '[')
		{
			k = rec(x, y, i + 1, dirH, dirV);
			i = k;
		}
		else
		{
			if (s[i] == ']')
			{
				return i;
			}
			else if (s[i] == 'U')
			{
				m[y][x] = '|';
				dirH = 0;
				dirV = 1;
			}
			else if (s[i] == 'L')
			{
				x--;
				m[y][x] = '_';
				dirH = -1;
				dirV = 0;
			}
			else if (s[i] == 'l')
			{
				x--;
				m[y][x] = '\\';
				dirH = -1;
				dirV = 1;
			}
			else if (s[i] == 'R')
			{
				x++;
				m[y][x] = '_';
				dirH = 1;
				dirV = 0;
			}
			else if (s[i] == 'r')
			{
				x++;
				m[y][x] = '/';
				dirH = 1;
				dirV = 1;
			}
			else if (s[i] == 'f')
			{
				m[y][x] = '*';
				dirH = dirV = 0;
			}
			else if (s[i] == 'p')
			{
				m[y][x] = 'o';
				dirH = dirV = 0;
			}
			else if (s[i] == 'P')
			{
				m[y][x] = 'O';
				dirH = dirV = 0;
			}
			if (x < minX)
			{
				minX = x;
			}
			if (x > maxX)
			{
				maxX = x;
			}
			if (y < minY)
			{
				minY = y;
			}
			if (y > maxY)
			{
				maxY = y;
			}
			x += dirH;
			y += dirV;
		}
	}
}
int main()
{
	while (scanf("%s", s) == 1)
	{
		memset(m, ' ', sizeof(m));
		tam = strlen(s);
		minX = LIM;
		minY = LIM;
		maxX = 0;
		maxY = 0;
		rec(LIM / 2, LIM / 2, 0, 0, 0);
		minX--;
		maxX++;
		minY--;
		maxY++;
		for (int x = minX; x < maxX; x++)
		{
			m[minY][x] = m[maxY][x] = '-';
		}
		for (int y = maxY - 1; y > minY; y--)
		{
			m[y][minX] = m[y][maxX] = '|';
		}
		m[minY][minX] = m[minY][maxX] = m[maxY][minX] = m[maxY][maxX] = '.';
		for (int i = maxY; i >= minY; i--)
		{
			m[i][maxX + 1] = 0;
			printf("%s\n", m[i] + minX);
		}
	}
	return 0;
}

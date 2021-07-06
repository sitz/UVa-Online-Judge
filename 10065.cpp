#include <bits/stdc++.h>

using namespace std;

#define MAXPOLY 105

struct point
{
	int x;
	int y;
};

struct polygon
{
	int vertexNumber;
	point vertex[MAXPOLY];
};

double area(point vertex[], int vertexNumber)
{
	double total = 0.0;
	for (int i = 0; i < vertexNumber; i++)
	{
		int j = (i + 1) % vertexNumber;
		total += (vertex[i].x * vertex[j].y - vertex[j].x * vertex[i].y);
	}
	return fabs(total / 2.0);
}

int crossProduct(point first, point second, point third)
{
	return (second.x - first.x) * (third.y - first.y) -
				 (second.y - first.y) * (third.x - first.x);
}

bool left_lower(point first, point second)
{
	if (first.x == second.x)
	{
		return first.y < second.y;
	}
	else
	{
		return first.x < second.x;
	}
}

void convex_hull(point vertex[], int vertexNumber, polygon &container)
{
	if (vertexNumber <= 3)
	{
		for (int i = 0; i < vertexNumber; i++)
		{
			container.vertex[i] = vertex[i];
		}
		container.vertexNumber = vertexNumber;
		return;
	}
	sort(vertex, vertex + vertexNumber, left_lower);
	point upper[MAXPOLY], lower[MAXPOLY];
	int top;
	upper[0] = vertex[0];
	upper[1] = vertex[1];
	top = 2;
	for (int i = 2; i < vertexNumber; i++)
	{
		upper[top] = vertex[i];
		while (top >= 2 && crossProduct(upper[top - 2], upper[top - 1], upper[top]) >= 0)
		{
			upper[top - 1] = upper[top];
			top--;
		}
		top++;
	}
	container.vertexNumber = 0;
	for (int i = 0; i < top; i++)
	{
		container.vertex[container.vertexNumber++] = upper[i];
	}
	lower[0] = vertex[vertexNumber - 1];
	lower[1] = vertex[vertexNumber - 2];
	top = 2;
	for (int i = vertexNumber - 3; i >= 0; i--)
	{
		lower[top] = vertex[i];
		while (top >= 2 && crossProduct(lower[top - 2], lower[top - 1], lower[top]) >= 0)
		{
			lower[top - 1] = lower[top];
			top--;
		}
		top++;
	}
	for (int i = 1; i < top - 1; i++)
	{
		container.vertex[container.vertexNumber++] = lower[i];
	}
}

int main(int ac, char *av[])
{
	point tile[MAXPOLY];
	polygon container;
	int vertexNumber, currentCase = 1;
	cout.precision(2);
	cout.setf(ios::fixed | ios::showpoint);
	while (cin >> vertexNumber, vertexNumber)
	{
		for (int i = 0; i < vertexNumber; i++)
		{
			cin >> tile[i].x;
			cin >> tile[i].y;
		}
		double used = area(tile, vertexNumber);
		convex_hull(tile, vertexNumber, container);
		cout << "Tile #" << currentCase++ << endl;
		double all = area(container.vertex, container.vertexNumber);
		double rate = (1.0 - used / all) * 100.0;
		cout << "Wasted Space = " << rate << " %" << endl;
		cout << endl;
	}
	return 0;
}

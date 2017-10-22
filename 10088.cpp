#include <bits/stdc++.h>

using namespace std;

typedef long long int LLI;

#define MAXPOLY 1050

struct point {LLI x, y;};

struct polygon
{
	LLI n;
	point p[MAXPOLY];
};

LLI gcd(LLI a, LLI b)
{
	if (b == 0)
	{
		return a;
	}
	if (b > a)
	{
		return gcd(b, a);
	}
	else
	{
		return gcd(b, a % b);
	}
}

LLI calArea(polygon &contour)
{
	LLI total = 0.0;
	for (LLI i = 0; i < contour.n; i++)
	{
		LLI j = (i + 1) % contour.n;
		total += (contour.p[i].x * contour.p[j].y -
							contour.p[j].x * contour.p[i].y);
	}
	return abs(total);
}

LLI boundaryPoLLIs(polygon &contour)
{
	LLI points = 0;
	for (LLI i = 0; i < contour.n; i++)
	{
		LLI j = (i + 1) % contour.n;
		if (contour.p[i].x == contour.p[j].x)
		{
			points += (abs(contour.p[j].y - contour.p[i].y) - 1);
		}
		else if (contour.p[i].y == contour.p[j].y)
		{
			points += (abs(contour.p[j].x - contour.p[i].x) - 1);
		}
		else
		{
			LLI xDiff = abs(contour.p[j].x - contour.p[i].x);
			LLI yDiff = abs(contour.p[j].y - contour.p[i].y);
			points += gcd(xDiff, yDiff) - 1;
		}
	}
	return (points + contour.n);
}

int main(int argc, char const *argv[])
{
	LLI vertexNumber;
	polygon contour;
	while (cin >> vertexNumber, vertexNumber)
	{
		contour.n = vertexNumber;
		for (LLI i = 0; i < vertexNumber; i++)
		{
			cin >> contour.p[i].x >> contour.p[i].y;
		}
		LLI vertexBoundary = boundaryPoLLIs(contour);
		LLI area = calArea(contour);
		cout << (2 * area + 4 - 2 * vertexBoundary) / 4 << endl;
	}
	return 0;
}

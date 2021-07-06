#include <bits/stdc++.h>

using namespace std;

int M[30000], tp;
struct ss
{
	int x, y;
};
void Gen()
{
	int i, j, k = 0;
	for (i = 0, j = 0; k < 1000000000; i += 4, j++)
	{
		k += i;
		M[j] = k;
	}
	tp = j;
}
int BS(int key)
{
	int lo = 0, up = tp - 1;
	int mid = (lo + up) / 2;
	while (1)
	{
		if (M[mid] > key)
		{
			if (M[mid - 1] < key)
			{
				return mid;
			}
			if (M[mid - 1] == key)
			{
				return mid - 1;
			}
			up = mid - 1;
		}
		else if (M[mid] < key)
		{
			if (M[mid + 1] >= key)
			{
				return mid + 1;
			}
			lo = mid + 1;
		}
		else
		{
			return mid;
		}
		mid = (lo + up) / 2;
	}
	return -1;
}
ss Find(int key)
{
	ss temp;
	int pos, a, b, d, t;
	pos = BS(key);
	a = M[pos];
	b = a - pos;
	temp.x = -pos;
	temp.y = 0;
	if (key <= a && key >= b)
	{
		d = a - key;
		temp.x += d;
		temp.y -= d;
		return temp;
	}
	a = b;
	b = b - pos;
	temp.x += pos;
	temp.y -= pos;
	if (key <= a && key >= b)
	{
		d = a - key;
		temp.x += d;
		temp.y += d;
		return temp;
	}
	a = b;
	b = a - pos;
	temp.x += pos;
	temp.y += pos;
	if (key <= a && key >= b)
	{
		d = a - key;
		temp.x -= d;
		temp.y += d;
		return temp;
	}
	a = b;
	b = a - pos + 1;
	temp.x -= pos;
	temp.y += pos;
	if (key <= a && key >= b)
	{
		d = a - key;
		temp.x -= d;
		temp.y -= d;
		return temp;
	}
}
double Dis(int x1, int y1, int x2, int y2)
{
	double dis;
	x1 = x1 - x2;
	x1 *= x1;
	y1 = y1 - y2;
	y1 *= y1;
	return sqrt(double(x1 + y1));
}
void Cal(int n, int m)
{
	ss t, u;
	t = Find(n);
	u = Find(m);
	printf("%.2lf\n", Dis(t.x, t.y, u.x, u.y));
}
int main()
{
	int n, m;
	Gen();
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n < 0 && m < 0)
		{
			break;
		}
		Cal(n, m);
	}
	return 0;
}

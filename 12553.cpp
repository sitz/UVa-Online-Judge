#include <bits/stdc++.h>

using namespace std;

#define N 100000

struct Item
{
	int num;
	int a, b;
	char op;
	void print()
	{
		printf("%d %c %d = %d\n", a, op, b, num);
	}
} item[10];
int target;
Item arr[8];
int t, ans, md;
inline int dist(int x, int y)
{
	if (x > y)
	{
		return x - y;
	}
	else
	{
		return y - x;
	}
}
bool f, g;

void calc(Item a[], int size, int tar)
{
	int i, j, k, l, tmp;
	Item b[10], m, n;
	if (dist(a[size - 1].num, tar) < md)
	{
		ans = a[size - 1].num;
		md = dist(a[size - 1].num, tar);
	}
	if (g)
	{
		return;
	}
	if (md == 0)
	{
		if (f)
		{
			for (int i = 0; i < 6 - size; ++i)
			{
				item[i].print();
			}
			g = true;
		}
		return;
	}
	if (size == 1)
	{
		return;
	}
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			m = a[i];
			n = a[j];
			for (k = 0, l = 0; k < size; ++k)
				if (k != i && k != j)
				{
					b[l++] = a[k];
				}
			b[size - 2].num = m.num + n.num;
			b[size - 2].a = m.num;
			b[size - 2].b = n.num;
			b[size - 2].op = '+';
			if (f)
			{
				item[6 - size] = b[size - 2];
			}
			calc(b, size - 1, tar);
			if (m.num > n.num)
			{
				b[size - 2].num = m.num - n.num;
				b[size - 2].a = m.num;
				b[size - 2].b = n.num;
				b[size - 2].op = '-';
				if (f)
				{
					item[6 - size] = b[size - 2];
				}
				calc(b, size - 1, tar);
			}
			else if (m.num < n.num)
			{
				b[size - 2].num = n.num - m.num;
				b[size - 2].a = n.num;
				b[size - 2].b = m.num;
				b[size - 2].op = '-';
				if (f)
				{
					item[6 - size] = b[size - 2];
				}
				calc(b, size - 1, tar);
			}
			b[size - 2].num = m.num * n.num;
			b[size - 2].a = m.num;
			b[size - 2].b = n.num;
			b[size - 2].op = '*';
			if (f)
			{
				item[6 - size] = b[size - 2];
			}
			calc(b, size - 1, tar);
			if (m.num % n.num == 0)
			{
				b[size - 2].num = m.num / n.num;
				b[size - 2].a = m.num;
				b[size - 2].b = n.num;
				b[size - 2].op = '/';
				if (f)
				{
					item[6 - size] = b[size - 2];
				}
				calc(b, size - 1, tar);
			}
			else if (n.num % m.num == 0)
			{
				b[size - 2].num = n.num / m.num;
				b[size - 2].a = n.num;
				b[size - 2].b = m.num;
				b[size - 2].op = '/';
				if (f)
				{
					item[6 - size] = b[size - 2];
				}
				calc(b, size - 1, tar);
			}
		}
	}
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < 6; ++i)
		{
			scanf("%d", &arr[i].num);
		}
		scanf("%d", &target);
		g = false;
		for (int i = 0; i < 6; ++i)
			if (arr[i].num == target)
			{
				g = true;
				break;
			}
		if (g)
		{
			printf("Target: %d\nBest approx: %d\n\n", target, target);
		}
		else
		{
			md = N;
			g = false;
			f = false;
			calc(arr, 6, target);
			printf("Target: %d\n", target);
			md = N;
			f = true;
			g = false;
			calc(arr, 6, ans);
			printf("Best approx: %d\n\n", ans);
		}
	}
	return 0;
}

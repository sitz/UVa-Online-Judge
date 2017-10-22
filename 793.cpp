#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

int p[MAX], rank_[MAX];

void make_set(int x)
{
	p[x] = x;
	rank_[x] = 0;
}

void link(int x, int y)
{
	if (rank_[x] > rank_[y])
	{
		p[y] = x;
	}
	else
	{
		p[x] = y;
		if (rank_[x] == rank_[y])
		{
			rank_[y] = rank_[y] + 1;
		}
	}
}

int find_set(int x)
{
	if (x != p[x])
	{
		p[x] = find_set(p[x]);
	}
	return p[x];
}

void union_set(int x, int y)
{
	link(find_set(x), find_set(y));
}

int main()
{
	int numOfCase;
	cin >> numOfCase;
	int f = 0;
	while (numOfCase--)
	{
		if (f)
		{
			cout << endl;
		}
		f = 1;
		int numOfNode;
		cin >> numOfNode;
		for (int i = 1; i <= numOfNode; i++)
		{
			make_set(i);
		}
		int yes = 0, no = 0;
		char cmd;
		int a, b;
		while (true)
		{
			cmd = cin.get();
			if (isalpha(cmd))
			{
				break;
			}
		}
		while (true)
		{
			if (!isalpha(cmd))
			{
				break;
			}
			cin >> a >> b;
			cin.get();
			if (cmd == 'c')
			{
				if (find_set(a) != find_set(b))
				{
					union_set(a, b);
				}
			}
			if (cmd == 'q')
			{
				if (find_set(a) == find_set(b))
				{
					yes++;
				}
				else
				{
					no++;
				}
			}
			cmd = cin.get();
		}
		cout << yes << "," << no << endl;
	}
	return 0;
}

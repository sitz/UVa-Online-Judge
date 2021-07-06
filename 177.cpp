#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, ll = 0, rl = 0, ul = 0, dl = 0;
	string b = "", temp1, temp2;
	while (true)
	{
		scanf("%d", &a);
		ll = 0;
		rl = 0;
		ul = 0;
		dl = 0;
		if (a == 0)
		{
			return 0;
		}
		b = "RU";
		for (int i = 1; i < a; ++i)
		{
			temp1 = b;
			for (int j = 0; j < temp1.size(); ++j)
			{
				if (temp1[j] == 'R')
				{
					temp1[j] = 'U';
				}
				else if (temp1[j] == 'L')
				{
					temp1[j] = 'D';
				}
				else if (temp1[j] == 'U')
				{
					temp1[j] = 'L';
				}
				else
				{
					temp1[j] = 'R';
				}
			}
			temp2 = temp1;
			for (int j = 0; j < temp1.size(); j++)
			{
				temp2[j] = temp1[temp1.size() - j - 1];
			}
			b += temp2;
		}
		int x = 0, y = 0;
		for (int i = 0; i < b.size(); ++i)
		{
			if (b[i] == 'R')
			{
				x += 1;
				if (x > rl)
				{
					rl = x;
				}
			}
			if (b[i] == 'L')
			{
				x -= 1;
				if (x < ll)
				{
					ll = x;
				}
			}
			if (b[i] == 'U')
			{
				y -= 1;
				if (y < ul)
				{
					ul = y;
				}
			}
			if (b[i] == 'D')
			{
				y += 1;
				if (y > dl)
				{
					dl = y;
				}
			}
		}
		const int num = dl - ul;
		string c[num + 1];
		y = (-1) * ul;
		x = (-1) * ll;
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] == 'R')
			{
				x += 1;
				if (c[y].size() < 2 * x)
				{
					c[y].resize(2 * x);
				}
				(c[y])[2 * x - 1] = '_';
			}
			if (b[i] == 'L')
			{
				x -= 1;
				if (c[y].size() < 2 * x + 2)
				{
					c[y].resize(2 * x + 2);
				}
				(c[y])[2 * x + 1] = '_';
			}
			if (b[i] == 'U')
			{
				y -= 1;
				if (c[y + 1].size() < 2 * x + 1)
				{
					c[y + 1].resize(2 * x + 1);
				}
				(c[y + 1])[2 * x] = '|';
			}
			if (b[i] == 'D')
			{
				y += 1;
				if (c[y].size() < 2 * x + 1)
				{
					c[y].resize(2 * x + 1);
				}
				(c[y])[2 * x] = '|';
			}
		}
		bool first = false;
		for (int i = 0; i < num + 1; i++)
		{
			for (int j = 0; j < c[i].size(); j++)
			{
				if ((c[i])[j] != '|' && (c[i])[j] != '_')
				{
					(c[i])[j] = ' ';
				}
			}
		}
		for (int i = 0; i < c[0].size(); i++)
		{
			if ((c[0])[i] != ' ')
			{
				first = true;
				break;
			}
		}
		for (int i = 0; i < num + 1; i++)
		{
			if (a == 1)
			{
				printf("_|\n");
				break;
			}
			if (i == 0 && first == false)
			{
				continue;
			}
			cout << c[i];
			putchar(10);
		}
		putchar('^');
		putchar(10);
	}
}

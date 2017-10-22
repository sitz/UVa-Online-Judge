#include <bits/stdc++.h>

using namespace std;

void south(int *p)
{
	int t1, t2, t3;
	t1 = p[0];
	t2 = p[1];
	t3 = p[2];
	p[0] = t2;
	p[1] = 7 - t1;
	p[2] = t3;
}
void north(int *p)
{
	int t1, t2, t3;
	t1 = p[0];
	t2 = p[1];
	t3 = p[2];
	p[0] = 7 - t2;
	p[1] = t1;
	p[2] = t3;
}
void east(int *p)
{
	int t1, t2, t3;
	t1 = p[0];
	t2 = p[1];
	t3 = p[2];
	p[0] = t3;
	p[1] = t2;
	p[2] = 7 - t1;
}
void west(int *p)
{
	int t1, t2, t3;
	t1 = p[0];
	t2 = p[1];
	t3 = p[2];
	p[0] = 7 - t3;
	p[1] = t2;
	p[2] = t1;
}

int main()
{
	char input[10];
	int i, t;
	while (cin >> t)
	{
		int string[3] = {1, 2, 3};
		if (t == 0)
		{
			break;
		}
		for (i = 1; i <= t; i++)
		{
			cin >> input;
			if (strcmp(input, "south") == 0)
			{
				south(string);
			}
			else if (strcmp(input, "north") == 0)
			{
				north(string);
			}
			else if (strcmp(input, "west") == 0)
			{
				west(string);
			}
			else if (strcmp(input, "east") == 0)
			{
				east(string);
			}
		}
		cout << string[0] << endl;
	}
	return (0);
}

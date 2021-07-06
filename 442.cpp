#include <bits/stdc++.h>

using namespace std;

bool error;
char cmd[500];
int numOfMatrics, idx;

struct Matrics
{
	char alpha;
	int row, col;
	int mul;
} mat[30];

void input()
{
	cin >> numOfMatrics;
	int i;
	for (i = 0; i < numOfMatrics; i++)
	{
		cin >> mat[i].alpha >> mat[i].row >> mat[i].col;
		mat[i].mul = 0;
	}
	cin.get();
}

void init()
{
	idx = 0;
	error = false;
}

Matrics solve()
{
	Matrics t;
	if (cmd[idx] == '(')
	{
		Matrics t1, t2;
		idx++;
		t1 = solve();
		t2 = solve();
		idx++;
		if (t1.col != t2.row)
		{
			error = true;
		}
		t.mul = t1.mul + t2.mul + t1.row * t1.col * t2.col;
		t.row = t1.row;
		t.col = t2.col;
	}
	else if (isalpha(cmd[idx]))
	{
		t.row = mat[cmd[idx] - 'A'].row;
		t.col = mat[cmd[idx] - 'A'].col;
		t.mul = 0;
		idx++;
	}
	else
	{
		idx++;
	}
	return t;
}

int main()
{
	input();
	while (cin.getline(cmd, 500))
	{
		init();
		Matrics matric;
		matric = solve();
		if (error)
		{
			printf("error\n");
		}
		else
		{
			cout << matric.mul << endl;
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define maxn 52

char B[maxn][maxn];
int N;
map<string, int> M;

void Process(int ply)
{
	int i, j, k, l;
	string a, b, c;
	a = b = c = "";
	for (i = 1, k = N; i <= N; i++, k--)
	{
		for (j = 1, l = N; j <= N; j++, l--)
		{
			if (B[j][k] == 1)
			{
				a += i;
				a += j;
			}
			if (B[k][l] == 1)
			{
				b += i;
				b += j;
			}
			if (B[i][l] == 1)
			{
				c += i;
				c += j;
			}
		}
	}
	M[a] = ply;
	M[b] = ply;
	M[c] = ply;
}
string GetString()
{
	string ss = "";
	int i;
	for (i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (B[i][j] == 1)
			{
				ss += i;
				ss += j;
			}
		}
	return ss;
}
void Cal()
{
	int res = 0, win, i, x, y, mv;
	char move;
	string ss;
	for (i = 0; i < 2 * N; i++)
	{
		cin >> x >> y >> move;
		if (res)
			continue;
		if (move == '+')
			B[x][y] = 1;
		else
			B[x][y] = 0;
		ss = GetString();
		if (M[ss] > 0)
		{
			res = 1;
			win = M[ss];
			mv = i + 1;
		}
		else
		{
			M[ss] = i % 2 + 1;
			Process(i % 2 + 1);
		}
	}
	if (res)
	{
		if (win == 1)
			win = 2;
		else
			win = 1;
		cout << "Player " << win << " wins on move " << mv << endl;
	}
	else
		cout << "Draw\n";
	M.clear();
}

int main()
{
	int i, j;
	while (cin >> N && N)
	{
		Cal();
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				B[i][j] = 0;
			}
		}
	}
	return 0;
}

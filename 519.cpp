#include <bits/stdc++.h>

using namespace std;

char sd[] = "FOI";
char IND[100], F[100];
int B[8][8];

struct sss
{
	string pice;
	int val;
};
struct xx
{
	char left, up;
};
vector<sss> v;
int R, C;
void Ini()
{
	int i, j;
	for (i = 0; sd[i]; i++)
	{
		j = sd[i];
		IND[j] = i;
	}
}
int Val(char ss[])
{
	int i, sum = 0, j = 1, k;
	for (i = 0; ss[i]; i++)
	{
		k = ss[i];
		k = IND[k];
		sum += k * j;
		j *= 3;
	}
	return sum;
}
xx Next(int r, int c)
{
	xx temp;
	int k;
	if (c == 1)
		temp.left = 'F';
	else
	{
		k = B[r][c - 1];
		if (v[k].pice[1] == 'F')
			temp.left = 'F';
		else if (v[k].pice[1] == 'I')
			temp.left = 'O';
		else
			temp.left = 'I';
	}
	if (r == 1)
		temp.up = 'F';
	else
	{
		k = B[r - 1][c];
		switch (v[k].pice[2])
		{
		case 'F':
			temp.up = 'F';
			break;
		case 'O':
			temp.up = 'I';
			break;
		case 'I':
			temp.up = 'O';
			break;
		}
	}
	return temp;
}
int Fit(int n, int r, int c)
{
	int k;
	if (r == 1 && v[n].pice[0] != 'F')
		return 0;
	if (r > 1)
	{
		k = B[r - 1][c];
		if (v[k].pice[2] == 'O' && v[n].pice[0] != 'I')
			return 0;
		if (v[k].pice[2] == 'I' && v[n].pice[0] != 'O')
			return 0;
	}
	if (r < R && v[n].pice[2] == 'F')
		return 0;
	if (r == R && v[n].pice[2] != 'F')
		return 0;
	if (c == 1 && v[n].pice[3] != 'F')
		return 0;
	if (c > 1)
	{
		k = B[r][c - 1];
		if (v[k].pice[1] == 'O' && v[n].pice[3] != 'I')
			return 0;
		if (v[k].pice[1] == 'I' && v[n].pice[3] != 'O')
			return 0;
	}
	if (c < C && v[n].pice[1] == 'F')
		return 0;
	if (c == C && v[n].pice[1] != 'F')
		return 0;
	return 1;
}
int Recur(int n, int level, int r, int c)
{
	int i, j, nr, nc;
	int a[100] = {0};
	if (level == R * C)
		return 1;
	B[r][c] = n;
	nr = r;
	nc = c + 1;
	if (c == C)
	{
		nr = r + 1;
		nc = 1;
	}
	F[n] = 1;
	for (i = 0; i < v.size(); i++)
	{
		if (F[i])
			continue;
		if (!Fit(i, nr, nc))
			continue;
		if (a[v[i].val])
			continue;
		a[v[i].val] = 1;
		if (Recur(i, level + 1, nr, nc))
			return 1;
	}
	F[n] = 0;
	return 0;
}
void Cal(int cat, int jut, int flt)
{
	int a[100] = {0};
	int i, f = 0, d;
	xx temp;
	d = 2 * R + 2 * C;
	if (cat != jut || d != flt)
	{
		cout << "NO\n";
		return;
	}
	for (i = 0; i < v.size(); i++)
	{
		if (!Fit(i, 1, 1))
			continue;
		if (a[v[i].val])
			continue;
		a[v[i].val] = 1;
		if (Recur(i, 1, 1, 1))
		{
			f = 1;
			break;
		}
	}
	if (f)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	int i, cav, jut, j, flt;
	char ss[10];
	sss temp;
	Ini();
	while (cin >> R >> C)
	{
		if (!R && !C)
			break;
		cav = jut = flt = 0;
		for (i = 0; i < R * C; i++)
		{
			cin >> ss;
			for (j = 0; ss[j]; j++)
				if (ss[j] == 'I')
					cav++;
				else if (ss[j] == 'O')
					jut++;
				else
					flt++;
			temp.pice = ss;
			temp.val = Val(ss);
			v.push_back(temp);
		}
		Cal(cav, jut, flt);
		memset(F, 0, 100);
		v.clear();
	}
	return 0;
}

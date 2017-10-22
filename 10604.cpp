#include <bits/stdc++.h>

using namespace std;

typedef long bbg;
bbg B[11], Temp[11][11], Pro[11][11], V[1679619], N, C, ind;
char Fg[1679619];
int S[1679619];

int Num(string ss, int l)
{
	int i, j, val = 0, p = 1;
	for (i = 0; i < l; i++)
	{
		j = ss[i] - '0';
		val += (j - 1) * p;
		p *= 6;
	}
	return val;
}
bbg Push_All(string ss)
{
	bbg i, j, k, l, n, m, v, d, temp, temp1;
	bbg min = 2147483647;
	string tt, xx;
	l = ss.length();
	if (l == 2)
	{
		n = ss[0] - '0';
		m = ss[1] - '0';
		temp = Temp[n][m];
		temp1 = Temp[n][m];
		if (temp > temp1)
			temp = temp1;
		return temp;
	}
	if (l <= 8)
	{
		v = Num(ss, l);
		if (Fg[v] == 1)
			return V[v];
		Fg[v] = 1;
		S[ind++] = v;
	}
	for (i = 0; i < l; i++)
	{
		n = ss[i] - '0';
		for (j = 0; j < l; j++)
		{
			if (i == j)
				continue;
			m = ss[j] - '0';
			xx = "";
			tt = "";
			xx += Pro[n][m] + '0';
			for (k = 0; k < l; k++)
			{
				if (k == i || k == j)
					continue;
				tt += ss[k];
			}
			tt += xx;
			sort(tt.begin(), tt.end());
			d = Push_All(tt) + Temp[n][m];
			if (min > d)
				min = d;
		}
	}
	if (l <= 8)
		V[v] = min;
	return min;
}
void Cal()//ok
{
	int i;
	ind = 0;
	string ss = "";
	for (i = 0; i < N; i++)
		ss += B[i] + '0';
	sort(ss.begin(), ss.end());
	cout << Push_All(ss) << endl;
}
void Free()
{
	int i, j;
	for (i = 0; i < ind; i++)
	{
		j = S[i];
		Fg[j] = 0;
		V[j] = 0;
	}
}

int main()
{
	int i, ks, j;
	char ss[100];
	cin >> ks;
	while (ks--)
	{
		cin >> C;
		for (i = 1; i <= C; i++)
			for (j = 1; j <= C; j++)
				cin >> Pro[i][j] >> Temp[i][j];
		cin >> N;
		for (i = 0; i < N; i++)
			cin >> B[i];
		Cal();
		Free();
		cin >> ss;
		if (!strcmp(ss, "."))
			break;
	}
	return 0;
}

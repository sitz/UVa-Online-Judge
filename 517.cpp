#include <bits/stdc++.h>

using namespace std;

int Trans[100];
vector<string> V, R;
map<string, int> M;
string ini, rules;
int N, Ind;

int Gen()
{
	string temp = "";
	int i, a, b, c, d, ind, v;
	Ind = 0;
	V.push_back("");
	while (1)
	{
		temp = "";
		for (i = 0; i < N; i++)
		{
			ind = (i - 2 + N) % N;
			a = ini[ind] - 'a';
			b = ini[i] - 'a';
			c = ini[(i + 1) % N] - 'a';
			v = a * 4 + b * 2 + c;
			temp += Trans[v] + 'a';
		}
		if (M[temp])
		{
			return M[temp];
			break;
		}
		M[temp] = ++Ind;
		ini = temp;
		V.push_back(temp);
	}
}
void Cal(int n)
{
	int s, i, d, id, k;
	string a, b;
	k = Gen();
	if (n < k)
		a = V[n];
	else
	{
		s = V.size() - 1;
		d = s - k + 1;
		n -= k;
		n %= d;
		a = V[k + n];
	}
	for (i = 0; i < N; i++)
	{
		id = i;
		b = "";
		s = 0;
		while (s++ < N)
		{
			b += a[id];
			id++;
			id %= N;
		}
		R.push_back(b);
	}
	sort(R.begin(), R.end());
	cout << R[0] << endl;
}
void Free()
{
	M.clear();
	V.clear();
	R.clear();
}

int main()
{
	int n, a, b, c, d, v;
	while (cin >> N)
	{
		cin >> ini;
		n = 8;
		while (n--)
		{
			cin >> rules;
			a = rules[0] - 'a';
			b = rules[1] - 'a';
			c = rules[2] - 'a';
			d = rules[3] - 'a';
			v = a * 4 + b * 2 + c;
			Trans[v] = d;
		}
		cin >> n;
		if (n == 0)
		{
			cout << ini << endl;
			continue;
		}
		Cal(n);
		Free();
	}
	return 0;
}

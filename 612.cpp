#include <bits/stdc++.h>

using namespace std;

class DNA
{
public:
	char string[60];
	int s;
};

int main()
{
	int solve(char *p, int x);
	void paixu(DNA * p, int *q, int x);
	DNA dna[100];
	int n, m;
	int sorted[100];
	int i, cnt;
	cin >> cnt;
	for (i = 0; i < cnt; i++)
	{
		cin >> n >> m;
		int r;
		for (r = 0; r < m; r++)
		{
			cin >> dna[r].string;
		}
		for (r = 0; r < m; r++)
		{
			dna[r].s = solve(dna[r].string, n);
		}
		paixu(dna, sorted, m);
		for (r = 0; r < m; r++)
		{
			cout << dna[sorted[r]].string << endl;
		}
		if (i != cnt - 1)
		{
			cout << endl;
		}
	}
	return 0;
}

int solve(char *p, int x)
{
	int i, j;
	int cnt = 0;
	for (i = 0; i < x - 1; i++)
		for (j = i + 1; j < x; j++)
			if (p[i] > p[j])
			{
				cnt++;
			}
	return cnt;
}

void paixu(DNA *p, int *q, int x)
{
	int i, j;
	int row;
	int min;
	for (i = 0; i < x; i++)
	{
		min = 1000000;
		for (j = 0; j < x; j++)
		{
			if (p[j].s < min)
			{
				min = p[j].s;
				row = j;
			}
		}
		q[i] = row;
		p[row].s = 1000000;
	}
}

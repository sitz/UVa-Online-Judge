#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x)

int N;
char Table[105][105];

int getVal(char x)
{
	if (x == '-')
	{
		return -1;
	}
	if (x == '0')
	{
		return 0;
	}
	if (x == '+')
	{
		return 1;
	}
	return 0;
}
void swapRow(int a, int b)
{
	for (int q = 0; q < N; q++)
	{
		swap(Table[a][q], Table[b][q]);
	}
}
void swapCol(int a, int b)
{
	for (int q = 0; q < N; q++)
	{
		swap(Table[q][a], Table[q][b]);
	}
}
int compRow(int a, int b)
{
	int ret = 0;
	for (int q = 0; q < N; q++)
	{
		if (Table[a][q] == Table[b][q])
		{
			continue;
		}
		int t = getVal(Table[a][q]) < getVal(Table[b][q]) ? -1 : 1;
		if (ret != 0 && ret != t)
		{
			return -5;
		}
		ret = t;
	}
	return ret;
}
int compCol(int a, int b)
{
	int ret = 0;
	for (int q = 0; q < N; q++)
	{
		if (Table[q][a] == Table[q][b])
		{
			continue;
		}
		int t = getVal(Table[q][a]) < getVal(Table[q][b]) ? -1 : 1;
		if (ret != 0 && ret != t)
		{
			return -5;
		}
		ret = t;
	}
	return ret;
}
int main()
{
	for (int kase = 1;; ++kase)
	{
		scanf("%d", &N);
		if (N < 0)
		{
			break;
		}
		printf("Case %d: ", kase);
		for (int q = 0; q < N; ++q)
		{
			scanf("%s", Table[q]);
		}
		int isBad = 0;
		for (int q = 0; q < N; ++q)
			for (int w = q + 1; w < N; ++w)
				if (compRow(q, w) < -1 || compCol(q, w) < -1)
				{
					isBad = 1;
				}
		if (isBad)
		{
			printf("-1\n");
			continue;
		}
		for (int q = 0; q < N; q++)
			for (int w = q + 1; w < N; ++w)
				if (compRow(q, w) < 0)
				{
					swapRow(q, w);
				}
		for (int q = 0; q < N; q++)
			for (int w = q + 1; w < N; ++w)
				if (compCol(q, w) < 0)
				{
					swapCol(q, w);
				}
		DEBUG(printf("Result:\n"));
		DEBUG(for (int q = 0; q < N; q++) printf("%s\n", Table[q]));
		vector<int> C_p, R_n;
		for (int q = 0; q < N; q++)
			if (Table[0][q] == '+')
				if (C_p.empty() || compCol(C_p.back(), q) != 0)
				{
					C_p.push_back(q);
				}
		for (int q = N - 1; q > 0; q--)
			if (compRow(q, 0) != 0)
				if (R_n.empty() || compRow(R_n.back(), q) != 0)
				{
					R_n.push_back(q);
				}
		DEBUG(printf("C+:"); for (int q = 0; q < C_p.size(); q++) printf("%d ", C_p[q]); printf("\n"));
		DEBUG(printf("R-:"); for (int q = 0; q < R_n.size(); q++) printf("%d ", R_n[q]); printf("\n"));
		vector<vector<int>> buff;
		int i = 0, j = 0;
		while (i < C_p.size() || j < R_n.size())
		{
			buff.push_back(vector<int>());
			if (i >= C_p.size())
			{
				buff.back().push_back(R_n[j] * 2);
				j++;
				continue;
			}
			if (j >= R_n.size())
			{
				buff.back().push_back(C_p[i] * 2 + 1);
				i++;
				continue;
			}
			int c = C_p[i];
			int r = R_n[j];
			if (Table[r][c] == '+')
			{
				buff.back().push_back(c * 2 + 1);
				i++;
			}
			if (Table[r][c] == '-')
			{
				buff.back().push_back(r * 2);
				j++;
			}
			if (Table[r][c] == '0')
			{
				buff.back().push_back(c * 2 + 1);
				i++;
				buff.back().push_back(r * 2);
				j++;
			}
		}
		vector<int> rows, cols;
		for (int q = 0; q < buff.size(); ++q)
			for (int w = 0; w < buff[q].size(); ++w)
				if (buff[q][w] & 1)//col,+
				{
					int col = buff[q][w] / 2;
					int val = (buff.size() - q);
					for (int e = 0; e < N; ++e)
						if (compCol(col, e) == 0)
						{
							cols.push_back(val);
						}
				}
				else//row,-
				{
					int row = buff[q][w] / 2;
					int val = -(buff.size() - q);
					for (int e = 0; e < N; ++e)
						if (compRow(row, e) == 0)
						{
							rows.push_back(val);
						}
				}
		//row,+ -> null
		//row,0
		for (int q = 0; q < N; ++q)
			if (compRow(0, q) == 0)
			{
				rows.push_back(0);
			}
		//col,0
		for (int q = 0; q < N; ++q)
			if (Table[0][q] == '0')
			{
				cols.push_back(0);
			}
		//col,-
		int T = 0;
		for (int q = 0; q < N; ++q)
			if (Table[0][q] == '-')
			{
				if (q == 0 || compCol(q - 1, q) != 0)
				{
					T--;
				}
				cols.push_back(T);
			}
		sort(rows.rbegin(), rows.rend());
		sort(cols.rbegin(), cols.rend());
		DEBUG(printf("Debug:\n"));
		for (int q = 0; q < rows.size(); q++)
		{
			for (int w = 0; w < cols.size(); ++w)
			{
				int val = rows[q] + cols[w];
				char ret = '0';
				if (val < 0)
				{
					ret = '-';
				}
				if (val > 0)
				{
					ret = '+';
				}
				if (ret != Table[q][w])
				{
					isBad = 1;
				}
				DEBUG(printf("%c", ret));
			}
			DEBUG(printf("\n"));
		}
		if (isBad)
		{
			printf("-1\n");
			continue;
		}
		vector<int> mix;
		for (int q = 0; q < rows.size(); ++q)
		{
			mix.push_back(-rows[q]);
		}
		for (int q = 0; q < cols.size(); ++q)
		{
			mix.push_back(cols[q]);
		}
		sort(mix.begin(), mix.end());
		if (mix.size() == 0)
		{
			printf("0\n");
			continue;
		}
		int k = mix[mix.size() / 2];
		int ret = 0;
		for (int q = 0; q < mix.size(); ++q)
		{
			ret += abs(mix[q] - k);
		}
		printf("%d\n", ret);
	}
	return 0;
}

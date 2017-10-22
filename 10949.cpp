#include <bits/stdc++.h>

using namespace std;

char map_[30][30];

string trans(string &w, int x, int y)
{
	int N = w.size();
	string s;
	s.resize(N + 1);
	s[0] = map_[x][y];
	for (int i = 0; i < N; ++i)
	{
		switch (w[i])
		{
		case 'E':
			y++;
			break;
		case 'W':
			y--;
			break;
		case 'N':
			x--;
			break;
		case 'S':
			x++;
			break;
		}
		s[i + 1] = map_[x][y];
	}
	return s;
}

int LCS(string &s1, string &s2)
{
	int i;
	vector<int> alpha[128];
	int LCS[20005] = {0};
	int n1 = s1.size(), n2 = s2.size(), n = 0;
	for (i = 0; i < n1; ++i)
	{
		alpha[s1[i]].push_back(i + 1);
	}
	for (i = 0; i < n2; ++i)
	{
		vector<int> &c = alpha[s2[i]];
		if (c.size() == 0)
		{
			continue;// s1無此字
		}
		if (n == 0)
		{
			LCS[n++] = c[0];
			continue;
		}// 最初陣列是空的
		int p = c.size() - 1;
		if (c[p] > LCS[n - 1])
		{
			LCS[n++] = c[p--];// 比尾端還大
		}
		int q = n - 1;
		for (; p >= 0; --p)// 往回找
		{
			while (q >= 0 && c[p] <= LCS[q])
			{
				q--;
			}
			LCS[q + 1] = c[p];
		}
	}
	return n;
}

int main()
{
	int cs;
	cin >> cs;
	for (int cn = 1; cn <= cs; ++cn)
	{
		int X, Y;
		cin >> X >> Y;
		for (int i = 0; i < X; ++i)
			for (int j = 0; j < Y; ++j)
			{
				cin >> map_[i][j];
			}
		int n1, n2, x, y;
		string s1, s2, buf;
		cin >> n1 >> x >> y;
		getline(cin, buf);
		getline(cin, s1);
		s1 = trans(s1, x - 1, y - 1);
		cin >> n2 >> x >> y;
		getline(cin, buf);
		getline(cin, s2);
		s2 = trans(s2, x - 1, y - 1);
		int n = LCS(s1, s2);
		cout << "Case " << cn << ": " << n1 - n + 1 << " " << n2 - n + 1 << endl;
	}
	return 0;
}

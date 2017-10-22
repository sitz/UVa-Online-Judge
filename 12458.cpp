#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

const int INF = 1 << 30;

template <class T>
struct interval
{
	T a, b;
};

bool cover(const interval<int> &I, int data)
{
	return I.a <= data && data <= I.b;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int h;
		scanf("%d ", &h);
		vector<vector<int>> data(h);
		rep(i, h)
		{
			static char s[100000];
			gets(s);
			for (int j = 0, a = 0;; j++)
			{
				if (s[j] == ' ' || s[j] == '\0')
				{
					if (j == 0 || s[j - 1] == ' ')
					{
						continue;
					}
					data[i].push_back(a);
					a = 0;
					if (s[j] == '\0')
					{
						break;
					}
				}
				else
				{
					a = 10 * a + (s[j] - '0');
				}
			}
		}
		vector<vector<int>> L(h), R(h);// answer
		vector<vector<interval<int>>> I(h);
		rep(i, h)
		{
			L[i].assign(data[i].size(), INF);
			R[i].assign(data[i].size(), INF);
			I[i].assign(data[i].size(), (interval<int>){
																			-INF, INF});
		}
		for (int i = 1; i < h; i++)
		{
			rep(j, data[i].size())
			{
				int a = data[i][j];
				rep(k, data[i - 1].size()) if (cover(I[i - 1][k], a))
				{
					if (a < data[i - 1][k])
						L[i - 1][k] = a, I[i][j] = (interval<int>){
																 I[i - 1][k].a, data[i - 1][k] - 1};
					else
						R[i - 1][k] = a, I[i][j] = (interval<int>){
																 data[i - 1][k] + 1, I[i - 1][k].b};
				}
			}
		}
		rep(i, h)
				rep(j, data[i].size())
		{
			printf("%d:", data[i][j]);
			if (L[i][j] != INF)
				printf("%d", L[i][j]);
			putchar('-');
			if (R[i][j] != INF)
				printf("%d", R[i][j]);
			putchar('\n');
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

// String

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 50000
#define LL long long

#define F(i, a, b) for (int i = (a); i < (b); i++)
#define Fs(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fe(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define Pr(x)                                                 \
	for (typeof(x.begin()) it = x.begin(); it != x.end(); it++) \
		cout << *it << " ";                                       \
	cout << endl;
#define Set(a, s) memset(a, s, sizeof(a))

string str[26 + 3][26 + 3];

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	string tmp;
	while (testCase--)
	{
		int n;
		scanf("%d", &n);
		bool isRowValid[26 + 3];
		Set(isRowValid, true);
		bool isLetter[26 + 3][26 + 3];
		Set(isLetter, false);
		for (int i = 0; i < n; i++)
		{
			int k;
			scanf("%d", &k);
			for (int j = 0; j < k; j++)
			{
				cin >> tmp;
				str[i][j] = "";
				for (size_t p = 0; p < tmp.size(); p++)
					str[i][j] += tolower(tmp[p]);
				isLetter[i][str[i][j].at(0) - 'a'] = true;
			}
		}
		string output[26 + 3];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int cnt = 0;
				int ind;
				for (int k = 0; k < n; k++)
					if (isRowValid[k] && isLetter[k][j])
					{
						cnt++;
						ind = k;
					}
				if (cnt == 1)
				{
					isRowValid[ind] = false;
					for (int k = 0; k < n; k++)
						if (str[ind][k].at(0) - 'a' == j)
						{
							output[i] = str[ind][k];
							j = n;
							break;
						}
				}
			}
		}
		sort(output, output + n);
		printf("Case #%d:\n", ++cases);
		for (int i = 0; i < n; i++)
		{
			printf("%c", toupper(output[i][0]));
			for (size_t j = 1; j < output[i].size(); j++)
				printf("%c", output[i][j]);
			printf("\n");
		}
	}
	return 0;
}

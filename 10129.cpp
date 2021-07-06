#include <bits/stdc++.h>

using namespace std;

#define Maxn 100000

int T, N, cou[130], in[130], out[130];
char Graph[130][Maxn];
bool yes, mark[200];

int main()
{
	cin >> T;
	char c, rec, sc;
	while (T--)
	{
		yes = false;
		memset(in, 0, sizeof(in));
		memset(cou, 0, sizeof(cou));
		memset(mark, false, sizeof(mark));
		memset(out, 0, sizeof(out));
		cin >> N;
		getchar();
		int tc = 0;
		for (int i = 0; i < N; i++)
		{
			while (1)
			{
				scanf("%c", &c);
				if (tc == 0)
				{
					sc = c, tc = 1;
				}
				if (c == '\n')
				{
					Graph[sc][cou[sc]++] = rec;
					Graph[rec][cou[rec]++] = sc;
					if (!mark[rec])
					{
						mark[rec] = true;
					}
					if (!mark[sc])
					{
						mark[sc] = true;
					}
					in[rec]++;
					out[sc]++;
					tc = 0;
					break;
				}
				rec = c;
			}
		}
		queue<char> q;
		for (char i = 'a'; i <= 'z'; i++)
		{
			if (mark[i])
			{
				mark[i] = false;
				q.push(i);
				break;
			}
		}
		while (!q.empty())
		{
			char tch = q.front();
			q.pop();
			for (int j = 0; j < cou[tch]; j++)
			{
				if (mark[Graph[tch][j]] == true)
				{
					mark[Graph[tch][j]] = false;
					q.push(Graph[tch][j]);
				}
			}
		}
		int ans = 0;
		for (int i = 'a'; i <= 'z'; i++)
		{
			if (mark[i] == true)
			{
				ans = 2;
				break;
			}
		}
		int oyes = 0, iyes = 0;
		for (char i = 'a'; ans != 2 && i <= 'z'; i++)
		{
			int temp = in[i] - out[i];
			if (temp >= 2 || temp <= -2)
			{
				ans = 2;
				break;
			}
			if (temp == 1)
			{
				iyes++;
			}
			if (temp == -1)
			{
				oyes++;
			}
		}
		if (ans == 0 && ((iyes == 1 && oyes == 1) || (iyes == 0 && oyes == 0)))
		{
			ans = 1;
		}
		cout << (ans == 1 ? "Ordering is possible." : "The door cannot be opened.") << endl;
	}
	return 0;
}

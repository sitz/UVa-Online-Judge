#include <bits/stdc++.h>

using namespace std;

bool alpha[26], digit[10];
char words[5][10];
int len[5], x[26];
int n;
void swap(char &a, char &b)
{
	char c = a;
	a = b;
	b = c;
}
bool DFS(int r, int c, int sum)
{
	if (c == len[n - 1])
	{
		int t[26], s = 0;
		for (int i = 0; i < 26; i++)
			if (x[i] != -1)
			{
				t[s++] = i;
			}
		for (int i = 0; i < s; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%c=%d", t[i] + 'A', x[t[i]]);
		}
		printf("\n");
		return true;
	}
	int index = words[r][c] - 'A';
	if (r == n - 1)
	{
		if (x[index] != -1)
		{
			if (sum % 10 != x[index])
			{
				return false;
			}
			return DFS(0, c + 1, sum / 10);
		}
		else
		{
			int t = sum % 10;
			if (digit[t])
			{
				return false;
			}
			x[index] = sum % 10;
			digit[t] = true;
			if (DFS(0, c + 1, sum / 10))
			{
				return true;
			}
			digit[t] = false;
			x[index] = -1;
			return false;
		}
	}
	if (c >= len[r])
	{
		return DFS(r + 1, c, sum);
	}
	if (x[index] != -1)
	{
		return DFS(r + 1, c, sum + x[index]);
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (len[r] > 1 && c == len[r] - 1 && i == 0)
			{
				continue;
			}
			if (!digit[i])
			{
				digit[i] = true;
				x[index] = i;
				if (DFS(r + 1, c, sum + i))
				{
					return true;
				}
				x[index] = -1;
				digit[i] = false;
			}
		}
		return false;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		memset(alpha, false, sizeof(alpha));
		memset(digit, false, sizeof(digit));
		memset(len, 0, sizeof(len));
		memset(x, -1, sizeof(x));
		for (int i = 0; i < n; i++)
		{
			scanf("%s", words[i]);
			len[i] = strlen(words[i]);
			for (int j = 0; j < len[i]; j++)
			{
				alpha[words[i][j] - 'A'] = true;
			}
			for (int j = 0, k = len[i] - 1; j < k; j++, k--)
			{
				swap(words[i][j], words[i][k]);
			}
		}
		DFS(0, 0, 0);
	}
	return 0;
}

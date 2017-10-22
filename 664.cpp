#include <bits/stdc++.h>

using namespace std;

double matrix[26][27], temp[27];
char str[1000];
int n, len;
double DFS(int left, int right)
{
	double t[27];
	double count = 0;
	memset(t, 0, sizeof(t));
	for (int ptr = left + 1; ptr < right; ptr++)
	{
		if (str[ptr] == ' ')
		{
			continue;
		}
		if (str[ptr] >= 'a' && str[ptr] <= 'z')
		{
			t[str[ptr] - 'a'] += 1.0;
			count++;
		}
		else if (str[ptr] == '(')
		{
			int s, match = 1;
			for (s = ptr + 1; match > 0; s++)
			{
				if (str[s] == '(')
				{
					match++;
				}
				if (str[s] == ')')
				{
					match--;
				}
			}
			double num = DFS(ptr, s);
			for (int i = 0; i < 27; i++)
			{
				t[i] += temp[i] / num;
			}
			ptr = s;
			count++;
		}
		else if (str[ptr] != ')')
		{
			bool f = true;
			if (str[ptr] == '-')
			{
				f = false;
				ptr++;
			}
			double x = 0;
			int y;
			for (y = ptr; str[y] >= '0' && str[y] <= '9'; y++)
			{
				x = x * 10 + str[y] - '0';
			}
			if (!f)
			{
				x *= -1;
			}
			t[n] += x;
			ptr = y;
			count++;
		}
	}
	for (int i = 0; i < 27; i++)
	{
		temp[i] = t[i];
	}
	return count;
}
void solve()
{
	bool s[26];
	memset(s, true, sizeof(s));
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][i])
		{
			double t = matrix[i][i];
			for (int j = i; j <= n; j++)
			{
				matrix[i][j] /= t;
			}
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					continue;
				}
				double b = matrix[j][i] / matrix[i][i];
				for (int k = i; k <= n; k++)
				{
					matrix[j][k] -= matrix[i][k] * b;
				}
			}
		}
		else
		{
			s[i] = false;
			for (int j = 0; j < n; j++)
				if (j != i && matrix[j][i])
				{
					s[j] = false;
				}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i])
		{
			printf("Expected score for %c = %.3lf\n", i + 'a', matrix[i][n] / matrix[i][i]);
		}
		else
		{
			printf("Expected score for %c undefined\n", i + 'a');
		}
	}
}
int main()
{
	int caseno = 1;
	while (gets(str) != NULL)
	{
		if (strcmp(str, "0") == 0)
		{
			break;
		}
		printf("Game %d\n", caseno++);
		sscanf(str, "%d", &n);
		memset(matrix, 0, sizeof(matrix));
		for (int i = 0; i < n; i++)
		{
			gets(str);
			matrix[i][str[0] - 'a'] = 1.0;
			len = strlen(str);
			int s;
			for (s = 0; str[s] != '('; s++)
				;
			double num = DFS(s, len - 1);
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] -= temp[j] / num;
			}
			matrix[i][n] = temp[n] / num;
		}
		solve();
		puts("");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int depth, N;
char s[210][210], str[210];
bool valid(char c)
{
	return !(c == ' ' || c == '\0' || c == '\n' || c == '-' || c == '|' || c == '#');
}
void print(int r, int c, char ch)
{
	printf("%c(", ch);
	int left, right;
	if (r + 3 <= depth && s[r + 1][c] == '|')
	{
		for (left = c; left >= 0 && s[r + 2][left] == '-'; left--)
			;
		for (right = c; s[r + 2][right] == '-'; right++)
			;
		for (int k = left + 1; k < right; k++)
			if (valid(s[r + 3][k]))
			{
				print(r + 3, k, s[r + 3][k]);
			}
	}
	printf(")");
}
int main()
{
	fgets(str, 210, stdin);
	sscanf(str, "%d\n", &N);
	while (N--)
	{
		memset(s, 0, 210 * 210);
		for (depth = 0;; ++depth)
		{
			fgets(s[depth], 210, stdin);
			int k;
			for (k = strlen(s[depth]); k >= 0; --k)
				if (s[depth][k] != '\0' && s[depth][k] != ' ' && s[depth][k] != '\n')
				{
					break;
				}
			s[depth][k + 1] = '\0';
			if (strcmp(s[depth], "#") == 0)
			{
				break;
			}
		}
		printf("(");
		for (int i = 0; i < (int)strlen(s[0]); i++)
		{
			if (valid(s[0][i]))
			{
				print(0, i, s[0][i]);
				break;
			}
		}
		printf(")\n");
	}
	return 0;
}

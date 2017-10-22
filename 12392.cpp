#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5;

int N, M;
int vs[MAX_N];
bool used_char[0x100];
int val[0x100];
int p, L;
char line[100001];

void init()
{
	for (int i = 0; i < N; i++)
	{
		scanf("%d", vs + i);
	}
	scanf("%d ", &M);
	scanf("%[^\n]%*c", line);
	memset(used_char, false, sizeof(used_char));
}

int expr()
{
	int ret = 0;
	if (line[p] == '(')
	{
		p++;
		ret = expr();
		p++;
	}
	else if (isalpha(line[p]))
	{
		ret = val[line[p++]];
	}
	char op = line[p];
	if (op == '+' || op == '-' || op == '*')
	{
		p++;
		int b = expr();
		if (op == '+')
		{
			return ret + b;
		}
		else if (op == '-')
		{
			return ret - b;
		}
		else
		{
			return ret * b;
		}
	}
	return ret;
}

bool sub()
{
	p = 0;
	for (char c = 'a'; c <= 'z'; c++)
	{
		if (used_char[c])
		{
			val[c] = vs[p++];
		}
	}
	p = 0;
	int e = expr();
	return e == M;
}

bool solve()
{
	L = strlen(line);
	sort(vs, vs + N);
	for (int i = 0; i < L; i++)
	{
		if (isalpha(line[i]))
		{
			used_char[line[i]] = true;
		}
	}
	do
	{
		if (sub())
		{
			return true;
		}
	} while (next_permutation(vs, vs + N));
	return false;
}

int main()
{
	while (scanf("%d", &N), N)
	{
		init();
		puts(solve() ? "YES" : "NO");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool seen[128];
char map_[5][5], whereis[128], row[128], col[128], phrase[2048], tocipher[2048], cipherTIME[2048];

void encrypt(char a, char b)
{
	if (row[a] == row[b])
	{
		a = map_[row[a]][(col[a] + 1) % 5];
		b = map_[row[b]][(col[b] + 1) % 5];
	}
	else if (col[a] == col[b])
	{
		a = map_[(row[a] + 1) % 5][col[a]];
		b = map_[(row[b] + 1) % 5][col[b]];
	}
	else
	{
		int r1 = row[a], r2 = row[b];
		int c1 = col[a], c2 = col[b];
		a = map_[r1][c2];
		b = map_[r2][c1];
	}
	putc(a, stdout);
	putc(b, stdout);
}

int main()
{
	int N, map__pos;
	scanf("%d\n", &N);
	while (N--)
	{
		memset(seen, 0, sizeof(seen));
		memset(phrase, 0, 2048);
		memset(tocipher, 0, 2048);
		fgets(phrase, 2048, stdin);
		fgets(tocipher, 2048, stdin);
		char *c = phrase;
		map__pos = 0;
		for (char *c = phrase; *c; ++c)
		{
			if (islower(*c))
			{
				*c -= 32;
			}
			if (!isupper(*c) || seen[*c])
			{
				continue;
			}
			map_[map__pos / 5][map__pos % 5] = *c;
			row[*c] = map__pos / 5;
			col[*c] = map__pos % 5;
			seen[*c] = 1;
			map__pos++;
		}
		for (char c = 'A'; c <= 'Z'; ++c)
		{
			if (seen[c] || c == 'Q')
			{
				continue;
			}
			map_[map__pos / 5][map__pos % 5] = c;
			row[c] = map__pos / 5;
			col[c] = map__pos % 5;
			map__pos++;
		}
		char *ct = cipherTIME;
		for (c = tocipher; *c; ++c)
			if (islower(*c))
			{
				*ct++ = (*c) - 32;
			}
		*ct = *(ct + 1) = 0;
		for (char *c = cipherTIME, *n;;)
		{
			if (!(*c))
			{
				break;
			}
			n = c + 1;
			if (*c == *n || (*n == 0))
			{
				encrypt(*c, 'X');
				--n;
			}
			else
			{
				encrypt(*c, *n);
			}
			c = n + 1;
		}
		putc(10, stdout);
	}
	return 0;
}

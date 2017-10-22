#include <bits/stdc++.h>

using namespace std;

#define MAX_CARS 300
#define MAX_LEN 15000
#define BITMAP_LEN ((MAX_LEN + 1 + 31) >> 5)

typedef unsigned int uint;

int max_len, bl, n, len[MAX_CARS + 1];
uint mask, b[MAX_CARS + 1][BITMAP_LEN], tmp[BITMAP_LEN];
bool sol[MAX_CARS + 1];

bool get(uint *src, int i)
{
	return ((src[i >> 5] & (1U << (i & 0x1F))) != 0);
}

void print_set(uint *src)
{
	bool first = true;
	for (int i = 0; i <= max_len; i++)
	{
		if (get(src, i))
		{
			if (first)
			{
				first = false;
			}
			else
			{
				printf(" ");
			}
			printf("%d", i);
		}
	}
}

void init()
{
	bl = (max_len + 1) >> 5;
	int x = (max_len + 1) & 0x1F;
	if (x == 0)
	{
		bl--;
		mask = (uint)(-1);
	}
	else
	{
		mask = (1U << x) - 1;
	}
	uint *p = b[0];
	p[0] = 1;
	for (int i = 1; i <= bl; i++)
	{
		p[i] = 0;
	}
	n = 0;
}

void do_shift(uint *src, uint *dest, int sh)
{
	int sh1 = sh & 0x1F;
	if (sh1)
	{
		int sh2 = 32 - sh1;
		uint prev = 0;
		for (int i = 0; i <= bl; i++)
		{
			uint x = src[i];
			dest[i] = (x << sh1) | prev;
			prev = (x >> sh2);
		}
	}
	else
	{
		memcpy(dest, src, (bl + 1) * sizeof(uint));
	}
	sh >>= 5;
	if (sh)
	{
		if (sh > bl)
		{
			sh = bl + 1;
		}
		else
		{
			memmove(dest + sh, dest, (bl + 1 - sh) * sizeof(uint));
		}
		memset(dest, 0, sh * sizeof(uint));
	}
	dest[bl] &= mask;
}

void do_or(uint *src1, uint *src2, uint *dest)
{
	for (int i = 0; i <= bl; i++)
	{
		dest[i] = src1[i] | src2[i];
	}
}

void do_zero(uint *dest, int x)
{
	int k = x >> 5;
	if (k > 0)
	{
		memset(dest, 0, k * sizeof(uint));
	}
	dest[k] &= ~((1U << (x & 0x1F)) - 1);
}

bool is_zero(uint *src)
{
	for (int i = 0; i <= bl; i++)
	{
		if (src[i])
		{
			return false;
		}
	}
	return true;
}

int find_non_zero(uint *src)
{
	for (int i = 0; i <= bl; i++)
	{
		if (src[i])
		{
			uint x = src[i];
			i <<= 5;
			while ((x & 1) == 0)
			{
				i++;
				x >>= 1;
			}
			return i;
		}
	}
	return -1;
}

void solve()
{
	int sum = 0;
	while (1)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)
		{
			break;
		}
		len[++n] = x;
		sum += x;
		do_shift(b[n - 1], tmp, x);
		do_or(b[n - 1], tmp, b[n]);
		if (sum > max_len)
		{
			int y = sum - max_len;
			if (y > max_len)
			{
				y = max_len + 1;
			}
			do_zero(b[n], y);
			if (is_zero(b[n]))
			{
				n--;
				do
				{
					scanf("%d", &x);
				} while (x != 0);
				return;
			}
		}
	}
}

void print_solution()
{
	printf("%d\n", n);
	int s = find_non_zero(b[n]);
	for (int i = n; i > 0; i--)
	{
		int x = len[i];
		if (x <= s)
		{
			if (get(b[i - 1], s - x))
			{
				sol[i] = true;
				s -= x;
			}
			else
			{
				sol[i] = false;
			}
		}
		else
		{
			sol[i] = false;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		puts(sol[i] ? "port" : "starboard");
	}
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++)
	{
		scanf("%d", &max_len);
		max_len *= 100;
		init();
		solve();
		if (i > 0)
		{
			putchar('\n');
		}
		print_solution();
	}
	return 0;
}

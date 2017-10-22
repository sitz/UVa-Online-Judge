#include <bits/stdc++.h>

using namespace std;

// algo for each (plain-text, cipher-text) pair is
// as follows. Values for k (the period length) are considered in
// turn from 1 up to the text length. For each value of k:
// 1. exists_permute is called to check that k is possible.  For every
//    full block, it is checked that the frequencies of plain text characters
//    matches that of the cipher text characters (if not one can't be a
//    permutation of the other).  If the final block is not a full block
//    then it isn't checked.
// 2. The overall set of bit maps is initialised---one for each position
//    in the line (0..linelen).  For overall[i], bit j is set if character
//    j in the cipher text is the same as character i in the plain text, and is
//    0 otherwise.
// 3. The k bitmaps (maps) are calculated based on the overall bitmaps.
//    maps[i] shows for position i in the block, the set of bit positions
//    in the cipher text that position i could be mapped to.  If any maps[i]
//    is 0 then the current value of k must be wrong.
// 4. Try to find a permutation based on maps.  Start with the plaintext
//    characters with the fewest possible cipher text positions.  Try all
//    possible combinations.
// 5. If a permutation is found print the details.

// maxlen of ciphertxt + plaintxt str
#define MAXLEN 256
// len(char[]) needed to hold a bitmap of maxlen bits
#define BIT_LEN (MAXLEN / 8)
#define NUM_CHARS 256

typedef unsigned char *bitmap;

struct lst
{
	int posn;
	bitmap b;
	int num_bits;
	struct lst *next;
} lst_arr[MAXLEN], *head;

string plain, cipher, cipher2;
int mapping[MAXLEN], linelen;
bitmap *maps, *overall;

static void clear_bits(bitmap b)
{
	for (int i = 0; i < BIT_LEN; i++)
	{
		b[i] = 0;
	}
}

static void set_bits(bitmap b)
{
	for (int i = 0; i < BIT_LEN; i++)
	{
		b[i] = 0xff;
	}
}

static int get_bit(bitmap b, int bit)
{
	int word = bit / 8;
	int offset = bit % 8;
	return (b[word] >> offset) & 1;
}

static void set_bit(bitmap b, int bit, int value)
{
	int word = bit / 8;
	int offset = bit % 8;
	if (value)
	{
		b[word] |= 1 << offset;
	}
	else
	{
		b[word] &= ~(1 << offset);
	}
}

static void and_bits(bitmap op1, bitmap op2)
{
	int i;
	for (i = 0; i < BIT_LEN; i++)
	{
		op1[i] &= op2[i];
	}
}

static int zero_bits(bitmap b)
{
	int i;
	for (i = 0; i < BIT_LEN; i++)
	{
		if (b[i])
		{
			return 0;
		}
	}
	return 1;
}

static int count_bits(bitmap b)
{
	int i;
	int cnt = 0;
	for (i = 0; i < MAXLEN; i++)
	{
		if (get_bit(b, i))
		{
			cnt++;
		}
	}
	return cnt;
}

static int exists_permute(int k, int linelen)
{
	int pcnt[NUM_CHARS], ccnt[NUM_CHARS];
	for (int block = 0; block + k < linelen; block += k)
	{
		for (int i = 0; i < NUM_CHARS; i++)
		{
			pcnt[i] = ccnt[i] = 0;
		}
		for (int i = 0; i < k && block + i < linelen; i++)
		{
			pcnt[plain[block + i]]++;
			ccnt[cipher[block + i]]++;
		}
		for (int i = 0; i < NUM_CHARS; i++)
		{
			if (pcnt[i] != ccnt[i])
			{
				return 0;
			}
		}
	}
	return 1;
}

static int compute_map(int i, int k, int linelen)
{
	int posn, j, block;
	static bitmap tmp;
	if (!tmp)
	{
		tmp = (bitmap) malloc(BIT_LEN);
	}
	// calc pos i for cycle length == k
	set_bits(maps[i]);
	for (posn = i; posn < linelen; posn += k)
	{
		clear_bits(tmp);
		block = (posn / k) * k;
		for (j = block; j < block + k; j++)
		{
			if (j >= linelen || get_bit(overall[posn], j))
			{
				set_bit(tmp, j - block, 1);
			}
		}
		and_bits(maps[i], tmp);
	}
}

static int search(struct lst *lst, bitmap used, int k)
{
	if (!lst)
	{
		return 1;
	}
	for (int i = 0; i < k; i++)
	{
		if (get_bit(lst->b, i) && !get_bit(used, i))
		{
			mapping[lst->posn] = i;
			set_bit(used, i, 1);
			if (search(lst->next, used, k))
			{
				return 1;
			}
			set_bit(used, i, 0);
		}
	}
	return 0;
}

static int check_permute(int k)
{
	int i;
	struct lst **lp;
	static bitmap used = 0;
	head = 0;
	for (i = 0; i < k; i++)
	{
		lst_arr[i].posn = i;
		lst_arr[i].num_bits = count_bits(maps[i]);
		lst_arr[i].b = maps[i];
		for (lp = &head; *lp && (*lp)->num_bits < lst_arr[i].num_bits;
				 lp = &(*lp)->next)
		{
			;
		}
		lst_arr[i].next = *lp;
		*lp = &lst_arr[i];
	}
	if (!used)
	{
		used = (bitmap)malloc(BIT_LEN);
	}
	clear_bits(used);
	return search(head, used, k);
}

static void print_permute(int k)
{
	int i;
	printf("%1d", k);
	for (i = 0; i < k; i++)
	{
		printf(" %1d->%1d", i + 1, mapping[i] + 1);
	}
	printf("\n");
}

static void decipher(string ctext, int k)
{
	char *cpos;
	int reverse_map[MAXLEN];
	int clen = ctext.length();
	while (clen % k != 0)
	{
		ctext += '?';
		clen++;
	}
	for (int i = 0; i < k; i++)
	{
		reverse_map[i] = mapping[i];
	}
	for (int cpos = 0; cpos < clen; cpos += k)
	{
		for (int i = 0; i < k; i++)
		{
			putchar(ctext[cpos+reverse_map[i]]);
		}
	}
	putchar('\n');
}

int main()
{
	int found, i, j, k, abort;
	maps = (bitmap*)malloc(MAXLEN * sizeof(*maps));
	overall = (bitmap*)malloc(MAXLEN * sizeof(*maps));
	for (i = 0; i < MAXLEN; i++)
	{
		maps[i] = (bitmap)malloc(BIT_LEN);
		overall[i] = (bitmap)malloc(BIT_LEN);
	}
	while (getline(cin, plain) && getline(cin, cipher) && getline(cin, cipher2))
	{
		found = 0;
		linelen = plain.length();
		for (i = 0; i < linelen; i++)
		{
			for (j = 0; j < linelen; j++)
			{
				set_bit(overall[i], j, plain[i] == cipher[j]);
			}
		}
		for (k = 1; k <= linelen && !found; k++)
		{
			if (exists_permute(k, linelen))
			{
				abort = 0;
				for (i = 0; !abort && i < k; i++)
				{
					compute_map(i, k, linelen);
					if (zero_bits(maps[i]))
					{
						abort = 1;
						break;
					}
				}
				if (!abort)
				{
					if (found = check_permute(k))
					{
						decipher(cipher2, k);
					}
				}
			}
		}
		if (!found)
		{
			printf("%s\n", cipher2.c_str());
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MX = 2000000;

bool lights[MX];
int nq, sq, n;

int hex_to_dec(char x)
{
	return (x <= '9') ? (x - '0') : (x - 'A' + 10);
}

char dec_to_hex(int x)
{
	return (x <= 9) ? ('0' + x) : ('A' + (x - 10));
}

struct bucket
{
	bool st, ho, hz;
	bucket()
	{
		st = false;
		ho = false;
		hz = false;
	}
	bool has_one()
	{
		if (st)
		{
			return hz;
		}
		return ho;
	}
};

void flip(int l, int r)
{
	r = min(r, n);
	for (int i = l; i <= r; i++)
	{
		lights[i] ^= 1;
	}
}

void find_one(vector<bucket> &bck, int tb, int l, int r)
{
	r = min(r, n);
	for (int i = l; i <= r; i++)
	{
		bck[tb].ho |= lights[i];
		bck[tb].hz |= !lights[i];
	}
}

void proc_bucket(vector<bucket> &bck, int tb, int lo, int hi)
{
	int l = tb * sq;
	int r = l + sq - 1;
	if (bck[tb].st)
	{
		flip(l, r);
	}
	bck[tb].st = false;
	bck[tb].ho = false;
	flip(lo, hi);
	find_one(bck, tb, l, r);
}

bool check_l(int l, int r, int &x, bool st)
{
	for (int i = l; i >= r; i--)
	{
		if (lights[i] == !st && i <= x)
		{
			x = i;
			return true;
		}
	}
	return false;
}

void get_l(vector<bucket> &bck, int &tb, int &l)
{
	int bck_t = tb;
	while (bck_t >= 0)
	{
		int lo = bck_t * sq + sq - 1;
		int hi = bck_t * sq;
		if (bck[bck_t].has_one() && check_l(lo, hi, l, bck[bck_t].st))
		{
			tb = bck_t;
			return;
		}
		else
		{
			bck_t--;
		}
	}
}

bool check_r(int l, int r, int &x, bool st)
{
	for (int i = l; i <= r; i++)
	{
		if (lights[i] == !st && i >= x && i < n)
		{
			x = i;
			return true;
		}
	}
	return false;
}

void get_r(vector<bucket> &bck, int &tb, int &r)
{
	int bck_t = tb;
	while (bck_t < nq)
	{
		int lo = bck_t * sq;
		int hi = lo + sq - 1;
		if (bck[bck_t].has_one() && check_r(lo, hi, r, bck[bck_t].st))
		{
			tb = bck_t;
			return;
		}
		else
		{
			bck_t++;
		}
	}
}

int main()
{
	int T, q, ss;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n,&q);
		string s;
		cin >> s;
		sq = sqrt(n) + 1;
		nq = n / sq + 1;
		vector<bucket> buckets(nq);
		ss = s.size();
		int idx = n - 1;
		for (int i = ss - 1; i >= 0; i--)
		{
			int dec = hex_to_dec(s[i]);
			for (int j = 0; j < 4 && idx >= 0; j++)
			{
				lights[idx--] = ((dec & (1 << j)) != 0);
			}
		}
		for (int i = idx; i >= 0; i--)
		{
			lights[i] = 0;
		}
		for (int i = 0; i < nq; i++)
		{
			find_one(buckets, i, i * sq, i * sq + sq - 1);
		}
		for (int i = 0; i < q; i++)
		{
			int l, r;
			scanf("%d%d", &l,&r);
			l--;
			r--;
			int bl = l / sq, br = r / sq;
			get_l(buckets, bl, l);
			get_r(buckets, br, r);
			if (bl == br)
			{
				proc_bucket(buckets, bl, l, r);
			}
			else
			{
				for (int i = bl + 1; i < br; i++)
				{
					buckets[i].st ^= 1;
				}
				proc_bucket(buckets, bl, l, bl * sq + sq - 1);
				proc_bucket(buckets, br, br * sq, r);
			}
		}
		for (int i = 0; i < nq; i++)
		{
			if (buckets[i].st)
			{
				flip(i * sq, i * sq + sq - 1);
			}
		}
		vector<char> ans;
		for (int i = n - 1; i >= 0; i--)
		{
			int c = 0, t = 0, b = 1;
			while (c < 4 && i >= 0)
			{
				if (lights[i])
				{
					t += b;
				}
				b <<= 1;
				c++;
				i--;
			}
			i++;
			ans.push_back(dec_to_hex(t));
		}
		bool fst = false;
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			if (ans[i] != '0' || fst)
			{
				printf("%c", ans[i]);
				fst = true;
			}
		}
		if (!fst)
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}

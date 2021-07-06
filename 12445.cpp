#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int hd, tl;
LL que[2002000];
map<LL, int> fwd;

LL encode(int *v)
{
	LL key = 0;
	for (int i = 0; i < 12; ++i)
	{
		key = (key << 4) + v[i];
	}
	return key;
}

inline LL l_dn(LL key)
{
	return (((key & (0xfffffLL << 24)) << 4) + ((key & 0x0f) << 24) + (key >> 44) + (key & (0xfffff << 4)));
}

inline LL l_up(LL key)
{
	return (((key & (0xfffffLL << 28)) >> 4) + ((key & (0x0fLL << 24)) >> 24) + ((key & 0x0f) << 44) + (key & (0xfffff << 4)));
}

inline LL r_dn(LL key)
{
	return ((key & (0xfffffLL << 28)) + ((key & 0x0f) << 24) + ((key & 0xffffff0) >> 4));
}

inline LL r_up(LL key)
{
	return ((key & (0xfffffLL << 28)) + ((key & (0x0fLL << 24)) >> 24) + ((key & 0xffffff) << 4));
}

inline LL a_dn(LL key)
{
	return ((key >> 4) + ((key & 0x0f) << 44));
}

inline LL a_up(LL key)
{
	return (((key & ((1LL << 44) - 1)) << 4) + ((key & (0x0fLL << 44)) >> 44));
}

LL decode(LL key, int *v)
{
	for (int i = 12; i-- > 0; key >>= 4)
	{
		v[i] = key & 0x0f;
	}
}

void dump(LL key)
{
	int v[32];
	decode(key, v);
	for (int i = 0; i < 12; ++i)
	{
		printf("%d ", v[i]);
	}
	puts("");
}

inline void check(LL key, int t)
{
	if (!fwd.count(key))
	{
		fwd[key] = t;
		if (t < 10)
		{
			que[tl++] = key;
		}
	}
}

void bfs_fore(void)
{
	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	hd = tl = 0;
	que[tl++] = encode(v);
	fwd[que[hd]] = 0;
	for (int t = 1; hd < tl; ++t)
	{
		int tl1 = tl;
		while (hd < tl1)
		{
			LL curr = que[hd++];
			check(l_dn(curr), t);
			check(l_up(curr), t);
			check(r_dn(curr), t);
			check(r_up(curr), t);
			check(a_dn(curr), t);
			check(a_up(curr), t);
		}
	}
}

inline int look_up(LL key, int t, map<LL, int> &backward)
{
	if (fwd.count(key))
	{
		return fwd[key];
	}
	if (!backward.count(key))
	{
		backward[key] = t;
		if (t < 11)
		{
			que[tl++] = key;
		}
	}
	return -1;
}

int bfs_back(LL key)
{
	map<LL, int> backward;
	hd = tl = 0;
	que[tl++] = key;
	backward[que[hd]] = 0;
	for (int t = 1; hd < tl; ++t)
	{
		int tl1 = tl, x;
		while (hd < tl1)
		{
			LL curr = que[hd++];
			if ((x = look_up(l_dn(curr), t, backward)) >= 0)
			{
				return (x + t);
			}
			if ((x = look_up(l_up(curr), t, backward)) >= 0)
			{
				return (x + t);
			}
			if ((x = look_up(r_dn(curr), t, backward)) >= 0)
			{
				return (x + t);
			}
			if ((x = look_up(r_up(curr), t, backward)) >= 0)
			{
				return (x + t);
			}
			if ((x = look_up(a_dn(curr), t, backward)) >= 0)
			{
				return (x + t);
			}
			if ((x = look_up(a_up(curr), t, backward)) >= 0)
			{
				return (x + t);
			}
		}
	}
	return -1;
}

int main()
{
	bfs_fore();
	int T;
	scanf("%d", &T);
	while (T-- > 0)
	{
		int v[32];
		for (int i = 0; i < 12; ++i)
		{
			scanf("%d", &v[i]);
		}
		LL key = encode(v);
		printf("%d\n", fwd.count(key) ? fwd[key] : bfs_back(key));
	}
	return 0;
}

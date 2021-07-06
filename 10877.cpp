#include <bits/stdc++.h>

using namespace std;

bool hash_[1000000];
int decoids[6], ndecoids;

int encode(int *p)
{
	int v = p[0];
	for (int cnt = 1; cnt < 6; cnt++)
	{
		v = v * 10 + p[cnt];
	}
	return v;
}

bool solve()
{
	int copy[6], i;
	// 1
	copy[0] = decoids[0];
	copy[1] = decoids[1];
	copy[2] = decoids[2];
	copy[3] = decoids[3];
	copy[4] = decoids[4];
	copy[5] = decoids[5];
	i = encode(copy);
	if (hash_[i])
	{
		return false;
	}
	hash_[i] = true;
	// 2
	copy[0] = decoids[0];
	copy[1] = decoids[4];
	copy[2] = decoids[1];
	copy[3] = decoids[3];
	copy[4] = decoids[5];
	copy[5] = decoids[2];
	i = encode(copy);
	hash_[i] = true;
	// 3
	copy[0] = decoids[0];
	copy[1] = decoids[5];
	copy[2] = decoids[4];
	copy[3] = decoids[3];
	copy[4] = decoids[2];
	copy[5] = decoids[1];
	i = encode(copy);
	hash_[i] = true;
	// 4
	copy[0] = decoids[0];
	copy[1] = decoids[2];
	copy[2] = decoids[5];
	copy[3] = decoids[3];
	copy[4] = decoids[1];
	copy[5] = decoids[4];
	i = encode(copy);
	hash_[i] = true;
	// 5
	copy[0] = decoids[1];
	copy[1] = decoids[2];
	copy[2] = decoids[0];
	copy[3] = decoids[5];
	copy[4] = decoids[3];
	copy[5] = decoids[4];
	i = encode(copy);
	hash_[i] = true;
	// 6
	copy[0] = decoids[1];
	copy[1] = decoids[3];
	copy[2] = decoids[2];
	copy[3] = decoids[5];
	copy[4] = decoids[4];
	copy[5] = decoids[0];
	i = encode(copy);
	hash_[i] = true;
	// 7
	copy[0] = decoids[1];
	copy[1] = decoids[4];
	copy[2] = decoids[3];
	copy[3] = decoids[5];
	copy[4] = decoids[0];
	copy[5] = decoids[2];
	i = encode(copy);
	hash_[i] = true;
	// 8
	copy[0] = decoids[1];
	copy[1] = decoids[0];
	copy[2] = decoids[4];
	copy[3] = decoids[5];
	copy[4] = decoids[2];
	copy[5] = decoids[3];
	i = encode(copy);
	hash_[i] = true;
	// 9
	copy[0] = decoids[2];
	copy[1] = decoids[5];
	copy[2] = decoids[0];
	copy[3] = decoids[4];
	copy[4] = decoids[3];
	copy[5] = decoids[1];
	i = encode(copy);
	hash_[i] = true;
	// 10
	copy[0] = decoids[2];
	copy[1] = decoids[3];
	copy[2] = decoids[5];
	copy[3] = decoids[4];
	copy[4] = decoids[1];
	copy[5] = decoids[0];
	i = encode(copy);
	hash_[i] = true;
	// 11
	copy[0] = decoids[2];
	copy[1] = decoids[1];
	copy[2] = decoids[3];
	copy[3] = decoids[4];
	copy[4] = decoids[0];
	copy[5] = decoids[5];
	i = encode(copy);
	hash_[i] = true;
	// 12
	copy[0] = decoids[2];
	copy[1] = decoids[0];
	copy[2] = decoids[1];
	copy[3] = decoids[4];
	copy[4] = decoids[5];
	copy[5] = decoids[3];
	i = encode(copy);
	hash_[i] = true;
	// 13
	copy[0] = decoids[3];
	copy[1] = decoids[5];
	copy[2] = decoids[2];
	copy[3] = decoids[0];
	copy[4] = decoids[4];
	copy[5] = decoids[1];
	i = encode(copy);
	hash_[i] = true;
	// 14
	copy[0] = decoids[3];
	copy[1] = decoids[4];
	copy[2] = decoids[5];
	copy[3] = decoids[0];
	copy[4] = decoids[1];
	copy[5] = decoids[2];
	i = encode(copy);
	hash_[i] = true;
	// 15
	copy[0] = decoids[3];
	copy[1] = decoids[1];
	copy[2] = decoids[4];
	copy[3] = decoids[0];
	copy[4] = decoids[2];
	copy[5] = decoids[5];
	i = encode(copy);
	hash_[i] = true;
	// 16
	copy[0] = decoids[3];
	copy[1] = decoids[2];
	copy[2] = decoids[1];
	copy[3] = decoids[0];
	copy[4] = decoids[5];
	copy[5] = decoids[4];
	i = encode(copy);
	hash_[i] = true;
	// 17
	copy[0] = decoids[4];
	copy[1] = decoids[1];
	copy[2] = decoids[0];
	copy[3] = decoids[2];
	copy[4] = decoids[3];
	copy[5] = decoids[5];
	i = encode(copy);
	hash_[i] = true;
	// 18
	copy[0] = decoids[4];
	copy[1] = decoids[3];
	copy[2] = decoids[1];
	copy[3] = decoids[2];
	copy[4] = decoids[5];
	copy[5] = decoids[0];
	i = encode(copy);
	hash_[i] = true;
	// 19
	copy[0] = decoids[4];
	copy[1] = decoids[5];
	copy[2] = decoids[3];
	copy[3] = decoids[2];
	copy[4] = decoids[0];
	copy[5] = decoids[1];
	i = encode(copy);
	hash_[i] = true;
	// 20
	copy[0] = decoids[4];
	copy[1] = decoids[0];
	copy[2] = decoids[5];
	copy[3] = decoids[2];
	copy[4] = decoids[1];
	copy[5] = decoids[3];
	i = encode(copy);
	hash_[i] = true;
	// 21
	copy[0] = decoids[5];
	copy[1] = decoids[0];
	copy[2] = decoids[2];
	copy[3] = decoids[1];
	copy[4] = decoids[4];
	copy[5] = decoids[3];
	i = encode(copy);
	hash_[i] = true;
	// 22
	copy[0] = decoids[5];
	copy[1] = decoids[4];
	copy[2] = decoids[0];
	copy[3] = decoids[1];
	copy[4] = decoids[3];
	copy[5] = decoids[2];
	i = encode(copy);
	hash_[i] = true;
	// 23
	copy[0] = decoids[5];
	copy[1] = decoids[3];
	copy[2] = decoids[4];
	copy[3] = decoids[1];
	copy[4] = decoids[2];
	copy[5] = decoids[0];
	i = encode(copy);
	hash_[i] = true;
	// 24
	copy[0] = decoids[5];
	copy[1] = decoids[2];
	copy[2] = decoids[3];
	copy[3] = decoids[1];
	copy[4] = decoids[0];
	copy[5] = decoids[4];
	i = encode(copy);
	hash_[i] = true;
	return true;
}

int main()
{
	while (scanf("%d", &ndecoids) && ndecoids)
	{
		memset(hash_, 0, sizeof(hash_));
		int kase, kind = 0;
		for (kase = 0; kase < ndecoids; kase++)
		{
			int i;
			for (i = 0; i < 6; i++)
			{
				scanf("%d", &decoids[i]);
			}
			if (solve())
			{
				kind++;
			}
		}
		printf("%d\n", kind);
	}
	return 0;
}

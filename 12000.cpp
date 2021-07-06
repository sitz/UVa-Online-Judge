#include <bits/stdc++.h>

using namespace std;

const int MAXS = 70;
const int MOD = 73405;

int n, k;
int cnt[MAXS];
vector<int> vec;
int valid[MAXS];
int sz;

void binary(int s)
{
	for (int i = 2 * k - 1; i >= 0; i--)
		if (s & (1 << i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	printf(" ");
}

struct MAT
{
	long long a[MAXS][MAXS];
	MAT()
	{
		memset(a, 0, sizeof(a));
	}
	void print()
	{
		printf("       ");
		for (int i = 0; i < sz; i++)
		{
			binary(vec[i]);
		}
		printf("\n");
		for (int i = 0; i < sz; i++)
		{
			binary(vec[i]);
			for (int j = 0; j < sz; j++)
			{
				printf("%6lld ", a[i][j]);
			}
			printf("\n");
		}
		puts("");
	}
};
MAT operator*(const MAT &a, const MAT &b)
{
	MAT c;
	for (int k = 0; k < sz; k++)
		for (int i = 0; i < sz; i++)
			if (a.a[i][k] > 0)
				for (int j = 0; j < sz; j++)
				{
					c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
				}
	return c;
}

void prepare()
{
	cnt[0] = 0;
	for (int s = 1; s < 65; s++)
	{
		int t = (s - 1) & s;
		cnt[s] = cnt[t] + 1;
	}
}

long long quick_pow(const MAT &mat, int n)
{
	MAT s = mat;
	MAT ret;
	for (int i = 0; i < sz; i++)
	{
		ret.a[i][i] = 1;
	}
	while (n > 0)
	{
		if (n & 1)
		{
			ret = ret * s;
		}
		s = s * s;
		n /= 2;
	}
	int st = 0;
	for (int i = 0; i < k; i++)
	{
		st = st * 2 + 1;
	}
	for (int i = 0; i < k; i++)
	{
		st *= 2;
	}
	return ret.a[valid[st]][valid[st]];
}

int main()
{
	prepare();
	int test;
	scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++)
	{
		MAT mat;
		scanf("%d%d", &n, &k);
		memset(valid, -1, sizeof(valid));
		vec.clear();
		for (int s = 0; s < (1 << (k * 2)); s++)
		{
			//printf("cnt[%d] = %d\n",s,cnt[s]);
			if (cnt[s] == k)
			{
				vec.push_back(s);
				valid[s] = vec.size() - 1;
			}
		}
		for (int i = 0; i < vec.size(); i++)
		{
			int s = vec[i];
			int t;
			for (int j = 0; j < (k * 2); j++)
				if ((s & (1 << j)) == 0)
				{
					t = s + (1 << j);
					t = (t << 1) % (1 << (2 * k));
					/*
					printf("judge ");
					binary(s);
					binary(t);
					printf(" j = %d\n",j);
					*/
					if (valid[t] > -1)
					{
						mat.a[i][valid[t]] = 1;
					}
				}
			t = ((s << 1) + 1) % (1 << (2 * k));
			//printf("valid[%d] = %d\n",t,valid[t]);
			if (valid[t] > -1)
			{
				mat.a[i][valid[t]] = 1;
			}
		}
		sz = vec.size();
		//printf("sz is %d\n",sz);
		//mat.print();
		long long ans = quick_pow(mat, n);
		printf("Case %d: ", cas);
		cout << ans << endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define i64 long long
#define u32 unsigned int
#define min(x, y) ((x) < (y) ? (x) : (y))

int C, num = 0;

const int MAX = 1000005;
u32 tag[MAX / 64 + 5];
int prime[MAX / 10], cnt;

double Log[50];

void init()
{
	prime[cnt++] = 2;
	int i, j;
	for (i = 3; i <= MAX; i += 2)
		if (!(tag[i >> 6] & (1 << (i / 2 % 32))))
		{
			prime[cnt++] = i;
			for (j = i * 3; j <= MAX; j += i * 2)
			{
				tag[j >> 6] |= (1 << (j / 2 % 32));
			}
		}
	for (i = 1; i < 50; i++)
	{
		Log[i] = log(1.0 * prime[i]);
	}
}

const i64 MOD = 1000000007;
i64 n;
vector<i64> V;

i64 POW(i64 a, i64 b)
{
	i64 ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans = ans * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}

i64 t, p[50], q[50], Sum;

void DFS(int dep, i64 cur)
{
	if (dep == t)
	{
		if (cur > 1)
		{
			V.push_back(cur);
		}
		return;
	}
	i64 i;
	for (i = 0; i <= q[dep]; i++)
	{
		DFS(dep + 1, cur);
		cur *= p[dep];
	}
}

double f[4005][45];
i64 Ans[4005][45], po[4005][45];
vector<int> mul[4005][2];

i64 DP()
{
	int i, j, k, p, q, S1 = V.size(), S2;
	i64 t;
	double temp;
	for (i = 0; i < S1; i++)
		for (j = 1; j <= Sum; j++)
		{
			po[i][j] = POW(prime[j], V[i] - 1);
		}
	for (i = 0; i < S1; i++)
		for (j = 0; j <= Sum; j++)
		{
			f[i][j] = 1e40;
		}
	for (i = 0; i < S1; i++)
	{
		f[i][1] = 1.0 * (V[i] - 1) * Log[1];
		Ans[i][1] = po[i][1];
		for (k = 1; k + 1 <= Sum && f[i][k] < 1e30; k++)
		{
			S2 = mul[i][0].size();
			for (j = 0; j < S2; j++)
			{
				p = mul[i][0][j];
				q = mul[i][1][j];
				t = V[p];
				temp = f[i][k] + 1.0 * (V[q] - 1) * Log[k + 1];
				if (temp < f[p][k + 1])
				{
					f[p][k + 1] = temp;
					Ans[p][k + 1] = Ans[i][k] * po[q][k + 1] % MOD;
				}
			}
		}
	}
	temp = 1e40;
	k = V.size() - 1;
	for (i = 1; i <= Sum; i++)
		if (f[k][i] < temp)
		{
			temp = f[k][i];
			j = i;
		}
	return Ans[k][j];
}

int find(int low, int high, i64 k)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) >> 1;
		if (V[mid] == k)
		{
			return mid;
		}
		if (V[mid] > k)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
}

i64 get()
{
	if (n == 1)
	{
		return 1;
	}
	V.clear();
	i64 i, j, temp = n;
	t = 0;
	Sum = 0;
	for (i = 0; i < cnt && (i64)prime[i] * prime[i] <= temp; i++)
		if (temp % prime[i] == 0)
		{
			p[t] = prime[i];
			q[t] = 0;
			while (temp % prime[i] == 0)
			{
				q[t]++;
				temp /= prime[i];
			}
			Sum += q[t];
			t++;
		}
	if (temp > 1)
	{
		p[t] = temp, q[t++] = 1, Sum++;
	}
	V.clear();
	DFS(0, 1);
	sort(V.begin(), V.end());
	for (i = 0; i < V.size(); i++)
	{
		mul[i][0].clear();
		mul[i][1].clear();
		for (j = i + 1; j < V.size(); j++)
			if (V[j] % V[i] == 0)
			{
				mul[i][0].push_back(j);
				mul[i][1].push_back(find(0, V.size() - 1, V[j] / V[i]));
			}
	}
	return DP();
}

int main()
{
	init();
	for (scanf("%d", &C); C--;)
	{
		scanf("%lld", &n);
		if (n < 0)
		{
			printf("impossible\n");
			continue;
		}
		n++;
		printf("%lld\n", get());
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

template <class T>
void checkmin(T &t, T x)
{
	if (x < t)
		t = x;
}
template <class T>
void checkmax(T &t, T x)
{
	if (x > t)
		t = x;
}
template <class T>
void _checkmin(T &t, T x)
{
	if (t == -1)
		t = x;
	if (x < t)
		t = x;
}
template <class T>
void _checkmax(T &t, T x)
{
	if (t == -1)
		t = x;
	if (x > t)
		t = x;
}
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long long lld;
#define foreach(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define DEBUG(a) cout << #a " = " << (a) << endl;
#define DEBUGARR(a, n)                               \
	for (int i = 0; i < (n); i++)                      \
	{                                                  \
		cout << #a "[" << i << "] = " << (a)[i] << endl; \
	}

#define MOD 4007
int N, M;
char mat[50][50];
int f[181][MOD], ST[181][MOD], table[181][MOD], No[181][MOD], Pre[181][MOD], Dump[181][MOD];
int Sum[181];
int getCP(int state, int i)
{
	return 3 & (state >> (i << 1));
}
void print(int state)
{
	for (int i = 0; i <= M; i++)
		printf("%d ", getCP(state, i));
	printf("\n");
}
int dump = 0;
void Push(int r, int state, int value, int lastpos)
{
	int p;
	for (p = state % MOD; table[r][p] != state && table[r][p] != -1;
			 p = (p + 1 == MOD ? 0 : p + 1))
		;
	if (table[r][p] == state)
	{
		if (value > f[r][No[r][p]])
		{
			f[r][No[r][p]] = value;
			Pre[r][No[r][p]] = lastpos;
		}
	}
	else
	{
		table[r][p] = state;
		No[r][p] = ++Sum[r];
		ST[r][Sum[r]] = state;
		f[r][Sum[r]] = value;
		Pre[r][No[r][p]] = lastpos;
		Dump[r][No[r][p]] = dump;
	}
}
bool check(int st)
{
	int i;
	for (i = 0; i < M; i++)
		if (!(getCP(st, i) == 0 || getCP(st, i) == 3))
			return 0;
	if (getCP(st, M) != 1)
		return 0;
	return 1;
}
int work()
{
	int i, j, L, R, k;
	for (i = 0; i <= N * M; i++)
		memset(table[i], -1, sizeof(table[i]));
	memset(Sum, 0, sizeof(Sum));
	Push(0, 1, 0, 0);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{

			//	printf("\n\n\n%d %d---------\n",i,j);

			int now = i * M + j, then = now + 1;
			for (k = 1; k <= Sum[now]; k++)
			{

				dump = 0;
				int cl = ST[now][k];
				if (j == 0)
				{
					cl <<= 2;
					cl &= ((1 << ((M + 1) * 2)) - 1);
				}
				L = getCP(cl, j);
				R = getCP(cl, j + 1);
				/*if (i==2&&j==4){
    				print(ST[now][k]);
    				printf("%d\n====\n",f[now][k]);
    				printf("L R: %d %d\n",L,R);
                }*/
				if (L)
					cl -= L << (j << 1);
				if (R)
					cl -= R << (2 * j + 2);
				int right = 0;
				if (j + 2 <= M)
					right = getCP(cl, j + 2);

				if (L == 0 && R == 0)
				{
					Push(then, cl, f[now][k], k);
					if (mat[i][j] != '#' && mat[i + 1][j] != '#' && mat[i][j + 1] != '#')//add
						Push(then, cl | (1 << (2 * j)) | (2 << (2 * j + 2)), f[now][k] + 1, k);
				}
				else if ((L == 0 && (R == 1 || R == 2)) || (R == 0 && (L == 1 || L == 2)))
				{
					int add = L + R;

					int nst = cl;

					if (mat[i + 1][j] != '#')
					{ //add
						//	print(nst|(add<<(j*2))|(3<<(j*2+2)));
						if (!(R == 0 && right != 0))
							Push(then, nst | (add << (j * 2)) | (3 << (j * 2 + 2)), f[now][k] + 1, k);
					}
					if (mat[i][j + 1] != '#')
					{
						//add

						Push(then, nst | (add << (j * 2 + 2)) | (3 << (j * 2)), f[now][k] + 1, k);
					}
				}
				else if ((L == 3 && (R == 0 || R == 3)) || (R == 3 && (L == 0 || L == 3)))
				{
					// print(cl);
					Push(then, cl, f[now][k], k);
				}
				else if (L == 1 && R == 1)
				{//add
					int tmp, tot = 0, t = j + 2;
					for (; t <= M; t++)
					{
						tmp = getCP(cl, t);
						if (tmp == 1)
							tot++;
						if (tmp == 2)
							tot--;
						if (tot < 0)
							break;
					}
					if ((right == 0 || right == 3))
					{
						int nst = cl;
						if (t <= M)
							nst ^= (3 << (t << 1));
						nst += 3 << (2 * j);
						nst += 3 << (2 * j + 2);
						if (j != M - 1)
						{
							if (right == 3)
								nst -= (3 << (2 * (j + 2)));
							dump = 1;
							Push(then + 1, nst, f[now][k] + 1, k);
						}
						else
						{
							Push(then, nst, f[now][k] + 1, k);
						}
					}
				}
				else if (L == 2 && R == 1)
				{
					//add
					if ((right == 0 || right == 3))
					{
						int nst = cl;
						nst += 3 << (2 * j);
						nst += 3 << (2 * j + 2);
						if (j != M - 1)
						{
							if (right == 3)
								nst -= (3 << (2 * (j + 2)));
							dump = 1;
							Push(then + 1, nst, f[now][k] + 1, k);
						}
						else
						{
							Push(then, nst, f[now][k] + 1, k);
						}
					}
				}
				else if (L == 2 && R == 2)
				{
					int tot = 0, tmp, t = j - 1;
					for (; t >= 0; t--)
					{
						tmp = getCP(cl, t);
						if (tmp == 2)
							tot++;
						if (tmp == 1)
							tot--;
						if (tot < 0)
							break;
					}
					if (t != -1 && (right == 0 || right == 3))
					{
						int nst = cl ^ (3 << (t << 1));
						nst += 3 << (2 * j);
						nst += 3 << (2 * j + 2);

						if (j != M - 1)
						{
							if (right == 3)
								nst -= (3 << (2 * (j + 2)));
							dump = 1;
							Push(then + 1, nst, f[now][k] + 1, k);
						}
						else
						{
							Push(then, nst, f[now][k] + 1, k);
						}
					}
				}
			}
		}
	}
	int now = N * M;
	int ans = 0;
	for (k = 1; k <= Sum[now]; k++)
	{

		if (check(ST[now][k]))
		{
			//printf("-------%d\n",f[now][k]);
			//print(ST[now][k]);
			ans = max(ans, f[now][k]);
		}
	}
	for (k = 1; k <= Sum[now]; k++)
		if (check(ST[now][k]) && ans == f[now][k])
		{
			break;
		}
	//printf("%d\n",ans);
	int st = k;
	int chos[200];
	memset(chos, 0, sizeof(chos));
	while (now != 0)
	{
		// print(ST[now][k]);
		// printf("%d %d :%d--%d\n",now/M, now%M, f[now][k],Dump[now][k]);

		int tmp = Dump[now][k];
		int pre = f[now - 1 - tmp][Pre[now][k]];
		if (pre < f[now][k])
			chos[now - 1 - tmp] = 1;
		k = Pre[now][k];
		now -= 1 + tmp;
	}
	chos[0] = 1;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			if (chos[i * M + j])
				printf("C");
			else
				printf("%c", mat[i][j]);
			if (j == M - 1)
				printf("\n");
		}
	printf("\n");
}

int main()
{
	int i;
	int tcas = 1;
	while (scanf("%d%d", &N, &M) != EOF)
	{
		if (N == 0 && M == 0)
			break;
		for (i = 0; i < N; i++)
			scanf("%s", mat[i]);
		for (i = 0; i <= N; i++)
			mat[i][M] = '#';
		for (i = 0; i <= M; i++)
			mat[N][i] = '#';
		mat[N - 1][M] = '.';
		printf("Case %d:\n", tcas++);
		work();
	}
	return 0;
}

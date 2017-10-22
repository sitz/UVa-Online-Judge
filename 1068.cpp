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
int N[3];
int mat[21][21][21];
int ans;
int src[3], dest[3], fd[3];
bool isin(int pos[])
{
	for (int i = 0; i < 3; i++)
		if (pos[i] >= 1 && pos[i] <= N[i])
			;
		else
			return 0;
	return 1;
}
void disp(int p[])
{
	for (int i = 0; i < 3; i++)
		printf("%d%c", p[i], i == 2 ? '\n' : ' ');
}
void dfs(int now[], int d[], int used)
{

	int i, j, forw, back[20], g, nd, ad[3], pos[3];
	for (i = 0; i < 3; i++)
		if (now[i] != dest[i] || d[i] != fd[i])
			break;
	//disp(now), disp(d), printf("%d\n-------------------------------\n",used);
	if (i == 3)
	{
		ans = min(ans, used);
		return;
	}
	if (used == 6)
		return;
	if (!isin(now) || used >= ans)
		return;
	for (forw = 2; forw <= 3; forw++)
	{
		for (i = 0; i < 3; i++)
			pos[i] = now[i];
		int t = 0;
		for (j = 0; j < forw; j++)
			for (i = 0; i < 3; i++)
			{
				if (j > 0)
					pos[i] += d[i];
				back[t++] = pos[i];
			}
		int bt = t;
		for (nd = 0; nd < 3; nd++)
			if (d[nd] == 0)
			{
				for (i = 0; i < 3; i++)
					ad[i] = 0;
				for (ad[nd] = -1; ad[nd] <= 1; ad[nd]++)
					if (ad[nd] != 0)
					{
						t = bt;
						for (g = 1; g <= 4 - forw; g++)
						{
							for (i = 0; i < 3; i++)
								back[t++] = pos[i] + g * ad[i];
						}
						for (i = 0; i < t; i += 3)
						{
							if (!isin(back + i) || mat[back[i]][back[i + 1]][back[i + 2]] == 1)
								break;
						}
						//	disp(back), disp(back+3), disp(back+6), disp(back+9);
						//	printf("\n----------------\n");
						if (i == t)
						{
							int np[3];
							for (i = 0; i < 3; i++)
								np[i] = pos[i] + (5 - forw) * ad[i];
							for (i = 0; i < t; i += 3)
								mat[back[i]][back[i + 1]][back[i + 2]] = 1;
							dfs(np, ad, used + 1);
							for (i = 0; i < t; i += 3)
								mat[back[i]][back[i + 1]][back[i + 2]] = 0;
						}
					}
			}
	}
}

int main()
{
#ifdef cwj
	freopen("in", "r", stdin);
#endif
	int tcas = 1;
	char srcdirs[100], destdirs[100];
	int i;
	while (scanf("%d", &N[0]) && N[0])
	{
		scanf("%d%d", &N[1], &N[2]);
		for (i = 0; i < 3; i++)
			scanf("%d", &src[i]);
		scanf("%s", srcdirs);
		for (i = 0; i < 3; i++)
			scanf("%d", &dest[i]);
		scanf("%s", destdirs);
		int mul;
		memset(mat, 0, sizeof(mat));
		if (srcdirs[0] == '-')
			mul = -1;
		else
			mul = 1;
		char c = srcdirs[1];
		int d[3];
		memset(d, 0, sizeof(d));
		if (c == 'x')
			d[0] = mul;
		if (c == 'y')
			d[1] = mul;
		if (c == 'z')
			d[2] = mul;

		if (destdirs[0] == '-')
			mul = -1;
		else
			mul = 1;
		c = destdirs[1];
		memset(fd, 0, sizeof(fd));
		if (c == 'x')
			fd[0] = mul;
		if (c == 'y')
			fd[1] = mul;
		if (c == 'z')
			fd[2] = mul;
		for (i = 0; i < 3; i++)
			dest[i] += fd[i];
		printf("Case %d: ", tcas++);
		if (isin(dest))
		{
			printf("Impossible\n");
			continue;
		}
		ans = 1000000000;
		dfs(src, d, 0);
		if (ans == 1000000000)
			printf("Impossible\n");
		else
			printf("%d\n", ans);
	}
}

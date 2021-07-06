#include <bits/stdc++.h>

using namespace std;

#define SZ 1000003
struct link
{
	int v, a, b;
	struct link *nx;
} * L[SZ];
int HF[1505], HS[1505], len[1505], times[30];
char F[1505][12], S[1505][12], ex1[24], ex2[24];
int main()
{
	int t, tt, m, n, i, j, k, ans;
	struct link *proc;
	scanf("%d", &tt);
	for (i = 0; i < SZ; i++)
	{
		L[i] = NULL;
	}
	for (i = times[0] = 1; i < 30; i++)
	{
		times[i] = (27 * times[i - 1]) % SZ;
	}
	for (t = 1; t <= tt; t++)
	{
		scanf("%d%d", &m, &n);
		getchar();
		ans = 0;
		for (i = 0; i < m; i++)
		{
			gets(F[i]);
			for (j = k = 0; F[i][j]; j++)
			{
				k = (27 * k + F[i][j] - '`') % SZ;
			}
			HF[i] = k;
		}
		for (i = 0; i < n; i++)
		{
			gets(S[i]);
			len[i] = strlen(S[i]);
			for (j = k = 0; S[i][j]; j++)
			{
				k = (27 * k + S[i][j] - '`') % SZ;
			}
			HS[i] = k;
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				k = ((long long int)HF[i] * times[len[j]] + HS[j]) % SZ;
				if (L[k] == NULL || L[k]->v != t)
				{
					for (proc = L[k]; proc != NULL; proc = L[k])
					{
						L[k] = proc->nx;
						free(proc);
					}
					proc = (link *)malloc(sizeof(struct link));
					proc->nx = NULL;
					proc->v = t;
					proc->a = i;
					proc->b = j;
					L[k] = proc;
					ans++;
				}
				else
				{
					for (proc = L[k]; proc != NULL; proc = proc->nx)
					{
						strcpy(ex1, F[i]);
						strcat(ex1, S[j]);
						strcpy(ex2, F[proc->a]);
						strcat(ex2, S[proc->b]);
						if (strcmp(ex1, ex2) == 0)
						{
							break;
						}
					}
					if (proc == NULL)
					{
						proc = (link *)malloc(sizeof(struct link));
						proc->nx = L[k];
						proc->v = t;
						proc->a = i;
						proc->b = j;
						L[k] = proc;
						ans++;
					}
				}
			}
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}

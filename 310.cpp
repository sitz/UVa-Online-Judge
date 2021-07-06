#include <bits/stdc++.h>

using namespace std;

#define MAXD 600000
#define HASH 70000

char a[110], b[110], w[20], z[20], st[MAXD][20], t[210];
int next[MAXD], hash_[HASH], Z;

void solve()
{
	int i, j, k, front, rear, v;
	front = rear = 0;
	memset(hash_, 0, sizeof(hash_));
	Z = 0;
	for (i = 0; z[i]; i++)
	{
		Z = Z * 2 + z[i] - 'a' + 1;
	}
	for (i = 0; w[i]; i++)
	{
		v = 0;
		for (j = i, k = 0; w[j] && z[k]; j++, k++)
		{
			v = v * 2 + w[j] - 'a' + 1;
			st[rear][k] = w[j];
		}
		st[rear][k] = '\0';
		if (!hash_[v])
		{
			hash_[v] = 1;
			++rear;
		}
	}
	while (front < rear)
	{
		if (hash_[Z])
		{
			break;
		}
		for (i = j = 0; st[front][i]; i++)
		{
			if (st[front][i] == 'a')
			{
				for (k = 0; a[k]; k++)
				{
					t[j++] = a[k];
				}
			}
			else
			{
				for (k = 0; b[k]; k++)
				{
					t[j++] = b[k];
				}
			}
		}
		t[j] = '\0';
		for (i = 0; t[i]; i++)
		{
			v = 0;
			for (j = i, k = 0; t[j] && z[k]; j++, k++)
			{
				st[rear][k] = t[j];
				v = v * 2 + t[j] - 'a' + 1;
			}
			st[rear][k] = '\0';
			if (!hash_[v])
			{
				hash_[v] = 1;
				++rear;
			}
		}
		front++;
	}
	if (front != rear)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

int main()
{
	while (gets(a) != NULL)
	{
		gets(b);
		gets(w);
		gets(z);
		if (z[0] == '\0')
		{
			printf("YES\n");
		}
		else
		{
			solve();
		}
	}
	return 0;
}

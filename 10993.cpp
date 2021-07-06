#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

bool v[MAXN];
char patt[11];
int queue_[MAXN], d[MAXN], p[MAXN], output[MAXN], len, base;

bool BFS()
{
	int pl = strlen(patt);
	for (int i = 0; i < pl; i++)
	{
		patt[i] -= '0';
	}
	int front = -1, rear = -1;
	memset(v, false, sizeof(v));
	for (int i = pl - 1; i >= 0; i--)
	{
		if (patt[i] == 0)
		{
			continue;
		}
		queue_[++rear] = (patt[i] % base);
		d[rear] = patt[i];
		v[patt[i]] = true;
		p[rear] = -1;
	}
	while (front < rear)
	{
		int s = queue_[++front];
		if (s == 0)
		{
			len = 0;
			int ptr = front;
			do
			{
				output[len++] = d[ptr];
				ptr = p[ptr];
			} while (ptr != -1);
			return true;
		}
		for (int i = pl - 1; i >= 0; i--)
		{
			int t = (s * 10 + patt[i]) % base;
			if (v[t])
			{
				continue;
			}
			v[t] = true;
			queue_[++rear] = t;
			d[rear] = patt[i];
			p[rear] = front;
		}
	}
	return false;
}

int main()
{
	while (scanf("%s%d", patt, &base) == 2)
	{
		if (strcmp(patt, "0") == 0 && !base)
		{
			break;
		}
		if (!BFS())
		{
			printf("impossible\n");
		}
		else
		{
			for (int i = len - 1; i >= 0; i--)
			{
				printf("%d", output[i]);
			}
			printf("\n");
		}
	}
	return 0;
}

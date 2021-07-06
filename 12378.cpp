#include <bits/stdc++.h>

using namespace std;

#define REP(a, n) for (int a = 0; a < (n); ++a)
#define FOR(a, b, c) for (int a = (b); a <= (c); ++a)
#define FORD(a, b, c) for (int a = (b); a >= (c); --a)
#define swap(t, a, b) t = a, a = b, b = t
#define CL(a, b) memset(a, b, sizeof(a))
#define WI(a) cout << #a << " : " << a << endl

typedef long long ll;
typedef unsigned long long ull;

char box[500010];
int p[500010];
int tot;

void reduce()
{
	tot = 1;
	int len = strlen(box);
	FOR(i, 1, len - 1)
	{
		if (box[i] != box[i - 1])
		{
			box[tot++] = box[i];
		}
	}
	box[tot] = '\0';
}

void modify()
{
	FORD(i, tot - 1, 0)
	{
		box[(i + 1) * 2] = box[i];
	}
	tot = tot * 2 + 1;
	box[0] = '$';
	FOR(i, 1, tot - 1)
	{
		if (i & 1)
		{
			box[i] = '#';
		}
	}
	box[tot++] = '#';
	box[tot] = '\0';
}
int main()
{
	int n;
	int t;
	int maxE = -1;
	int mx, id;
	scanf("%d\n", &t);
	while (t--)
	{
		maxE = -1;
		gets(box);
		//		WI(box);
		reduce();
		//		WI(box);
		modify();
		//		WI(box);
		mx = 0;
		FOR(i, 1, tot - 1)
		{
			if (mx > i)
			{
				p[i] = min(p[2 * id - i], mx - i);
			}
			else
			{
				p[i] = 1;
			}
			while (box[i - p[i]] == box[i + p[i]])
			{
				p[i]++;
			}
			if (i + p[i] > mx)
			{
				mx = i + p[i];
				id = i;
			}
		}
		int maxE = -1;
		//		WI(box[tot-1]);
		FOR(i, 1, tot - 1)
		{
			if (p[i] - 1 > maxE)
			{
				maxE = p[i] - 1;
			}
		}
		printf("%d\n", (maxE + 1) / 2);
	}
	return 0;
}

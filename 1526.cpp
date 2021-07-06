#include <bits/stdc++.h>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
const int N = 9005;
int w, n, sum, an, pos;
struct Seg
{
	int value, len, pos;
} s[N], ans[N];

bool cmp(Seg a, Seg b)
{
	return a.len < b.len;
}

int getnum(int pos)
{
	int l = 1, r = n;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (s[mid].pos > pos)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return s[l - 1].value;
}

int cal(int pos)
{
	int num = getnum(pos), ans = 0;
	int r = (pos - 1) / w;
	int c = (pos - 1) % w;
	for (int i = r - 1; i <= r + 1; i++)
		for (int j = c - 1; j <= c + 1; j++)
		{
			int v = i * w + j;
			if (i < 0 || j < 0 || j >= w || v >= sum || v == pos - 1)
			{
				continue;
			}
			int num2 = getnum(v + 1);
			int t = abs(num2 - num);
			ans = max(ans, t);
		}
	return ans;
}

int main()
{
	while (~scanf("%d", &w) && w)
	{
		n = sum = an = 0;
		while (~scanf("%d%d", &s[n].value, &s[n].len) && s[n].value || s[n].len)
		{
			if (n != 0)
			{
				s[n].pos = s[n - 1].pos + s[n - 1].len;
			}
			else
			{
				s[n].pos = 1;
			}
			sum += s[n].len;
			n++;
		}
		s[n].len = s[n].value = 0;
		s[n].pos = s[n - 1].pos + s[n - 1].len;
		for (int k = 0; k <= n; k++)
		{
			int r = (s[k].pos - 1) / w;
			int c = (s[k].pos - 1) % w;
			for (int i = r - 1; i <= r + 1; i++)
				for (int j = c - 1; j <= c + 1; j++)
				{
					int v = i * w + j;
					if (i < 0 || j < 0 || j >= w || v >= sum)
					{
						continue;
					}
					ans[an].len = v + 1;
					ans[an++].value = cal(v + 1);
				}
		}
		sort(ans, ans + an, cmp);
		Seg save = ans[0];
		printf("%d\n", w);
		for (int i = 0; i < an; i++)
		{
			if (ans[i].value == save.value)
			{
				continue;
			}
			printf("%d %d\n", save.value, ans[i].len - save.len);
			save = ans[i];
		}
		printf("%d %d\n", save.value, sum - save.len + 1);
		printf("0 0\n");
	}
	printf("0\n");
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL x, y;
int N;
char str[100];

int sgn(LL t)
{
	return t < 0 ? -1 : t > 0;
}

int Get(int st, char end, LL &ret)
{
	int sgn = 1;
	if (str[st] == '-' || str[st] == '+')
	{
		if (str[st] == '-')
		{
			sgn = -1;
		}
		st++;
	}
	ret = 0;
	while (str[st] != end)
	{
		ret = ret * 10 + str[st++] - '0';
	}
	ret *= sgn;
	return st;
}

int main()
{
	while (cin >> x >> y >> N, N)
	{
		int cnt = 0;
		LL a = 0, b = 0, c = 0, u, v;
		for (int i = 0; i < N; i++)
		{
			scanf("%lld %lld %s", &u, &v, str);
			//			cout << str << endl;
			u -= x;
			v -= y;
			int pos = Get(0, 'x', a);
			pos = Get(pos + 1, 'y', b);
			Get(pos + 1, '=', c);
			//			cout << a << " " << b << " " << c << endl;
			//			if(c)
			//			{
			//				if(sgn(u*y - v*x) == sgn(c))
			//				{
			//					cnt ++;
			//				}
			//			}
			//			else
			{
				if (sgn(-u * b + v * a) == 1)
				{
					cnt++;
				}
			}
			//			cout << cnt << "  ";
		}
		cout << cnt * (N - cnt) << endl;
	}
	return 0;
}

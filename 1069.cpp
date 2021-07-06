#include <bits/stdc++.h>

using namespace std;

//*************************OUTPUT*************************
#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

//**************************CONSTANT***********************
#define INF 0x7f7f7f7f
#define eps 1e-8
#define PI acos(-1.)
#define PI2 asin(1.);
typedef long long LL;
//typedef __int64 LL;   //codeforces
typedef unsigned int ui;
typedef unsigned long long ui64;
#define MP make_pair
typedef vector<int> VI;
typedef pair<int, int> PII;
#define pb push_back
#define mp make_pair

//***************************SENTENCE************************
#define CL(a, b) memset(a, b, sizeof(a))
#define sqr(a, b) sqrt((double)(a) * (a) + (double)(b) * (b))
#define sqr3(a, b, c) sqrt((double)(a) * (a) + (double)(b) * (b) + (double)(c) * (c))

//****************************FUNCTION************************
template <typename T>
double DIS(T va, T vb)
{
	return sqr(va.x - vb.x, va.y - vb.y);
}
template <class T>
inline T INTEGER_LEN(T v)
{
	int len = 1;
	while (v /= 10)
	{
		++len;
	}
	return len;
}
template <typename T>
inline T square(T va, T vb)
{
	return va * va + vb * vb;
}

// aply for the memory of the stack
//#pragma comment (linker, "/STACK:1024000000,1024000000")
//end

#define CY 10000

bool vis[105];
int ar[CY], br[CY];
char S[CY];
int idx;

int cal(LL value, int k, int mod)
{
	LL single = 1;
	while (k > 0)
	{
		if (k & 1)
		{
			single = single * value % mod;
		}
		value = value * value % mod;
		k >>= 1;
	}
	return (int)single;
}

int main(void)
{
	int cas = 0;
	while (~scanf("%s", S) && S[0] != '.')
	{
		memset(vis, false, sizeof(vis));
		memset(br, -1, sizeof(br));
		int n = (int)strlen(S);
		idx = 0;
		int x = 0, sign = 1, i;
		bool flag = false;
		for (i = 0; S[i] != '/'; ++i)
		{
			if (S[i] >= '0' && S[i] <= '9')
			{
				x = 10 * x + S[i] - '0';
				flag = true;
			}
			if (S[i] == '-')
			{
				if (-1 == br[idx] && vis[idx])
				{
					if (flag)
					{
						br[idx++] = x;
					}
					else
					{
						br[idx++] = 1;
					}
				}
				sign = -1;
				x = 0;
				flag = false;
			}
			if (S[i] == '+')
			{
				if (-1 == br[idx] && vis[idx])
				{
					if (flag)
					{
						br[idx++] = x;
					}
					else
					{
						br[idx++] = 1;
					}
				}
				sign = 1;
				x = 0;
				flag = false;
			}
			if (S[i] == 'n')
			{
				if (flag)
				{
					ar[idx] = sign * x;
				}
				else
				{
					ar[idx] = sign;
				}
				vis[idx] = true;
				x = 0;
				flag = false;
			}
			if (S[i] == ')')
			{
				if (!vis[idx])
				{
					ar[idx] = sign * x;
					br[idx++] = 0;
					flag = false;
					x = 0;
				}
				else
				{
					if (flag)
					{
						br[idx++] = x;
					}
					else
					{
						br[idx++] = 1;
					}
					x = 0;
					flag = false;
				}
			}
		}
		int D = 0;
		for (; S[i]; ++i)
		{
			if (S[i] >= '0' && S[i] <= '9')
			{
				D = 10 * D + S[i] - '0';
			}
		}
		int k, sum = 0;
		for (k = 0; k <= br[0] + 1; ++k)
		{
			for (int i = 0; i < idx; ++i)
			{
				int ans = cal(k, br[i], D);
				ans = (int)((LL)ans * ar[i] % D);
				sum = (int)(((LL)sum + ans) % D);
			}
			if (sum)
			{
				break;
			}
		}
		if (k > br[0] + 1)
		{
			printf("Case %d: Always an integer\n", ++cas);
		}
		else
		{
			printf("Case %d: Not always an integer\n", ++cas);
		}
	}
	return 0;
}

/*
(n^2-n)/2
(2n^3+3n^2+n)/6
(-n^14-11n+1)/3
(n^4-6n^3+23n^2-18n+24)/24
(6)/3
(6)/6
(n^3-3n^2+2n)/6
(n^3-3n^2+2n)/12
(n^4-6n^3+11n^2-6n)/24
*/

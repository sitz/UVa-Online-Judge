#include <bits/stdc++.h>

using namespace std;

#define SET(a) memset(a, -1, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define CLR(a) memset(a, 0, sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define MP(a, b) make_pair(a, b)
#define PII pair<int, int>
#define PCC pair<char, char>
#define PIC pair<int, char>
#define PCI pair<char, int>
#define VS vector<string>
#define VI vector<int>
#define VC vector<char>
#define max3(a, b, c) max(a,max(b,c)
#define min3(a, b, c) min(a,min(b,c)
#define LL long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define For(i, a) for (int i = 0; i < a; i++)

#define S(a) scanf("%d", &a)
#define S2(a, b) scanf("%d%d", &a, &b)
#define S3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define SLL(a) scanf("%lld", &a)
#define SLL2(a, b) scanf("%lld%lld", &a, &b)
#define SLL3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define SS(a) scanf("%s", a)
#define SC(a) scanf("%c", &a)
#define SD(a) scanf("%lf", &a)
#define P(a) printf("%d", a)
#define PLL(a) printf("%lld", a)
#define PD(a) printf("%lf", a)
#define PC(a) printf("%c", a)
#define PS(a) printf("%s", a)
#define KS printf("Case %d: ", kk++)
#define KN printf("Case %d:\n", kk++)
#define KH printf("Case #%d: ", kk++)
#define NL printf("\n")
#define DB cout << "done" << endl;

#define EPS 1e-9
#define MOD 1000000007
#define INF INT_MAX / 3
#define MX 100010

template <typename T>
inline string tostring(T a)
{
	ostringstream os("");
	os << a;
	return os.str();
}
template <typename T>
inline LL tolong(T a)
{
	LL res;
	istringstream os(a);
	os >> res;
	return res;
}
template <typename T>
inline VI parse(T str)
{
	VI res;
	int s;
	istringstream os(str);
	while (os >> s)
	{
		res.PB(s);
	}
	return res;
}
template <class T>
inline T _sqrt(T x)
{
	return (T)sqrt((double)x);
}
template <class T>
inline T _bigmod(T n, T m)
{
	T ans = 1, mult = n % MOD;
	while (m)
	{
		if (m & 1)
		{
			ans = (ans * mult) % MOD;
		}
		m >>= 1;
		mult = (mult * mult) % MOD;
	}
	ans %= MOD;
	return ans;
}
template <class T>
inline T _modinv(T x)
{
	return _bigmod(x, (T)MOD - 2) % MOD;
}
inline int LEN(string a)
{
	return a.length();
}
inline int LEN(char a[])
{
	return strlen(a);
}
template <class T>
inline T _gcd(T a, T b)
{
	return (b.chk() == 0) ? a : _gcd(b, a % b);
}
template <class T>
inline T _lcm(T x, T y)
{
	return x * y / _gcd(x, y);
}

int main()
{
	int tc, kk = 1, n, m, s1l, s2l, cnt1, cnt2, cnt3, cnt;
	cin >> tc;
	string s1, s2, tmp1, tmp2, total[210], pos[110], neg[110], chg[110];
	while (tc--)
	{
		cin >> s1 >> s2;
		s1l = LEN(s1);
		s2l = LEN(s2);
		cnt = 0;
		map<string, int> key1, key2;
		map<string, string> val1, val2;
		FOR(i, 1, s1l - 2)
		{
			tmp1 = "";
			while (s1[i] != ':')
			{
				tmp1 += s1[i];
				i++;
			}
			total[cnt++] = tmp1;
			key1[tmp1] = 1;
			i++;
			tmp2 = "";
			while (s1[i] != ',' && s1[i] != '}')
			{
				tmp2 += s1[i];
				i++;
			}
			val1[tmp1] = tmp2;
		}
		FOR(i, 1, s2l - 2)
		{
			tmp1 = "";
			while (s2[i] != ':')
			{
				tmp1 += s2[i];
				i++;
			}
			key2[tmp1] = 1;
			if (key1[tmp1] != 1)
			{
				total[cnt++] = tmp1;
			}
			i++;
			tmp2 = "";
			while (s2[i] != ',' && s2[i] != '}')
			{
				tmp2 += s2[i];
				i++;
			}
			val2[tmp1] = tmp2;
		}
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		For(i, cnt)
		{
			if (key1[total[i]] == 1 && key2[total[i]] != 1)
			{
				neg[cnt1++] = total[i];
			}
			else if (key1[total[i]] != 1 && key2[total[i]] == 1)
			{
				pos[cnt2++] = total[i];
			}
			else if (val1[total[i]] != val2[total[i]])
			{
				chg[cnt3++] = total[i];
			}
		}
		sort(pos, pos + cnt2);
		sort(neg, neg + cnt1);
		sort(chg, chg + cnt3);
		if (!(cnt1 | cnt2 | cnt3))
		{
			cout << "No changes" << endl;
		}
		else
		{
			if (cnt2)
			{
				cout << "+" << pos[0];
				FOR(i, 1, cnt2 - 1)
				cout << "," << pos[i];
				cout << endl;
			}
			if (cnt1)
			{
				cout << "-" << neg[0];
				FOR(i, 1, cnt1 - 1)
				cout << "," << neg[i];
				cout << endl;
			}
			if (cnt3)
			{
				cout << "*" << chg[0];
				FOR(i, 1, cnt3 - 1)
				cout << "," << chg[i];
				cout << endl;
			}
		}
		cout << endl;
	}
	return 0;
}

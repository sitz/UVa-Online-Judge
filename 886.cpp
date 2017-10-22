#include <bits/stdc++.h>

using namespace std;

#define mem(x, y) memset(x, y, sizeof(x))
#define CLEAR(x) memset(x, 0, sizeof(x))

#define pb push_back
#define Sort(v) sort(v.begin(), v.end())
#define RSort(v) sort(v.rbegin(), v.rend())
#define CSort(v, C) sort(v.begin(), v.end(), C)
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x) * (x))
#define find_dist(a, b) sqrt(sqr(a.x - b.x) + sqr(a.y - b.y))

#define ERR 1e-9
#define pi (2 * acos(0))
#define PI 3.141592653589793

#define scanint(a) scanf("%d", &a)
#define scanLLD(a) scanf("%lld", &a)
#define scanstr(s) scanf("%s", s)
#define scanline(l) scanf(" %[^\n]", l);

#define check(n, pos) (n & (1 << (pos)))
#define biton(n, pos) (n | (1 << (pos)))
#define bitoff(n, pos) (n & ~(1 << (pos)))

#define WHITE 0
#define GREY 1
#define BLACK 2

typedef vector<int> vint;
typedef vector<vint> vint2D;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<vchar> vchar2D;
typedef queue<int> Qi;
typedef queue<Qi> Qii;
typedef map<int, int> Mii;
typedef map<string, int> Msi;
typedef map<int, string> Mis;
typedef stack<int> stk;
typedef pair<int, int> pp;
typedef pair<int, pp> ppp;
typedef long long int LLD;
const int inf = 0x7fffffff;

struct point_int
{
	int x, y;
	point_int() {}
	point_int(int a, int b)
	{
		x = a, y = b;
	}
};

// Point for x,y (int) coordinate in 2D space
struct point_double
{
	double x, y;
	point_double() {}
	point_double(double a, double b)
	{
		x = a, y = b;
	}
};

// Point for x,y (double) coordinate in 2D space
struct Node
{
	int v, w;
	Node() {}
	bool operator<(const Node &a) const
	{
		return w > a.w;
	}
	Node(int _v, int _w)
	{
		v = _v, w = _w;
	}
};
// Node for Dijkstra

namespace my
{
template <class T>
T gcd(T a, T b)
{
	return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b)
{
	return a / gcd(a, b) * b;
}
template <class T>
T big_mod(T n, T p, T m)
{
	if (p == 0)
	{
		return (T)1;
	}
	T x = big_mod(n, p / 2, m);
	x = (x * x) % m;
	if (p & 1)
	{
		x = (x * n) % m;
	}
	return x;
}
template <class T>
T multiplication(T n, T p, T m)
{
	if (p == 0)
	{
		return (T)0;
	}
	T x = multiplication(n, p / 2, m);
	x = (x + x) % m;
	if (p & 1)
	{
		x = (x + n) % m;
	}
	return x;
}
template <class T>
T my_pow(T n, T p)
{
	if (p == 0)
	{
		return 1;///n to the power p
	}
	T x = my_pow(n, p / 2);
	x = (x * x);
	if (p & 1)
	{
		x = (x * n);
	}
	return x;
}
template <class T>
double getdist(T a, T b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));/// distance between a & b
}
template <class T>
T extract(string s, T ret)
{
	stringstream ss(s);/// extract words or numbers from a line
	ss >> ret;
	return ret;
}
template <class T>
string tostring(T n)
{
	stringstream ss;/// convert a number to string
	ss << n;
	return ss.str();
}
template <class T>
inline T Mod(T n, T m)
{
	return (n % m + m) % m;///For Positive Negative No.
}
template <class T>
T MIN3(T a, T b, T c)
{
	return min(a, min(b, c));/// minimum of 3 number
}
template <class T>
T MAX3(T a, T b, T c)
{
	return max(a, max(b, c));///maximum of 3 number
}
template <class T>
void print_vector(T &v)
{
	int sz = v.size();/// prints all elements in a vector
	if (sz)
	{
		cout << v[0];
	}
	for (int i = 1; i < sz; i++)
	{
		cout << ' ' << v[i];
	}
	cout << "\n";
}
bool isVowel(char ch)
{
	ch = toupper(ch);
	if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
	{
		return true;
	}
	return false;
}
bool isConsonant(char ch)
{
	if (isalpha(ch) && !isVowel(ch))
	{
		return true;
	}
	return false;
}
}
/**Shortcut input function**/
int read_int()
{
	int n;
	scanf("%d", &n);
	return n;
}
int read_LLD()
{
	LLD n;
	scanf("%lld", &n);
	return n;
}
inline int buffer_input()
{
	char inp[1000];
	scanstr(inp);
	return atoi(inp);
}

const string Map = "22233344455566677778889999";
vector<pair<string, string> > Dic;

int main()
{
	string S1, S2, S3;
	while (cin >> S1)
	{
		if (isdigit(S1[0]))
		{
			break;
		}
		cin >> S2 >> S3;
		string Name = "";
		Name += tolower(S1[0]);
		for (int i = 0; i < S2.size(); i++)
		{
			Name += tolower(S2[i]);
		}
		string Sug = "";
		for (int i = 0; i < Name.size(); i++)
		{
			Sug += (Map[Name[i] - 'a']);
		}
		Dic.pb(make_pair(Sug, S3));
	}
	do
	{
		vector<string> Ans;
		bool flag = false;
		for (pair<string, string> x : Dic)
		{
			if (x.second == S1)
			{
				cout << x.second << endl;
				flag = true;
				break;
			}
			bool ok = true;
			for (int i = 0; i < S1.size(); i++)
			{
				if (x.first[i] != S1[i])
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				Ans.pb(x.second);
			}
		}
		if (!flag)
		{
			if (Ans.size())
			{
				my::print_vector(Ans);
			}
			else
			{
				cout << 0 << "\n";
			}
		}
	} while (cin >> S1);
	return 0;
}

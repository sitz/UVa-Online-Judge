#include <bits/stdc++.h>

using namespace std;

#define rep(x, n) for (int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define x first
#define y second

template <class T>
void pv(T a, T b)
{
	for (T i = a; i != b; ++i)
	{
		cout << *i << " ";
	}
	printf("\n");
}

typedef unsigned long long Int;
typedef pair<int, int> pt;

Int gcd(Int A, Int B)
{
	while (A)
	{
		B %= A;
		swap(A, B);
	}
	return B;
}

Int root(Int A)
{
	Int r = sqrt(double(A));
	if (r * r != A)
	{
		r = 0;
	}
	return r;
}

Int solve(Int AB, Int BC, Int AC)
{
	Int g = gcd(AB, AC);
	AB /= g, AC /= g;
	if (BC % AC)
	{
		return 0;
	}
	else
	{
		BC /= AC;
	}
	Int x = gcd(AB, BC);
	return x * root(AB / x) * root(BC / x);
}

bool valid(vector<Int> &a)
{
	sort(a.begin(), a.end());
	if (a[0] <= 1)
	{
		return false;
	}
	if (a.back() > 1e9)
	{
		return false;
	}
	rep(i, a.size() - 1)
	{
		if (a[i] == a[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool pop(map<Int, int> &M, Int x)
{
	if (M.count(x) == 0)
	{
		return false;
	}
	else
	{
		M[x]--;
	}
	if (M[x] <= 0)
	{
		M.erase(x);
	}
	return true;
}

Int top(map<Int, int> &M)
{
	return M.begin()->first;
}

int main()
{
	cin.sync_with_stdio(false);
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int n;
		cin >> n;
		int m = n * (n - 1) / 2;
		vector<Int> b(m), a(n, 2e9);
		rep(i, m) cin >> b[i];
		sort(b.begin(), b.end());
		if (n == 3)
		{
			a[0] = solve(b[0], b[1], b[2]);
			a[1] = solve(b[1], b[2], b[0]);
			a[2] = solve(b[2], b[0], b[1]);
			valid(a);
		}
		else
		{
			Int AB = b[0];
			Int AC = b[1];
			int lim = min(m, n + 2);
			for (int candidate = 2; candidate < lim; candidate++)
			{
				Int BC = b[candidate];
				Int A = solve(AB, AC, BC);
				Int B = solve(AB, BC, AC);
				Int C = solve(AC, BC, AB);
				if (A > B)
				{
					swap(A, B);
				}
				if (A > C)
				{
					swap(A, C);
				}
				if (B > C)
				{
					swap(B, C);
				}
				if (A <= 1)
				{
					continue;
				}
				int ok = true;
				map<Int, int> M;
				rep(i, m) M[b[i]]++;
				pop(M, AB), pop(M, AC), pop(M, BC);
				vector<Int> aa(n);
				aa[0] = A;
				aa[1] = B;
				aa[2] = C;
				for (int p = 3; p < n; p++)
				{
					Int X = top(M);
					if (X % A)
					{
						ok = false;
						goto fail;
					}
					aa[p] = X / A;
					for (int i = 0; i < p; i++)
					{
						if (!pop(M, aa[i] * aa[p]))
						{
							ok = false;
							goto fail;
						}
					}
				}
			fail:
				if (ok && valid(aa) && aa < a)
				{
					a = aa;
				}
			}
		}
		printf("Case %d:", testcase);
		rep(i, n)
		{
			printf(" %d", int(a[i]));
		}
		printf("\n");
	}
	return 0;
}

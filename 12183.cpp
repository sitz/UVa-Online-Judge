#include <bits/stdc++.h>

using namespace std;

// method : circulant matrices, repeated squaring
// runtime: O(N^2*log(S))

// intermediate values up to 10^18
typedef long long ll;
// a circulant matrix is represented by its first row
typedef vector<ll> vl;

int n;
ll mod;

// modular product of circulant matrices v and w
vl mult(const vl v, const vl w)
{
	vl res(n);
	// first row of usual matrix product
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		// use circulant property of w
		{
			res[i] = (res[i] + v[j] * w[(i + n - j) % n]) % mod;
		}
	return res;
}

// modular power v^k of circulant matrix v
vl exp(const vl v, int k)
{
	// v^0 = identity matrix
	if (k == 0)
	{
		vl res(n);
		res[0] = 1;
		return res;
	}
	// v^1 = v
	if (k == 1)
	{
		return v;
	}
	// v^(2i) = (v^2)^i and v^(2i+1) = v*(v^2)^i
	vl w = exp(mult(v, v), k / 2);
	return k & 1 ? mult(v, w) : w;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int s, l, r, x;
		cin >> n >> s >> l >> r >> x;
		vl msg(n);
		for (int i = 0; i < n; i++)
		{
			cin >> msg[i];
		}
		// modulo 10^x
		mod = 1;
		while (x--)
		{
			mod *= 10;
		}
		// circulant matrix with diagonals (l,1,r)
		vl mat(n);
		mat[0] = 1;
		mat[1] = r;
		mat[n - 1] = l;
		// s steps amount to s-th power
		mat = exp(mat, s);
		// for the i-th decrypted number, take mat[i,j] times msg[j]
		for (int i = 0; i < n; i++)
		{
			ll sum = 0;
			for (int j = 0; j < n; j++)
			// use circulant property of mat
			{
				sum = (sum + mat[(j + n - i) % n] * msg[j]) % mod;
			}
			cout << sum << (i < n - 1 ? ' ' : '\n');
		}
	}
	return 0;
}

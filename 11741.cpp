#include <bits/stdc++.h>

using namespace std;

#define ll long long

//mega

#define SIZE 20
ll mod = 10000007;

class Matrix
{
public:
	ll N;
	ll matrix[SIZE][SIZE];
	Matrix(ll n)
	{
		N = n;
	}
	ll getDim()
	{
		return N;
	}
	void setZer()
	{
		memset(matrix, 0, sizeof(matrix));
	}
	void setOne()
	{
		ll i;
		setZer();
		for (i = 0; i < N; ++i)
		{
			matrix[i][i] = 1;
		}
	}
	void setVal(ll array[][SIZE])
	{
		ll i, j;
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				matrix[i][j] = array[i][j];
			}
		}
	}
	Matrix operator+(Matrix &A)
	{
		Matrix ret(N);
		ll i, j;
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				ret.matrix[i][j] = (matrix[i][j] + A.matrix[i][j]) % mod;
			}
		}
		return ret;
	}
	Matrix operator*(Matrix &A)
	{
		Matrix ret(N);
		ll i, j, k;
		long long temp;
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				ret.matrix[i][j] = 0;
				for (k = 0; k < N; ++k)
				{
					temp = (long long)matrix[i][k] * A.matrix[k][j];
					ret.matrix[i][j] = (ret.matrix[i][j] + temp) % mod;
				}
			}
		}
		return ret;
	}
	void printMatrix()
	{
		ll i, j;
		puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				printf("%3d ", matrix[i][j]);
			}
			puts("");
		}
		puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	}
} base(SIZE), ret(SIZE);
Matrix bigmod(Matrix A, ll K)
{
	if (K == 1)
	{
		return base;
	}
	if (K & 1)
	{
		ret = bigmod(A, K - 1);
		ret = ret * base;
		return ret;
	}
	ret = bigmod(A, K >> 1);
	ret = ret * ret;
	return ret;
}
Matrix bigmodmat2(Matrix base, ll K)
{
	ret = base;
	Matrix ans(base.N);
	ans.setOne();
	while (K)
	{
		if (K % 2)
		{
			ans = ans * ret;
		}
		K /= 2;
		ret = ret * ret;
	}
	return ans;
}

//

const ll N = 102;
ll r, n, c, x[N], y[N];

bool valid(vector<ll> &cx, ll mask)
{
	ll i, sz = cx.size();
	for (i = 0; i < sz; i++)
	{
		if (mask & (1 << cx[i]))
		{
			return false;
		}
	}
	return true;
}

ll C[20][20];

void g(ll now, ll pos, ll next)
{
	if (pos == r)
	{
		//cout<<next<<"d"<<endl;
		C[now][next]++;
		return;
	}
	if (now & (1 << pos))
	{
		g(now, pos + 1, next);
	}
	else
	{
		g(now, pos + 1, next ^ (1 << pos));
		if (pos < (r - 1) && !(now & (1 << (pos + 1))))
		{
			g(now, pos + 2, next);
		}
	}
}

map<ll, vector<ll>> e;
ll ccount[N], ncount[N];

int main()
{
	//  freopen("in.txt","r",stdin);
	ll i, j, k, now, next, mask;
	int cs = 0;
	while (cin >> r >> c >> n)
	{
		if (!r && !c && !n)
		{
			break;
		}
		e.clear();
		for (i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
			// scanf("%d%d",&x[i],&y[i]);
			e[y[i]].push_back(x[i]);
		}
		memset(C, 0, sizeof(C));
		for (i = 0; i < (1 << r); i++)
		{
			g(i, 0, 0);
			//   cout<<C[0][0]<<endl;while(1);
		}
		for (now = 0; now < (1 << r); now++)
		{
			for (next = 0; next < (1 << r); next++)
			{
				base.matrix[now][next] = C[now][next];
				//     cout<<C[now][next]<<endl;
			}
		}//while(1);
		base.N = (1 << r);
		for (now = 0; now < (1 << r); now++)
		{
			ccount[now] = 0;
		}
		ccount[(1 << r) - 1] = 1;
		ll last = 0, tot;
		map<ll, vector<ll>>::iterator it;
		for (it = e.begin(); it != e.end(); it++)
		{
			ll cy = it->first;
			vector<ll> cx = it->second;
			// cout<<cy<<"-->"<<" ";
			//for(i=0;i<cx.size();i++)cout<<cx[i]<<" ";cout<<endl;
			tot = cy - last + 1;
			// cout<<tot<<endl;while(1);
			Matrix ret = bigmod(base, tot);
			memset(ncount, 0, sizeof(ncount));
			for (next = 0; next < (1 << r); next++)
			{
				for (now = 0; now < (1 << r); now++)
				{
					ncount[next] += (ccount[now] * ret.matrix[next][now]) % mod;
					ncount[next] %= mod;
				}
			}
			memset(ccount, 0, sizeof(ccount));
			mask = 0;
			for (i = 0; i < (int)cx.size(); i++)
			{
				mask |= (1 << cx[i]);
			}
			// while(1);
			for (now = 0; now < (1 << r); now++)
			{
				if (!valid(cx, now))
				{
					continue;
				}
				ccount[now | mask] = ncount[now];
			}
			last = cy + 1;
		}
		tot = c - last + 1;
		//cout<<tot<<endl;while(1);
		//  base.printMatrix();
		memset(ncount, 0, sizeof(ncount));
		if (tot)
		{
			Matrix ret = bigmod(base, tot);
			for (next = 0; next < (1 << r); next++)
			{
				for (now = 0; now < (1 << r); now++)
				{
					ncount[next] += (ccount[now] * ret.matrix[next][now]) % mod;
					ncount[next] %= mod;
				}
			}
		}
		ll ans = ncount[0];
		printf("Case %d: ", ++cs);
		cout << ans << endl;
	}
	return 0;
}

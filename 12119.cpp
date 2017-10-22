#include <bits/stdc++.h>

using namespace std;

#pragma comment(linker, "/STACK:36777216")
#define lowbit(x) (x & (-x))
#define lc(x) (x << 1)
#define rc(x) (lc(x) + 1)
#define pi (acos(-1))
#define eps 1e-11
#define maxn 1000005
#define maxm 50005
#define ll long long
#define ull unsigned long long
#define inf 0x7fffffffffffffffll
#define pb push_back
#define mp make_pair

vector<ll> _div;
vector<pair<ll, int>> _div2;
int cnt, tot, sz, ans, p_cnt;
ll prime[10005][2], dcp[100005][105], tt[100005], tmp[100005], pr[maxn];
bool is_prime[maxn];

ll gcd(ll x, ll y) { return !y ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
/*
ll mul_mod(ll x,ll y,ll k){
    x%=k,y%=k;
    ll res=0;
    while(y){
        if(y&1){
            res+=x;
            if(res>=k)res-=k;
        }
        x+=x,y>>=1;
        if(x>=k)x-=k;
    }
    return res;
}
ll pow_mod(ll x,ll y,ll k){
    ll res=1;
    while(y){
        if(y&1)res=mul_mod(res,x,k);
        x=mul_mod(x,x,k),y>>=1;
    }
    return res;
}
ll witness(ll a,ll b,ll c) {
    if(b==0)return 1;
    ll x,y,t=0;
    while((b&1)==0)
        b>>=1,t++;
    y=x=pow_mod(a,b,c);
    while(t--){
        y=mul_mod(x,x,c);
        if(y==1 && x!=1 && x!=c-1)
            return false;
        x=y;
    }
    return y==1;
}
bool miller_rabin(ll n) {
    if(n==2)return true;
    if(n<2 || (n&1)==0)return false;
    for(int i=0;i<3;i++)
        if(witness(rand()%(n-2)+2,n-1,n)!=1)
            return false;
    return true;
}

ll pollard_rho(ll n,ll c){
    if(n%2==0)return 2;
    ll i=1,k=2,x,y,d;
    while(1){
        i++;
        x=(mul_mod(x,x,n)+c)%n;
        d=gcd(y-x,n);
        if(d==n)return n;
        if(d!=n && d>1)return d;
        if(i==k) y=x,k<<=1;
    }
}
void calc(ll n,ll c){
    if(n==1)return;
    if(miller_rabin(n)){
        _div.pb(n);
        return;
    }
    ll k=n;
    while(k==n)k=pollard_rho(n,c--);
    calc(k,c),calc(n/k,c);
}
*/
void prime_table()
{
	memset(is_prime, 1, sizeof(is_prime));
	for (int i = 2; i < maxn; i++)
	{
		if (is_prime[i])
			pr[++p_cnt] = i;
		for (int j = 1; j <= p_cnt && i * pr[j] < maxn; j++)
		{
			is_prime[i * pr[j]] = false;
			if (i % pr[j] == 0)
				break;
		}
	}
}
void go_prime(ll x)
{
	for (int i = 1; i <= p_cnt && pr[i] <= x; i++)
		if (x % pr[i] == 0)
		{
			prime[++cnt][0] = pr[i];
			ll kk = x;
			while (kk % pr[i] == 0)
				prime[cnt][1]++, kk /= pr[i];
		}
}

void dfs_find_div(ll now, int pos)
{
	if (now > 1000000)
		return;
	ll res = 1;
	if (pos == cnt + 1)
	{
		//tot++;
		//memcpy(dcp[tot],tt,sizeof(dcp[tot]));
		//_div2.pb(mp(now,tot));
		tmp[++sz] = now;
		return;
	}
	for (int i = 0; i <= prime[pos][1]; i++)
	{
		tt[pos] = i;
		dfs_find_div(now * res, pos + 1);
		res *= prime[pos][0];
	}
}

void go(ll _1, ll _2, ll n)
{
	//cout<<_1<<' '<<_2<<' '<<endl;
	ll res = 1; /*
    for(int i=1;i<=cnt;i++){
        ll k=max(dcp[x][i],dcp[y][i]);
        int tmp;
        if(k==prime[i][1])tmp=0;
        else tmp=prime[i][1];
        for(int j=1;j<=tmp;j++)
            res*=prime[i][0];
    }*/
	//cout<<res<<endl;
	ll l = _2 + 1, r = _1 + 25;
	if (r < l)
		return;
	int k1 = lower_bound(tmp + 1, tmp + 1 + sz, l) - tmp;
	int k2 = lower_bound(tmp + 1, tmp + 1 + sz, r) - tmp;
	for (int i = k1; i <= k2; i++)
		if (tmp[i] >= l && tmp[i] <= r && lcm(_1, lcm(_2, tmp[i])) == n)
			printf("%lld %lld %lld\n", _1, _2, tmp[i]), ans++;
}

void init()
{
	//_div.clear(),_div2.clear();
	memset(prime, 0, sizeof(prime));
	//memset(dcp,0,sizeof(dcp));
	//memset(tt,0,sizeof(tt));
	memset(tmp, 0, sizeof(tmp));
	tot = cnt = sz = ans = 0;
}

ll n;
int cas;

int main()
{
	prime_table();
	while (scanf("%lld", &n) == 1)
	{
		if (!n)
			break;
		init();
		go_prime(n);
		/*for(int i=1;i<=cnt;i++)
            cout<<prime[i][0]<<' '<<prime[i][1]<<endl;*/
		//calc_prime();
		//calc(n,240);
		/*sort(_div.begin(),_div.end());

        prime[cnt=1][0]=_div[0],prime[1][1]=1;
        for(int i=1,l=_div.size();i<l;i++){
            if(_div[i]==_div[i-1])prime[cnt][1]++;
            else prime[++cnt][0]=_div[i],prime[cnt][1]=1;
        }*/

		dfs_find_div(1, 1);
		//sort(_div2.begin(),_div2.end());
		sort(tmp + 1, tmp + 1 + sz);
		/*for(int i=1;i<=tot;i++){
            for(int j=1;j<=cnt;j++){
                cout<<prime[j][0]<<' '<<dcp[i][j]<<endl;
            }
            cout<<endl;
        }*/
		/*for(int i=0,l=_div2.size();i<l;i++)
            tmp[++sz]=_div2[i].first;*/

		printf("Scenario %d:\n", ++cas);
		for (int i = 1; i <= sz; i++)
			for (int j = i + 1; j <= sz && tmp[j] - tmp[i] <= 25; j++)
				go(tmp[i], tmp[j], n);
		if (!ans)
			printf("Such bells don't exist\n");
		printf("\n");
	}
}

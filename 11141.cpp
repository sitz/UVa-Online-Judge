#include <bits/stdc++.h>

using namespace std;

#define mini(a, b) ((a) < (b) ? (a) : (b))
#define maxi(a, b) ((a) > (b) ? (a) : (b))
const int MaxN = 200;
int t, n, pow2[13];
vector<pair<int, int>> edges[MaxN];
int a[MaxN][6];
int ans[4096], tans[4096];

bool Findd(vector<pair<int, int>> &vt, pair<int, int> &pr)
{
	for (int i = 0; i < vt.size(); i++)
		if (vt[i] == pr)
		{
			return true;
		}
	return false;
}
int tool(int a)
{
	int res = 0;
	while (a)
	{
		a = a / 2;
		res++;
	}
	return res;
}
bool iscorrect(int a)
{
	for (int i = 0; i < 12; i += 2)
		if ((a & pow2[i]) && (a & pow2[i + 1]))
		{
			return false;
		}
	return true;
}
bool jaygah(int a, int jaygah)
{
	return a & pow2[jaygah];
}
int makenew(int prime, int fs, int sc)
{
	if (fs == sc)
	{
		if (jaygah(prime, fs * 2))
		{
			return prime;
		}
		return prime | pow2[fs * 2 + 1];
	}
	if (!jaygah(prime, fs * 2))
	{
		prime += pow2[fs * 2];
	}
	if (jaygah(prime, fs * 2 + 1))
	{
		prime -= pow2[fs * 2 + 1];
	}
	if (!jaygah(prime, sc * 2) && !jaygah(prime, sc * 2 + 1))
	{
		prime += pow2[sc * 2 + 1];
	}
	return prime;
}
void chapcon(int a)
{
	while (a)
	{
		cout << a % 2;
		a = a / 2;
	}
	return;
}
void sumer(int dcnm, int edgnm)
{
	int fs = edges[dcnm][edgnm].first, sc = edges[dcnm][edgnm].second;
	if (fs == sc)
	{
		for (int i = 0; i < pow2[12]; i++)
			if (iscorrect(i) && tool(i % pow2[fs * 2 + 2]) % 2 == 0)
			{
				tans[makenew(i, fs, sc)] = (ans[i] + tans[makenew(i, fs, sc)]) % 1000000000;
				/*if(ans[i]!=0)
				{cout<<fs<<' '<<sc<<"avalie ";chapcon(i);cout<<' '<<ans[i]<<endl;}*/
			}
	}
	else
	{
		for (int i = 0; i < pow2[fs * 2 + 2]; i++)
			for (int j = 0; j < pow2[(5 - sc + 1) * 2]; j++)
			{
				int avalie = i + (j << (sc * 2));
				if (tool(i) % 2 == 1 || !iscorrect(avalie) || (jaygah(avalie, sc * 2) || jaygah(avalie, sc * 2 + 1)))
				{
					continue;
				}
				tans[makenew(avalie, fs, sc)] = (tans[makenew(avalie, fs, sc)] + ans[avalie]) % 1000000000;
				/*if(ans[avalie]!=0)
				{cout<<fs<<' '<<sc<<"avalie ";chapcon(avalie);cout<<' '<<ans[avalie]<<endl;}*/
			}
	}
	return;
}
int main()
{
	pow2[0] = 1;
	for (int i = 1; i < 13; i++)
	{
		pow2[i] = pow2[i - 1] * 2;
	}
	cin >> t;
	for (int cas = 0; cas < t; cas++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			edges[i].clear();
			//scanf("%d%d%d%d%d%d",a[i],a[i]+1,a[i]+2,a[i]+3,a[i]+4,a[i]+5);
			cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
			for (int j = 0; j < 6; j++)
			{
				a[i][j]--;
			}
			for (int j = 0; j < 3; j++)
			{
				int ta = mini(a[i][j], a[i][5 - j]), tb = maxi(a[i][j], a[i][5 - j]);
				pair<int, int> bp = make_pair(ta, tb);
				if (!Findd(edges[i], bp))
				{
					edges[i].push_back(bp);
				}
			}
		}
		memset(ans, 0, sizeof ans);
		memset(tans, 0, sizeof tans);
		tans[0] = 1;
		ans[0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < edges[i].size(); j++)
			{
				sumer(i, j);
			}
			memcpy(ans, tans, sizeof tans);
		}//n dynamic
		int sum = 0;
		for (int i = 0; i < 4096; i++)
		{
			sum = (sum + ans[i]) % 1000000000;
		}
		cout << sum - 1 << endl;
	}//case reader;
	return 0;
}

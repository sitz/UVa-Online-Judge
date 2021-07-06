#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back

#define N 5000
#define OUTPUT 0
#define OR 1
#define AND 2
#define NOT 3
#define ALPHABET 4

typedef vector<int> vint;
typedef vector<bool> vbool;
class Node
{
public:
	vbool val;
	int type;
	int chara;
	void take_and(vbool &a, vbool &b)
	{
		val.clear();
		rep(i, a.size()) val.pb(a[i] & b[i]);
	}
	void take_or(vbool &a, vbool &b)
	{
		val.clear();
		rep(i, a.size()) val.pb(a[i] | b[i]);
	}
	void take_not(vbool &a)
	{
		val.clear();
		rep(i, a.size()) val.pb(!a[i]);
	}
};

Node node[N];
vint edge[N];					 //should be clear
vbool alpha[26];			 //should be clear
int assign[100][100];	//should be initialize with -1
bool visited[100][100];//initialiize with false
string m[128];				 //should be clear??

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int opp[] = {1, 0, 3, 2};
char verify[4] = {'|', '|', '-', '-'};

int convert(int r)
{
	int index = 0;
	rep(i, r)
	{
		rep(j, m[i].size())
		{
			if (isupper(m[i][j]))
			{
				node[index].type = ALPHABET;
				node[index].chara = m[i][j] - 'A';
				assign[i][j] = index++;
			}
			else if (m[i][j] == ':')
			{
				if (i != 0 && i + 1 < r && m[i - 1][j] == ':' &&
						m[i + 1][j] == ':')
				{
					m[i][j] = ' ';
				}
			}
			else if (m[i][j] == '\\' || m[i][j] == '/')
			{
			}
			else if (m[i][j] == ')')//AND
			{
				node[index].type = AND;
				assign[i][j] = index++;
			}
			else if (m[i][j] == '>')//OR
			{
				node[index].type = OR;
				assign[i][j] = index++;
			}
			else if (m[i][j] == 'o')//NOT
			{
				node[index].type = NOT;
				assign[i][j] = index++;
			}
			else if (m[i][j] == '?')//OUTPUT
			{
				node[index].type = OUTPUT;
				assign[i][j] = index++;
			}
		}
	}
	rep(i, r) rep(j, m[i].size()) if (m[i][j] == ':')
	{
		m[i][j] = '-';
	}
	return index;
}

void tsort(int r, int y, int x, vint &res, int prev, int prevnode)
{
	//  cout << y <<" " <<x << " " << m[y][x] << " " <<" " << prev <<" " << prevnode << " " << assign[y][x] << endl;
	if (assign[y][x] != -1 && node[assign[y][x]].type != ALPHABET)
	{
		edge[assign[y][x]].pb(prevnode);
		prevnode = assign[y][x];
	}
	if (visited[y][x] == true)
	{
		return;
	}
	visited[y][x] = true;
	if (m[y][x] == '+')
	{
		rep(i, 4)
		{
			int ney = y + dy[i], nex = x + dx[i];
			if (nex < 0 || nex >= 100 || ney < 0 || ney >= r)
			{
				continue;
			}
			if ((m[ney][nex] == '-' || m[ney][nex] == '|') && m[ney][nex] != verify[prev] &&
					m[ney][nex] == verify[i])
			{
				tsort(r, ney, nex, res, i, prevnode);
			}
		}
	}
	else if (m[y][x] == '-')
	{
		int nex = x + dx[prev], ney = y + dy[prev];
		if (m[ney][nex] == '\\')
		{
			tsort(r, ney + 1, nex + 1, res, prev, prevnode);
		}
		else if (m[ney][nex] == '/')
		{
			tsort(r, ney - 1, nex + 1, res, prev, prevnode);
		}
		else
		{
			tsort(r, ney, nex, res, prev, prevnode);
		}
	}
	else if (m[y][x] == '|')
	{
		int nex = x + dx[prev], ney = y + dy[prev];
		tsort(r, ney, nex, res, prev, prevnode);
	}
	else if (isupper(m[y][x]))
	{
		rep(i, 4)
		{
			int nex = x + dx[i], ney = y + dy[i];
			if (nex < 0 || nex >= 100 || ney < 0 || ney >= r)
			{
				continue;
			}
			if (verify[i] == m[ney][nex])
			{
				tsort(r, ney, nex, res, i, prevnode);
			}
		}
	}
	else if (m[y][x] == 'o')
	{
		int nex = x + dx[prev], ney = y + dy[prev];
		tsort(r, ney, nex, res, prev, prevnode);
	}
	else if (m[y][x] == ')' || m[y][x] == '>')
	{
		int nex = x + dx[prev], ney = y + dy[prev];
		tsort(r, ney, nex, res, prev, prevnode);
	}
	else if (m[y][x] == '?')
	{
	}
	else
	{
		assert(false);
	}
	if (assign[y][x] != -1)
	{
		res.pb(assign[y][x]);
	}
}

void solve(int r)//2nd argument , in, is result of tsort
{
	int n = convert(r);
	int tar = -10000;
	/*
	rep(i,r){
	  rep(j,m[i].size()){
	    if (assign[i][j] == -1)cout << m[i][j];
	    else cout << (int)assign[i][j];
	  }
	  cout << endl;
	}
	*/
	rep(i, n) edge[i].clear();
	vint in;
	rep(i, r)
			rep(j, m[i].size()) if (isupper(m[i][j]))
	{
		tsort(r, i, j, in, -1, assign[i][j]);
	}
	reverse(in.begin(), in.end());
	rep(i, in.size())
	{
		int now = in[i];
		if (node[now].type == ALPHABET)
		{
			node[now].val = alpha[node[now].chara];
		}
		else if (node[now].type == OUTPUT)
		{
			node[now].val = node[edge[now][0]].val;
			tar = now;
		}
		else if (node[now].type == AND)
		{
			node[now].take_and(node[edge[now][0]].val, node[edge[now][1]].val);
		}
		else if (node[now].type == OR)
		{
			node[now].take_or(node[edge[now][0]].val, node[edge[now][1]].val);
		}
		else if (node[now].type == NOT)
		{
			node[now].take_not(node[edge[now][0]].val);
		}
	}
	rep(i, node[tar].val.size()) cout << node[tar].val[i] << endl;
}

main()
{
	int tc = 0;
	while (getline(cin, m[0]))
	{
		//if (tc++)puts("");
		rep(i, 26) alpha[i].clear();
		rep(i, 100) rep(j, 100)
		{
			assign[i][j] = -1;
			visited[i][j] = false;
		}
		int r = 1;
		while (getline(cin, m[r]) && m[r][0] != '*')
		{
			r++;
		}
		rep(i, r) while (m[i].size() < 100)
		{
			m[i] += ' ';
		}
		REP(i, r + 1, 100)
		{
			m[i].clear();
		}
		string tmp;
		while (getline(cin, tmp) && tmp != "*")
		{
			rep(i, 26) alpha[i].pb(tmp[i] == '1' ? true : false);
		}
		solve(r);
		puts("");
	}
}

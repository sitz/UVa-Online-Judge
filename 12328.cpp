#include <bits/stdc++.h>

using namespace std;

#define M 110
#define MOD 1000003
#define MAX_BOUND 1100
#define MAX_MINE 1510
#define MAX_BOUND_LEN 2800
#define safe_sight 4

class partial_state_type
{
public:
	vector<pair<int, int>> cnt;
};
partial_state_type partial_state[MAX_BOUND];

const int hh[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int ll[8] = {1, 0, -1, 0, 1, 1, -1, -1};

int n, m, T, total_state, data[M][M];
bool visited[M][M];
int added_unrevealed[M][M];
vector<pair<int, int>> around, numbers;

bool touch_bound_flag;
int dfs_timer;

int global_tag, top, board[M][M];
pair<int, int> stk[M * M];

int dp[MAX_BOUND_LEN][MAX_MINE][16];
int lmt[MAX_BOUND_LEN], cnter[M][M], total_inner = 0;
int cnt_should_check[MAX_BOUND_LEN];
pair<int, int> should_check[MAX_BOUND_LEN][10];

int find_dep_counter = 0, dep_counter[M][M];

long long global_dp[MAX_MINE];
int CC[10001][1001];

inline void read_data()
{
	cin >> n >> m >> T;
	int i, j;
	char ch;
	memset(data, -1, sizeof(data));
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			cin >> ch;
			data[i][j] = ch == '.' ? -1 : (ch - '0');
		}
}

inline bool in_bound(int a, int b)
{
	return !(a < 1 || a > n || b < 1 || b > m);
}

inline void dfs_extract_field_bound(int a, int b)
{
	dfs_timer++;
	visited[a][b] = true;
	numbers.push_back(make_pair(a, b));
	if (a == 1 || a == n || b == 1 || b == m)
		touch_bound_flag = true;
	int i, tempa, tempb;
	for (i = 0; i < 8; i++)
	{
		tempa = a + hh[i];
		tempb = b + ll[i];
		if (in_bound(tempa, tempb) && data[tempa][tempb] == -1 && !added_unrevealed[tempa][tempb])
		{
			added_unrevealed[tempa][tempb] = dfs_timer;
			around.push_back(make_pair(tempa, tempb));
		}
	}
	for (i = 0; i < 4; i++)
	{
		tempa = a + hh[i];
		tempb = b + ll[i];
		if (in_bound(tempa, tempb) && data[tempa][tempb] > 0 && data[tempa][tempb] < 9 && !visited[tempa][tempb])
			dfs_extract_field_bound(tempa, tempb);
	}
}

inline bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}

//int __builtin_popcount (uint x)
inline int pop_count(int s)
{
	int i, res = 0;
	for (i = 0; i < safe_sight; i++)
		if (s & (1 << i))
			res++;
	return res;
}
inline int pop_count(int s, int l)
{
	int i, res = 0;
	for (i = 0; i < l; i++)
		if (s & (1 << i))
			res++;
	return res;
}

inline void clear_around(pair<int, int> p)
{
	int i, a = p.first, b = p.second;
	int tempa, tempb;
	for (i = 0; i < 8; i++)
	{
		tempa = a + hh[i];
		tempb = b + ll[i];
		if (!in_bound(tempa, tempb))
			continue;
		cnter[tempa][tempb] = 0;
	}
}

inline void set_around(pair<int, int> p)
{
	int i, a = p.first, b = p.second;
	int tempa, tempb;
	for (i = 0; i < 8; i++)
	{
		tempa = a + hh[i];
		tempb = b + ll[i];
		if (!in_bound(tempa, tempb))
			continue;
		cnter[tempa][tempb]++;
	}
}

inline bool check_around(pair<int, int> p)
{
	int i, a = p.first, b = p.second;
	int tempa, tempb;
	for (i = 0; i < 8; i++)
	{
		tempa = a + hh[i];
		tempb = b + ll[i];
		if (!in_bound(tempa, tempb))
			continue;
		if (data[tempa][tempb] > 0 && data[tempa][tempb] < 9)
			if (data[tempa][tempb] != cnter[tempa][tempb])
				return false;
	}
	return true;
}

inline bool ok(int *who, int *chosen, int cc, pair<int, int> *dep, int cnt_dep)
{
	int i, j;
	int a, b, tempa, tempb;
	for (i = 0; i < cnt_dep; i++)
		cnter[dep[i].first][dep[i].second] = 0;
	for (i = 0; i < cc; i++)
		if (chosen[i] == 1)
		{
			a = stk[who[i]].first;
			b = stk[who[i]].second;
			for (j = 0; j < 8; j++)
			{
				tempa = a + hh[j];
				tempb = b + ll[j];
				cnter[tempa][tempb]++;
			}
		}
	for (i = 0; i < cnt_dep; i++)
		if (cnter[dep[i].first][dep[i].second] != data[dep[i].first][dep[i].second])
			return false;
	return true;
}

inline bool check_included(int a, int b, int *who, int cc)
{
	int i;
	for (i = 0; i < cc; i++)
		if (a == stk[who[i]].first && b == stk[who[i]].second)
			return true;
	return false;
}

inline bool covered(int a, int b, int *who, int cc)
{
	int i, tempa, tempb;
	for (i = 0; i < 8; i++)
	{
		tempa = a + hh[i];
		tempb = b + ll[i];
		if (in_bound(tempa, tempb) && data[tempa][tempb] == -1)
			if (!check_included(tempa, tempb, who, cc))
				return false;
	}
	return true;
}

void find_dep(int *who, int cc, pair<int, int> *dep, int &cnt_dep)
{
	int a, b, tempa, tempb, i, j;
	cnt_dep = 0;
	for (i = 0; i < cc; i++)
	{
		a = stk[who[i]].first;
		b = stk[who[i]].second;
		for (j = 0; j < 8; j++)
		{
			tempa = a + hh[j];
			tempb = b + ll[j];
			if (data[tempa][tempb] < 1 || dep_counter[tempa][tempb] == find_dep_counter)
				continue;
			dep_counter[tempa][tempb] = find_dep_counter;
			if (covered(tempa, tempb, who, cc))
				dep[cnt_dep++] = make_pair(tempa, tempb);
		}
	}
}

bool acceptable(int tm, int hm)
{
	int cc = 8, who[10], chosen[10], i;
	for (i = 0; i < 4; i++)
	{
		who[i] = i;
		chosen[i] = (hm & (1 << i)) ? 1 : 0;
	}
	for (i = 0; i < 4; i++)
	{
		who[i + 4] = top - 4 + i;
		if (tm & (1 << i))
			chosen[i + 4] = 1;
		else
			chosen[i + 4] = 0;
	}
	pair<int, int> dep[100];
	int cnt_dep;
	find_dep_counter++;
	find_dep(who, cc, dep, cnt_dep);
	return ok(who, chosen, cc, dep, cnt_dep);
}

inline bool check_ok(int place, int mask)
{
	int who[5], chosen[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		who[i] = place - 2 + i;
		if (mask & (1 << i))
			chosen[i] = 1;
		else
			chosen[i] = 0;
	}
	return ok(who, chosen, 5, should_check[place + 2], cnt_should_check[place + 2]);
}

inline void work_inner_dp()
{
	int tail_mask, i, j, k;
	bool flag;
	int mask = (1 << safe_sight) - 1;
	map<int, int> table;
	table.clear();
	for (tail_mask = 0; tail_mask < (1 << safe_sight); tail_mask++)
	{
		flag = false;
		for (i = 0; i < (1 << safe_sight); i++)
			if (acceptable(tail_mask, i))
			{
				flag = true;
				dp[3][pop_count(i)][i] = 1;
			}
			else
			{
				dp[3][pop_count(i)][i] = 0;
			}
		if (!flag)
			continue;
		memset(lmt, 0, sizeof(int) * (top + 1));
		for (i = 0; i < 4; i++)
			lmt[i] = 4;
		for (i = 3; i < top - 1; i++)
		{
			for (j = 0; j <= lmt[i] + 1; j++)
				for (k = 0; k < (1 << safe_sight); k++)
					dp[i + 1][j][k] = 0;// clear previous information
			for (j = 0; j <= lmt[i]; j++)
				for (k = 0; k < (1 << safe_sight); k++)
					if (dp[i][j][k] > 0)
					{
						if (check_ok(i - 1, k + (1 << safe_sight)))
						{
							dp[i + 1][j + 1][(k + (1 << safe_sight)) >> 1] += dp[i][j][k];
							dp[i + 1][j + 1][(k + (1 << safe_sight)) >> 1] %= MOD;
							lmt[i + 1] = max(lmt[i + 1], j + 1);
							lmt[i + 1] = min(lmt[i + 1], T);
						}
						if (check_ok(i - 1, k))
						{
							dp[i + 1][j][k >> 1] += dp[i][j][k];
							dp[i + 1][j][k >> 1] %= MOD;
							lmt[i + 1] = max(lmt[i + 1], j);
							lmt[i + 1] = min(lmt[i + 1], T);
						}
					}
		}
		for (i = 0; i <= lmt[top - 1]; i++)
			if (dp[top - 1][i][tail_mask] != 0)
				table[i] += dp[top - 1][i][tail_mask];
	}
	total_state++;
	partial_state[total_state].cnt.clear();
	map<int, int>::iterator it;
	for (it = table.begin(); it != table.end(); it++)
		partial_state[total_state].cnt.push_back(*it);
}

inline void force_enum()
{
	int i, mask;
	bool flag;
	map<int, int> table;
	table.clear();
	for (mask = 0; mask < (1 << top); mask++)
	{
		for (i = 0; i < top; i++)
			clear_around(stk[i]);
		for (i = 0; i < top; i++)
			if (mask & (1 << i))
				set_around(stk[i]);
		flag = true;
		for (i = 0; i < top; i++)
			if (!check_around(stk[i]))
				flag = false;
		if (!flag)
			continue;
		table[pop_count(mask, top)]++;
	}
	total_state++;
	partial_state[total_state].cnt.clear();
	map<int, int>::iterator it;
	for (it = table.begin(); it != table.end(); it++)
		partial_state[total_state].cnt.push_back(*it);
}

inline void make_dep()
{
	int i, j;
	int who[5];
	for (i = 4; i < top; i++)
	{
		for (j = 0; j < 5; j++)
			who[j] = i - 4 + j;
		find_dep_counter++;
		find_dep(who, 5, should_check[i], cnt_should_check[i]);
	}
}

inline bool adj(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) <= 1 && abs(a.second - b.second) <= 1;
}

inline void dfsxxxx(int a, int b)
{
	stk[top++] = make_pair(a, b);
	board[a][b] = -1;
	int tempa, tempb, i, choosea, chooseb, dist = -1;
	for (i = 0; i < 8; i++)
	{
		tempa = a + hh[i];
		tempb = b + ll[i];
		if (board[tempa][tempb] == global_tag)
		{
			if (dist == -1 || abs(added_unrevealed[tempa][tempb] - added_unrevealed[a][b]) < dist)
			{
				dist = abs(added_unrevealed[tempa][tempb] - added_unrevealed[a][b]);
				choosea = tempa;
				chooseb = tempb;
			}
		}
	}
	if (dist == -1)
		return;
	dfsxxxx(choosea, chooseb);
}

inline void output_stk()
{
	puts("STK:");
	for (int i = 0; i < top; i++)
		printf("%d %d\n", stk[i].first, stk[i].second);
}

inline void output_dep()
{
	int i, j;
	for (i = 4; i < top; i++)
	{
		printf("%d: ", i);
		for (j = 0; j < cnt_should_check[i]; j++)
			printf("(%d %d) ", should_check[i][j].first, should_check[i][j].second);
		puts("");
	}
}

inline void process_cycle()
{
	top = 0;
	if (around.size() <= 8)
	{
		int i;
		for (i = 0; i < around.size(); i++)
			stk[top++] = around[i];
		force_enum();
		return;
	}
	if (touch_bound_flag)
	{
		int i, a, b;
		for (i = 0; i < around.size(); i++)
		{
			a = around[i].first;
			b = around[i].second;
			if (a == 1 || a == n || b == 1 || b == m)
			{
				dfsxxxx(a, b);
				break;
			}
		}
	}
	else
	{
		dfsxxxx(around[0].first, around[0].second);
	}
	make_dep();
	work_inner_dp();
}

inline bool is_inner(int a, int b)
{
	if (data[a][b] != -1)
		return false;
	int tempa, tempb, i;
	for (i = 0; i < 8; i++)
	{
		tempa = a + hh[i];
		tempb = b + ll[i];
		if (data[tempa][tempb] != -1)
			return false;
	}
	return true;
}

inline void init()
{
	memset(visited, false, sizeof(visited));
	memset(added_unrevealed, false, sizeof(added_unrevealed));
	memset(board, -1, sizeof(board));
	int i, j, k, cnt = 0;
	total_state = 0;
	global_tag = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (i == 1 || i == n || j == 1 || j == m)
				if (!visited[i][j] && data[i][j] > 0 && data[i][j] < 9)
				{
					touch_bound_flag = false;
					around.clear();
					numbers.clear();
					dfs_timer = 0;
					dfs_extract_field_bound(i, j);
					global_tag++;
					for (k = 0; k < around.size(); k++)
						board[around[k].first][around[k].second] = global_tag;
					process_cycle();
				}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (!visited[i][j] && data[i][j] > 0 && data[i][j] < 9)
			{
				touch_bound_flag = false;
				around.clear();
				numbers.clear();
				dfs_timer = 0;
				dfs_extract_field_bound(i, j);
				global_tag++;
				for (k = 0; k < around.size(); k++)
					board[around[k].first][around[k].second] = global_tag;
				process_cycle();
			}
	total_inner = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (is_inner(i, j))
				total_inner++;
}

inline int calc_C(int a, int b)
{
	if (a < b)
		return 0;
	if (b == 0)
		return 1;
	if (CC[a][b] != -1)
		return CC[a][b];
	if (a == b)
		return CC[a][b] = 1;
	else
		return CC[a][b] = (calc_C(a - 1, b - 1) + calc_C(a - 1, b)) % MOD;
}

inline int work_ans()
{
	memset(global_dp, 0, sizeof(global_dp));
	global_dp[0] = 1;
	int i, j, k;
	pair<int, int> temp;
	for (i = 1; i <= total_state; i++)
	{
		for (j = T; j >= 0; j--)
			if (global_dp[j] != 0)
			{
				for (k = 0; k < partial_state[i].cnt.size(); k++)
				{
					temp = partial_state[i].cnt[k];
					if (j + temp.first > T)
						break;
					global_dp[j + temp.first] = (global_dp[j + temp.first] + global_dp[j] * temp.second) % MOD;
				}
				global_dp[j] = 0;
			}
	}
	int res = 0, tt;
	for (i = 0; i <= T; i++)
		if (global_dp[i] != 0)
		{
			res += (global_dp[i] * (tt = calc_C(total_inner, T - i))) % MOD;
			res %= MOD;
		}
	return res;
}

int main()
{
	int t;
	memset(CC, -1, sizeof(CC));
	int ans, i;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		read_data();
		init();
		ans = work_ans();
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}

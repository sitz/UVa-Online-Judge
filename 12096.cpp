#include <bits/stdc++.h>

using namespace std;

/**
 * Algorithm: give each set a unique integer ID, represent a set of
 *            sets as a set of IDs.
 */

typedef set<int> Set;

vector<int> setstack;
map<Set, int> setid;
Set sets[1000000];

int SetId(const Set &s)
{
	int &r = setid[s];
	if (!r)
	{
		r = setid.size(), sets[r - 1] = s;
	}
	return r - 1;
}

int pop()
{
	int x = setstack.back();
	setstack.pop_back();
	return x;
}

void solve(int n)
{
	char cmd[30];
	setid.clear();
	setstack.clear();
	SetId(sets[0]);
	for (int i = 0; i < n && scanf("%s", cmd); ++i)
	{
		Set res, sub, X, Y;
		int x, y;
		switch (*cmd)
		{
		case 'P':
			setstack.push_back(0);
			break;
		case 'D':
			setstack.push_back(setstack.back());
			break;
		case 'U':
			x = pop();
			y = pop();
			set_union(sets[x].begin(), sets[x].end(),
								sets[y].begin(), sets[y].end(),
								inserter(res, res.begin()));
			setstack.push_back(SetId(res));
			break;
		case 'I':
			x = pop();
			y = pop();
			set_intersection(sets[x].begin(), sets[x].end(),
											 sets[y].begin(), sets[y].end(),
											 inserter(res, res.begin()));
			setstack.push_back(SetId(res));
			break;
		case 'A':
			x = pop();
			y = pop();
			res = sets[y];
			res.insert(x);
			setstack.push_back(SetId(res));
			break;
		case 'X':
			X = sets[pop()];
			Y = sets[pop()];
			for (Set::iterator it = X.begin(); it != X.end(); ++it)
				for (Set::iterator jt = Y.begin(); jt != Y.end(); ++jt)
				{
					sub.clear();
					sub.insert(*it);
					sub.insert(*jt);
					res.insert(SetId(sub));
				}
			setstack.push_back(SetId(res));
			break;
		default:
			assert(0);
		}
		printf("%d\n", (int)sets[setstack.back()].size());
	}
	printf("***\n");
}

int main()
{
	int t, n;
	for (scanf("%d", &t); scanf("%d", &n), t--; solve(n))
		;
	return 0;
}

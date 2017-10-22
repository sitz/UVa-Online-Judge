#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 7;
const LL INF = 1LL << 60;

int n;
LL arr[MAXN], tgt;

// prob can be reduced to replacing arithmetic ops: +, -, *, / btw a set of # and check if the res >= tgt. note that we can use >=1 # in any order for the solution use recursive and bitmask approach, on each iteration, we check if we haven't included the ith number (hose) in the solution, if not, include it using the possible operators and recursively call the method again
// - if a subtraction gives a negative number, prune the branch (not able to subtract more water than
// available)
// - if a division gives a non-integer number, prune the branch (not able to divide into non-integer
//   numbers)

LL solve(int mask, LL acc)
{
	// if current solution is greater or equal than tgt, use it as current minimum, or use inf otherwise
	LL mini = acc >= tgt ? acc : INF;
	// iterate through each number (hose)
	for (int i = 0; i < n; ++i)
	{
		// if i-th # (hose) is alrdy incl in soln, skip
		if (mask & (1 << i))
		{
			continue;
		}
		// try add i-th hose to soln
		mini = min(mini, solve(mask | (1 << i), acc + arr[i]));
		// if subtraction won't give neg #, try subtracting i-th hose from soln
		if (acc >= arr[i])
		{
			mini = min(mini, solve(mask | (1 << i), acc - arr[i]));
		}
		// try multiplying i-th hose to the solution
		mini = min(mini, solve(mask | (1 << i), acc * arr[i]));
		// if division won't give non-integer #, try dividing i-th hose from soln
		if (acc % arr[i] == 0)
		{
			mini = min(mini, solve(mask | (1 << i), acc / arr[i]));
		}
	}
	return mini;
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		n = 0;
		stringstream ss(line);
		ss >> tgt;
		if (tgt == 0LL)
		{
			break;
		}
		while (ss >> arr[n++])
			; // store hose val in arr[]
		n--;// actual # hose
		// initially call recursive() with mask 0 (haven't incl any hose yet) and 0ll as accum (no op performed yet)
		LL ans = solve(0, 0LL);
		printf("%lld\n", ans == INF ? 0LL : ans);
	}
	return 0;
}

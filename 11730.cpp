#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

bool isnp[1001] = {};
bool visited[1001] = {};
int step[1001] = {};
vector<int> prime;

void sieve()
{
	for (int i = 2; i < 1001; i++)
	{
		if (!isnp[i])
		{
			for (int j = i * i; j < 1001; j += i)
			{
				isnp[j] = true;
			}
		}
		prime.push_back(i);
	}
}

vector<int> getFactor(int n)
{
	vector<int> V;
	int i = 0;
	if (!isnp[n])
	{
		return V;
	}
	while (n != 1)
	{
		if (n % prime[i] == 0)
		{
			V.push_back(prime[i]);
		}
		while (n % prime[i] == 0)
		{
			n /= prime[i];
		}
		i++;
	}
	return V;
}

int BFS(int start, int end)
{
	queue<int> Q;
	memset(visited, 0, sizeof(visited));
	visited[start] = true;
	step[start] = 0;
	Q.push(start);
	while (!Q.empty())
	{
		int node = Q.front();
		Q.pop();
		vector<int> factor = getFactor(node);
		if (node == end)
		{
			return step[node];
		}
		for (int i = 0; i < factor.size(); i++)
		{
			int sum = node + factor[i];
			if (visited[sum] || sum > 1000)
			{
				continue;
			}
			visited[sum] = true;
			step[sum] = step[node] + 1;
			Q.push(sum);
		}
	}
	return -1;
}

int main()
{
	sieve();
	int S, T;
	int cs = 0;
	while (cin >> S >> T && S && T)
	{
		cout << "Case " << ++cs << ": " << BFS(S, T) << endl;
	}
	return 0;
}

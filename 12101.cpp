#include <bits/stdc++.h>

using namespace std;

int a, b;
int p[9999] = {0};
int visited[9999] = {0};
bool isprime(int x)
{
	for (int i = 2; i <= sqrt((double)x); ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int BFS(int s, int r)
{
	queue<int> q;
	q.push(s);
	p[s] = 0;
	visited[s] = 1;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 0; i <= 9; i++)
		{
			int y1 = (temp / 10) * 10 + i;
			if (isprime(y1) && !visited[y1])
			{
				q.push(y1);
				p[y1] = p[temp] + 1;
				visited[y1] = 1;
			}
			int y2 = temp % 10 + (temp / 100) * 100 + i * 10;
			if (isprime(y2) && !visited[y2])
			{
				q.push(y2);
				p[y2] = p[temp] + 1;
				visited[y2] = 1;
			}
			int y3 = temp % 100 + (temp / 1000) * 1000 + 100 * i;
			if (isprime(y3) && !visited[y3])
			{
				q.push(y3);
				p[y3] = p[temp] + 1;
				visited[y3] = 1;
			}
			if (i != 0)
			{
				int y4 = temp % 1000 + i * 1000;
				if (isprime(y4) && !visited[y4])
				{
					q.push(y4);
					p[y4] = p[temp] + 1;
					visited[y4] = 1;
				}
			}
			if (visited[r])
			{
				return p[r];
			}
		}
	}
	return 0;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		memset(visited, 0, sizeof(visited));
		memset(p, 0, sizeof(p));
		cin >> a >> b;
		cout << BFS(a, b) << endl;
	}
	return 0;
}

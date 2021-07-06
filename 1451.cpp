#include <bits/stdc++.h>

using namespace std;

const int maxn = 10e5 + 10;

char str[maxn];
int q[maxn], sum[maxn];

double dis(int a, int b)
{
	return (sum[b] - sum[a]) * 1.0 / (b - a);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		scanf("%s", str + 1);
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + str[i] - '0';
		int ansl = 0, ansr = m;
		double ans = dis(0, m);
		int front = 0, rear = -1, length = m;
		for (int i = m; i <= n; i++)
		{
			int ita = i - m;
			while (front < rear && dis(q[rear], ita) <= dis(q[rear - 1], ita))
				rear--;
			q[++rear] = ita;
			while (front < rear && dis(q[front], i) <= dis(q[front + 1], i))
				front++;
			double itb = dis(q[front], i);
			if (itb > ans)
			{
				ans = itb;
				ansl = q[front];
				ansr = i;
				length = i - q[front];
			}
			else if (itb == ans && length > i - q[front])
			{
				ansl = q[front];
				ansr = i;
				length = i - q[front];
			}
		}
		printf("%d %d\n", ansl + 1, ansr);
	}
	return 0;
}

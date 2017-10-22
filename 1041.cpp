#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
VI right_[52], goal;

int pos[52], trans[52], wa[52][2], In[52], T, ans_wn, ans[52][2];

void disp(VI A)
{
	int i;
	for (i = 0; i < 52; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}
int count_dif(VI A, VI B)
{
	int cnt = 0, i, tmp;
	for (i = 0; i < 52; i++)
	{
		pos[A[i]] = i;
	}
	for (i = 0; i < 52; i++)
	{
		if (B[i] != A[i])
		{
			int now = B[i];
			do
			{
				cnt++;
				tmp = B[pos[now]];
				B[pos[now]] = now;
				now = tmp;
			} while (pos[now] != i);
			B[i] = now;
		}
	}
	return cnt;
}

void dfs(int dep, int wn, VI A, int must)
{
	if (dep > T || wn >= ans_wn)
	{
		return;
	}
	int need = count_dif(A, right_[T - dep]);
	if (need > must)
	{
		return;
	}
	if (need + dep > T)
	{
		return;
	}
	if (need == 0)
	{
		if (wn < ans_wn)
		{
			ans_wn = wn;
			for (int i = 0; i < wn; i++)
			{
				ans[i][0] = wa[i][0], ans[i][1] = wa[i][1];
			}
		}
		return;
	}
	VI B = A, C;
	C.resize(52);
	for (int i = 0; i < 51; i++)
	{
		wa[wn][1] = i;
		wa[wn][0] = dep;
		swap(B[i], B[i + 1]);
		for (int j = 0; j < 52; j++)
		{
			C[j] = B[trans[j]];
		}
		dfs(dep + 1, wn + 1, C, need);
		swap(B[i], B[i + 1]);
	}
	for (int i = 0; i < 52; i++)
	{
		C[i] = B[trans[i]];
	}
	dfs(dep + 1, wn, C, need);
}

int main()
{
	int tt, tcas = 1, i, j;
	scanf("%d", &tt);
	for (i = 0; i < 52; i++)
	{
		goal.push_back(i);
	}
	while (tt--)
	{
		vector<int> init;
		for (i = 0; i < 52; i++)
		{
			scanf("%d", &In[i]), init.push_back(In[i]);
		}
		for (i = 0; i < 52; i++)
		{
			if (i < 26)
			{
				trans[i] = i * 2 + 1;
			}
			else
			{
				trans[i] = (i - 26) * 2;
			}
		}
		T = 0;
		vector<int> A;
		A = goal;
		right_[0] = goal;
		while (++T)
		{
			vector<int> tmp;
			tmp.resize(52);
			for (i = 0; i < 52; i++)
			{
				tmp[trans[i]] = A[i];
			}
			A = tmp;
			right_[T] = A;
			if (count_dif(A, init) <= T)
			{
				break;
			}
		}
		printf("Case %d\n", tcas++);
		printf("Number of shuffles = %d\n", T);
		ans_wn = 52;
		dfs(0, 0, init, 100);
		if (ans_wn == 0)
		{
			printf("No error in any shuffle\n");
		}
		else
		{
			for (i = ans_wn - 1; i >= 0; i--)
			{
				printf("Error in shuffle %d at location %d\n", T - ans[i][0], ans[i][1]);
			}
		}
		printf("\n");
	}
	return 0;
}

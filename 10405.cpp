#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 1000;

char A[MAXSIZE + 5], B[MAXSIZE + 5];
int LCS[MAXSIZE + 1][MAXSIZE + 1];

int main()
{
	while (cin.getline(A + 1, MAXSIZE))
	{
		cin.getline(B + 1, MAXSIZE);
		int i, j, lenA, lenB;
		lenA = strlen(A + 1);
		lenB = strlen(B + 1);
		LCS[0][0] = 0;
		for (i = 0; i <= lenA; i++)
		{
			LCS[i][0] = 0;
		}
		for (i = 0; i <= lenB; i++)
		{
			LCS[0][i] = 0;
		}
		for (i = 1; i <= lenA; i++)
			for (j = 1; j <= lenB; j++)
				if (A[i] == B[j])
				{
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				}
				else
				{
					LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
				}
		cout << LCS[lenA][lenB] << endl;
	}
	return 0;
}

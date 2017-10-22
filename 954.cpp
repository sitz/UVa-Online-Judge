#include <bits/stdc++.h>

using namespace std;

char piece[20][515], flag, used[17];
int grid[4][4], soln[4][4], conf[100][17], conf_index[100], kase = 1, n = 1;

/*int safe(int rank, int r, int c){
    if( r && piece[rank][1] != piece[grid[ r - 1 ][c]][3]) return 0;
    if( c && piece[rank][2] != piece[grid[r][ c - 1 ]][0]) return 0;
    return 1;
}*/

void backtrack(int r, int c)
{
	register int i, x = 0, y = 0, j, maxj;
	if (r == 4)
	{
		for (r = 0; r < 4; r++)
			for (c = 0; c < 4; c++)
			{
				soln[r][c] = grid[r][c];
			}
		flag++;
		return;
	}
	/*for ( i = 1; i <= 16  && flag < 3; i++ ){
	    if( !used[i] && safe( i, r, c ) ){
	        grid[r][c] = i;
	        used[i] = 1;
	        (c == 3) ? backtrack( r + 1, 0 ) : backtrack( r , c + 1 );
	        grid[r][c] = 0;
	        used[i] = 0;
	    }
	}*/
	if (c == 0)
	{
		x = 10 * (piece[grid[r - 1][c]][3] - '0'), maxj = 10;
		for (j = 0; j < maxj && flag < 3; j++, x++)
		{
			for (i = 0; i < conf_index[x] && flag < 3; i++)
			{
				if (!used[conf[x][i]])
				{
					grid[r][c] = conf[x][i];
					used[conf[x][i]] = 1;
					(c == 3) ? backtrack(r + 1, 0) : backtrack(r, c + 1);
					grid[r][c] = 0;
					used[conf[x][i]] = 0;
				}
			}
		}
	}
	else if (r == 0)
	{
		x = piece[grid[r][c - 1]][0] - '0', maxj = 10;
		for (j = 0; j < maxj && flag < 3; j++, x += 10)
		{
			for (i = 0; i < conf_index[x] && flag < 3; i++)
			{
				if (!used[conf[x][i]])
				{
					grid[r][c] = conf[x][i];
					used[conf[x][i]] = 1;
					(c == 3) ? backtrack(r + 1, 0) : backtrack(r, c + 1);
					grid[r][c] = 0;
					used[conf[x][i]] = 0;
				}
			}
		}
	}
	else
	{
		x = 10 * (piece[grid[r - 1][c]][3] - '0') + piece[grid[r][c - 1]][0] - '0';
		for (i = 0; i < conf_index[x] && flag < 3; i++)
		{
			if (!used[conf[x][i]])
			{
				grid[r][c] = conf[x][i];
				used[conf[x][i]] = 1;
				(c == 3) ? backtrack(r + 1, 0) : backtrack(r, c + 1);
				grid[r][c] = 0;
				used[conf[x][i]] = 0;
			}
		}
	}
}

void solve()
{
	int i;
	for (i = 1; i <= 16 && flag < 3; i++)
	{
		grid[0][0] = i;
		used[i] = 1;
		backtrack(0, 1);
		used[i] = 0;
	}
}

int parse_input()
{
	register int i, j = 0;
	register char ch, tmp = 0, notspace = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n' && notspace == 0)
		{
			break;
		}
		if (!isspace(ch) && ch != '\n')
		{
			notspace = ch;
			if (n <= 17)
			{
				piece[n][j++] = ch;
			}
		}
		else
		{
			if (n <= 17 && j)
			{
				piece[n][j] = 0;
			}
			if (j)
			{
				n++;
			}
			j = 0;
		}
		if (ch == '\n')
		{
			notspace = 0;
		}
		tmp = ch;
	}
	if (tmp == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	register int i, j, x;
	while (parse_input())
	{
		x = n - 1;
		for (i = 0; i < 100; i++)
		{
			conf_index[i] = 0;
		}
		if (x != 16)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
		for (i = 1; i <= 16; i++)
		{
			if (flag)
			{
				for (j = 0; piece[i][j] && isdigit(piece[i][j]); j++)
					;
				if (piece[i][j] || j != 4)
				{
					flag = 0;
				}
			}
			x = 10 * (piece[i][1] - '0') + piece[i][2] - '0';
			if (flag)
			{
				conf[x][conf_index[x]++] = i;
			}
		}
		for (i = 1; i < 16 && flag; i++)
			for (j = i + 1; j <= 16 && flag; j++)
				if (strcmp(piece[i], piece[j]) == 0)
				{
					flag = 0;
				}
		if (flag)
		{
			solve();
		}
		if (kase > 1)
		{
			puts("");
		}
		printf("%d\n", flag);
		if (flag == 2)
		{
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (j)
					{
						putchar(' ');
					}
					printf(piece[soln[i][j]]);
				}
				puts("");
			}
		}
		kase++;
		n = 1;
	}
	return 0;
}

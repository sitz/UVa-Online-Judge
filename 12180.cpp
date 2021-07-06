#include <bits/stdc++.h>

using namespace std;

// method : alpha-beta pruning
// runtime: slow (didn't check, probably exponential)

/* maximum number of mugs */
#define MAXM 4
/* number of turns swapped mugs are "locked" into their place */
#define LOCKTURNS 4
/* maximum number of swaps per player per game */
#define NROFSWAPS 3
/* infinity (must be sufficiently large) */
#define INF 12345

/* stores the state of a game */
/* bips[i] = number of stones in mug i (mugs are numbered as given in the problem input) */
/* lock[i] = number of turns before mugs i and i + M can be swapped again */
/* swap[i] = number of remaining swaps for player i */
typedef struct
{
	int bips[2 * (MAXM + 1)], lock[MAXM], swap[2];
} state_t;

/* M = number of mugs per player */
/* N = total number of mugs and bowls, i.e. 2*M+1 */
int M, N;

/* Just do it. */
/* stat = pointer to current state of game */
/* plya = whose turn is it? */
/* alph = current player can certainly reach this score (as in alpha-beta pruning) */
/* beta = current player cannot be better than this */
int nike(const state_t *stat, int plya, int alph, int beta)
{
	/* last = index of last mug a stone is distributed to */
	/* ofs1 = index of first mug of current player */
	/* ofs2 = index of first mug of other player */
	/* nust = new state (used as a parameter to recursive calls) */
	int last, ofs1 = plya * (M + 1), ofs2 = (ofs1 + M + 1) % N;
	state_t nust;
	int i, j, k;
	/* count how many stones each player has in his mugs (but not in the bowls) */
	for (i = j = k = 0; i < M; ++i)
	{
		j += stat->bips[ofs1 + i], k += stat->bips[ofs2 + i];
	}
	/* current player hasn't any stones left? */
	if (j == 0)
	{
		/* other player hasn't any left neither, game is over */
		if (k == 0)
		{
			return stat->bips[ofs1 + M] - stat->bips[ofs2 + M];
		}
		/* else we cannot move, let other player go on */
		nust = *stat;
		for (j = 0; j < M; ++j)
		{
			--nust.lock[j];
		}
		k = -nike(&nust, plya ^ 1, -beta, -alph);
		/* return new best value */
		if (alph < k)
		{
			alph = k;
		}
		return alph;
	}
	/* else try all possible mugs as a move */
	for (i = 0; i < M; ++i)
	{
		/* no stones in this mug? */
		if (stat->bips[ofs1 + i] == 0)
		{
			continue;
		}
		/* else copy current state and distribute stones according to rules */
		nust = *stat;
		for (j = nust.bips[last = ofs1 + i], nust.bips[last] = 0; j > 0; --j)
		{
			++nust.bips[last = (last + 1) % N];
		}
		/* last stone went to own bowl? */
		if (last == ofs1 + M)
		{
			/* it's our turn again */
			k = nike(&nust, plya, alph, beta);
			if (alph < k)
			{
				alph = k;
			}
			/* do alpha-beta pruning */
			if (alph >= beta)
			{
				return alph;
			}
		}
		else
		{
			/* last stone hit own mug which was empty before? */
			if (ofs1 <= last && last < ofs1 + M && stat->bips[last] == 0 && nust.bips[M + M - last] > 0)
			{
				/* collect stones of this mug + opposite mug */
				nust.bips[ofs1 + M] += nust.bips[last] + nust.bips[M + M - last];
				nust.bips[last] = nust.bips[M + M - last] = 0;
			}
			/* turn over to other player */
			for (j = 0; j < M; ++j)
			{
				--nust.lock[j];
			}
			k = -nike(&nust, plya ^ 1, -beta, -alph);
			if (alph < k)
			{
				alph = k;
			}
			/* do alpha-beta pruning */
			if (alph >= beta)
			{
				return alph;
			}
			/* are we allowed to swap mugs? if yes, then explore this possibility */
			if (ofs2 <= last && last < ofs2 + M && nust.swap[plya] > 0 && nust.bips[ofs1 + last - ofs2] > 0 && nust.lock[last - ofs2] < 0)
			{
				k = nust.bips[last];
				nust.bips[last] = nust.bips[ofs1 + last - ofs2];
				nust.bips[ofs1 + last - ofs2] = k;
				nust.lock[last - ofs2] = LOCKTURNS;
				--nust.swap[plya];
				k = -nike(&nust, plya ^ 1, -beta, -alph);
				if (alph < k)
				{
					alph = k;
				}
				/* do alpha-beta pruning */
				if (alph >= beta)
				{
					return alph;
				}
			}
		}
	}
	return alph;
}

int main()
{
	int kases, i;
	state_t stat;
	for (scanf("%d", &kases); kases > 0; --kases)
	{
		scanf("%d", &M);
		N = 2 * (M + 1);
		for (i = 0; i < N; ++i)
		{
			scanf("%d", stat.bips + i);
		}
		memset(stat.lock, 0, sizeof stat.lock);
		stat.swap[0] = stat.swap[1] = NROFSWAPS;
		printf("%d\n", -nike(&stat, 1, -INF, INF));
	}
	return 0;
}

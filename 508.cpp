#include <bits/stdc++.h>

using namespace std;

//#define LOCAL
//#define TESTING
#define maxn 1005

char c[maxn], m[maxn][15], word[maxn][15], mword[maxn][100], mlen[maxn], code[maxn][100], clen[maxn];
int result;

int check(char *codes, int len, int wordn, int change)
{
	int finded = 0;
	for (int i = 0; i < wordn; i++)
	{
		if ((len == mlen[i] - change) || (len == mlen[i] + change))
		{
			int lim;
			bool eq = true;
			if (len > mlen[i])
			{
				lim = mlen[i];
			}
			else
			{
				lim = len;
			}
			for (int j = 0; j < lim; j++)
			{
				if (codes[j] != mword[i][j])
				{
					eq = false;
					break;
				}
			}
			if (eq)
			{
				if (!finded)
				{
					result = i;
				}
				finded++;
			}
		}
	}
	return finded;
}

int main()
{
#ifdef LOCAL
	freopen("xt4-6.in", "r", stdin);
//freopen("xt4-6.out","w",stdout);
#endif
	//è¯»å¥åä¸ªå­ç¬¦ç¼ç 
	char temp, tempc;
	int cn = 0, cm, ind = 0;
	memset(c, 0, sizeof(c));
	memset(m, 0, sizeof(m));
	for (;;)
	{
		char temps[maxn];
		scanf("%s", temps);
		if (temps[0] == '*')
		{
			break;
		}
		for (int i = 0; i < strlen(temps); i++)
		{
			if (isalpha(temps[i]) || isdigit(temps[i]))
			{
				c[cn] = temps[i];
				cn++;
				cm = 0;
			}
			else if (temps[i] == '.' || temps[i] == '-')
			{
				m[cn - 1][cm] = temps[i];
				cm++;
			}
		}
	}
	//è¯»å¥åä¸ªå­ç¬¦ç¼ç ç»æ
	//è¯»å¥è¯å¸
	int wordn = 0, wcn = 0, mwn = 0, maxmlen = 0;
	bool firstc = true;
	memset(word, 0, sizeof(word));
	memset(mword, 0, sizeof(mword));
	memset(mlen, 0, sizeof(mlen));
	for (;;)
	{
		char temps[maxn];
		scanf("%s", temps);
		if (temps[0] == '*')
		{
			break;
		}
		for (int i = 0; i < strlen(temps); i++)
		{
			if (isalpha(temps[i]) || isdigit(temps[i]))
			{
				word[wordn][wcn] = temps[i];
				wcn++;
				for (int j = 0; j < strlen(c); j++)
				{
					if (temps[i] == c[j])
					{
						for (int k = 0; k < strlen(m[j]); k++)
						{
							mword[wordn][mwn] = m[j][k];
							mwn++;
						}
						break;
					}
				}
			}
		}
		mlen[wordn] = mwn;
		wordn++;
		wcn = 0;
		if (maxmlen < mwn)
		{
			maxmlen = mwn;
		}
		mwn = 0;
	}
	//è¯»å¥è¯å¸ç»æ
	//è¯»å¥å¾è§£ç¼ç å¹¶è¾åºå¯¹åºç»æ
	int coden = 0, cnn = 0;
	firstc = true;
	bool firstoutput = true;
	memset(code, 0, sizeof(code));
	memset(clen, 0, sizeof(clen));
	for (;;)
	{
		char temps[maxn];
		scanf("%s", temps);
		if (temps[0] == '*')
		{
			break;
		}
		for (int i = 0; i < strlen(temps); i++)
		{
			if (temps[i] == '.' || temps[i] == '-')
			{
				code[coden][cnn] = temps[i];
				cnn++;
			}
		}
		//è¾åºcode[coden]å¯¹åºçword[]
		int rtype;
		rtype = check(code[coden], cnn, wordn, 0);
		if (rtype == 1)
		{
			printf("%s\n", word[result]);
		}
		else if (rtype > 1)
		{
			printf("%s!\n", word[result]);
		}
		else
		{
			for (int i = 1; i < maxmlen; i++)
			{
				rtype = check(code[coden], cnn, wordn, i);
				if (rtype)
				{
					break;
				}
			}
			printf("%s?\n", word[result]);
		}
		result = -2;
		//è¾åºç»æ
		coden++;
		firstoutput = false;
		clen[coden] = cnn;
		cnn = 0;
	}
	//è¯»å¥å¾è§£ç¼ç å¹¶è¾åºå¯¹åºç»æç»æ
	return 0;
}

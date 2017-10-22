#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

static char twos[65536][7];
static char threes[65536][7];
static char fours[65536][7];
static char fives[65536][7];

static int isword(const char *word)
{
	int i, n = strlen(word);
	for (i = 0; i < n; i++)
	{
		if (!isalpha(word[i]))
		{
			return 0;
		}
	}
	return 1;
}
static void uniq_insert(char buf[][7], char *cptr)
{
	int i = 0, j;
	char buffer[BUFSIZ];
	(void)strcpy(buffer, cptr);
	for (j = 0; j < 7 && buffer[j] != 0; j++)
	{
		buffer[j] = tolower(buffer[j]);
	}
	while (buf[i][0] != 0)
	{
		if (strcmp(buf[i], buffer) == 0)
		{
			return;
		}
		i++;
	}
	(void)strcpy(buf[i], buffer);
}
static void to_try(char first[][7], char second[][7], char *crypted)
{
	int i, j, n, arr[] = {0, 2, 4, 8};
	char buffer[BUFSIZ], salt[BUFSIZ];
	salt[0] = crypted[0];
	salt[1] = crypted[1];
	salt[2] = 0;
	for (i = 0; first[i][0] != 0; i++)
	{
		for (j = 0; second[j][0] != 0; j++)
		{
			for (n = 0; n < 4; n++)
			{
				sprintf(buffer, "%s%d%s", first[i], arr[n], second[j]);
				if (strcmp(crypt(buffer, salt), crypted) == 0)
				{
					printf("%s\n", buffer);
					exit(0);
				}
			}
		}
	}
}

int main()
{
	char crypted[BUFSIZ], *cptr, buffer[BUFSIZ], temp[BUFSIZ];
	const char *sep = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\n\t";
	bzero(twos, sizeof(twos));
	bzero(threes, sizeof(threes));
	bzero(fours, sizeof(fours));
	bzero(fives, sizeof(fives));
	fgets(temp, BUFSIZ, stdin);
	sscanf(temp, "%s", crypted);
	while (fgets(buffer, BUFSIZ, stdin) != NULL)
	{
		cptr = strtok(buffer, sep);
		while (cptr != NULL)
		{
			if (isword(cptr))
			{
				switch (strlen(cptr))
				{
				case 2:
					uniq_insert(twos, cptr);
					break;
				case 3:
					uniq_insert(threes, cptr);
					break;
				case 4:
					uniq_insert(fours, cptr);
					break;
				case 5:
					uniq_insert(fives, cptr);
					break;
				}
			}
			cptr = strtok(NULL, sep);
		}
	}
	to_try(twos, threes, crypted);
	to_try(twos, fours, crypted);
	to_try(twos, fives, crypted);
	to_try(threes, twos, crypted);
	to_try(threes, threes, crypted);
	to_try(fours, twos, crypted);
	to_try(fours, threes, crypted);
	to_try(fives, twos, crypted);
	to_try(threes, fours, crypted);
	return 0;
}

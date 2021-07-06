#include <bits/stdc++.h>

using namespace std;

int cin_, lahead;
int fpeek(FILE *stream)
{
	int c;
	c = fgetc(stream);
	ungetc(c, stream);
	return c;
}

int main()
{
	while ((cin_ = fgetc(stdin)) != EOF)
	{
		lahead = fpeek(stdin);
		if (cin_ == '\\')
		{
			if (lahead == 'b' || lahead == 'i')
			{
				cin_ = fgetc(stdin);
			}
			else if (lahead == '*')
			{
				cin_ = fgetc(stdin);
				while ((cin_ = fgetc(stdin)) != EOF &&
							 (cin_ != '\\' || (cin_ == '\\' && fpeek(stdin) != '*')))
				{
					fputc(cin_, stdout);
				}
				if (fpeek(stdin) == '*')
				{
					cin_ = fgetc(stdin);
				}
			}
			else if (lahead == 's')
			{
				cin_ = fgetc(stdin);
				while ((cin_ = fgetc(stdin)) != EOF && isdigit(cin_));
				if (cin_ != EOF && cin_ != '.')
				{
					ungetc(cin_, stdin);
				}
				while ((cin_ = fgetc(stdin)) != EOF && isdigit(cin_));
				if (cin_ != EOF)
				{
					ungetc(cin_, stdin);
				}
			}
			else if (lahead != EOF)
			{
				cin_ = fgetc(stdin);
				fputc(cin_, stdout);
			}
		}
		else
		{
			fputc(cin_, stdout);
		}
	}
	return 0;
}

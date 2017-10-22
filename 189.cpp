#include <bits/stdc++.h>

using namespace std;

int main()
{
	int result = 0, ch = getchar();
	while (1)
	{
		if (ch == EOF)
		{
			break;
		}
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' ||
				ch == ';' || ch == '.' || ch == ')' || ch == ']' || ch == ',')
		{
			ch = getchar();
			continue;
		}
		if (ch == '{')
		{
			do
			{
				ch = getchar();
			} while (ch != '}');
			ch = getchar();
			continue;
		}
		if (ch == '(')
		{
			ch = getchar();
			if (ch != '*')
			{
				result++;//operator (
				continue;
			}
			char prev = getchar();
			ch = getchar();
			while (!(prev == '*' && ch == ')'))
			{
				prev = ch;
				ch = getchar();
			}
			ch = getchar();
			continue;
		}
		if (ch == '\'')//string..
		{
			result++;
			int state = 0;
			while (1)
			{
				ch = getchar();
				if (state == 0)
				{
					if (ch == '\'')
					{
						state = 1;
					}
				}
				else
				{
					if (ch == '\'')
					{
						state = 0;
					}
					else
					{
						break;
					}
				}
			}
			continue;
			/*
			        int prev=getchar();
			        ch=getchar();
			    if (prev=='\'') continue; //empty string
			        while (1)
			            {
			            if (prev=='\'' && ch=='\'')
			                ch=0;
			            else if (prev=='\'' && ch!='\'')
			                break;
			            prev=ch;
			            ch=getchar();
			            }
			        continue;
			*/
			//        printf("<<string>>\n");
		}
		if (ch == '_' || isalpha(ch))
		{
			//var,ident
			result++;
			//        printf("<<id>>\n");
			while (ch == '_' || isalpha(ch) || isdigit(ch))
			{
				ch = getchar();
			}
		}
		else if (isdigit(ch))
		{
			//dec const..
			result++;
			//        printf("<<dec const>>\n");
			while (isdigit(ch))
			{
				ch = getchar();
			}
			/*
			        if (ch=='.') ch=getchar();
			        else continue;
			        while (isdigit(ch))
			            ch=getchar();
			*/
			if (ch == '.')
			{
				ch = getchar();
				while (isdigit(ch))
				{
					ch = getchar();
				}
			}
			if (ch == 'E' || ch == 'e')
			{
				ch = getchar();
			}
			else
			{
				continue;
			}
			if (ch == '+' || ch == '-')
			{
				ch = getchar();
			}
			//        else while (1); //debug..yes continue;
			while (isdigit(ch))
			{
				ch = getchar();
			}
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
						 ch == '=' || ch == '<' || ch == '>' || ch == '@' || ch == '^' ||
						 ch == '[')
		{
			char t = ch;
			result++;
			//        printf("<<operator>>\n");
			ch = getchar();
			switch (t)
			{
			case '<':
				if (ch == '=' || ch == '>')
				{
					ch = getchar();
				}
				break;
			case '>':
				if (ch == '=')
				{
					ch = getchar();
				}
				break;
			}
		}
		else if (ch == ':')
		{
			ch = getchar();
			if (ch == '=')
			{
				result++;
				//            printf("<<:=>>\n");
				ch = getchar();
			}
		}
		else if (ch == '$')
		{
			//hex const
			result++;
			//        printf("<<hex const>>\n");
			do
			{
				ch = getchar();
			} while (isxdigit(ch));
		}
		else if (ch == '~')
		{
			ch = getchar();
			if (ch == '~')
			{
				char name[80];
				gets(name);
				printf("Program by %s contains %d units.\n", name, result);
				result = 0;
				ch = getchar();
			}
		}
	}
	return 0;
}

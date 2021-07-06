#include <bits/stdc++.h>

using namespace std;

/*   @JUDGE_ID:   2905EH   10467   C++  "carfull output!!" */
//2003/3/26 a_q10467.cpp
//#include <cassert>

#define GAP 5
#define ADDR(x, y) (((y) << 16) | (x))
#define GETY(y) ((y) >> 16)
#define GETX(x) ((x)&0xFFFF)

struct PictureStruct
{
	map<int, char> pos2char;
	int width;
	void set(int x, int y, char ch)
	{
		pos2char[ADDR(x, y)] = ch;
	}
	/*
	char get(int x,int y) const
	{
	  map<int,char>::const_iterator it=pos2char.find(y*65536+x);
	  if (it==pos2char.end()) return ' ';
	  return (*it).second;
	}
	*/
	int getFirstLineX() const
	{
		map<int, char>::const_iterator it = pos2char.begin();
		return GETX((*it).first);
	}
	void print() const
	{
		int y = 0, x = -1;
		map<int, char>::const_iterator it;
		for (it = pos2char.begin(); it != pos2char.end(); ++it)
		{
			int yy = GETY((*it).first);
			int xx = GETX((*it).first);
			if (y < yy)
			{
				x = -1;
				putchar('\n');
			}
			for (int k = xx - x - 1; --k >= 0;)
			{
				putchar(' ');
			}
			putchar((*it).second);
			y = yy;
			x = xx;
		}
		putchar('\n');
	}
	void paint(int x, int y, const PictureStruct &pic)
	{
		map<int, char>::const_iterator it;
		for (it = pic.pos2char.begin(); it != pic.pos2char.end(); ++it)
		{
			int yy = GETY((*it).first);
			int xx = GETX((*it).first);
			pos2char[ADDR((x + xx), (y + yy))] = (*it).second;
		}
	}
};

char line[256];

PictureStruct parseExpr(int a, int b);
PictureStruct parseTerm(int a, int b);
PictureStruct parseFactor(int a, int b);

PictureStruct parseExpr(int a, int b)
{
	PictureStruct ret;
	int depth = 0;
	for (int i = b; --i >= a;)
	{
		if (line[i] == ')')
		{
			depth++;
		}
		else if (line[i] == '(')
		{
			depth--;
		}
		else if (depth == 0 && (line[i] == '+' || line[i] == '-'))
		{
			PictureStruct left = parseExpr(a, i);
			PictureStruct right = parseTerm(i + 1, b);
			ret.width = left.width + right.width + GAP;
			ret.paint(0, 2, left);
			ret.paint(left.width + GAP, 2, right);
			int x1 = 0 + left.getFirstLineX();
			int x2 = left.width + GAP + right.getFirstLineX();
			for (int i = x1; i <= x2; i++)
			{
				ret.set(i, 1, '=');
			}
			ret.set(left.width + GAP / 2, 0, 'E');
			ret.set(left.width + GAP / 2, 1, '|');
			ret.set(left.width + GAP / 2, 2, line[i]);
			return ret;
		}
	}
	PictureStruct c = parseTerm(a, b);
	ret.width = c.width;
	ret.paint(0, 2, c);
	int xx = c.getFirstLineX();
	ret.set(xx, 0, 'E');
	ret.set(xx, 1, '|');
	return ret;
}

PictureStruct parseTerm(int a, int b)
{
	PictureStruct ret;
	int depth = 0;
	for (int i = b; --i >= a;)
	{
		if (line[i] == ')')
		{
			depth++;
		}
		else if (line[i] == '(')
		{
			depth--;
		}
		else if (depth == 0 && (line[i] == '*' || line[i] == '/'))
		{
			PictureStruct left = parseTerm(a, i);
			PictureStruct right = parseFactor(i + 1, b);
			ret.width = left.width + right.width + GAP;
			ret.paint(0, 2, left);
			ret.paint(left.width + GAP, 2, right);
			int x1 = 0 + left.getFirstLineX();
			int x2 = left.width + GAP + right.getFirstLineX();
			for (int i = x1; i <= x2; i++)
			{
				ret.set(i, 1, '=');
			}
			ret.set(left.width + GAP / 2, 0, 'T');
			ret.set(left.width + GAP / 2, 1, '|');
			ret.set(left.width + GAP / 2, 2, line[i]);
			return ret;
		}
	}
	PictureStruct c = parseFactor(a, b);
	ret.width = c.width;
	ret.paint(0, 2, c);
	int xx = c.getFirstLineX();
	ret.set(xx, 0, 'T');
	ret.set(xx, 1, '|');
	return ret;
}

PictureStruct parseFactor(int a, int b)
{
	PictureStruct ret;
	if (line[a] == '(' && line[b - 1] == ')')
	{
		PictureStruct c = parseExpr(a + 1, b - 1);
		ret.width = c.width + GAP + 1;
		ret.paint((GAP + 1) / 2, 2, c);
		int xx = c.getFirstLineX() + (GAP + 1) / 2;
		for (int k = ret.width; --k >= 0;)
		{
			ret.set(k, 1, '=');
		}
		ret.set(xx, 0, 'F');
		ret.set(xx, 1, '|');
		ret.set(0, 2, '(');
		ret.set(ret.width - 1, 2, ')');
		return ret;
	}
	//assert(b==a+1 && line[a]=='i');
	ret.width = 1;
	ret.set(0, 0, 'F');
	ret.set(0, 1, '|');
	ret.set(0, 2, 'i');
	return ret;
}

int main()
{
	int c = 0;
	while (gets(line))
	{
		//assert(strspn(line,"+-*/()i")==strlen(line)); //yes
		if (c++)
		{
			putchar('\n');
		}
		parseExpr(0, strlen(line)).print();
	}
	return 0;
}
/*@END_OF_SOURCE_CODE*/

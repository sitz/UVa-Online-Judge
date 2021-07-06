#include <bits/stdc++.h>

using namespace std;

#define K 1024

char note[20 * K], dic[100 * K], dic1[100 * K], *s[100 * K], str[100];
int len;

int compare(const void *a, const void *b)
{
	return strcmp(*(char **)a, *(char **)b);
}

int complen(char *a, char *b)
{
	for (int l = 0;; l++)
		if (!a[l] || !b[l] || a[l] != b[l])
		{
			return l;
		}
}

// binary search
char *BinarySearch(int left, int right, char *ss)
{
	int mid = (left + right) / 2, ans, ans1;
	while (left <= right)
	{
		if (strcmp(s[mid], ss) >= 0)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		mid = (left + right) / 2;
	}
	if (ans != 0)
	{
		ans1 = ans - 1;
	}
	char *p1 = s[ans], *p2 = s[ans1];
	return complen(p1, ss) > complen(p2, ss) ? p1 : p2;
}

int main()
{
	gets(note);
	int nl = strlen(note);
	char *s1 = dic, *s2 = dic1;
	dic[0] = dic1[0] = 0;
	while (gets(str) != NULL)
	{
		strcat(str, "$");
		int l = strlen(str);
		strcat(s1, str);
		s1 += l;
		for (int i = 0; i < l; i++)
		{
			str[i] = tolower(str[i]);
		}
		strcat(s2, str);
		s2 += l;
	}
	len = strlen(dic1);
	for (int i = 0; i < len; i++)
	{
		s[i] = dic1 + i;
	}
	qsort(s, len, sizeof(char *), compare);
	vector<string> c;
	for (int i = 0, l; i < nl; i += l)
	{
		if (note[i] == ' ')
		{
			l = 1;
			continue;
		}
		char *t = BinarySearch(0, len - 1, note + i), *tt = str;
		l = complen(note + i, t);
		int k = t - dic1;
		for (int i = 0; i < l; i++)
		{
			str[i] = *(dic + k + i);
		}
		while (*tt == ' ')
		{
			tt++;
		}
		while (str[l - 1] == ' ')
		{
			l--;
		}
		str[l] = '\0';
		string temp(tt);
		c.push_back(temp);
	}
	printf("%d\n", c.size());
	for (int i = 0; i < c.size(); i++)
	{
		puts(c[i].c_str());
	}
	return 0;
}

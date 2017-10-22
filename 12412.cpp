#include <bits/stdc++.h>

using namespace std;

#define pi acos(-1)
#define INF 0x7fffffff
#define clr(x) memset(x, 0, sizeof(x));
#define clrto(x, siz, y)            \
	for (int xx = 0; xx <= siz; xx++) \
		x[xx] = y;
#define clrset(x, siz)              \
	for (int xx = 0; xx <= siz; xx++) \
		x[xx] = xx;
#define clrvec(x, siz)             \
	for (int xx = 0; x <= siz; xx++) \
		x[xx].clear();
#define myprogram By_135678942570
#define clrcpy(x, siz, y)          \
	for (int xx = 0; xx < siz; xx++) \
		x[xx] = y[xx];

map<string, int> mp1;
double ave[5];
string sub[5] = {"Chinese", "Mathematics", "English", "Programming"};
int stucnt;

struct Class
{
	int pass[5], passsub[5], sum[5], cnt;
} CLASS[22];
struct node
{
	string num;
	string name;
	int cid, C, M, E, P, sum, flag, cntpass;
} STU[201111];
void printmenu()
{
	printf("Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
}

int main()
{
	while (1)
	{
		printmenu();
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		else if (n == 4)
			puts("Showing the ranklist hurts students' self-esteem. Don't do that.");
		else if (n == 1)
			while (1)
			{
				puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
				int b;
				string a, c;
				int e, f, g, h;
				cin >> a;
				if (a[0] == '0' && a.size() == 1)
					break;
				scanf("%d", &b);
				cin >> c;
				scanf("%d%d%d%d", &e, &f, &g, &h);
				node temp;
				temp.cntpass = (e >= 60) + (f >= 60) + (g >= 60) + (h >= 60);
				if (mp1[a] != 0)
				{
					puts("Duplicated SID.");
					continue;
				}
				mp1[a] = stucnt + 1;
				temp.num = a;
				temp.cid = b;
				temp.name = c;
				temp.C = e;
				temp.M = f;
				temp.E = g;
				temp.P = h;
				temp.sum = e + f + g + h;
				temp.flag = 1;
				STU[++stucnt] = temp;
				CLASS[b].cnt++;
				CLASS[b].sum[0] += e;
				CLASS[b].sum[1] += f;
				CLASS[b].sum[2] += g;
				CLASS[b].sum[3] += h;
				CLASS[b].passsub[0] += e >= 60;
				CLASS[b].passsub[1] += f >= 60;
				CLASS[b].passsub[2] += g >= 60;
				CLASS[b].passsub[3] += h >= 60;
				CLASS[b].pass[temp.cntpass]++;
				b = 0;
				CLASS[b].cnt++;
				CLASS[b].sum[0] += e;
				CLASS[b].sum[1] += f;
				CLASS[b].sum[2] += g;
				CLASS[b].sum[3] += h;
				CLASS[b].passsub[0] += e >= 60;
				CLASS[b].passsub[1] += f >= 60;
				CLASS[b].passsub[2] += g >= 60;
				CLASS[b].passsub[3] += h >= 60;
				CLASS[b].pass[temp.cntpass]++;
			}
		else if (n == 2)
			while (1)
			{
				puts("Please enter SID or name. Enter 0 to finish.");
				string c;
				cin >> c;
				if (c[0] == '0' && c.size() == 1)
					break;
				int cnt = 0;
				if (isalpha(c[0]))
				{
					for (int i = 1; i <= stucnt; i++)
					{
						if (STU[i].flag && STU[i].name == c)
						{
							cnt++;
							STU[i].flag = 0;
							int x = STU[i].cid;
							mp1[STU[i].num] = 0;
							CLASS[x].cnt--;
							CLASS[x].pass[STU[i].cntpass]--;
							CLASS[x].sum[0] -= STU[i].C;
							CLASS[x].sum[1] -= STU[i].M;
							CLASS[x].sum[2] -= STU[i].E;
							CLASS[x].sum[3] -= STU[i].P;
							CLASS[x].passsub[0] -= STU[i].C >= 60;
							CLASS[x].passsub[1] -= STU[i].M >= 60;
							CLASS[x].passsub[2] -= STU[i].E >= 60;
							CLASS[x].passsub[3] -= STU[i].P >= 60;
							x = 0;
							CLASS[x].cnt--;
							CLASS[x].pass[STU[i].cntpass]--;
							CLASS[x].sum[0] -= STU[i].C;
							CLASS[x].sum[1] -= STU[i].M;
							CLASS[x].sum[2] -= STU[i].E;
							CLASS[x].sum[3] -= STU[i].P;
							CLASS[x].passsub[0] -= STU[i].C >= 60;
							CLASS[x].passsub[1] -= STU[i].M >= 60;
							CLASS[x].passsub[2] -= STU[i].E >= 60;
							CLASS[x].passsub[3] -= STU[i].P >= 60;
						}
					}
				}
				else
				{
					int i = mp1[c];
					if (i && STU[i].flag)
					{
						cnt++;
						STU[mp1[c]].flag = 0;
						mp1[c] = 0;
						int x = STU[i].cid;
						CLASS[x].cnt--;
						CLASS[x].pass[STU[i].cntpass]--;
						CLASS[x].sum[0] -= STU[i].C;
						CLASS[x].sum[1] -= STU[i].M;
						CLASS[x].sum[2] -= STU[i].E;
						CLASS[x].sum[3] -= STU[i].P;
						CLASS[x].passsub[0] -= STU[i].C >= 60;
						CLASS[x].passsub[1] -= STU[i].M >= 60;
						CLASS[x].passsub[2] -= STU[i].E >= 60;
						CLASS[x].passsub[3] -= STU[i].P >= 60;
						x = 0;
						CLASS[x].cnt--;
						CLASS[x].pass[STU[i].cntpass]--;
						CLASS[x].sum[0] -= STU[i].C;
						CLASS[x].sum[1] -= STU[i].M;
						CLASS[x].sum[2] -= STU[i].E;
						CLASS[x].sum[3] -= STU[i].P;
						CLASS[x].passsub[0] -= STU[i].C >= 60;
						CLASS[x].passsub[1] -= STU[i].M >= 60;
						CLASS[x].passsub[2] -= STU[i].E >= 60;
						CLASS[x].passsub[3] -= STU[i].P >= 60;
					}
				}
				printf("%d student(s) removed.\n", cnt);
			}
		else if (n == 3)
			while (1)
			{
				puts("Please enter SID or name. Enter 0 to finish.");
				string c;
				cin >> c;
				if (c[0] == '0' && c.size() == 1)
					break;
				if (isalpha(c[0]))
				{
					for (int i = 1; i <= stucnt; i++)
					{
						if (STU[i].flag && STU[i].name == c)
						{
							int rank = 1;
							for (int j = 1; j <= stucnt; j++)
								if (STU[j].flag && STU[j].sum > STU[i].sum)
								{
									rank++;
								}
							printf("%d ", rank);
							cout << STU[i].num << " ";
							printf("%d ", STU[i].cid);
							cout << STU[i].name << " ";
							printf("%d %d %d %d %d %.2f\n", STU[i].C, STU[i].M, STU[i].E, STU[i].P, STU[i].sum, STU[i].sum / 4.0 + 1e-5);
						}
					}
				}
				else
				{
					int i = mp1[c];
					if (i && STU[i].flag)
					{
						int rank = 1;
						for (int j = 1; j <= stucnt; j++)
							if (STU[j].flag && STU[j].sum > STU[i].sum)
								rank++;
						printf("%d ", rank);
						cout << STU[i].num << " ";
						printf("%d ", STU[i].cid);
						cout << STU[i].name << " ";
						printf("%d %d %d %d %d %.2f\n", STU[i].C, STU[i].M, STU[i].E, STU[i].P, STU[i].sum, STU[i].sum / 4.0 + 1e-5);
					}
				}
			}
		else if (n == 5)
		{
			puts("Please enter class ID, 0 for the whole statistics.");
			int q;
			scanf("%d", &q);
			for (int i = 0; i < 4; i++)
			{
				cout << sub[i] << endl;
				printf("Average Score: %.2f\n", (double)CLASS[q].sum[i] / CLASS[q].cnt + 1e-5);
				printf("Number of passed students: %d\n", CLASS[q].passsub[i]);
				printf("Number of failed students: %d\n", CLASS[q].cnt - CLASS[q].passsub[i]);
				puts("");
			}
			puts("Overall:");
			int cnt = 0;
			printf("Number of students who passed all subjects: %d\n", CLASS[q].pass[4]);
			cnt += CLASS[q].pass[4];
			for (int i = 3; i >= 1; i--)
			{
				cnt += CLASS[q].pass[i];
				printf("Number of students who passed %d or more subjects: %d\n", i, cnt);
			}
			printf("Number of students who failed all subjects: %d\n", CLASS[q].pass[0]);
			puts("");
		}
	}
	return 0;
}

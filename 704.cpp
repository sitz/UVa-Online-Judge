#include <bits/stdc++.h>

using namespace std;

map<string, bool> mark;
map<string, string> mark1;
string goal = "034305650121078709t90121";
struct node
{
	int step;		 //记录步数
	string path; //记录路径
	string state;//记录状态
	node()
	{
		step = 0;
	};
};
int ans = 100;//存储答案
string sans;
int judge(node a)//判断节点
{
	if (a.state == goal)//匹配成功
	{
		ans = a.path.size();
		sans = a.path;
		return 1;
	}
	else if (mark1[a.state] != "")//匹配成功
	{
		int t = a.path.size() + mark1[a.state].size();
		if (t < ans)
		{
			ans = t;
			sans = a.path;
			for (int i = mark1[a.state].size() - 1; i >= 0; i--)
			{
				sans += mark1[a.state][i];
			}
		}
	}
	else
	{
		return 0;
	}
	return 2;
}
int main()
{
	int cases, x, i;
	char c, d;
	cin >> cases;
	while (cases--)
	{
		ans = 100;
		mark.clear(), mark1.clear();
		string str;
		for (i = 0; i < 24; i++)
		{
			cin >> x;
			if (x == 10)
			{
				str = str + 't';
			}
			else
			{
				str = str + char(x + '0');
			}
		}
		node tp, ts;
		tp.state = str;
		mark[str] = true;
		if (judge(tp))
		{
			cout << "PUZZLE ALREADY SOLVED" << endl;
			continue;
		}
		queue<node> q;
		q.push(tp);
		tp.state = goal;
		queue<node> dq;
		dq.push(tp);
		while (!dq.empty())//从目的状态向前搜索
		{
			tp = dq.front(), dq.pop();
			if (tp.step > 7)
			{
				break;
			}
			ts = tp;
			ts.path += '3';//左顺时针
			c = ts.state[10], d = ts.state[11];
			ts.state.erase(10, 2);
			ts.state.insert(0, 1, c), ts.state.insert(1, 1, d);
			str = ts.state.substr(9, 3);
			ts.state.replace(21, 3, str);
			ts.step++;
			if (ts.step <= 7 && mark1[ts.state] == "")//判重
			{
				mark1[ts.state] = ts.path;//记录路径
				dq.push(ts);
			}
			ts = tp;
			ts.path += '4';//右顺时针
			c = ts.state[12], d = ts.state[13];
			ts.state.append(1, c), ts.state.append(1, d);
			ts.state.erase(12, 2);
			str = ts.state.substr(21, 3);
			ts.state.replace(9, 3, str);
			ts.step++;
			if (ts.step <= 7 && mark1[ts.state] == "")
			{
				mark1[ts.state] = ts.path;
				dq.push(ts);
			}
			ts = tp;
			ts.path += '1';//左逆时针
			c = ts.state[0], d = ts.state[1];
			ts.state.insert(12, 1, c), ts.state.insert(13, 1, d);
			ts.state.erase(0, 2);
			str = ts.state.substr(9, 3);
			ts.state.replace(21, 3, str);
			ts.step++;
			if (ts.step <= 7 && mark1[ts.state] == "")
			{
				mark1[ts.state] = ts.path;
				dq.push(ts);
			}
			ts = tp;
			ts.path += '2';
			c = ts.state[22], d = ts.state[23];
			ts.state.erase(22, 2);
			ts.state.insert(12, 1, c), ts.state.insert(13, 1, d);
			str = ts.state.substr(21, 3);
			ts.state.replace(9, 3, str);
			ts.step++;
			if (ts.step <= 7 && mark1[ts.state] == "")
			{
				mark1[ts.state] = ts.path;
				dq.push(ts);
			}
		}
		int ok = 0;
		while (!q.empty())//正向搜索
		{
			tp = q.front(), q.pop();
			if (tp.step > 9)
			{
				break;
			}
			ts = tp;
			ts.path += '2';//右顺时针
			c = ts.state[12], d = ts.state[13];
			ts.state.append(1, c), ts.state.append(1, d);
			ts.state.erase(12, 2);
			str = ts.state.substr(21, 3);
			ts.state.replace(9, 3, str);
			ts.step++;
			if (ts.step <= 9 && !mark[ts.state])//判断
			{
				int rs = judge(ts);
				if (rs)
				{
					ok = 1;
					if (rs == 1)
					{
						break;
					}
				}
				mark[ts.state] = true;
				q.push(ts);
			}
			ts = tp;
			ts.path += '1';//左顺时针
			c = ts.state[10], d = ts.state[11];
			ts.state.erase(10, 2);
			ts.state.insert(0, 1, c), ts.state.insert(1, 1, d);
			str = ts.state.substr(9, 3);
			ts.state.replace(21, 3, str);
			ts.step++;
			if (ts.step <= 9 && !mark[ts.state])
			{
				int rs = judge(ts);
				if (rs)
				{
					ok = 1;
					if (rs == 1)
					{
						break;
					}
				}
				mark[ts.state] = true;
				q.push(ts);
			}
			ts = tp;
			ts.path += '4';
			c = ts.state[22], d = ts.state[23];
			ts.state.erase(22, 2);
			ts.state.insert(12, 1, c), ts.state.insert(13, 1, d);
			str = ts.state.substr(21, 3);
			ts.state.replace(9, 3, str);
			ts.step++;
			if (ts.step <= 9 && !mark[ts.state])
			{
				int rs = judge(ts);
				if (rs)
				{
					ok = 1;
					if (rs == 1)
					{
						break;
					}
				}
				mark[ts.state] = true;
				q.push(ts);
			}
			ts = tp;
			ts.path += '3';//左逆时针
			c = ts.state[0], d = ts.state[1];
			ts.state.insert(12, 1, c), ts.state.insert(13, 1, d);
			ts.state.erase(0, 2);
			str = ts.state.substr(9, 3);
			ts.state.replace(21, 3, str);
			ts.step++;
			if (ts.step <= 9 && !mark[ts.state])
			{
				int rs = judge(ts);
				if (rs)
				{
					ok = 1;
					if (rs == 1)
					{
						break;
					}
				}
				mark[ts.state] = true;
				q.push(ts);
			}
		}
		if (!ok)
		{
			cout << "NO SOLUTION WAS FOUND IN 16 STEPS" << endl;
		}
		else
		{
			cout << sans << endl;
		}
	}
	return 0;
}
/*
12
0 3 4 5 0 3 6 5 0 1 2 1 0 7 8 7 0 9 10 9 0 1 2 1
0 9 4 3 0 5 6 5 0 1 2 1 0 7 8 7 0 9 10 3 0 1 2 1
2 1 0 3 4 3 0 5 6 9 0 5 0 1 0 7 8 7 0 9 10 9 0 5
0 3 4 5 0 3 6 5 0 1 2 1 0 7 8 7 0 9 10 9 0 1 2 1
0 9 4 3 0 5 6 5 0 1 2 1 0 7 8 7 0 9 10 3 0 1 2 1
2 1 0 3 4 3 0 5 6 9 0 5 0 1 0 7 8 7 0 9 10 9 0 5
0 3 4 5 0 3 6 5 0 1 2 1 0 7 8 7 0 9 10 9 0 1 2 1
0 9 4 3 0 5 6 5 0 1 2 1 0 7 8 7 0 9 10 3 0 1 2 1
2 1 0 3 4 3 0 5 6 9 0 5 0 1 0 7 8 7 0 9 10 9 0 5
*/

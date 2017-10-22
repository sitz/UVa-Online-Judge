#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************************
 * 12100
 *
 *
 * Classification:
 *
 * Author:
 *   Javier Gonzalez Nova <javigonzalez@udec.cl>
 *
 * Description:
 *
 *
 */

typedef struct
{
	int value;
	bool mine;
} Job;

vector<int> Jobs_value;

bool isHigher(int num)
{
	int index;
	for (int i = 0; i < Jobs_value.size(); i++)
	{
		if (num < Jobs_value[i])
		{
			return false;
		}
		if (num == Jobs_value[i])
		{
			index = i;
		}
	}
	Jobs_value[index] = 0;
	return true;
}

int main()
{
	int c;								 /*Cantidad de casos*/
	int num_jobs, pos_job; /*Numero de trabajos, posicion de mi trabajo*/
	cin >> c;
	while (c--)
	{
		cin >> num_jobs >> pos_job;
		queue<Job> Jobs_queue;
		Jobs_value.clear();
		for (int i = 0; i < num_jobs; i++)
		{
			int tmp;
			cin >> tmp;
			Job t;
			if (i == pos_job)
			{
				t.mine = true;
			}
			else
			{
				t.mine = false;
			}
			t.value = tmp;
			Jobs_queue.push(t);
			Jobs_value.push_back(tmp);
		}
		int minutes = 0;
		while (1)
		{
			Job v = Jobs_queue.front();
			Jobs_queue.pop();
			if (isHigher(v.value))
			{
				if (v.mine)
				{
					cout << minutes + 1 << endl;
					break;
				}
				else
				{
					minutes++;
				}
			}
			else
			{
				Jobs_queue.push(v);
			}
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int c = 1;
	int num_soldier;
	vector<int> Brief;
	vector<int> Job;
	while (cin >> num_soldier && num_soldier)
	{
		int B, J;
		Brief.clear();
		Job.clear();
		for (int i = 0; i < num_soldier; i++)
		{
			cin >> B >> J;
			Brief.push_back(B);
			Job.push_back(J);
		}
		int sum_until_i = 0;
		int sum_until_j = 0;
		int result = 0;
		for (int i = 0; i < num_soldier; i++)
		{
			sum_until_i += Brief.at(i);
			sum_until_j = sum_until_i;
			for (int j = i + 1; j < num_soldier; j++)
			{
				sum_until_j += Brief.at(j);
				if (max(sum_until_i + Job.at(i), sum_until_j + Job.at(j)) >
						max(sum_until_i - Brief.at(i) + Brief.at(j) + Job.at(j),
								sum_until_j + Job.at(i)))
				{
					sum_until_i = sum_until_i - Brief.at(i) + Brief.at(j);
					int temp_B, temp_J;
					temp_B = Brief.at(j);
					temp_J = Job.at(j);
					Brief.at(j) = Brief.at(i);
					Job.at(j) = Job.at(i);
					Brief.at(i) = temp_B;
					Job.at(i) = temp_J;
				}
			}
			result = max(result, sum_until_i + Job.at(i));
		}
		cout << "Case " << c << ": " << result << endl;
		c++;
	}
	return (0);
}

#include <bits/stdc++.h>

using namespace std;

struct Predict
{
	int movie_;
	double score_;

	Predict(int movie, double score)
			: movie_(movie), score_(score)
	{
	}
};

bool cmp(const Predict &a, const Predict &b)
{
	return a.score_ > b.score_;
}

int main()
{
	int n, m, c;
	scanf("%d%d%d", &n, &m, &c);

	double mat_rating[52][202] = {}, mat_sim[202][202] = {};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			mat_rating[i][j] = -1.0f;
		}
	}

	double rating;
	int usr, movie;
	for (int i = 0; i < c; i++)
	{
		scanf("%d%d%lf", &usr, &movie, &rating);
		mat_rating[usr][movie] = rating;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j <= m; j++)
		{
			double rating_diff = 0.0f;
			for (int k = 1; k <= n; k++)
			{
				double rating_i = mat_rating[k][i];
				double rating_j = mat_rating[k][j];
				if ((rating_i > 0.0f) && (rating_j > 0.0f))
				{
					double diff = rating_i - rating_j;
					rating_diff = rating_diff + diff * diff;
				}
			}
			mat_sim[i][j] = 1.0f / (1.0f + rating_diff);
			mat_sim[j][i] = mat_sim[i][j];
		}
	}

	while (scanf("%d", &usr) == 1)
	{
		vector<Predict> predicts;
		for (int i = 1; i <= m; i++)
		{
			if (mat_rating[usr][i] < 0.0f)
			{
				bool is_similar = false;
				double numer = 0.0f, denom = 0.0f;
				for (int j = 1; j <= m; j++)
				{
					if (mat_rating[usr][j] < 0.0f)
					{
						continue;
					}
					is_similar = true;
					numer += (mat_sim[i][j] * mat_rating[usr][j]);
					denom += mat_sim[i][j];
				}

				// if denom == zero
				// means movie i is dis-similar to any movie watched
				// shd not recommend
				if (is_similar)
				{
					double score = numer / denom;
					predicts.push_back(Predict(i, score));
				}
			}
		}
		sort(predicts.begin(), predicts.end(), cmp);

		printf("Recommendations for user %d:\n", usr);
		for (unsigned int i = 0; i < predicts.size(); i++)
		{
			if (i > 9)
			{
				break;
			}
			printf("%d %.3lf\n", predicts[i].movie_, predicts[i].score_);
		}
		printf("\n");
	}

	return 0;
}

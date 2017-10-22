#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 29

typedef struct List { double x, y, p; } LIST;
LIST lst[1005];
double dp[1005], pre[1005];

double dist(double a, double b, double c, double d) {
  return hypot(a - c, b - d);
}

int main() {
  int N, n, i, j;
  while (~scanf(" %d", &N) && N) {
    memset(pre, 0, sizeof(pre));
    for (i = 0; i < 1005; i++) {
      dp[i] = 999999999.9;
    }
    for (n = 1; n <= N; n++) {
      scanf(" %lf %lf %lf", &lst[n].x, &lst[n].y, &lst[n].p);
      pre[n] = pre[n - 1] + lst[n].p;
    }
    N++;
    lst[N].x = 100.000;
    lst[N].y = 100.000;
    lst[N].p = 0.000;
    lst[0].x = 0.000;
    lst[0].y = 0.000;
    lst[0].p = 0.000;
    dp[1] = dist(0, 0, lst[1].x, lst[1].y) + 1;
    dp[0] = 0.000;
    for (i = 2; i <= N; i++) {
      for (j = i - 1; j >= 0; j--) {
        double tmp = dist(lst[i].x, lst[i].y, lst[j].x, lst[j].y);
        dp[i] = min(dp[i], dp[j] + tmp + pre[i - 1] - pre[j]);
      }
      dp[i] += 1.00000;
    }
    printf("%.3lf\n", dp[N]);
  }
  return 0;
}

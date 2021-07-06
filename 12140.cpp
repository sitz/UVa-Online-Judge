#include <bits/stdc++.h>

using namespace std;

double low, high, mid, eps = 1e-8, now_x, now_y;
int dp[1 << 19], n, k, cont[1 << 19], cnt;

struct point {
  double x, y;
};
point mon[20];

struct pp {
  int state, num;
  bool operator<(const pp &temp) const { return num > temp.num; }
};
pp lst[1000];

bool dfs(int state, int id, int now_v, int now_num) {
  int ns, i, j, s, p, q, least = now_v, tnum;
  if (dp[state] <= now_v) {
    return false;
  }
  dp[state] = now_v;
  if (now_v > k) {
    return false;
  }
  if (state == (1 << n) - 1 || now_v + n - now_num <= k) {
    return true;
  }
  ns = state;
  pp nlst[170];
  for (i = 0; i < cnt; i++) {
    nlst[i] = lst[i];
    nlst[i].num = cont[nlst[i].state | state] - cont[state];
  }
  sort(nlst, nlst + cnt);
  tnum = now_num;
  for (i = 0; i < cnt; i++) {
    tnum += max(1, nlst[i].num);
    least++;
    if (tnum >= n) {
      break;
    }
  }
  if (least > k) {
    return false;
  }
  for (i = 0; i < cnt; i++) {
    if (dfs(state | nlst[i].state, id, now_v + 1, now_num + nlst[i].num)) {
      return true;
    }
  }
  return false;
}

bool check(double r) {
  int i, j, s, p, q, ncnt;
  double dis;
  cnt = 0;
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      dis = sqrt((mon[i].x - mon[j].x) * (mon[i].x - mon[j].x) +
                 (mon[i].y - mon[j].y) * (mon[i].y - mon[j].y));
      if (dis > 2 * r) {
        continue;
      }
      double theta, alpha, fi;
      theta = atan2(mon[i].y - mon[j].y, mon[i].x - mon[j].x);
      alpha = acos(dis / (2.0 * r));
      for (s = 0; s < 2; s++) {
        if (s == 0) {
          fi = theta + alpha;
        } else {
          fi = theta - alpha;
        }
        now_x = mon[j].x + r * cos(fi);
        now_y = mon[j].y + r * sin(fi);
        lst[cnt].state = lst[cnt].num = 0;
        for (p = 0; p < n; p++) {
          dis = sqrt((mon[p].x - now_x) * (mon[p].x - now_x) +
                     (mon[p].y - now_y) * (mon[p].y - now_y));
          if (dis < r + 1e-7) {
            lst[cnt].state |= (1 << p);
            lst[cnt].num++;
          }
        }
        cnt++;
      }
    }
  sort(lst, lst + cnt);
  ncnt = 0;
  for (i = 0; i < cnt; i++) {
    for (j = 0; j < ncnt; j++) {
      if ((lst[i].state & lst[j].state) == lst[i].state) {
        break;
      }
    }
    if (j >= ncnt) {
      lst[ncnt++] = lst[i];
    }
  }
  cnt = ncnt;
  for (i = 0; i < (1 << n); i++) {
    dp[i] = 1000000000;
  }
  return dfs(0, 0, 0, 0);
}

int main() {
  int i, j, s, p, q, tst = 0, t;
  for (i = 0; i < (1 << 18); i++) {
    j = i;
    cont[i] = 0;
    while (j) {
      cont[i]++;
      j = ((j - 1) & j);
    }
  }
  scanf("%d", &t);
  while (t--) {
    tst++;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
      scanf("%lf%lf", &mon[i].x, &mon[i].y);
    }
    low = 0;
    high = 7500;
    while (low < high - eps) {
      mid = (low + high) / 2.0;
      if (check(mid)) {
        high = mid;
      } else {
        low = mid + eps;
      }
    }
    printf("Case %d: %.2f\n", tst, low);
  }
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point3 {
  int x, y, z;

  Point3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
  bool operator<(const Point3 &u) const {
    return x - u.x < 0 || (x - u.x == 0 && y - u.y < 0) ||
           (x - u.x == 0 && y - u.y == 0 && z - u.z < 0);
  }
  bool operator>(const Point3 &u) const { return u < (*this); }
  bool operator==(const Point3 &u) const {
    return !(u < (*this) || (*this) < u);
  }
  bool operator!=(const Point3 &u) const { return !((*this) == u); }
  bool operator<=(const Point3 &u) const { return *this < u || *this == u; }
  bool operator>=(const Point3 &u) const { return *this > u || *this == u; }
  Point3 operator+(const Point3 &u) const {
    return Point3(x + u.x, y + u.y, z + u.z);
  }
  Point3 operator-(const Point3 &u) const {
    return Point3(x - u.x, y - u.y, z - u.z);
  }
  Point3 operator*(const int u) const { return Point3(x * u, y * u, z * u); }
  Point3 operator/(const int u) const { return Point3(x / u, y / u, z / u); }

  void read() { scanf("%d%d%d", &x, &y, &z); }
};

typedef Point3 Vector3;
ll getDot(Vector3 a, Vector3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
Vector3 getCross(Vector3 a, Vector3 b) {
  return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                 a.x * b.y - a.y * b.x);
}
ll getPowerLength(Vector3 u) { return getDot(u, u); }

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

struct Rat {
  ll s, m;
  Rat(ll s = 0, ll m = 1) {
    ll d = gcd(s, m);
    s /= d, m /= d;
    if (m < 0)
      m = -m, s = -s;
    this->s = s;
    this->m = m;
  }

  Rat operator+(const Rat &u) const {
    ll d = gcd(m, u.m);
    return Rat(s * (u.m / d) + u.s * (m / d), m * (u.m / d));
  }
  Rat operator-(const Rat &u) const {
    ll d = gcd(m, u.m);
    return Rat(s * (u.m / d) - u.s * (m / d), m * (u.m / d));
  }
  Rat operator*(const Rat &u) const { return Rat(s * u.s, m * u.m); }
  // Rat operator * (const int& u) const { return Rat(s*u, m); }
  // Rat operator / (const Rat& u) const { return Rat(s*u.m, m*u.s); }
  // Rat operator / (const int& u) const { return Rat(s, m*u); }
  bool operator<(const Rat &u) const { return s * u.m < u.s * m; }
  bool operator>(const Rat &u) const { return u < (*this); }
  bool operator==(const Rat &u) const { return !(u < (*this) || (*this) < u); }
  bool operator!=(const Rat &u) const { return !((*this) == u); }
  bool operator<=(const Rat &u) const { return *this < u || *this == u; }
  bool operator>=(const Rat &u) const { return *this > u || *this == u; }
};

inline int dcmp(Rat u) {
  if (u.s == 0)
    return 0;
  else
    return u.s < 0 ? -1 : 1;
}

Rat getDistancePointToSegment(Point3 p, Point3 a, Point3 b) {
  if (a == b)
    return getPowerLength(p - a);
  Vector3 v1 = b - a, v2 = p - a, v3 = p - b;
  if (getDot(v1, v2) < 0)
    return getPowerLength(v2);
  else if (getDot(v1, v3) > 0)
    return getPowerLength(v3);
  else
    return Rat(getPowerLength(getCross(v1, v2)), getPowerLength(v1));
}

bool getDistanceLineToLine(Point3 p1, Vector3 u, Point3 p2, Vector3 v, Rat &s) {
  ll b = getDot(u, u) * getDot(v, v) - getDot(u, v) * getDot(u, v);
  if (b == 0)
    return false;
  ll a = getDot(u, v) * getDot(v, p1 - p2) - getDot(v, v) * getDot(u, p1 - p2);
  s = Rat(a, b);
  return true;
}

const ll inf = 0x3f3f3f3f;

int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    Point3 a, b, c, d;
    a.read(), b.read(), c.read(), d.read();

    Rat s, t, ans(inf);
    bool flag1 = getDistanceLineToLine(a, b - a, c, d - c, s);
    bool flag2 = getDistanceLineToLine(c, d - c, a, b - a, t);
    if (flag1 && flag2 && s.s > 0 && s.s < s.m && t.s > 0 && t.s < t.m) {
      Vector3 u = b - a, v = d - c;
      Rat x1 = Rat(a.x) + s * u.x, y1 = Rat(a.y) + s * u.y,
          z1 = Rat(a.z) + s * u.z;
      Rat x2 = Rat(c.x) + t * v.x, y2 = Rat(c.y) + t * v.y,
          z2 = Rat(c.z) + t * v.z;
      ans =
          (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1);
    } else {
      ans = min(ans, getDistancePointToSegment(a, c, d));
      ans = min(ans, getDistancePointToSegment(b, c, d));
      ans = min(ans, getDistancePointToSegment(c, a, b));
      ans = min(ans, getDistancePointToSegment(d, a, b));
    }
    printf("%lld %lld\n", ans.s, ans.m);
  }
  return 0;
}

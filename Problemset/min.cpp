#include <bits/stdc++.h>
using namespace std;

int MOD = 998244353;
struct mint {
  long long x;
  mint(long long x=0):x((x%MOD+MOD)%MOD){}
  mint& operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}
  mint& operator-=(const mint a) {if ((x += MOD-a.x) >= MOD) x -= MOD;return *this;}
  mint& operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}
  mint operator+(const mint a) const {mint res(*this);return res+=a;}
  mint operator-(const mint a) const {mint res(*this);return res-=a;}
  mint operator*(const mint a) const {mint res(*this);return res*=a;}
  mint pow(long long b) const {
    mint res(1), a(*this);
    while (b) {
      if (b & 1) res *= a;
      a *= a;
      b >>= 1;
    }
    return res;
  }
  // for prime MOD
  mint inv() const {return pow(MOD-2);}
  mint& operator/=(const mint a) {return (*this) *= a.inv();}
  mint operator/(const mint a) const {mint res(*this);return res/=a;}

  // Relational operators
  bool operator<(const mint& a) const { return x < a.x; }
  bool operator>(const mint& a) const { return x > a.x; }
  bool operator<=(const mint& a) const { return x <= a.x; }
  bool operator>=(const mint& a) const { return x >= a.x; }
  bool operator==(const mint& a) const { return x == a.x; }
  bool operator!=(const mint& a) const { return x != a.x; }
};
ostream& operator<<(ostream& os, const mint& a) {os << a.x; return os;}
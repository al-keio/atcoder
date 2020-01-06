#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); var <= (end); var++)
#define RFOR(var, begin, end) for (int var = (begin); var >= (end); var--)
#define REP(var, length) FOR(var, 0, length - 1)
#define RREP(var, length) RFOR(var, length - 1, 0)
#define EACH(value, var) for (auto value : var)
#define SORT(var) sort(var.begin(), var.end())
#define REVERSE(var) reverse(var.begin(), var.end())
#define RSORT(var) SORT(var); REVERSE(var)
#define OPTIMIZE_STDIO ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed
#define endl '\n'

const ll MOD = 1e9 + 7;
struct mint {
    ll x;
    mint() : x(0) {}
    mint(ll x) : x((x % MOD + MOD) % MOD) {}
    mint& operator+=(const mint& r) { if ((x += r.x) >= MOD) { x -= MOD; } return *this; }
    mint& operator-=(const mint& r) { if ((x -= r.x) < 0) { x += MOD; } return *this; }
    mint& operator*=(const mint& r) { if ((x *= r.x) > MOD) { x %= MOD; } return *this; }
    mint& operator++() { if ((++x) >= MOD) { x -= MOD; } return *this; }
    mint operator++(int) { mint ret = x; if ((++x) >= MOD) { x-= MOD; } return ret; }
    mint& operator--() { if ((--x) < 0) { x += MOD; } return *this; }
    mint operator--(int) { mint ret = x; if ((--x) < 0) { x += MOD; } return ret; }
    mint operator+(const mint& r) { mint ret; return ret = x + r.x; }
    mint operator-(const mint& r) { mint ret; return ret = x - r.x; }
    mint operator*(const mint& r) { mint ret; return ret = x * r.x; }
    mint operator-() { return mint() - *this; }
    bool operator<(const mint& a) { return x < a.x; }
    bool operator>(const mint& a) { return x > a.x; }
    bool operator<=(const mint& a) { return x <= a.x; }
    bool operator>=(const mint& a) { return x >= a.x; }
    bool operator==(const mint& a) { return x == a.x; }
    bool operator!=(const mint& a) { return x != a.x; }
};
ostream& operator<<(ostream& os, const mint& r) { os << r.x; return os; }
ostream& operator>>(ostream& os, const mint& r) { os >> r.x; return os; }

void solve(istream& cin, ostream& cout) {
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
}
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (998244353)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"
 
template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
using oms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// read question properly
// don't forget newlines!!!!!!
// take care about cin >> t;
// comment the optimization before debugging
// ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS
 
struct Mint
{
    int value;
    static const int MOD_value = MOD;
 
    Mint(long long v = 0)
    {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }
    Mint(long long a, long long b) : value(0)
    {
        *this += a;
        *this /= b;
    }
 
    Mint &operator+=(Mint const &b)
    {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }
    Mint &operator-=(Mint const &b)
    {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }
    Mint &operator*=(Mint const &b)
    {
        value = (long long)value * b.value % MOD;
        return *this;
    }
 
    friend Mint mexp(Mint a, long long e)
    {
        Mint res = 1;
        while (e)
        {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend Mint inverse(Mint a) { return mexp(a, MOD - 2); }
 
    Mint &operator/=(Mint const &b) { return *this *= inverse(b); }
    friend Mint operator+(Mint a, Mint const b) { return a += b; }
    friend Mint operator-(Mint a, Mint const b) { return a -= b; }
    friend Mint operator-(Mint const a) { return 0 - a; }
    friend Mint operator*(Mint a, Mint const b) { return a *= b; }
    friend Mint operator/(Mint a, Mint const b) { return a /= b; }
    friend std::ostream &operator<<(std::ostream &os, Mint const &a) { return os << a.value; }
    friend bool operator==(Mint const &a, Mint const &b) { return a.value == b.value; }
    friend bool operator!=(Mint const &a, Mint const &b) { return a.value != b.value; }
};
 
int hp[100001];
 
vector<int> fact;
 
void dfs(const vector<pair<int, int>> &pf, int idx, int prod)
{
    if (idx == pf.size())
    {
        if (prod != 1)
            fact.push_back(prod);
        return;
    }
    int p = 1;
    for (int i = 0; i <= pf[idx].second; i++)
    {
        dfs(pf, idx + 1, prod * p);
        p *= pf[idx].first;
    }
}
 
void factors(ll k)
{
    fact.resize(0);
    map<int, int> fac;
    while (k > 1)
    {
        fac[hp[k]]++;
        k /= hp[k];
    }
    vector<pair<int, int>> pf;
    for (auto x : fac)
    {
        pf.push_back(x);
    }
    dfs(pf, 0, 1);
}
 
Mint ncr(int n, int r)
{
    assert(n >= r);
    assert(r >= 0);
    Mint a = 1;
    for (int i = n; i >= n - r + 1; i--)
    {
        a *= i;
    }
    Mint b = 1;
    for (int i = 1; i <= r; i++)
    {
        b *= i;
    }
    return a / b;
}
 

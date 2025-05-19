#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
int k, n, m;
vector<string> wd;
int mxx = 0;

void rec(int i, vector<int> &v, int cnt, const vector<string> &word) {
    if (i == static_cast<int>(word.size())) {  
        if (cnt > mxx) mxx = cnt;
        return;
    }
    if (cnt + (static_cast<int>(word.size()) - i) <= mxx) return;  
    for (int j = 0; j < n; j++) {
        if (v[j] == 0) {
            v[j] = static_cast<int>(word[i].size());  
            rec(i + 1, v, cnt + 1, word);
            v[j] = 0;
            break;
        } else {
            if (v[j] + 1 + static_cast<int>(word[i].size()) <= m) {  
                v[j] += 1 + static_cast<int>(word[i].size());  
                rec(i + 1, v, cnt + 1, word);
                v[j] -= 1 + static_cast<int>(word[i].size());  
            }
        }
    }
    rec(i + 1, v, cnt, word);
}

void solve() {
    cin >> k;
    wd.resize(k);
    for (auto &s : wd) cin >> s;
    cin >> n >> m;

    vector<string> v;
    for (auto &s : wd) if (static_cast<int>(s.size()) <= m) v.push_back(s); 

    sort(v.begin(), v.end(), [](const string &a, const string &b) -> bool {
        if (a.size() != b.size()) return a.size() > b.size();
        return a < b;
    });

    vector<int> temp(n, 0);
    rec(0, temp, 0, v);
    cout << mxx;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    int t = 1000;
    while(t!=0){t--;}
    solve();

    return 0;
}
#include <iostream>
#include <map>
#include <vector>
#include <numeric> // for __gcd in GCC/Clang
using namespace std;

const int MOD = 998244353;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    // dp maps gcd_value -> count of ways (paths) ending with that gcd value.
    // Start with the first city.
    map<int, int> dp;
    dp[a[0]] = 1;
    
    // Process cities from the second one onward.
    for (int i = 1; i < n; i++) {
        map<int, int> new_dp;
        
        // For each active state, update the state by incorporating a[i]
        for (auto &entry : dp) {
            int currentGcd = entry.first;
            int count = entry.second;
            int newGcd = gcd(currentGcd, a[i]);  // Using GCC extension __gcd
            new_dp[newGcd] = (new_dp[newGcd] + count) % MOD;
        }
        
        // Also consider starting a new path at city i.
        new_dp[a[i]] = (new_dp[a[i]] + 1) % MOD;
        
        dp = move(new_dp);
    }
    
    // Sum up all counts.
    int result = 0;
    for (auto &entry : dp) {
        result = (result + entry.second) % MOD;
    }
    
    cout << result << "\n";
    return 0;
}

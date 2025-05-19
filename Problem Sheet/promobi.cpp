#include <bits/stdc++.h>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

bool isanagram(string s1,string s2,string s3){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    sort(s3.begin(),s3.end());
    if(s1 == s2 && s2 == s3) return true;
    return false;
}

string toBase62(long long n) {
    const string base62Chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    if (n == 0) return "0";
    
    string result;
    bool isNegative = (n < 0);
    n = abs(n);

    while (n > 0) {
        result += base62Chars[n % 62];
        n /= 62;
    }

    if (isNegative) result += '-';
    reverse(result.begin(), result.end());
    return result;
}

void solve(){
    long long n;cin>>n;
    cout<<toBase62(n)<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Special Characters
// void solve(){
//     int n;cin>>n;
//     if(n&1){
//         cout<<"No"<<nline;
//         return;
//     }
//     string ans;
//     for(int i=0;i<n/2;i++){
//         if(i&1) ans+="AA";
//         else ans+="BB";
//     }
//     cout<<"Yes"<<nline;
//     cout<<ans<<endl;
// }

// Array Fix
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     bool flag = true;
//     for(int i=1;i<n;i++){
//         if(arr[i]<arr[i-1]){
//             flag = false;
//             break;
//         }
//     }
//     if(flag){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     vector<int> temp;
//     int ind = -1;
//     for(int i=1;i<n;i++){
//         if(arr[i]<arr[i-1]) ind = i;
//     }
//     for(int i=0;i<ind;i++){
//         vector<int> v;
//         if(arr[i] == 0){
//             temp.push_back(0);
//             continue;
//         }
//         while(arr[i]){
//             v.push_back(arr[i]%10);
//             arr[i]/=10;
//         }
//         reverse(v.begin(),v.end());
//         for(int ele : v) temp.push_back(ele);
//     }
//     for(int i = ind;i<n;i++) temp.push_back(arr[i]);
//     int len = temp.size();
//     // for(int ele : temp) cout<<ele<<" ";
//     // cout<<endl;
//     for(int i=1;i<len;i++){
//         if(temp[i-1]>temp[i]){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

//  Arrow Path
// void solve(){
//     int n;cin>>n;
//     vector<string> vs(2);
//     for(int i=0;i<2;i++) cin>>vs[i];
//     // for the first row
//     for(int i=1;i<n;i+=2){
//         if(vs[0][i]=='<' && vs[1][i-1]=='<'){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     for(int i=1;i<n-1;i+=2){
//         if(vs[0][i]=='<' && vs[1][i+1]=='<'){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Tandem Repeats?
bool isPossible(string &s,int k){
    int len = k/2;
    int n = s.length();
    vector<int> prefix(n,0);
    for(int i=0;i<n-len;i++){
        if(s[i] == '?' || s[i+len] == '?') prefix[i] = 1;
        else if(s[i]==s[i + len]) prefix[i] = 1;
        else prefix[i] = 0;
    }
    for(int i=1;i<n;i++){
        if(prefix[i] == 1) prefix[i] += prefix[i-1];
    }
    for(int i=0;i<n;i++){
        if(prefix[i] == len) return true;
    }
    return false;
}

void solve(){
    string s;cin>>s;
    int n = s.length();
    int ans = 0;
    if(n&1) n--;
    for(int i=n;i>=2;i-=2){
        // cout<<i<<endl;
        if(isPossible(s,i)){
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
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
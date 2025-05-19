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

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int _max = 0;
//     for(int i=0;i<n;i+=2){
//         _max = max(arr[i],_max);
//     }
//     cout<<_max<<endl;
// }

// AND Reconstruction
// void solve(){
//     int n;cin>>n;
//     int b[n-1];
//     for(int i=0;i<n-1;i++) cin>>b[i];
//     vector<int> ans;
//     ans.push_back(b[0]);
//     for(int i=0;i<n-2;i++) ans.push_back(b[i]|b[i+1]);
//     ans.push_back(b[n-2]);
//     for(int i=0;i<n-1;i++){
//         if((ans[i]&ans[i+1])!=b[i]){
//             cout<<-1<<endl;
//             return;
//         }
//     }
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Absolute Zero
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int cnt = 0;
    int odd = 0,even = 0;
    for(int i=0;i<n;i++){
        if(arr[i]&1) odd++;
        else even++;
        if(odd>0 && even>0){
            cout<<-1<<endl;
            return;
        }
    }
    vector<int> ans;
    while(cnt<41){
        cnt++;
        int _max = *max_element(arr,arr+n);
        int _min = *min_element(arr,arr+n);
        int mid = (_max+_min)/2;
        for(int i=0;i<n;i++) arr[i] = abs(arr[i]-mid);
        ans.push_back(mid);
        int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];
        if(sum==0) break;
    }
    cout<<ans.size()<<endl;
    for(int ele : ans) cout<<ele<<" ";
    cout<<endl;
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
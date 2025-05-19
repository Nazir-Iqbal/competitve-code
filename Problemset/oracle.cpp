#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void f(int end,int ind,int arr[],int sum,unordered_map<int,int> &mp){
    if(ind > end){
        // cout<<sum<<endl;
        mp[sum]++;
        return;
    }
    // taking the element;
    f(end,ind+1,arr,sum+arr[ind],mp);
    // not taking element
    f(end,ind+1,arr,sum,mp);
}

void solve(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    unordered_map<int,int> m1,m2;
    f((n - 1)/2, 0, arr, 0, m1);
    f(n - 1, (n - 1)/2 + 1,  arr, 0, m2);
    int ans = 0;
    for(auto &ele : m1){
        // cout<<ele.first<<" "<<ele.second<<endl;
        int left = x - ele.first;
        ans += ele.second * m2[left];
    }
    cout<<ans<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}
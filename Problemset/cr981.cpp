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
//     bool flag = true;
//     int i = 1,cur = 0;
//     while(cur<=n && cur>=-n){
//         // cout<<cur<<endl;
//         if(flag) cur-=(2*i-1);
//         else cur+=(2*i-1);
//         flag ^=1;
//         i++;
//     }

//     if(flag) cout<<"Kosuke"<<endl;
//     else cout<<"Sakurako"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n][n];
//     for(int i=0;i<n;i++)  for(int j=0;j<n;j++) cin>>arr[i][j];
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int _max = INT_MIN;
//         for(int j=0;j<n-i;j++){
//             if(arr[j][i+j]<0) _max = max(_max,abs(arr[j][i+j]));
//         }
//         if(_max!=INT_MIN) ans += _max;
//     }
//     for(int i=1;i<n;i++){
//         int _max = INT_MIN;
//         for(int j=0;j<n-i;j++){
//             if(arr[i+j][j]<0) _max = max(_max,abs(arr[i+j][j]));
//         }
//         if(_max!=INT_MIN) ans += _max;
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans = 0,sum = 0;
//     map<int,int> mp;
//     mp[0] = 1;
//     for(int i=0;i<n;i++){
//         sum += arr[i];
//         if(arr[i] == 0 || mp[sum]!=0){
//             // cout<<i<<" "<<sum<<endl;
//             ans++;
//             mp.clear();
//             mp[0] = 1;
//             sum = 0;
//             continue;
//         }
//         mp[sum]++;
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int l = 1,r = n-2;
//     while(l<=r){
//         if(arr[l-1]==arr[l] || arr[r]==arr[r+1]){
//             if(arr[l] != arr[r]) swap(arr[l],arr[r]);
//             // else if(arr[l-1]!=arr[r+1]) swap(arr[l-1],arr[r+1]);
//         }
//         l++,r--;
//     }
//     int ans = 0;
//     for(int i=0;i<n-1;i++){
//         if(arr[i]==arr[i+1]) ans++;
//     }
//     cout<<ans<<endl;
// }

// E. Sakurako, Kosuke, and the Permutation
// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     unordered_map<int,int> mp,pos;
//     for(int i=1;i<=n;i++){
//         if(arr[i] == i) continue;
//         mp[i] = arr[i];
//         pos[arr[i]] = i;
//     }
//     int ans = 0;
//     for(auto &ele : mp){
//         if(ele.first == ele.second) continue;
//         int num1 = ele.first , num2 = ele.second , num3 = mp[num2];
//         if(num1 == num3) continue;
//         int pos1 = pos[num1];
//         int temp = mp[pos1];
//         mp[pos1] = num3;
//         mp[num2] = num1;
//         pos[temp] = num2;
//         pos[num1] = num2;
//         pos[num3] = pos1;
//         ans++;
//     }
//     cout<<ans<<endl;
// }

// Kosuke's Sloth

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> test(n,0);
    test[1] = test[2] = 1;
    for(int i=3;i<n;i++) test[i] += test[i-1]+test[i-2];
    for(int i=1;i<n;i++) cout<<test[i]<<" ";
    cout<<endl;
    for(int i=1;i<n;i++) if(test[i]%k==0) cout<<test[i]<<" ";
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
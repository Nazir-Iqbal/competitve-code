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

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int hsn[4] ={0};
//     int ans = 0;
//     for(int i=0;i<4*n;i++){
//         if(s[i] == '?') continue;
//         else{
//             hsn[s[i]-'A']++;
//         }
//     }
//     for(int i=0;i<4;i++) ans += min(n,hsn[i]);
//     cout<<ans<<endl;
// }

// Parity and Sum
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int odd = 0,even = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i]&1) odd++;
//         else even++;
//     }
//     if(odd==0 || even == 0){
//         cout<<0<<endl;
//         return;
//     }
//     int maxo = 0;
//     vector<int> maxe;
//     for(int i=0;i<n;i++){
//         if(arr[i]&1) maxo = max(maxo,arr[i]);
//         else maxe.push_back(arr[i]);
//     }
//     sort(maxe.begin(),maxe.end());
//     int ans = 0,ind = -1;
//     for(int i=0;i<maxe.size();i++){
//         if(maxo>maxe[i]) ans++,maxo+=maxe[i];
//         else{
//             ind = i;
//             break;
//         }
//         // cout<<i<<" "<<maxo<<endl;
//     }
//     if(ind!=-1){
//         for(int i=maxe.size()-1;i>=ind;i--){
//             if(maxo<maxe[i]){
//                 ans+=2;
//                 maxo += 2*maxe[i];
//             }else ans++,maxo += maxe[i];
//         }
//     }
//     cout<<ans<<endl;
// }

// Light Switches
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int _min = arr[0];
    for(int i=0;i<n;i++) arr[i] -= _min;
    vector<int> hsn(k+1,-1);
    for(int i=0;i<n;i++){
        int temp = arr[i]%k;
        if(hsn[temp]==-1) hsn[temp] = arr[i];
        else{
            int div = abs(hsn[temp]-arr[i])/k;
            if(div&1){
                cout<<-1<<endl;
                return;
            }
        }
    }
    for(int i=0;i<k;i++) hsn[i] = 0;
    for(int i=0;i<n;i++){
        int rem = arr[i]%k;
        int div = arr[i]/k;
        // cout<<arr[i]<<" "<<div<<" "<<rem<<endl;
        if(div&1){
            hsn[0]++;
            hsn[rem]--;
        }else{
            hsn[rem]++;
            hsn[k]--;
        }
    }
    for(int i=1;i<=k;i++) hsn[i] += hsn[i-1];
    // for(int i=0;i<=k;i++) cout<<hsn[i]<<" ";
    // cout<<endl;
    int ind = -1;
    for(int i=0;i<k;i++){
        if(hsn[i] == n){
            ind = i;
            break;
        }
    }
    if(ind==-1){
        cout<<-1<<endl;
        return;
    }
    int _max = arr[n-1]+_min;
    int div = (_max-(_min+ind))/k;
    if(div&1) div++;
    int calc = div*k+ind+_min;
    if(calc<_max) calc = (div+2)*k+ind;
    cout<<calc<<endl;
}

// void solve();

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